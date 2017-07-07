---
layout: post
title: "centos添加sudo用户"
date: 2014-04-05 00:22:48 +0800
comments: true
categories: [linux]
tags: [linux,centos,sudo]
---
sudo简介
--------------------
> 给不是root用户提供一个方便的超级使用权限,例如:*sudo vim*
> centos里面没有默认的sudo用户,在ubuntu里面就有，没有就自己添加呗，没啥大不了的，还能学到点东西吧

> sudo的配置文件在：*/etc/sudoers*,需要先切换到root用户才能操作

配置文件
---------------------
###添加超级用户权限
> *vim /etc/sudoers*找到*root ALL=(ALL) ALL*这一行，在这行下添加一行：*username ALL=(ALL) ALL*
<!-- more -->

###sudo命令的时候都提示你输入根密码
> 找到*#%wheel ALL=(ALL) ALL*这一行，去除前面的注释符*#*就行了

###sudo时不要每次都输入密码
> 找到*#%wheel ALL=(ALL)NOPASSWD:ALL*这一行，同样去除前面的注释符*#*就行了

这样配置文件就设置完成了

添加用户名到wheel用户组
--------------------
``` sh
usermod -G wheel username
```

#OK了。。。


