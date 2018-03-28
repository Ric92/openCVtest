#ifndef CAMERA_H
#define CAMERA_H
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include<vector>

class camera{
public:
    camera(cv::Mat TranslationVector,cv::Mat RotationMatrix,cv::Mat Intrinsic);
    std::vector<cv::Point2f> project(std::vector<cv::Point3f> Points){
        projectPoints(Points,rotationVector,translationVector,intrinsic,cv::noArray(),projections,cv::noArray(),0);
        return projections;
    }
    std::vector<cv::Point2f> Projections(){return projections;}
private:
    cv::Mat intrinsic;
    cv::Mat translationVector;
    cv::Mat rotationMatrix;
    cv::Mat rotationVector;
    std::vector<cv::Point2f> projections;
};

camera::camera(cv::Mat TranslationVector,cv::Mat RotationMatrix,cv::Mat Intrinsic){
    translationVector=TranslationVector;
    rotationMatrix=RotationMatrix;
    cv::Rodrigues(rotationMatrix,rotationVector);
    intrinsic=Intrinsic;
}


#endif // CAMERA_H
