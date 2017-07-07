---
layout: post
title: "ubuntu_wifi&pppoe"
date: 2014-03-24 10:13:05 +0800
comments: true
categories: ubuntu
---

学校现在上网全部要拨号，加上我在宿舍用的是无线路由，也就是要在ubuntu下实现连接wifi后再拨号，这个功能在默认的ubuntu网络设置里面是没有的，里面有dsl但是对有线网络使用的，有点小郁闷。不过总是有解决方法的，我这就介绍我的一种实现方法：*dsl-provider* 

1. ubuntu12.04默认就安装了dsl-provider，直接上命令行设置dsl-provider:
```
sudo pppoeconf
```  
![pppoeconf](/images/20140324125533.png)
一直按照提示进行，注意倒数第二个提示，提示你要不要开机自动拨号，这个选**no**，不要自动拨号，因为经测试多次，都会卡在开机界面60S*waiting up to 60 more seconds for network configuration*,当然也有好的解决方法，但还是麻烦了一点，开机后自己拨号不是更好？～
<!-- more -->
2. 这样基本就能上网了，可是如果你急着重启了的话就会有问题了，重启后会发现网络图标莫名其妙不见了！！！
原因是：
> pppoe的网络连接和network-manage的链接方式冲突  
解决方法1：每次连接好pppoe后关机的话要先手动退出pppoe:
```
sudo poff dsl-provider
```
这样显然太麻烦了，看解决方法2吧！  
解决方法2：清除pppoe设置,也就是把
```
/etc/network/interfaces
```
文件里有关pppoeconf设定的东西全部注释掉:  
```
sudo gedit /etc/network/interfaces
```  
只要留下这两行就行了:
``` sh
auto lo
iface lo inet loopback
```
3. 这样就完美解决了问题了，以后要拨号上网只要执行下：
```
sudo pon dsl-provider
```
就行了
