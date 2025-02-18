//*** Visual studio include guard ***//
//#pragma once

//*** Traditional include guard ***//
#ifndef HEADER_H
#define HEADER_H


// Our libraries
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

// Name space
using std::string;
using std::vector;
using std::endl;
using std::cout;

using cv::CascadeClassifier;
using cv::VideoCapture;
using cv::Point2f;
using cv::Scalar;
using cv::Vec4i;
using cv::Point;
using cv::Size;
using cv::Rect;
using cv::Mat;
using cv::FONT_HERSHEY_DUPLEX;
using cv::FONT_HERSHEY_PLAIN;
using cv::CHAIN_APPROX_SIMPLE;
using cv::WINDOW_AUTOSIZE;
using cv::COLOR_BGR2GRAY;
using cv::COLOR_BGR2HSV;
using cv::RETR_EXTERNAL;
using cv::WINDOW_NORMAL;
using cv::CAP_PROP_FPS;
using cv::MORPH_RECT;
using cv::FILLED;
using cv::getPerspectiveTransform;
using cv::getStructuringElement;
using cv::warpPerspective;
using cv::createTrackbar;
using cv::boundingRect;
using cv::GaussianBlur;
using cv::drawContours;
using cv::findContours;
using cv::approxPolyDP;
using cv::contourArea;
using cv::namedWindow;
using cv::arcLength;
using cv::rectangle;
using cv::cvtColor;
using cv::putText;
using cv::waitKey;
using cv::inRange;
using cv::imread;
using cv::imshow;
using cv::dilate;
using cv::resize;
using cv::circle;
using cv::erode;
using cv::Canny;
using cv::read;
using cv::line;

// Function prototyping
void getContours(Mat imgDil, Mat img);

#endif // End of ifndef
