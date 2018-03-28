#include <stdio.h>
#include <opencv2/opencv.hpp>
#include<vector>
#include<camera.h>
#include<memory>

using namespace cv;
using namespace std;

vector<std::shared_ptr<camera>> Cluster;

int main(int argc, char** argv )
{    
    auto createCamera=[&](Mat translationVector,Mat opencvRotMatrix,Mat intrinsic){
        std::shared_ptr<camera> newCamera=std::shared_ptr<camera>(new camera(translationVector,opencvRotMatrix,intrinsic));
        Cluster.push_back(newCamera);
    };

    vector<cv::Point3f> objectPoints={Point3f(1,3,5),Point3f(2,2,5),Point3f(3,0,10),Point3f(4,-2,10),Point3f(5,0,10)};
    cout << objectPoints << endl << endl;

    Mat intrinsic=(cv::Mat1d(3, 3) << 300, 0, 320, 0, 300, 240, 0, 0, 1);
    cout << intrinsic << endl << endl;
    cv::Mat translationVector=(cv::Mat_<double>(1, 3) << 0 ,0 ,0);
    Mat opencvRotMatrix=(cv::Mat_<double>(3,3) <<
                             1,0,0,
                             0,1,0,
                             0,0,1);
    vector<cv::Point2f> projections;



    createCamera(translationVector,opencvRotMatrix,intrinsic);
    createCamera((cv::Mat_<double>(1, 3) << 2 ,0 ,0),opencvRotMatrix,intrinsic);
    createCamera((cv::Mat_<double>(1, 3) << 4 ,0 ,0),opencvRotMatrix,intrinsic);
    cv::Mat display = cv::Mat::zeros(480,640,CV_8UC3);
    int j=1;
    for(auto &actualCam: Cluster){
        projections=actualCam->project(objectPoints);
        cout << "Camera: " << j << endl;
        for(auto &feature: projections){
            if(640<abs(feature.x) || 480<abs(feature.y)) cout << "Warning: Point out of range" << endl;
            cout << feature.x << ", " << feature.y << endl;
            cv::circle(display, feature, 3, cv::Scalar(255,0,0),3);
        }
        cv::imshow(to_string(j), display);
        j++;

    }
    cv::waitKey();

    return 0;
}
