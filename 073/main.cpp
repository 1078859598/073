#include <iostream>
#include <opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat dstMat;
	cv::Mat	srcMat = cv::imread("C:/Users/HS/Desktop/18.jpg", 1);
	cv::Mat CannyMat;
	Canny(srcMat, CannyMat, 150, 200);


	std::vector<cv::Vec4i>	lines;
	cv::HoughLinesP(CannyMat, lines, 1, CV_PI / 180, 30, 5, 10);
	std::vector<cv::Vec4i>::iterator it = lines.begin();


	for (; it != lines.end(); ++it)
	{
		cv::Point pt1, pt2;
		pt1.x = (*it)[0];
		pt1.y = (*it)[1];
		pt2.x = (*it)[2];
		pt2.y = (*it)[3];
		cv::line(srcMat, pt1, pt2, cv::Scalar(255, 0, 0), 1, CV_AA);
	}


	imshow("srcMat", srcMat);
	imshow("CanntMat", CannyMat);
	waitKey(0);

}
