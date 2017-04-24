#ifndef LEARNINGFACE_H
#define LEARNINGFACE_H

#include "cv.h"
#include "cvaux.h"
#include "face.hpp"
#include "core/core.hpp"
#include "highgui/highgui.hpp"
#include <QObject>
#include <QThread>

using namespace std;
using namespace cv;

class LearningFace: public QThread
{
    Q_OBJECT
public:
    LearningFace(QObject *parent = 0);
    ~LearningFace();
    void train(void);
    static Ptr<face::FaceRecognizer> faceRecingze;//全局变量
protected:
   void run();
};

#endif // LEARNINGFACE_H
