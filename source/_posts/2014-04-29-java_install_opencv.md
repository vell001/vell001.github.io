---
layout: post
title: "java安装使用opencv"
date: 2014-4-29 2:01:35 +0800
updated: 2014-4-29 2:01:35 +0800
comments: true
categories: [opencv]
tags: [opencv,java]
---
> 好久以前就想玩玩opencv了，一直没时间玩，今天晚上闲得慌，果断找出之前下过的opencv来了，本来是想在我的Ubuntu上玩的，可是学校网太不给力，只有蹭个同学的翼讯客户端网速才能快点，所以就又回到win7了。 
 
> 在win7的ubuntu虚拟机里面完全配置好了python版的opencv后，发现vmware不给力啊，读取摄像头时直接卡死了，就出现一张图片，出现莫名其妙的`select timeout`；很是怀疑vmware的问题，于是在win7下配置一遍python的opencv，发现简直就是煎熬；由于我之前安装的全是64位的python，32位的模块安装包直接检测不到64为python的注册表，找不见安装位置，没法安装，害我重装了个32位的，小郁闷。

> 既然win7下python这么麻烦，那我熟悉的java会不会简单点啊；果然，java就是简单呀~区区几步就ok了，先来个java的配置，有时间再上Python的（主要是不想在win7下用python，太烦了，没意思）

## 环境
* win7 x64
* opencv-2.4.8[（下载地址）](http://opencv.org/downloads.html)
* myeclipse（或者eclipse都行，方法一样）
* jdk1.7_x64

## 准备opencv
1. 下载windows版的opencv，双击运行，得到一个`opencv`文件夹
2. 打开myeclipse，新建一个普通的java项目
3. 把`opencv/build/java`文件下的`opencv-248.jar`文件拷贝到项目根目录下，右键添加到`Build Path`(我电脑是英文的，中文我还真不知道具体名字，(*^__^*) 嘻嘻……)
4. 最后配置`Native library location`就完工了，配置过程如下：
![](/images/20140429000833.png)  
![](/images/20140429001405.png)  

## 简单测试
测试代码：
``` java
import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;

public class Main {

    public static void main(String[] args) {
        System.out.println("Welcome to OpenCV " + Core.VERSION);
        System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
        Mat m  = Mat.eye(3, 3, CvType.CV_8UC1);
        System.out.println("m = ");
        System.out.println(" " + m.dump());
    }

}

```
测试结果：  
![](/images/20140429002033.png)

> 今天就到这，晚安了