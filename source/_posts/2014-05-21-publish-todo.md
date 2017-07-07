---
layout: post
title: "完全DIY的新软件：ToDo"
date: 2014-5-21 0:02:41 +0800
updated: 2014-5-21 0:02:41 +0800
comments: true
categories: [java]
tags: [java,ToDo]
---
## ToDo简介
> ToDo是一个开源跨平台的时间管理软件，有两大功能：  
> 1. 备忘录功能，定时提醒  
> 2. 定时锁屏功能，默认每隔2小时自动将电脑锁屏（不是休眠），你无法操作电脑做任何工作，休息五分钟后自动解锁，强迫玩电脑时间长的你休息一下啦！  

## 为啥会有ToDo
> 1. 因为我自己玩电脑时间比较长，常常玩起电脑来忘了时间，所以需要一个备忘录软件  
> 2. 玩时间长对眼睛不好，所以需要一个定时让我休息的软件  
> 3. 由于我经常在linux和windows平台之间切换工作，所以需要一个完全跨平台的时间管理软件，这样更统一  
> 4. 我相信会有很多像我这样需要ToDo这款软件的人  

## 庐山真面目

###centos下的效果：
![](/images/todo/20140520232222.png)  
![](/images/todo/20140520232318.png)  
![](/images/todo/20140520232341.png)  
![](/images/todo/20140520233418.png)  

###windows下的效果：
![](/images/todo/20140520232411.png)  
![](/images/todo/20140520232422.png)  
![](/images/todo/20140520232432.png)  
![](/images/todo/20140520233313.png)  
![](/images/todo/20140520235759.png)  

## v002.1更新内容
1. 更完整的中英支持   
![](/images/todo/20140530130326.png)  
![](/images/todo/20140530130435.png)  
![](/images/todo/20140530130458.png)  
2. 添加锁屏倒计时的推迟按钮，能推迟锁屏  
![](/images/todo/20140530134845.png)  

## 软件下载使用

### 下载地址
> [当前最新版v002.1](https://github.com/vell001/ToDo/tree/master/release)  
> [源代码地址](https://github.com/vell001/ToDo)

### 使用方法
**运行前提**：系统必须正确安装有JRE/JDK环境，没有的自行百度啦~  

在`release`文件夹下有这些文件：run.bat、run.sh、todo_x32.exe、todo_x64.exe、ToDo002.jar  

1. Windows: 
	1. 选择对应系统的`.exe`文件运行，推荐建立快捷方式到桌面上
	2. 点击run.bat运行
2. Linux / MacOS
	1. 终端执行`chmod a+x run.sh`，后`./run.sh&`
	2. 直接`bash run.sh&`
	3. 甚至直接`java -jar ToDo002.jar`


