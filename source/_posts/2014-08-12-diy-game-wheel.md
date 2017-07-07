---
layout: post
title: "diy游戏方向盘"
date: 2014-8-12 15:33:18 +0800 
updated: 2014-8-12 15:33:18 +0800 
comments: true
categories: [VSim]
tags: [diy,VSim]
---
## 前言
> 实习完后一直在学校呆着，真是呆着~啥事没干。实习过去了轻松了许多，昨天开始手痒了，好久没玩车了。立马想起来很久的想法了，就是做个游戏方向盘啦

## 准备阶段
> 准备使用我手上现有的arduino uno r3（就是上次[模拟赛车座椅](/2014/03/09/vsim.html)的那个控制板!）来做，之前就知道r3可以转到dfu模式直接实现usb hid就行了，可是我的r3板子和官网的居然不是一样的，我发现，我的板子芯片是atmega328p的，可恶啊，官网是atmega16u2的。我问淘宝商家我的板子能不能进dfu，人家反问我神马是dfu~  
> 后来google了半天，有人说atmega328p根本没有usb的支持，好吧，昨天一下午就是折腾这个。我也不管有没有支持了，当然，如果是直接使用usb hid的话会简单得多，而且网上资料也多。  
> 我晚上直接放弃了又usb支持的想法了，开始找纯粹的软件驱动方法了。我上github和SourceForge搜了下开源软件，最终在Sourceforge上找到了一个比较热门的摇杆模拟器软件叫**VJOY**([软件地址](http://vjoystick.sourceforge.net/site/))，查了相关资料发现，这是一个比较古老的项目，貌似底层的开发是没有开源的，不过提供了很好的接口。而且最近有人更新了beta版，下载量也不错，就决定用它了  
> 整体架构流程：通过arduino获取电位器的值，通过串口传输到pc端的feeder里，做一些处理后feeder再进行对vjoy虚拟控制器的设置，vjoy虚拟控制器控制游戏。  
> 示意图： ![](/images/game_wheel/system_arch.png)
> my feeder: 这个就是我的主要代码部分，通过它得到arduino传过来的数据，处理后发送个vjoy的虚拟控制器，达到一个控制效果

## 实施
> 因为就做最简单的控制方向，就没有高神马协议了，做复杂了再说吧  

### arduino编程
这是一小部分程序，直接使用ardublock插件了：  
![](/images/game_wheel/ardublock.png)  

### vjoy安装配置
安装配置教程很多，直接上官网吧，不会的goole下咯：[http://vjoystick.sourceforge.net/site/](http://vjoystick.sourceforge.net/site/)

### my feeder的编写
在vjoy的sdk里面有很详细的说明文档，也非常简单。vjoy支持C#和C++，我这选择C++，开发环境是win7X64 VS2012，官网使用的是VS2008，只要不低于VS2008就行了。  
这个feeder要做两件事：  
1. 读取串口值  
2. 设置vjoy虚拟控制器

设置vjoy只要按照说明文档来，应该没问题，可是串口编程我之前从来没做过啊，小挑战，今早就是折腾串口编程了。  
微软提供的串口编程接口实在太难用了，就一直在找第三方大神的，后来找到了CnComm这个类，国产的哦！非常好用。作者的博客：[http://blog.csdn.net/wujian53/article/details/4090554](http://blog.csdn.net/wujian53/article/details/4090554)

这个代码就不上了，等我做完善了，再一块开源吧~

## 成果展
演示视频： 
<embed src="http://www.tudou.com/v/htw40lFy-vk/&resourceId=99962045_05_02_99&tid=0/v.swf" type="application/x-shockwave-flash" allowscriptaccess="always" allowfullscreen="true" wmode="opaque" width="480" height="400"></embed>

-----------------
结束语
> 一直想自制一个游戏方向盘，从昨天开始查资料，到今天上午，完成了这么一个demo，功能有了，就差个外壳了，呵呵，当然还有力反馈没有做，暂时没钱，等有钱了再说吧