---
layout: post
title: "VS2012下配置OpenCV"
date: 2014/11/3 23:30:22 +0800 
updated: 2014/11/3 23:30:26 +0800 
comments: true
categories: [OpenCV]
tags: [VS2012,OpenCV]
---
## 前言
好久没更新我的博客了，因为我最近正在完成我自己的一个做车的梦想，做一辆卡丁车~这个项目花了我大部分时间，做完后会写一篇长博客来详述的。同时还在做一个和图像处理相关的一个小项目，所以第一想到的就是*opencv*了，由于非常不习惯VS的编辑器（我基本不用VS，除非迫不得已，所以我的VS版本还是两年前下的2012版），要是做界面开发都会用QT，对QT了解比VS多，O(∩_∩)O哈哈~这次先入门一下opencv，从最基本的VS配置开始吧！QT需要自己编译下opencv，有点麻烦，有时间再做QT的配置吧

## 环境
* 系统: win7 x64 英文版
* 开发环境: VisualStudio 2012 X64 （其他版本的VS操作差不多）

## 准备
> 我之前下过2.4.8版的opencv，官网已经出到opencv3了，我就不下了，opencv2就够用了，文档还比较齐全，等熟了opencv2后在升级吧  
> 不同版本的配置都是**相通**的，基本一样

 opencv: [http://opencv.org/downloads.html](http://opencv.org/downloads.html)
下载OpenCV for Windows版，这个是个exe文件，双击运行其实就是解压而已，随便选择一个文件夹，这边我选的是: ``D:\TDDOWNLOAD\opencv``

## 配置环境
1. 添加到path环境变量（可以添加到系统变量或用户变量，我这添加到用户变量）
	> 推荐添加环境变量，这样就不会出现exe运行时**dll找不见**的问题了！
    1. 新建一个*OPENCV248*的变量，值为：``D:\TDDOWNLOAD\opencv\build\x86\vc12\bin``
    > 具体的目录看你自己的情况而定，比如你是准备开发64位的软件就选x64文件夹，至于vc12还是vc11，我是vs2012本要选vc11的，结果vc12也没出错（莫非向下兼容？no idea！），vs2012是vc11，vs2010则是vc10，更高的选vc12吧！
    2. 在Path变量后添加``%OPENCV248%;``
    3. 如图：![](/images/opencv/20141103231302.png)

2. 新建项目，配置项目属性
    1. 添加包含目录  
	    ``D:\TDDOWNLOAD\opencv\build\include;``
    2. 添加库目录  
	    ``D:\TDDOWNLOAD\opencv\build\x86\vc12\lib;``
	    > 这个目录还是和*OPENCV248*环境变量一样，根据你自己的情况而定  
    	> ![](/images/opencv/20141103233338.png)

	3. 添加链接器的附加依赖项
```
opencv_calib3d248d.lib
opencv_contrib248d.lib
opencv_core248d.lib
opencv_features2d248d.lib
opencv_flann248d.lib
opencv_gpu248d.lib
opencv_highgui248d.lib
opencv_imgproc248d.lib
opencv_legacy248d.lib
opencv_ml248d.lib
opencv_nonfree248d.lib
opencv_objdetect248d.lib
opencv_ocl248d.lib
opencv_photo248d.lib
opencv_stitching248d.lib
opencv_superres248d.lib
opencv_ts248d.lib
opencv_video248d.lib
opencv_videostab248d.lib
```
		> 其中后边`248d`代表我的opencv是2.4.8版本，对应的调试方案是`debug`，如果是`248`则表示调试方案是`release`  
		> 其他项加入的库可以在`D:\TDDOWNLOAD\opencv\build\x86\vc12\lib`这个目录下找见
		> ![](/images/opencv/20141103234056.png)
		> ![](/images/opencv/20141103235021.png)

## 测试
``` cpp
#include <opencv2/opencv.hpp>   
#include <iostream> 
using namespace cv; 
void main() {      
    IplImage *src;     
    src = cvLoadImage("D:\\Picture\\logo.png");     
    cvNamedWindow("vell001",CV_WINDOW_AUTOSIZE);    
    cvShowImage("vell001",src);    
    cvWaitKey(0);
    cvDestroyWindow("vell001");  
    cvReleaseImage(&src); 
}
```

结果：
![](/images/opencv/20141103235710.png)

## 后语
非常简单的环境配置是学习opencv的开始，下一步挑战人脸识别~