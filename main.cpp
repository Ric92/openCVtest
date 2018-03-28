#include <stdio.h>
#include <opencv2/opencv.hpp>
#include<vector>

using namespace cv;
using namespace std;

int main(int argc, char** argv )
{    
    cout << "Points" << endl;

    vector<cv::Point3f> objectPoints={Point3f(1,3,5),Point3f(2,2,5),Point3f(3,0,10),Point3f(4,-2,10),Point3f(5,0,10)};
    cout << objectPoints << endl << endl;

    cout << "Intrinsic" << endl << endl;

    Mat intrinsic=(cv::Mat1d(3, 3) << 300, 0, 320, 0, 300, 240, 0, 0, 1);
    cout << intrinsic << endl << endl;

    cv::Mat translationVector=(cv::Mat_<double>(1, 3) << 0 ,0 ,0);
    cout << "Translation vector: "<< translationVector << endl << endl;

    cout << "Rotation matrix" << std::endl;
    Mat opencvRotMatrix=(cv::Mat_<double>(3,3) <<
                             1,0,0,
                             0,1,0,
                             0,0,1);
    cout << opencvRotMatrix << endl << endl;
    Mat rotationVector;
    Rodrigues(opencvRotMatrix,rotationVector);
    cout << "Rotation vector associated: " << rotationVector <<endl<<endl;
    std::vector<cv::Point2f> projections;
    projectPoints(objectPoints,rotationVector,translationVector,intrinsic,cv::noArray(),projections,cv::noArray(),0);
    cout << "Projected points" << endl << projections <<endl;
    cv::Mat display = cv::Mat::zeros(480,640,CV_8UC3);
    int j=1;
    for(auto &feature: projections){
                std::cout << feature.x << ", " << feature.y << std::endl;
                cv::circle(display, feature, 3, cv::Scalar(255,0,0),3);
                j++;
            }
    cv::imshow("Camara 1", display);
    cv::waitKey();
    return 0;
}
