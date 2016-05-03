#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <jni.h>

#include <android/log.h>
#define TAG "jc_sdk"
#define JC_LOG(...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)


struct NativeWorkerArgs
{
	jint id;
	jint iterations;
};

//方法ID能被缓存
static jmethodID gOnNaviteMessage = NULL;
//Java虚拟机接口指针
static JavaVM* gVm = NULL;
//对象的全局引用
static jobject gObj = NULL;

//互斥锁实例
statci pthread_mutex_t mutex;

jint JNI_OnLoad(JavaVM* vm,void* reserved)
{
	//缓存Java虚拟机接口指针
	gVm = vm;

	return JNI_VERSION_1_4;
}
JNIEXPORT void JNICALL Java_com_duanzw_guides_cplusplusNdk_NativeThreadActivity_nativeInit(JNIEnv* env,jobject obj)
{
	//初始化互斥锁
	if(0 != pthread_mutex_init(&mutex,NULL))
	{
		//获取异常类
		jclass exceptionClazz = (*env)->FindClass("java/lang/RuntimeException");
		//抛出异常
		(*env)->ThrowNew(env,exceptionClazz,"Unable to initialize mutex");

		return;
	}
	if(NULL == gObj)
	{
		//为对象创建一个新的全局引用
		gObj = (*env)->NewGlobalRef(env,obj);
		if(NULL == gObj)
		{
			return;
		}
	}
	if(NULL == gOnNaviteMessage)
	{
		//从对象中获取类
		jclass clazz = (*env)->GetObjectClass(env,obj);

		//为回调获取方法ID
		gOnNaviteMessage = (*env)->GetMethodID(env,clazz,"onNativeMessage","(Ljava/lang/String;)V");

		//如果方法没有找到
		if(NULL == gOnNaviteMessage)
		{
			jclass exceptionClazz = (*env)->FindClass(env,"java/lang/RuntimeException");
			//抛出异常
			(*env)->ThrowNew(env,exceptionClazz,"Unable to find method");
		}
	}
}

JNIEXPORT void JNICALL Java_com_duanzw_guides_cplusplusNdk_NativeThreadActivity_nativeFree(JNIEnv* env,jobject obj)
{

	if(NULL != gObj)
	{
		//删除全局引用
		(*env)->DeleteGlobalRef(env,gObj);
		gObj = NULL;
	}
	//销毁互斥锁
	if(0 != pthread_mutex_destory(&mutex))
	{
		//获取异常类
		jclass exceptionClazz = (*env)->FindClass(env,"java/lang/RuntimeException");
		//抛出异常类
		(*env)->ThrowNew(env,exceptionClazz,"Unable to destory mutex");

		return;
	}
}
JNIEXPORT void JNICALL Java_com_duanzw_guides_cplusplusNdk_NativeThreadActivity_nativeWorker(JNIEnv* env,jobject obj,jint id,jint iterations)
{
	int i;
	//循环给定的迭代次数
	for(i = 0;i < iterations;i++)
	{
		//准备消息
		char message[26];
		sprintf(message,"Worker %d: Iteration %d",id,i);
		JC_LOG("Worker %d: Iteration %d",id,i);

		//来自C字符串的消息
		jstring messageString = (*env)->NewStringUTF(env,message);
		//调用原生消息方法
		(*env)->CallVoidMethod(env,obj,gOnNaviteMessage,messageString);

		//检查是否产生异常
		// if(NULL != (*env)->ExceptionOccurred())
		// {
		// 	break;
		// }

		//睡眠一秒
		sleep(1);
	}
}

static void* nativeWorkerThread(void *args)
{
	JNIEnv* env = NULL;

	//将当前线程附加到Java虚拟机上
	//并且获得JNIEnv接口指针
	if(0 == (*gVm)->AttachCurrentThread(gVm,&env,NULL))
	{
		//获取原生worker线程参数
		struct NativeWorkerArgs* nativeWorkerArgs = (struct NativeWorkerArgs *)args;

		//在线程上下文中运行原生worker
		Java_com_duanzw_guides_cplusplusNdk_NativeThreadActivity_nativeWorker(env,gObj,nativeWorkerArgs->id,nativeWorkerArgs->iterations);

		//释放原生worker线程参数
		// delete nativeWorkerArgs;

		//从java虚拟机中分离当前线程
		(*gVm)->DetachCurrentThread(gVm);
	}

	return (void *)1;
}
JNIEXPORT void JNICALL Java_com_duanzw_guides_cplusplusNdk_NativeThreadActivity_posixThreads(JNIEnv* env,jobject obj,jint jthreads,jint jiterations)
{
	JC_LOG("-----------");
	jint i,j;
	//线程句柄
	pthread_t handles[jthreads];
	for(i = 0;i < jthreads;i++)
	{
		//原生worker线程参数
		struct NativeWorkerArgs* nativeWorkerArgs = (struct NativeWorkerArgs*)malloc(sizeof(struct NativeWorkerArgs));
		nativeWorkerArgs->id = i;
		nativeWorkerArgs->iterations = jiterations;

		//线程句柄
		pthread_t thread;
		//创建一个新的线程
		int result = pthread_create(&handles[i],NULL,nativeWorkerThread,(void *)nativeWorkerArgs);
		if(0 != result)
		{
			//获取异常类
			jclass exceptionClazz = (*env)->FindClass(env,"java/lang/RuntimeException");
			//抛出异常
			(*env)->ThrowNew(env,exceptionClazz,"Unable to create thread");
			return;
		}

	}
	//等待线程中止
	for(j = 0;j < jthreads;j++)
	{
		void *result = NULL;

		//连接每个线程句柄
		if(0 != pthread_join(handles[j],&result))
		{
			//获取异常类
			jclass exceptionClazz = (*env)->FindClass(env,"java/lang/RuntimeException");
			//抛出异常
			(*env)->ThrowNew(env,exceptionClazz,"Unable to join thread");
		}
		else
		{
			//准备message
			char message[26];
			sprintf(message,"Worker %d returned %d",i,(int)result);

			//来自C字符串的message
			jstring messageString = (*env)->NewStringUTF(env,message);

			//调用原生消息方法
			(*env)->CallVoidMethod(env,obj,gOnNaviteMessage,messageString);

			//检查是否产生异常
			if(NULL != (*env)->ExceptionOccurred(env))
			{
				return;
			}
		}
	}
}
