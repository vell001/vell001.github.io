---
layout: post
title: "opencv下特征识别VMatcher"
date: 2014/11/16 17:08:28 +0800 
updated: 2014/11/16 19:13:19 +0800 
comments: true
categories: [OpenCV]
tags: [VMatcher,OpenCV]
---
## 前言
之前玩了一下人脸识别，感觉opencv挺好用的。代码比较简单，因为很多都已经封装好了，而且大多数是以C代码的形式封装，也就是说都是一些函数，只要了解功能和参数就行了，就我这菜鸟花了估计不到半个小时就能自己写一个人脸识别了。可惜我涉及的一个项目里面人脸识别是用不到了，主要是建筑物识别。前天晚上自己训练了一个分类器，感觉训练得不好，识别率不咋样，可能是我的图片不够。今天下午试试特征识别，感觉还可以，而且找到了一个开源的封装类[RobustMatcher](https://github.com/openplanets/scape/blob/master/pc-qa-matchbox/DPQAlib/RobustMatcher.cpp),写得很好，用起来也很方便，为了学习也为了达到我的要求，我在这个代码的基础上修改了一些东西，有点不要脸的改了个名字，叫[VMatcher](https://github.com/vell001/VMatcher)

## 环境
* windows7 x64 
* vs2012
* opencv 2.4.8

## 特征识别过程简介
1. 先确定一下用哪个算法做特征识别，有三个类需要实例化，类的详细文档见：[docs.opencv.org](http://docs.opencv.org/modules/features2d/doc/features2d.html) 特征识别的相关算法优缺点介绍：[computer-vision-talks](http://computer-vision-talks.com/articles/2011-01-04-comparison-of-the-opencv-feature-detection-algorithms/)
	1. detector: 检测对象，用于检测特征点；有十种检测方法：
		1. "FAST" – FastFeatureDetector
		2. "STAR" – StarFeatureDetector
		3. "SIFT" – SIFT (nonfree module)
		4. "SURF" – SURF (nonfree module)
		5. "ORB" – ORB
		6. "MSER" – MSER
		7. "GFTT" – GoodFeaturesToTrackDetector
		8. "HARRIS" – GoodFeaturesToTrackDetector with Harris detector enabled
		9. "Dense" – DenseFeatureDetector
		10. "SimpleBlob" – SimpleBlobDetector   
		常用的有SIFT、SURF、ORB，我这都用的是ORB，我用着这个效果比较好
	2. extractor: 提取对象，用于提取特征描述矩阵；具体类有：
		1. SiftDescriptorExtractor
		2. SurfDescriptorExtractor
		3. CalonderDescriptorExtractor
		4. BriefDescriptorExtractor	
		5. OpponentColorDescriptorExtractor
	3. matcher: 匹配对象，用于匹配两个描述矩阵；具体类有：
		1. BruteForceMatcher
		2. FlannBasedMatcher
``` cpp
cv::Ptr<cv::FeatureDetector> detector = new cv::OrbFeatureDetector(numKeyPoints);
cv::Ptr<cv::DescriptorExtractor> extractor = new cv::OrbDescriptorExtractor;
cv::Ptr<cv::DescriptorMatcher> matcher = new  cv::BruteForceMatcher<cv::HammingLUT>;
```

2. 获取图片
``` cpp
cv::Mat img1;
cv::Mat img2;
img1 = cv::imread("./images/1.jpg");
img2 = cv::imread("./images/2.jpg");
```

3. 检测特征点
``` cpp
std::vector<cv::KeyPoint> img1_keypoints;
std::vector<cv::KeyPoint> img2_keypoints;
detector->detect(img1,img1_keypoints);
detector->detect(img2,img2_keypoints);
```

4. 计算特征描述矩阵
``` cpp
cv::Mat descriptors1, descriptors2;
extractor->compute(image1,keypoints1,descriptors1);
extractor->compute(image2,keypoints2,descriptors2);
```

5. 匹配两个特征描述
``` cpp
std::vector<std::vector<cv::DMatch> > matches1;
matcher->knnMatch(descriptors1,descriptors2,matches1,2);
std::vector<std::vector<cv::DMatch> > matches2;
matcher->knnMatch(descriptors2,descriptors1,matches2,2);
```

6. 剔除距离过大的特征点（由ratioTest实现）
``` cpp
int removed= ratioTest(matches1);
	removed= ratioTest(matches2);
```

7. 剔除不匀称的特征点（由symmetryTest实现）
``` cpp
std::vector<cv::DMatch> matches;
symmetryTest(matches1,matches2,matches);
```

8. 如果要求非常精确，可以再加上RANSAC算法去剔除不符合的特征点（由ransacTest实现）
``` cpp
std::vector<cv::DMatch> matches;
cv::Mat fundemental= ransacTest(symMatches, keypoints1, keypoints2, matches);
```

9. 显示匹配点图片（由showImage实现）
``` cpp
vMatcher.showImage(img1, img2, matches, img1_keypoints, img2_keypoints);
```

## VMatcher
根据RobustMatcher修改，封装好了以上所有操作，使用简单，代码见我的[github](https://github.com/vell001/VMatcher)，上我的测试main函数
``` cpp
#include "VMatcher.h"

#define ImageTest // VideoTest or ImageTest

int main()
{
	// set parameters
	int numKeyPoints = 2000;

	//Instantiate robust matcher
	VMatcher vMatcher;

	//instantiate detector, extractor, matcher
	cv::Ptr<cv::FeatureDetector> detector = new cv::OrbFeatureDetector(numKeyPoints);
	cv::Ptr<cv::DescriptorExtractor> extractor = new cv::OrbDescriptorExtractor;
	cv::Ptr<cv::DescriptorMatcher> matcher = new cv::BruteForceMatcher<cv::HammingLUT>;

	vMatcher.setFeatureDetector(detector);
	vMatcher.setDescriptorExtractor(extractor);
	vMatcher.setDescriptorMatcher(matcher);

#ifdef ImageTest
	//Load input image detect keypoints
	cv::Mat img1;
	std::vector<cv::KeyPoint> img1_keypoints;
	cv::Mat img1_descriptors;
	cv::Mat img2;
	std::vector<cv::KeyPoint> img2_keypoints;
	cv::Mat img2_descriptors;

	std::vector<cv::DMatch>  matches;

	img1 = cv::imread("./images/1.jpg");
	img2 = cv::imread("./images/2.jpg");
	
	vMatcher.match(img1, img2, matches, img1_keypoints, img2_keypoints);
	std::cout << "matched number :" << matches.size() << std::endl;
	vMatcher.showImage(img1, img2, matches, img1_keypoints, img2_keypoints);
	cvWaitKey(0);
	system("pause");
#endif // ImageTest

#ifdef VideoTest
	cv::Mat img1;
	std::vector<cv::KeyPoint> img1_keypoints;
	cv::Mat img1_descriptors;
	img1 = cv::imread("./images/1.jpg");
	cv::VideoCapture Camera(0);
	if (!Camera.isOpened())
		return -1;
	while (cv::waitKey(33) != 27) {
		cv::Mat img2;
		std::vector<cv::KeyPoint> img2_keypoints;
		cv::Mat img2_descriptors;

		std::vector<cv::DMatch>  matches;
		
		if (!Camera.read(img2))
			break;
		//cv::imshow("video", img2);

		vMatcher.match(img1, img2, matches, img1_keypoints, img2_keypoints);
		std::cout << "matched number :" << matches.size() << std::endl;
		vMatcher.showImage(img1, img2, matches, img1_keypoints, img2_keypoints);

		system("cls");
	}
	Camera.release();
#endif // VideoTest

}
```

## 识别效果展
> 来个我的女神赫本的识别  

### 图片对图片的识别
![](/images/opencv/20141116193043.png)

### 图片对视频的识别
![](/images/opencv/20141116193820.png)