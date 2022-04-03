#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
int main()
{
	// 读入一张图片
	Mat img = imread("C://Users//hp//Downloads//s.jpg");
	// 创建一个名为 “猫咪”的窗口
	namedWindow("CAT");
	// 在窗口中显示猫¨
	imshow("CAT", img);
	// 等待n ms后窗口自动关闭
	waitKey(2000);
	//n替换为阿拉伯数字
	return 0;
}


//#include <iostream>
//#include <opencv2/opencv.hpp>
//using namespace cv;
//int main() {
//    //    读取图像
//    Mat img = imread("C://Users//hp//Pictures//Camera Roll//QQ图片20210509232457.jpg");
//    Mat gray, edges;
//    //    转为灰度图
//    cvtColor(img, gray, COLOR_BGR2GRAY);
//    //    均值滤波
//    blur(gray, gray, Size(3, 3));
//    //    边缘检测
//    Canny(gray, edges, 100, 220, 3);
//
//
//   imwrite("edge.jpg", edges);
//    return 0;
//}