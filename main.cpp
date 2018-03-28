#include <stdio.h>
#include <opencv2/opencv.hpp>
#include<vector>

using namespace cv;
using namespace std;

int main(int argc, char** argv )
{
    std::vector<cv::Point3f> objectPoints={cv::Point3f(1,0,5),cv::Point3f(2,2,5),cv::Point3f(3,0,10),cv::Point3f(4,-2,10),cv::Point3f(5,0,10)};
    Mat M(2,2, CV_8UC3, Scalar(0,0,255));
    cout << "M = " << endl << " " << objectPoints << endl;
    return 0;
}
