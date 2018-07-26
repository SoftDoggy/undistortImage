#include "undistort.h"
#include <iostream>
#include <cstdlib>

#include<opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

int main()
{
	UndistortImages undistortImages;
	undistortImages.setParamters();
	undistortImages.readFileImg();
	system("pause");
	return 0;
}