#ifndef _UNDISTORT_H
#define _UNDISTORT_H

#include<opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <io.h>

using namespace cv;
using namespace std;

class UndistortImages {
private:
	cv::Mat matrix;
	cv::Mat coeff;
	cv::Mat new_matrix;//matrix after undistort
	double fx = 1840.8, fy = 1843.9, cx = 982.4004, cy = 576.7908;
	double radialDistortion[2] = { 0.0663 ,-0.2152 };
	double tangentialDistortion[2] = { 0,0 };
	string srcPath = "D:\\VSproject\\fisheyeTransform\\fisheyeTransform\\src";
	string dstPath = "D:\\VSproject\\fisheyeTransform\\fisheyeTransform\\dst";
	void getFiles(string path,vector<string>& files, vector<string>& imgsName);

public:
	void setParamters();
	void readFileImg();
};

#endif