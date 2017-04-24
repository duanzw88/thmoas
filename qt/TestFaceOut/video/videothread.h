#ifndef VIDEOTHREAD_H
#define VIDEOTHREAD_H


#include <QThread>
#include <QImage>
#include <QTimer>
#include <QLabel>
#include <highgui.h>
#include <QSqlQuery>
#include "video/learningface.h"
#include "video/camdevice.h"
#include "iostream"


using namespace std;
using namespace cv;

class VideoThread : public QThread
{
    Q_OBJECT
public:
    explicit VideoThread(QObject *parent = 0);
    ~VideoThread();
    void stop();
    void InitVideoDevice();
    volatile bool saveFlags;//保存图片
    volatile bool recoFlags;//识别标志
    volatile bool deviceFlags;//设备是否开启
    QTimer *timer;
    Ptr<face::FaceRecognizer> face1;


 protected:
    void run();
private:

    //识别
    void recognize();

    void newrecnize(void);

    //QLabel *label_cam;
    volatile bool stopped;
    int image_width;//图片显示宽度
    int image_height;   //图片显示高度
    int camReturn;  //摄像头使用过程返回的结果，用于状态判断
    CamDevice *m_camera;  //摄像头
    uchar *imgBuf;  //QImage图像空间
    QImage *frame;  //QImage图像


    CvMemStorage *storage;
    CvHaarClassifierCascade *cascade;
    QString cascadeFile;
    int m_FaceCount;

    //以下两个函数用于YUV格式转换成RGB格式
    int convert_yuv_to_rgb_pixel(int y, int u, int v);
    int convert_yuv_to_rgb_buffer(unsigned char *yuv, unsigned char *rgb, unsigned int width, unsigned int height);
    IplImage *QImageToIplImage(const QImage * qImage);
    void detect_and_draw(IplImage *img);
    //char* qstring_to_char(QString str);



signals:
    void VideoSourc(QImage);
    void returnRecongnize(QString);
    void SendError(QString);
    void SendTestValue(QString);
    
private slots:
    void update();
    void display_error(QString err);
    void cutThePic(IplImage *img,CvRect* r, int mode);    
};

#endif // VIDEOTHREAD_H
