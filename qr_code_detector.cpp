// Include libraries
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

// Function to read the qr code
void display(Mat frame){
	// Matrix object to catch the bounding box of the QR Code
	Mat bbox, rectifiedImage;

	// Create QR Code Detector object
	QRCodeDetector qrDecoder = QRCodeDetector();

	// Extract string data from the QR Code using method detectAndDecode()
	string qrCodeData = qrDecoder.detectAndDecode(frame, bbox, rectifiedImage);

	// Check if a QR Code has been detected
	if(qrCodeData.length()>0){
		// Extract bounding box starting coordinate
		int p1_x = (int)bbox.at<float>(0,0);
		int p1_y = (int)bbox.at<float>(0,1);

		// Add QR Code Value on each frame
		putText(frame, qrCodeData, Point(p1_x,p1_y), 
				FONT_HERSHEY_SIMPLEX, 1.0, 
				Scalar(0,255,0), 5);
	}

	// Display the frames
	imshow("Frame", frame);
}

int main(){
	// Create a VideoCapture object, and read and existing video
	VideoCapture cap("../video/input.mp4");

	// Disable the code above, and enable the one below to use webcam
	// VideoCapture cap(0);

	// Create video write object to generate output video
 	int frame_width = cap.get(CAP_PROP_FRAME_WIDTH);
  	int frame_height = cap.get(CAP_PROP_FRAME_HEIGHT);
	VideoWriter outmp4("../video/output.mp4", VideoWriter::fourcc('F','M','P','4'), 24, Size(frame_width,frame_height));

	// Check the video is loaded sucessfully
	if(!cap.isOpened()){
		cout << "Error opening the video..." << endl;
		return -1;
	}

	// Matrix to hold each video frame
	Mat frame;

	// Display the video until ESC key is pressed
	while(1){
		// Copy the video frame-by-frame from cap to frame
		cap >> frame;

		// If the frame is empty, stop the dislay
		if(frame.empty())
			break;

		// Display QR Code value on the frame
		display(frame);

		// Write output video with QRCode text 
		outmp4.write(frame);

		// Stop when ESC key is pressed
		char c = (char)waitKey(25);
		if(c == 27)
			break;
	}
	// Release the objects when done
	cap.release();
  	outmp4.release();

	// Close all the windows
	destroyAllWindows();
	return 0;
}