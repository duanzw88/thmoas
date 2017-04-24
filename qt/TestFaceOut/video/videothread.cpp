#include "videothread.h"
#include <QDebug>
#include <highgui.h>

#define image_Format QImage::Format_RGB888 //图片显示格式
#define cameraDevice "/dev/video0"  //摄像头设备
#define imgSizeScaleSmall 0.5    //图像防缩比例
#define imgSizeScaleBig 2    //图像防缩比例
#define haarXML "./data/haarcascade_frontalface_alt2.xml"   //人脸模型级联分类器文件

VideoThread::VideoThread(QObject *parent) :
    QThread(parent)
{
    stopped = false;//停止线程
    this->saveFlags = true;//是否保存图片
    this->recoFlags = false;//是否识别
    this->deviceFlags = false;//摄像头是否成功

    image_width = 320 ;//图片显示宽度
    image_height = 240 ;   //图片显示高度
    connect(this,SIGNAL(finished()),this,SLOT(deleteLater()));

    this->InitVideoDevice();//初始化摄像头

    //获取摄像头图像
    this->timer = new QTimer(this);
    connect(this->timer,SIGNAL(timeout()),this,SLOT(update()));
    this->timer->start(1);

     // Storage for the rectangles detected
     cascadeFile = haarXML;
     cascade = (CvHaarClassifierCascade *) cvLoad(cascadeFile.toUtf8());
     m_FaceCount = 0;
     storage = cvCreateMemStorage(0);    
}

VideoThread::~VideoThread()
{
    qDebug() << "###video Thread delete###";
    if(this->deviceFlags)
    {
        this->m_camera->stop_capturing();
        this->m_camera->uninit_device();
        this->m_camera->close_device();
        qDebug() << "###close videodevice###";
    }
}


void VideoThread::run()
{
    qDebug() << "###video Thread start###";
    while(!this->stopped)
    {
        if(this->recoFlags)
        {
            this->newrecnize();
            this->recoFlags = false;//防止用上一次拍的图片去识别
        }
    }
}

void VideoThread::newrecnize()
{
    //读取抓取的照片temp/1.bmp
    Mat image=imread("temp/1.bmp", CV_LOAD_IMAGE_GRAYSCALE);
    //返回人员编号
    int predict;
    //相似度
    double dummy;
    //预测
    LearningFace::faceRecingze->predict(image,predict,dummy);
    //打印结果
    qDebug() << "perdict = "  << predict << " dummy="<< dummy;

    //判断返回值

    if(predict == -1)
    {
        //-1 未识别到
        return;
    }
    //查询数据库里是否存有该人
    QSqlDatabase db = QSqlDatabase::database("connection1");
    QSqlQuery query(db);
    query.exec(tr("SELECT * from user where userTempID = '%1'").arg(predict));
    query.first();
    if(query.value(0).isNull())
    {
        //没有这个人
        db.close();
        return;
    }
    //发送识别的人员给调用的线程
    emit this->returnRecongnize(QString::number(predict));
    this->stop();//停止该识别线程
}


//初始化摄像头
void VideoThread::InitVideoDevice()
{
    qDebug() << "video init";
    imgBuf = (unsigned char *)malloc(image_width * image_height/*QWidget::width()*QWidget::height()*/* 3 * sizeof(char));
    frame = new QImage(imgBuf,image_width,image_height,image_Format);   //根据存储空间开辟QImage图像
    m_camera = new CamDevice(tr(cameraDevice));  //获取摄像头设备
    connect(m_camera, SIGNAL(display_error(QString)), this,SLOT(display_error(QString)));
    this->deviceFlags = true;
    //打开摄像头
    camReturn = m_camera->open_device();
    if(-1==camReturn)
    {
        emit this->SendError("未发现设备");
        stopped = true;
        this->deviceFlags = false;
        return;
    }

    //初始化摄像头
    camReturn = m_camera->init_device();
    if(-1==camReturn)
    {
        emit this->SendError("初始化失败");
        stopped = true;
        return;
    }

    //摄像头开始捕获图像
   camReturn = m_camera->start_capturing();
   if(-1==camReturn)
   {
       emit this->SendError("start capture failed");
       stopped = true;
       return;
   }

   if(-1==camReturn)
   {
       emit this->SendError("get frame failed");
       stopped = true;
       return;
   }
   qDebug() << "video init finished";
}

void VideoThread::display_error(QString err)
{
    qDebug() << "error:" << err;
    stopped = true;
    emit this->SendError(err);
    return;
}

//捕捉图像
void VideoThread::update()
{
    //qDebug() << "###update###";
    uchar * pImgBuf;
    unsigned int len;
    //size_t len;
    camReturn = m_camera->get_frame((void **)&pImgBuf,(size_t *)&len);
    //m_camera->get_frame()
    convert_yuv_to_rgb_buffer(pImgBuf,imgBuf,image_width,image_height/*QWidget::width(),QWidget::height()*/);
    frame->loadFromData((uchar *)imgBuf,/*len*/image_width * image_height * 3 * sizeof(char));
    IplImage* src = QImageToIplImage(frame);
    if (!src)
    {
        printf("img error!");
        return;
    }
    double sizeScale = imgSizeScaleSmall;
    CvSize img_cvsize;
    img_cvsize.width = src->width * sizeScale;
    img_cvsize.height = src->height * sizeScale;
    IplImage* dst = cvCreateImage(img_cvsize, src->depth, src->nChannels);
    cvResize(src, dst, CV_INTER_LINEAR);
    detect_and_draw(dst);//检测
    sizeScale = imgSizeScaleBig;
    img_cvsize.width = dst->width * sizeScale;
    img_cvsize.height = dst->height * sizeScale;
    IplImage* img = cvCreateImage(img_cvsize, dst->depth, dst->nChannels);
    cvResize(dst, img, CV_INTER_LINEAR);
    QImage qimage = QImage((uchar *)img->imageData, img->width,img->height, image_Format);
    //IplImage为BGR格式，QImage为RGB格式，所以要交换B和R通道显示才正常
    //可以用OpenCV的cvConcertImage函数交换，也可以用QImage的rgbSwapped函数交换；
    qimage = qimage.rgbSwapped();
    //把实时画面发送给调用线程
    emit this->VideoSourc(qimage);
    camReturn = m_camera->unget_frame();
    cvReleaseImage(&img);   //释放图片内存
    cvReleaseImage(&src);
}

int VideoThread::convert_yuv_to_rgb_buffer(unsigned char *yuv, unsigned char *rgb, unsigned int width, unsigned int height)
{
    unsigned int in, out = 0;
    unsigned int pixel_16;
    unsigned char pixel_24[3];
    unsigned int pixel32;
    int y0, u, y1, v;
    for(in = 0; in < width * height * 2; in += 4) {
     pixel_16 =
      yuv[in + 3] << 24 |
      yuv[in + 2] << 16 |
      yuv[in + 1] <<  8 |
      yuv[in + 0];
     y0 = (pixel_16 & 0x000000ff);
     u  = (pixel_16 & 0x0000ff00) >>  8;
     y1 = (pixel_16 & 0x00ff0000) >> 16;
     v  = (pixel_16 & 0xff000000) >> 24;
     pixel32 = convert_yuv_to_rgb_pixel(y0, u, v);
     pixel_24[0] = (pixel32 & 0x000000ff);
     pixel_24[1] = (pixel32 & 0x0000ff00) >> 8;
     pixel_24[2] = (pixel32 & 0x00ff0000) >> 16;
     rgb[out++] = pixel_24[0];
     rgb[out++] = pixel_24[1];
     rgb[out++] = pixel_24[2];
     pixel32 = convert_yuv_to_rgb_pixel(y1, u, v);
     pixel_24[0] = (pixel32 & 0x000000ff);
     pixel_24[1] = (pixel32 & 0x0000ff00) >> 8;
     pixel_24[2] = (pixel32 & 0x00ff0000) >> 16;
     rgb[out++] = pixel_24[0];
     rgb[out++] = pixel_24[1];
     rgb[out++] = pixel_24[2];
    }
    return 0;
}

int VideoThread::convert_yuv_to_rgb_pixel(int y, int u, int v)
{
    unsigned int pixel32 = 0;
    unsigned char *pixel = (unsigned char *)&pixel32;
    int r, g, b;
    r = y + (1.370705 * (v-128));
    g = y - (0.698001 * (v-128)) - (0.337633 * (u-128));
    b = y + (1.732446 * (u-128));
    if(r > 255) r = 255;
    if(g > 255) g = 255;
    if(b > 255) b = 255;
    if(r < 0) r = 0;
    if(g < 0) g = 0;
    if(b < 0) b = 0;
    pixel[0] = r * 220 / 256;
    pixel[1] = g * 220 / 256;
    pixel[2] = b * 220 / 256;
    return pixel32;
}

IplImage* VideoThread::QImageToIplImage(const QImage *qImage)
{
    int width = qImage->width();
    int height = qImage->height();
    CvSize Size;
    Size.height = height;
    Size.width = width;
    IplImage *IplImageBuffer = cvCreateImage(Size, IPL_DEPTH_8U, 3);    //记着释放内存
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            QRgb rgb = qImage->pixel(x, y);
            cvSet2D(IplImageBuffer, y, x, CV_RGB(qRed(rgb), qGreen(rgb), qBlue(rgb)));
        }
    }
    return IplImageBuffer;
}

//检测
void VideoThread::detect_and_draw(IplImage *img)
{
    //qDebug() << "###draw###";
   static CvScalar colors[] =
{
    {cvScalar(0,0,255)},
    {cvScalar(0,128,255)},
    {cvScalar(0,255,255)},
    {cvScalar(0,255,0)},
    {cvScalar(255,128,0)},
    {cvScalar(255,255,0)},
    {cvScalar(255,0,0)},
    {cvScalar(255,0,255)}
};
    //static CvScalar colors = cvScalar(0,0,355);

    double scale = 2.0;
    IplImage* gray = cvCreateImage( cvSize(img->width,img->height), 8, 1 );
    IplImage* small_img = cvCreateImage( cvSize( cvRound (img->width/scale),
                cvRound (img->height/scale)), 8, 1 );
    int i;

    cvCvtColor( img, gray, CV_BGR2GRAY );// change face to greyscale
    cvResize( gray, small_img, CV_INTER_LINEAR ); // give the gray pic to small_img and dont change the gray
    cvEqualizeHist( small_img, small_img );     //change face to Equalized ,prepare to compare
    cvEqualizeHist( gray, gray );     //change face to Equalized ,prepare to compare

    cvClearMemStorage( storage );

    if( cascade )
    {
        double t = (double)cvGetTickCount();
        CvSeq* faces = cvHaarDetectObjects( small_img, cascade, storage,
                        1.2, 2, 0, cvSize(30, 30) );
        t = (double)cvGetTickCount() - t;
       // printf( "detection time = %gms\n", t/((double)cvGetTickFrequency()*1000.) );

        for( i = 0; i < (faces ? faces->total : 0); i++ )
        {
            CvRect* r = (CvRect*)cvGetSeqElem( faces, i );

                        CvPoint rectP1, rectP2;
                        rectP1.x = cvRound(r->x * scale);
                        rectP1.y = cvRound(r->y * scale);
                        rectP2.x = cvRound((r->x + r->width) * scale);
                        rectP2.y = cvRound((r->y + r->height) * scale);
                        cvRectangle(img, rectP1, rectP2, colors[i], 1, 8, 0);
                        if(this->saveFlags)
                        {
                            cutThePic(img,r,0);
                            cutThePic(gray,r,1);
                        }
        }
        m_FaceCount = faces->total;
}

        cvReleaseImage( &gray );
        cvReleaseImage( &small_img );

}

void VideoThread::cutThePic(IplImage *img, CvRect *r, int mode)
{
    /* cut the face off the pic*/
        cvSetImageROI(img,cvRect(r->x * 2.0,r->y * 2.0,r->width *2.0,r->height*2.0));
        IplImage* dst = cvCreateImage(cvSize(r->width *2.0,r->height*2.0),
                IPL_DEPTH_8U,
                img->nChannels);
        cvCopy(img,dst,0);
        cvResetImageROI(img);
    /* resize the face to fit the standard */
        CvSize dst_size;
        dst_size.height = 112;
        dst_size.width = 92;
        IplImage* final_dst = cvCreateImage(dst_size,IPL_DEPTH_8U,img->nChannels);
        cvResize(dst,final_dst,CV_INTER_LINEAR);

        //显示用
        CvSize dst_size_show;
        dst_size_show.height = 120;
        dst_size_show.width = 120;
        IplImage* final_dst_show = cvCreateImage(dst_size_show,IPL_DEPTH_8U,img->nChannels);
        cvResize(dst,final_dst_show,CV_INTER_LINEAR);
        switch(mode)
        {
        case 0:
            cvSaveImage("temp/originalface.jpg", final_dst_show);
            break;
        case 1:
            cvSaveImage("temp/1.bmp", final_dst);
            this->recoFlags = true;
            break;
        default:
            break;
        }


        cvReleaseImage( &dst );
        cvReleaseImage( &final_dst );
}

void VideoThread::stop()
{
    qDebug() << "###video Thread endding###";
    stopped = true;
}
