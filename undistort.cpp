
#include "undistort.h"

void UndistortImages::setParamters()
{
	matrix = Mat(3, 3, CV_64F);
	matrix.at<double>(0, 0) = fx;
	matrix.at<double>(0, 1) = 0;
	matrix.at<double>(0, 2) = cx;
	matrix.at<double>(1, 0) = 0;
	matrix.at<double>(1, 1) = fy;
	matrix.at<double>(1, 2) = cy;
	matrix.at<double>(2, 0) = 0;
	matrix.at<double>(2, 1) = 0;
	matrix.at<double>(2, 2) = 1;

	coeff = Mat(1, 4, CV_64F);
	coeff.at<double>(0, 0) = radialDistortion[0];
	coeff.at<double>(0, 1) = radialDistortion[1];
	coeff.at<double>(0, 2) = tangentialDistortion[0];
	coeff.at<double>(0, 3) = tangentialDistortion[1];
}

void UndistortImages::readFileImg() 
{
	vector<string> imgs;
	vector<string> imgsName;
	getFiles(srcPath, imgs,imgsName);
	cv::Mat srcMat,dstMat;
	for (int i = 0;i < imgs.size();i++ ) {
		srcMat = imread(imgs[i]);
		undistort(srcMat,dstMat,matrix,coeff,new_matrix);
		imwrite(dstPath + "\\" + imgsName[i], dstMat);
	}
}

void UndistortImages::getFiles(string path,vector<string>& files, vector<string>& imgsName)
{
	//文件句柄  
	long   hFile = 0;
	//文件信息  
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if (fileinfo.size > 0) {
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
				imgsName.push_back(fileinfo.name);
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}
