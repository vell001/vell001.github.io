---
layout: post
title: "交叉编译python2.7.2"
date: 2014-4-26 2:01:35 +0800
updated: 2014-4-26 2:01:35 +0800
comments: true
categories: [python]
tags: [python,linux,ok6410]
---
## 环境
* ubuntu12.04 x86
* ok6410开发板
* arm-linux-gcc-4.3.2
* python-2.7.2 

## 配置交叉编译工具
* 
```
sudo mkdir /usr/local/arm 
```
创建目录，若目录已存在会提示错误，跳过即可
* 
```
sudo tar zxvf arm-linux-gcc-4.3.2.tgz -C /
```
编译器解压到/usr/local/arm
* 
```
sudo gedit /etc/profile
```
添加如下内容
```
export PATH=/usr/local/arm/4.3.2/bin:$PATH
export TOOLCHAIN=/usr/local/arm/4.3.2
export TB_CC_PREFIX=arm-linuxexport PKG_CONFIG_PREFIX=$TOOLCHAIN/arm-none-linux-gnueabi
```
* 要想永久生效的话就重启吧，要想在当前终端用一下的话：`source /ect/profile`(建议重启下啦)
* 测试下：`arm-linux-gcc -v` 出现如下提示说明安装成功啦
![](/images/20140425194440.png)

## 准备相关文件
1. python2.7.2源代码 : [http://www.python.org/ftp/python/2.7.2/Python-2.7.2.tar.bz2](http://www.python.org/ftp/python/2.7.2/Python-2.7.2.tar.bz2)，下载后解压
2. arm-linux-gcc-4.3.2，自行google吧，我用的是开发板自带的，你按照需要选择就行了
3. 补丁文件：去我的github找相对应的补丁文件吧：[vell001-github](https://github.com/vell001/python_cross_compilation_patchs)，下载好后放到python的源代码目录

## 编译生成PC版本的python语法解析器
进入解压后的python源代码目录，执行：
```
./configure  # for build-system's native tool-chain
make python Parser/pgen
mv python hostpython
mv Parser/pgen Parser/hostpgen
make distclean
```
成功后：
![](/images/20140425200654.png)

## 打补丁
```
patch -p1 < Python-2.7.2-xcompile.patch
```
![](/images/20140425210131.png)

## 编译开始啦
我的是arm-linux-gcc，也可以是别的编译器的哦  
```

CC=arm-linux-gcc CXX=arm-linux-g++ AR=arm-linux-ar RANLIB=arm-linux-ranlib ./configure --host=arm-linux --build=i686-linux-gnu --prefix=/python --disable-ipv6 --enable-shared

make HOSTPYTHON=./hostpython HOSTPGEN=./Parser/hostpgen BLDSHARED="arm-linux-gcc -shared" CROSS_COMPILE=arm-linux- CROSS_COMPILE_TARGET=yes HOSTARCH=arm-linux BUILDARCH=arm-linux-gnu SVNVERSION=2.7.2


```
完成后：  
![](/images/20140425220715.png)
## 编译时问题
我make时没有加`-i`参数（忽略错误），会报一些错误，导致编译进行不下去，而这些错误就是这几个模块的问题：
```
_bsddb             _curses            _curses_panel   
_sqlite3           _ssl               _tkinter        
bsddb185           bz2                dbm             
dl                 gdbm               linuxaudiodev   
nis                ossaudiodev        readline        
sunaudiodev        zlib 
```
这些模块没有编译进去没啥大影响的，要是真要用上了再说吧，google肯定会有解决方法的

## 安装
* 先建一个装安装文件的目录：`_install` （我的完整路径是`~/Python-2.7.2/_install`，在`make install`的`prefix`属性中用到，看清楚哦，不要搞错了）
```
mkdir _install
```
* 
```
make install HOSTPYTHON=./hostpython BLDSHARED="arm-linux-gcc -shared" CROSS_COMPILE=arm-linux- CROSS_COMPILE_TARGET=yes prefix=~/Python-2.7.2/_install
```
* 成功后会在`_install`目录下创建四个目录:  
![](/images/20140426001533.png)

## 打包啦！
* 先来压缩下`lib`吧
```
cd _install/lib/python2.7
python2 -m py_compile *.py
rm *.py
```
这样就把库文件夹整个压缩了一半多啊，上图：
压缩前：![](/images/20140426005143.png)
压缩后:![](/images/20140426004936.png)
* 打包放到开发板上测试啦
```
tar czvf arm-python2.7.2.tar.gz *
```
打包后总共12.7M，还行吧，在没有做任何压缩之前可是40M啊~~~

## 测试
我是直接上U盘拷的，这样快一点，我直接安装在`/python`目录下
```
mkdir /python
cp arm-python2.7.2.tar.gz /python/ && cd /python
tar -zxvf arm-python2.7.2.tar.gz
```
把库文件`libpython2.7.so libpython2.7.so.1.0`放到`/usr/lib`下
```
cd lib/
mv libpython2.7.so* /usr/lib
```
配置环境变量
```
vi /etc/profile
```
添加：
```
export PYTHONHOME=/python
export PYTHONPATH=.:$PYTHONHOME:$PYTHONHOME/lib/python2.7/site-packages
export PATH=$PATH:$PYTHONHOME/bin:$PYTHONHOME:$PYTHONPATH
```
立即生效或重启
```
source /etc/profile
```
这下就OK啦：
![](/images/20140426020001.png)

### 今天就到这了，太晚了，就不优化了，python还有很多可以压缩的地方，明天再说吧，晚安啦

2014/4/26 2:01:35 

> 参考:[http://randomsplat.com/id5-cross-compiling-python-for-embedded-linux.html](http://randomsplat.com/id5-cross-compiling-python-for-embedded-linux.html)