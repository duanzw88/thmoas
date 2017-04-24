#include "learningface.h"
#include <QStringList>
#include <QDebug>

//提取算法
Ptr<face::FaceRecognizer> LearningFace::faceRecingze = face::createEigenFaceRecognizer(0,3.5e+3);
//Ptr<face::FaceRecognizer> LearningFace::faceRecingze = face::createLBPHFaceRecognizer(1,8,8,8,7.5e+1);
//Ptr<face::FaceRecognizer> LearningFace::faceRecingze = face::createFisherFaceRecognizer();

LearningFace::LearningFace(QObject *parent):
    QThread(parent)
{
    connect(this,SIGNAL(finished()),this,SLOT(deleteLater()));
}

LearningFace::~LearningFace()
{
    qDebug() << "train thread finish";
}
void LearningFace::run()
{
    this->train();
}

//加载train.txt
void LearningFace::train()
{
    vector<Mat> images;
    vector<int> labels;

    FILE * imgListFile = 0;
    char imgFilename[512];
    int iFace, nFaces=0;
    int number = 0;
    char pic[512];

    if( !(imgListFile = fopen("train.txt", "r")) )
    {
        fprintf(stderr, "Can\'t open file %s\n", "train.txt");
        return;
    }

    // 统计人脸数
    while( fgets(imgFilename, 512, imgListFile) ) ++nFaces;
    rewind(imgListFile);
    //qDebug() << "###train7";
    qDebug() << "train persion count" << nFaces;
    for(iFace=0; iFace<nFaces; iFace++)
    {
        //qDebug() << "fscanf";
        // 从文件中读取序号和人脸名称
        fscanf(imgListFile,"%d %s",&number,pic);
        //qDebug() << "read" << number << pic;
        images.push_back(imread(pic, CV_LOAD_IMAGE_GRAYSCALE));
        labels.push_back(number);
    }
    //qDebug() << "###train10";
     fclose(imgListFile);
     //qDebug() << "###train9";
    LearningFace::faceRecingze->train(images,labels);
    LearningFace::faceRecingze->save("new.xml");
    qDebug() << "###newtrain finish";
}
