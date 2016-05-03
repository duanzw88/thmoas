#include <stdio.h>
#include <jni.h>
//va_list
#include <stdarg.h>
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stddef.h>

//最大日志消息长度
#define MAX_LOG_MESSAGE_LENGTH 256
#define MAX_BUFFER_SIZE 80

/**
 * 将给定的消息记录到应用程序
 * @param env    JNIEnv interface
 * @param obj    object interface
 * @param format 消息格式和参数
 */
static void LogMessage(JNIEnv* env,jobject obj,const char* format,...)
{
	//缓存日志方法ID
	static jmethodID methodID = NULL;

	//如果方法ID未缓存
	if(NULL == methodID)
	{
		//从java对象获取类
		jclass clazz = env->GetObjectClass(obj);
		//从给定方法获取方法ID
		methodID = env->GetMethodID(clazz,"logMessage","(Ljava/lang/String;)V");

		//释放类引用
		env->DeleteLocalRef(clazz);
	}
	if(NULL != methodID)
	{
		//格式化日志消息
		char buffer[MAX_LOG_MESSAGE_LENGTH];

		va_list ap;
		va_start(ap,format);
		vsnprintf(buffer,MAX_LOG_MESSAGE_LENGTH,format,ap);
		va_end(ap);

		//将缓冲区转换为Java字符串
		jstring message = env->NewStringUTF(buffer);

		//如果字符串构造正确
		if(NULL != message)
		{
			//记录消息
			env->CallVoidMethod(obj,methodID,message);

			//释放消息引用
			env->DeleteLocalRef(message);
		}
	}
}

/**
 * 用给定的异常类和异常消息抛出新的异常
 * @param env       [description]
 * @param className [description]
 * @param message   [description]
 */
static void ThrowException(JNIEnv *env,const char* className,const char* message)
{
	//获取异常类
	jclass clazz = env->FindClass(className);
	//如果没有获取到异常类
	if(NULL != clazz)
	{
		//抛出异常
		env->ThrowNew(clazz,message);
		//释放原生类引用
		env->DeleteLocalRef(clazz);
	}

}

static void ThrowErrnoException(JNIEnv *env,const char* className,int errnum)
{
	char buffer[MAX_LOG_MESSAGE_LENGTH];

	//获取错误消息号
	if(-1 == strerror_r(errnum,buffer,MAX_LOG_MESSAGE_LENGTH))
	{
		strerror_r(errno,buffer,MAX_LOG_MESSAGE_LENGTH);
	}

	//抛出异常
	ThrowException(env,className,buffer);
}

/**
 * 构造新的TCP socket
 * @param  env [description]
 * @param  obj [description]
 * @return     [description]
 */
static int NewTcpSocket(JNIEnv* env,jobject obj)
{
	//构造socket
	LogMessage（env,obj,"Constructing a new TCP socket...");

	int tcpSocket = socket(PF_INET,SOCK_STREAM,0);

	//检查socket构造是否正确
	if(-1 == tcpSocket)
	{
		//抛出带错误的异常
		ThrowErrnoException(env,"java/io/IOException",errno);
	}

	return tcpSocket;
}

/**
 * 将socket绑定到某一端口号
 * @param env  [description]
 * @param obj  [description]
 * @param sd   [description]
 * @param port [description]
 */
static void BindSocketToPort(JNIEnv* env,jobject obj,int sd,unsigned short port)
{
	struct sockaddr_in address;

	//绑定socket地址
	memset(&address,0,sizeof(address));
	address.sin_family = PF_INET;

	//绑定到所有地址
	address.sin_addr.s_addr = htonl(INADDR_ANY);

	//将端口转换为网络字节顺序
	address.sin_port = htons(port);

	//绑定socket
	LogMessage(env,obj,"Binding to port %hu.",port);
	if(-1 == bind(sd,(struct sockaddr*)&address,sizeof(address)))
	{
		//抛出异常
		ThrowErrnoException(env,"java/io/IOException",errno);
	}

}

static unsigned short GetSocketPort(JNIEnv* env,jobject obj,int sd)
{
	unsigned short port = 0;
	struct sockaddr_in address;
	socklen_t addressLength = sizeof(address);

	//获取socket地址
	if(-1 == getsockname(sd,(struct sockaddr*)&address,&addressLength))
	{
		//抛出异常
		ThrowErrnoException(env,"java/io/IOException",errno);
	}
	else
	{
		//将端口转换为主机字节顺序
		port = ntohs(address.sin_port);
		LogMessage(env,obj,"Binded to random port %hu.",port);
	}

	return port;
}

/**
 * 监听指定的待处理连接的backlog的socket，当backlog已满时拒绝新的连接
 * @param env     [description]
 * @param obj     [description]
 * @param sd      [description]
 * @param backlog [description]
 */
static void ListenOnSocket(JNIEnv *env,jobject obj,int sd,int backlog)
{
	//监听给定的backlog的socket
	LogMessage(env,obj,"Listening on socket with a backlog of %d pending connections.",backlog);
	if(-1 == listen(sd,backlog))
	{
		//抛出异常
		ThrowErrnoException(env,"java/io/IOException",errno);
	}
}

/**
 * 记录给定地址的IP地址和端口号
 * @param env     [description]
 * @param obj     [description]
 * @param message [description]
 * @param address [description]
 */
static void LogAddress(JNIEnv* env,jobject obj,const char* message,const struct sockaddr_in* address)
{
	char ip[INET_ADDRSTRLEN];

	//将ip地址转换为字符串
	if(NULL == inet_ntop(PF_INET,*(address->sin_addr),ip,INET_ADDRSTRLEN))
	{
		//抛出带错误号的异常
		ThrowErrnoException(env,"java/io/IOException",errno);
	}
	else
	{
		//将端口转换为主机字节顺序
		unsigned short port = ntohs(address->sin_port);

		//记录地址
		LogMessage(env,obj,"%s %s:%hu.",message,ip,port);
	}
}

static int AcceptOnSocket(JNIEnv* env,jobject obj,int sd)
{
	struct sockaddr_in address;
	socklen_t addressLength = sizeof(address);

	//阻塞和等待进来的客户连接
	//并且接受它
	LogMessage(env,obj,"Wating for a client connection...");
	int clientSocket = accept(sd,(struct sockaddr*)&address,&addressLength);
	if(-1 == clientSocket)
	{
		//抛出带错误的异常
		ThrowErrnoException(env,"java/io/IOException",errno);
	}
	else
	{
		//记录地址
		LogAddress(env,obj,"Client connection form ",&address);
	}

	return clientSocket;
}

/**
 * 阻塞并接收来自socket的数据放到缓冲区
 * @param  env        [description]
 * @param  obj        [description]
 * @param  sd         [description]
 * @param  buffer     [description]
 * @param  bufferSize [description]
 * @return            [description]
 */
static ssize_t ReceiveFromSocket(JNIEnv* env,jobject obj,int sd,char* buffer,size_t bufferSize)
{
	//阻塞并接收来自socket的数据放到缓冲区
	LogMessage(env,obj,"Receiving from the socket...");
	ssize_t recvSize = recv(sd,buffer,bufferSize - 1,0);
	if(-1 == recvSize)
	{
		//抛出带错误号的异常
		ThrowErrnoException(env,"java/io/IOException",errno);
	}
	else
	{
		//以NULL结尾缓冲区形成一个字符串
		buffer[recvSize] = NULL;
		if(recvSize > 0)
		{
			LogMessage(env,obj,"Received %d bytes:%s",recvSize,buffer);
		}
		else
		{
			LogMessage(env,obj,"Client disconnected.");
		}
	}

	return recvSize;
}

static ssize_t SendToSocket(JNIEnv* env,jobject obj,int sd,const char* buffer,size_t bufferSize)
{
	//将数据缓冲区发送到socket
	LogMessage(env,obj,"Sending to the socket...");
	ssize_t sentSize = send(sd,buffer,bufferSize,0);

	//如果发送失败
	if(-1 == sentSize)
	{
		//抛出带错误号的异常
		ThrowErrnoException(env,"java/io/IOException",errno);
	}
	else
	{
		if(sentSize > 0)
		{
			LogMessage(env,obj,"Sent %d bytes:%s",sentSize,buffer);
		}
		else
		{
			LogMessage(env,obj,"Client disconnected.");
		}
	}

	return sentSize;
}

//原生TCP服务器方法
void Java_com_duanzw_guides_cplusplusNdk_EchoServerActivity_nativeStartTcpServer(JNIEnv* env,jobject obj,port)
{
	//构造新的TCP socket
	int serverSocket = NewTcpSocket(env,obj);
	if(NULL == env->ExceptionOccurred())
	{
		//将socket绑定到某端口
		BindSocketToPort(env,obj,serverSocket,(unsigned short)port);
		if(NULL != env->ExceptionOccurred())
		{
			return;
		}
		//如果请求了随机端口号
		if(0 == port)
		{
			//获取当前绑定的端口号socket
			GetSocketPort(env,obj,serverSocket);
			if(NULL != env->ExceptionOccurred())
			{
				return;
			}
		}

		//监听有4个等待连接的backlog的socket
		ListenOnSocket(env,obj,serverSocket,4);
		if(NULL != env->ExceptionOccurred())
		{
			return;
		}
		//接受socket的一个客户连接
		int clientSocket = AcceptOnSocket(env,obj,serverSocket);
		if(NULL != env->ExceptionOccurred())
		{
			return;
		}

		char buffer[MAX_BUFFER_SIZE];
		ssize_t recvSize;
		ssize_t sentSize;

		//接收并发送回数据
		while(1)
		{
			//从socket中接收
			recvSize = ReceiveFromSocket(env,obj,clientSocket,buffer,MAX_BUFFER_SIZE);
			if( (0 == recvSize) || (NULL != ExceptionOccurred()))
			{
				break;
			}

			//发送给socket
			sentSize = SendToSocket(env,obj,clientSocket,buffer,(size_t)recvSize);
			if( (0 == sentSize) || (NULL != env->ExceptionOccurred()))
			{
				break;
			}
		}
		//关闭客户端socket
		close(clientSocket);
	}
}

static void ConnectToAddress(JNIEnv *env,jobject jobj,int sd,const char *ip,unsigned short port)
{
	//连接到给定的IP地址和给定的端口号
	LogMessage(env,obj,"Connecting to  %s : %uh...",ip,port);

	struct sockaddr_in address;

	memset(&address,0,sizeof(address));
	address.sin_family = PF_INET;
	//将IP地址字符串转换为网络地址
	if(0 == inet_aton(ip,&(address.sin_addr)))
	{
		//抛出异常
		ThrowErrnoException(env,"java/io/IOException",errno);
	}
	else
	{
		//将端口号转换为网络字节序
		address.sin_port = hotns(port);
		//转换地址
		if(-1 == connect(sd,(const sockaddr *)&address,sizeof(address)))
		{
			//抛出异常
			ThrowErrnoException(env,"java/io/IOException",errno);
		}
		else
		{
			LogMessage(env,obj,"Connected");
		}
	}
}
