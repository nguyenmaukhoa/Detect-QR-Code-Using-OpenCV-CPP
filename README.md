# Detect QR Code using OpenCV and C++

**Quick Response Code** or **QR Code** is invented by the Japanese in 1994, first applied in automotive industry, and used widely nowadays in our daily life due to its fast readibility and versatility. QR Code represents many types of information such as text, URL for a website, phone number...But, how a machine can transale a QR Code into useable information? There are many software, platform and libraries to do this. Today, I'm gonna show you the mechanism of QR Code translation using the most popular Computer Vision open source library **OpenCV**, and the **C++** programming language.

For example, this QR Code represents the url to the webpage `https://en.wikipedia.org/wiki/English_Wikipedia`

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/d0/QR_code_for_mobile_English_Wikipedia.svg/1280px-QR_code_for_mobile_English_Wikipedia.svg.png" width="200">

## Installation

1. Download source code 
```
git clone https://github.com/nguyenmaukhoa/Detect-QR-Code-Using-OpenCV-CPP.git
```

2. Download and Install **Cmake** (A C++ Compiler)
```
https://cmake.org/download/
```

## Usage

Open terminal/command line window at **/build** folder

1. Build C++ file using **Cmake** when you make changes
```
cmake --build . --config Release
```
3. Run application file 
```
./qr_code_detector
```

### Note:

An input video is provided for this project, but if you want to run the code with the webcam, just uncomment the code at line **#46**, and comment line **#43**
in the file `qr_code_detector.cpp`
```
	42. // Create a VideoCapture object, and read and existing video
	43. VideoCapture cap("../video/input.mp4");
  
	45. // Disable the code above, and enable the one below to use webcam
	46. //VideoCapture cap(0);
```

## References

Lear more about how to use OpenCV to handle QR Code at:
```
https://learnopencv.com/opencv-qr-code-scanner-c-and-python/
```
