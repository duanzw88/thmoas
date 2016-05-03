# 准备开始

## 初始化OpenGL
  android中使用特殊的类GLSurfaceView初始化OpenGL。GLSurfaceView会处理OpenGL初始化过程中比较基本的操作。  
在幕后，GLSurfaceView实际上为它自己创建一个窗口(window)，并在试图层次上穿个“洞”，让底层的OpenGL surface显示出来
从Android4.0开始，Android提供了一个纹理视图(TextureView)，它可以渲染OpenGL而不是使用创建单独的窗口或打洞了，这就意味着，这个视图可以像一个常规窗口一样，可以被操作，且有动画和变形特效。但是TextureView没有内置OpenGL初始化的操作，要想使用TextureView，一种方法是执行自定义的OpenGL初始化并在TextureView上运行，另外一种是吧GLSurfaceView得源代码拿出来，把它适配到TextureView上。
## 渲染器Render类
渲染器接口方法：
```
onSurfaceCreated(GL10 glUnused,EGLConfig config)
说明:
	当Surface被创建的时候，GLSurfaceView会调用这个方法；
	这发生在应用程序第一次运行的时候，并且当设备被唤醒或者从其他activity切换回来时，这个方法也可能会被调用。
```
```
onSurfaceChanged(GL10 glUnused,int width,int height)
说明：
	在Surface被创建以后，每次Surface的尺寸发生变化，这个方法都会被GLSurfaceView调用。在横竖屏切换的时候，Surface尺寸会发生变化
```
```
onDrawFrame(GL10 glUnused)
说明:
	当绘制一帧时，这个方法会被GLSurfaceView调用。在这个方法中，我们一定要绘制一些东西，即使是清空屏幕；因为在这个方法后，渲染缓冲区会被交换并显示在屏幕上，如果什么都没画，可能会看到屏幕闪烁效果
```