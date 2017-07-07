---
layout: post
title: "ok6410安装debian"
date: 2014-05-04 2:01:35 +0800
updated: 2014-05-04 2:01:35 +0800
comments: true
categories: [ok6410]
tags: [ok6410,emdebian,debian,linux,ubuntu]
---
> ok6410自带的系统实在太难用了，必须换一个才甘心啊，今天晚上google到了个emdebian，果断移植~~~

## 环境及工具
1. win7_x64 + ubuntu12.04_x86
2. ok6410-A
3. Yaffs2文件系统制作工具：`mkyaffs2image-nand2g`

## 准备

使用`debootstrap`定制emdebian，先安装  
```
sudo apt-get install debootstrap
```

建立一个工作目录  
```
cd ~
mkdir debian-ok6410 
cd debian-ok6410
```

## 下载配置系统文件

debian有两个版本可选，一个是完整的debian，一个是emdebian（精简版，去掉了不必要的驱动和manpages等），在这小板子上还是用emdebian吧。  

debian:  
由于国内163有debian的源，所以为了速度就换到163了
```
sudo debootstrap --arch=armel --foreign squeeze rootfs/ http://tel.mirrors.163.com/debian
sudo echo "deb http://tel.mirrors.163.com/debian squeeze main" >> rootfs/etc/apt/sources.listsources.list
```

emdebian（推荐）:  
还有由于`emdebian.org`国内无法访问(后来发现能访问，可是速度极其慢，还是推荐换源)，还好官网提供了两个源，所以换到bytesatwork的源了`http://emdebian.bytesatwork.ch/`，另一个还是被墙了，不得已只能用这个啦~
```
sudo debootstrap --arch=armel --foreign --include=vim,openssh-server squeeze rootfs/ http://emdebian.bytesatwork.ch/mirror/grip/
sudo echo "deb http://emdebian.bytesatwork.ch/mirror/grip/ squeeze main" >> rootfs/etc/apt/sources.list
```
说明：`--include`一些常用软件`vim,openssh-server`

配置系统  
```
echo "proc /proc proc none 0 0" >> rootfs/etc/fstab
echo "OK6410" > rootfs/etc/hostname
sudo mkdir -p rootfs/usr/share/man/man1/
sudo mknod rootfs/dev/console c 5 1
```

## 制作Yaffs2文件系统
使用官方工具制作(官方资料里面有这个工具，我的是2Gflash的，所以选择的是`mkyaffs2image-nand2g`)  
```
sudo ./mkyaffs2image-nand2g rootfs/ rootfs.yaffs2
```
使用SD卡安装系统，详细参考官方文档

## 第一次启动系统(安装系统)
先设置启动参数，在重置后快速按任意键进入uboot menu，查看原来的启动参数：
```
echo $bootargs
```

我的得到的是：`root=/dev/mtdblock2 rootfstype=yaffs2 console=ttySAC0,115200`  
所以在此之上加`noinitrd`,和`init=/bin/sh`，只启动sh这一个进程  
```
setenv bootargs "root=/dev/mtdblock2 noinitrd rootfstype=yaffs2 console=ttySAC0,115200 init=/bin/sh"

saveenv
reset
```
特别注意，引号不能为中文的`“`，必须为英文的`"`,要不然会报错：`Kernel panic - not syncing: VFS: Unable to mount root fs on unknown-block(2,0)`

安装系统
```
/debootstrap/debootstrap --second-stage
```
正在安装(耐心等待吧)：  
![](/images/20140504003307.png)
安装成功：  
![](/images/20140504022154.png)

此时可以对系统进行必要的配置
```
echo "ttySAC0" >> /etc/securetty
printf "T0:123:respawn:/sbin/getty 115200 ttySAC0\n" >> /etc/inittab
passwd
```

## 第二次启动系统
```
reboot -f
```

在重启后快速按任意键进入uboot menu，设置启动参数，修改init（`init=/sbin/init`）  
```
setenv bootargs "root=/dev/mtdblock2 noinitrd rootfstype=yaffs2 console=ttySAC0,115200 init=/sbin/init"

saveenv
reset
```

耐心等待成功的到来吧：  
![](/images/20140504023731.png)

接下来就可以使用强大的debian工具了，如：apt-get  

> 今天又熬夜了，伤不起啊~为啥我的思想老是在晚上那么的活跃啊！！！   
> 赶紧睡了，明天起不来了呀  

2014/5/4 2:56:56 