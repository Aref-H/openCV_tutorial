/*Chapter one : Read images , videos and webcam.
* Note : Uncomment each example to see it's performance*/


// ****** Image ******

#include "Header.h"

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);  // Matrix data type equal to func read from path
	imshow("Image", img);  // Func that will show the image that  is in our Mat
	waitKey(0);  // Maiking infinate delay
}



// ****** Video ******
/*
#include "Header.h"

string path = "Resources/test_video.mp4";
VideoCapture cap(path);  // VideoCapure obj 
Mat img;  // Matrix data type

void main() {
	while (true) {  // While loop to iterate through all images "Video" 
		cap.read(img);  // From cap obj 
		imshow("Image", img);  // Func that will show the image that is in our Mat
		waitKey(1);  // Maiking delay 
	}
}
*/


// ****** Webcam ******
/*
#include "Header.h"

VideoCapture cap(0);  // My webcam id
Mat img;  // Matrix data type

void main() {  // While loop to iterate through all images "Video" 
	while (true) {
		cap.read(img);  // From cap obj
		imshow("Webcam", img);  // Func that will show the image that is  in our Mat
		waitKey(1);  // Making delay
	}
}
*/





/*Chapter two : Basic functions.*/


// ****** Image process ******
/*
#include "Header.h"

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgBlur2, imgCanny, imgDila, imgErode;

	cvtColor(img, imgGray, COLOR_BGR2GRAY);  // Seting color
	GaussianBlur(img, imgBlur, Size(3, 3), 3, 0);  // Blur
	GaussianBlur(imgGray, imgBlur2, Size(3, 3), 3, 0);  // Blur
	Canny(imgBlur, imgCanny, 30, 80);  // Edge detector

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));  // Kernel for using in dilate func
	dilate(imgCanny, imgDila, kernel);  // Dilation
	erode(imgDila, imgErode, kernel);

	// Func that will show the image that is  in our Mat
	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Blur2", imgBlur2);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDila);
	imshow("image Erode", imgErode); 

	waitKey(0);
}
*/





/*Chapter three : Resize and crope image.*/


// ****** Resize ******
/*
#include "Header.h"

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgResize, imgScale;

	//cout << img.size() << endl;  // Output size of our imag
	resize(img, imgResize, Size(640, 480));  // Image resizing function with specefic size
	resize(img, imgScale, Size(), 0.5, 0.5);  // Image scaling

	imshow("Image", img);
	imshow("Image Resize", imgResize);
	imshow("Image Scale", imgScale);

	waitKey(0);
}
*/


// ****** Crop ******
/*
#include "Header.h"

void main() {
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgCrop;

	Rect crp(300, 200, 300, 250);  // Rectangle data type for croping
	imgCrop = img(crp);  // Puting crp into the our img matrix data type

	imshow("Image", img);
	imshow("Image Crop", imgCrop);

	waitKey(0);
}
*/





/*Chapter four : Drawing shapes and text.*/


// ****** Drawing and texting ******
/*
#include "Header.h"

void main() {

	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));  // Blank image

	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);  // Making circle
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);  // Making rectangle
	rectangle(img, Rect(125, 221, 263, 71), Scalar(255, 255, 255), 3);  // Making another rectangle using Rect
	line(img, Point(125, 298), Point(388, 298), Scalar(255, 255, 255), 3);  // Making a single line
	putText(img, "Hello world", Point(137, 270), FONT_HERSHEY_DUPLEX, 1.34, Scalar(0, 69, 255), 2);  // Adding text
	
	imshow("Blank image", img);

	waitKey(0);
}
*/





/*Chapter five : Warp perspective.*/


// ****** Warp images ******
/*
#include "Header.h"

float wK = 250, hK = 350;  // King
float wQ = 300, hQ = 370;  // Quine
float wJ = 260, hJ = 360;  // Jack
float w9 = 310, h9 = 360;  // Nine

void main() {

	string path = "Resources/cards.jpg";
	Mat img = imread(path);
	
	Mat matrixK, imgWarpK;  // King
	Mat matrixQ, imgWarpQ;  // Quine
	Mat matrixJ, imgWarpJ;  // Jack
	Mat matrix9, imgWarp9;  // Nine

	// King
	Point2f srcK[4] = { {529,142},{771,190},{405,395},{674,457} };
	Point2f dstK[4] = { {0.0f,0.0f},{wK,0.0f},{0.0f,hK},{wK,hK} };
	matrixK = getPerspectiveTransform(srcK, dstK);
	warpPerspective(img, imgWarpK, matrixK, Point(wK, hK));
	// Cheking the selected points using circle
	for (int i = 0; i < 4; i++) {
		circle(img, srcK[i], 10, Scalar(0, 0, 255), FILLED);
	}

	// Quine  
	Point2f srcQ[4] = { {64,324},{340,280},{90,633},{403,572} };
	Point2f dstQ[4] = { {0.0f,0.0f},{wQ,0.0f},{0.0f,hQ},{wQ,hQ} };
	matrixQ = getPerspectiveTransform(srcQ, dstQ);
	warpPerspective(img, imgWarpQ, matrixQ, Point(wQ, hQ));

	// Jack  
	Point2f srcJ[4] = { {778,106},{1018,83},{843,358},{1116,329} };
	Point2f dstJ[4] = { {0.0f,0.0f},{wJ,0.0f},{0.0f,hJ},{wJ,hJ} };
	matrixJ = getPerspectiveTransform(srcJ, dstJ);
	warpPerspective(img, imgWarpJ, matrixJ, Point(wJ, hJ));

	// Nine  
	Point2f src9[4] = { {744,385},{1021,436},{647,708},{968,780} };
	Point2f dst9[4] = { {0.0f,0.0f},{w9,0.0f},{0.0f,h9},{w9,h9} };
	matrix9 = getPerspectiveTransform(src9, dst9);
	warpPerspective(img, imgWarp9, matrix9, Point(w9, h9));

	imshow("Image", img);  // Image
	imshow("Image Warp King", imgWarpK);  // King
	imshow("Image Warp Quine", imgWarpQ);  // Quine
	imshow("Image Warp Jack", imgWarpJ);  // Jack
	imshow("Image Warp Nine", imgWarp9);  // Nine

	waitKey(0);
}
*/





/*Chapter six : Color detection*/


// ****** Detecting shapes by color ******
/*
#include "Header.h"

void main() {

	string path = "Resources/lambo.png";
	//string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgHSV, mask;

	int hmin = 0, smin = 0, vmin = 0;       // To find this values we use trackbar.We must
	int hmax = 179, smax = 255, vmax = 255; // keep our shape white and other things black

	cvtColor(img, imgHSV, COLOR_BGR2HSV);  // Getting image in HSV color

	namedWindow("Trackbars", WINDOW_NORMAL);  // Opening a new window
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true) {

		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);

		imshow("Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Image mask", mask);

		waitKey(1);
	}
}
*/





/*Chapter seven : Shapes detection*/


// ****** Detect shapes ******
/*
#include "Header.h"

void main() {

	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	// Preprocessing
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);	
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil, img);

	imshow("Image", img);
	//imshow("Image Gray", imgGray);
	//imshow("Image Blur", imgBlur);
	//imshow("Image Canny", imgCanny);
	//imshow("Image Dilate", imgDil);

	waitKey(0);
}

void getContours(Mat imgDil, Mat img) {

	vector<vector<Point>> contours;
	vector<Vec4i> heirarchy;
	findContours(imgDil, contours, heirarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	string objectType;
	
	// Noise filtering ,finding shapes and bounding Rectangle 
	for (int i = 0; i < contours.size(); i++) {

		int area = contourArea(contours[i]);
		cout << area << endl;

		if (area > 1000) {

			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);

			//drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
		}
	}
	
	// Adding shapes name
	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);
		cout << area << endl;

		if (area > 1000) {

			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);

			int objCor = (int)conPoly[i].size();

			if (objCor == 3) { objectType = "Tri"; }
			if (objCor == 4) {
				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				cout << aspRatio << endl;
				if (aspRatio > 0.95 && aspRatio < 1.05) { objectType = "Square"; }
				else { objectType = "Rect"; }
			}
			if (objCor > 4) { objectType = "Circle"; }

			putText(img, objectType, { boundRect[i].x, boundRect[i].y - 5 },
				FONT_HERSHEY_PLAIN, 1.4, Scalar(0, 69, 255), 2);
		}
	}
}
*/





/*Chapter eight : Face detection*/


// ****** Detect human face ******
/*
#include "Header.h"

void main() {

	string path = "Resources/test.png";
	Mat img = imread(path);

	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	if (faceCascade.empty()) { cout << "Can't load .xml file!"; }

	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);

	for (int i = 0; i < faces.size(); i++) {
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
	}

	imshow("Image", img);

	waitKey(0);
}
*/