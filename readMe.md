# 使用说明
* 本程序是VS2015，直接打开.sln文件即可
* 代码主要在三个文件中，main.cpp，undistort.h，undistort.cpp
* 在undistort.h中把相机内参矩阵赋值给fx、fy、cx、cy，畸变系数也需要赋值
* 程序自动读取src文件夹下的所有图片，进行畸变校正后存储到dst文件夹下。