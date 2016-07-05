#include <opencv2/opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

using namespace cv;

int imgshow()
{
	Mat img = imread("D://1.bmp");
	imshow("IMG", img);
	return cv::waitKey(0);
}

int erode()
{
	Mat img = imread("D://1.bmp");
	imshow("IMG", img);
	
	Mat element = getStructuringElement(MORPH_RECT, Size(10, 10));
	Mat dstImg;
	erode(img, dstImg, element);
	imshow("erode", dstImg);

	return cv::waitKey(0);
}

int blur()
{
	Mat img = imread("D://1.bmp");
	imshow("IMG", img);

	Mat dstImg;
	blur(img, dstImg, Size(10, 10));
	imshow("blur", dstImg);
	return cv::waitKey(0);
}

int canny()
{
	Mat img = imread("D://1.bmp");
	imshow("IMG", img);

	Mat dstImg;
	Mat edge;
	
	cvtColor(img, dstImg, CV_BGR2GRAY);
	imshow("canny", dstImg);
	blur(dstImg, edge, Size(3,3));
	imshow("canny1", edge);
	Canny(edge, edge, 3, 9,3);
	imshow("canny3", edge);
	return cv::waitKey(0);
}

int video()
{
	VideoCapture capture;
	capture.open("D://1.avi");

	Mat frame;
	while(1)
	{
		try{
		capture >> frame;

		imshow("avi", frame);
		}
		catch(...)
		{
			break;
		}
		waitKey(1);
	}

	return 0;
}

int camera()
{
	VideoCapture capture;
	try{
		capture.open(0);
	}
	catch(...)
	{
		return -1;
	}

	while(1)
	{
		Mat frame;
		try
		{
		
			capture >> frame;
			imshow("camera", frame);

		}
		catch(...)
		{
			break;
		}
		
		waitKey(1);

	}
}

int main()
{
	int ret;
	ret = imgshow();

	ret = erode();

	ret = blur();

	ret = canny();

	ret = video();

	ret = camera();

	return ret;
}