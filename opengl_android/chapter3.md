# 编译着色器及在屏幕上绘图
## 加载着色器
在android项目中，着色器是在资源文件中写的代码，所以第一步需要把代码加载到内存中。
### 从资源中加载着色器源码
  函数如下：
```
public static String readTextureFileFromResource(Context context,int resourceId) {     StringBuilder body = new StringBuilder();      try     {         InputStream         inputStream         = context.getResources().openRawResource(resourceId);         InputStreamReader   inputStreamReader   = new InputStreamReader(inputStream);         BufferedReader      bufferedReader      = new BufferedReader(inputStreamReader);          String nextLine;         while( (nextLine = bufferedReader.readLine()) != null)         {             body.append(nextLine);             body.append("\n");         }     }     catch (IOException e)     {      }     catch (Resources.NotFoundException e)     {         throw  new RuntimeException("Resource not found:" + resourceId,e);     }      return body.toString();  }

```
### 在渲染中读入着色器代码
```
//读取着色器源码 String vertexShaderSource = TextResourceReader.*readTextureFileFromResource*(context, R.raw.*simple_vertex_shader*); String fragmentShaderSource = TextResourceReader.*readTextureFileFromResource*(context,R.raw.*simple_fragment_shader*); 

```
## 编译着色器
把着色器代码读出之后，就需要编译着色器了，为了未来项目使用，编译着色器创建了一个新的辅助类，该类可以创建新的着色器对象，编译着色器源码，并且返回代表那个着色器代码的着色器对象。编译部分代码如下:
```
public static int compileVertexShader(String shaderCode) {     return *compileShader*(*GL_VERTEX_SHADER*,shaderCode); } public static int compileFragmentShader(String shaderCode) {     return *compileShader*(*GL_FRAGMENT_SHADER*,shaderCode); }  private static int compileShader(int type,String shaderCode) {     //创建新的着色器对象     final int shaderObjectId = glCreateShader(type);     if(0 == shaderObjectId)     {               return 0;     }      //加入着色器源代码上传到着色器对象里     //该调用告诉opengl读入字符串shaderCode定义的源代码，并把它与shaderObject所引用的着色器     //关联起来     glShaderSource(shaderObjectId,shaderCode);      //编译着色器     glCompileShader(shaderObjectId);      //取出编译状态     final int[] compileStatus = new int[1];     glGetShaderiv(shaderObjectId,GL_COMPILE_STATUS,compileStatus,0);     if(LoggerConfig.ON)     {         Log.v(TAG,"Results of compiling source:" + "\n" + shaderCode + "\n:"                                                 + glGetShaderInfoLog(shaderObjectId));     }      //验证编译状态     if(compileStatus[0] == 0)     {         glDeleteShader(shaderObjectId);         if(LoggerConfig.ON)         {             Log.w(TAG,"Compilation of shader failed");         }          return 0;     }     return shaderObjectId; }

```
### 创建一个新的着色器对象
创建着色器并检查这个创建是否成功。
```
final int shaderObjectId = glCreateShader(type); if(0 == shaderObjectId) {    return 0; }

```
### 上传和编译着色器源码
```
*glShaderSource*(shaderObjectId,shaderCode);

```
### 取出编译状态
```
//取出编译状态 final int[] compileStatus = new int[1]; glGetShaderiv(shaderObjectId,GL_COMPILE_STATUS*,compileStatus,0);

```
### 取出着色器日志
### 验证着色器编译状态并返回着色器ID
```
//验证编译状态 if(compileStatus[0] == 0) {     glDeleteShader*(shaderObjectId);     if(LoggerConfig.*ON*)     {         Log.*w*(*TAG*,"Compilation of shader failed");     }      return 0; }
```
### 在renderer类中编译着色器
```
//编译着色器 int vertexShader = ShaderHelper.*compileVertexShader*(vertexShaderSource); int fragmentShader = ShaderHelper.*compileFragmentShader*(fragmentShaderSource);

```
## 把着色器链接进OpenGL的程序
### 理解OpenGL程序
  简单来说，一个OpenGL程序就是把一个顶点着色器和一个片段着色器链接在一起变成单个对象。
顶点着色器和片段着色器总是一起工作的，没有片段着色器，OpenGL就不知道怎么绘制那些组成每个点、直线和三角形的片段；如果没有顶点着色器，OpenGL就不知道在哪里绘制这些片段
  顶点着色器计算屏幕上每个顶点的最终位置，当OpenGL把这些顶点组织成点、直线和三角形并且分解成片段的时候，它就会向片段着色器询问每个片段的最后颜色。顶点和片段着色器一起合成屏幕上最终的图像
  虽然顶点着色器和片段着色器总是要一起工作的，但并不意味着他们必须一对一匹配，可以同时在多个程序中使用同一个着色器。
## 拼接
## 绘制到屏幕