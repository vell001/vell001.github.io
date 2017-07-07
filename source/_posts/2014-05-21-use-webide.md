---
layout: post
title: "使用webIDE搭建hexo博客环境"
date: 2014-5-21 20:08:20 +0800
updated: 2014-5-21 20:08:20 +0800
comments: true
categories: [hexo]
tags: [hexo,webIDE,nitrous]
---
> *webIDE*就是一个在浏览器里面的集成开发环境，实现云开发，不在纠结于电脑的环境配置了，直接云配置啦！  
> 我今天发现一个非常好的webIDE：[nitrous](https://www.nitrous.io)，它提供了多钟语言支持：Node.js、Python、Go、Rails、PHP，下来就开始玩玩它啦

## 我为啥玩webIDE
> 我前段时间接触到hexo博客系统，感觉非常好啊，我的个人博客[vblog](http://vblog.vell001.ml)就是hexo的产物。  
> hexo是node.js写的，配置node.js环境比较费劲，特别是在windows下，简直是中折磨。我个人在linux和windows环境间切换工作的频率比较高，我需要两边都配置好环境，太费劲了。于是想到在webIDE里搭建一个hexo环境，这样就非常省事了。相当于有一台电脑在云端，只要通过web就可以完全访问，于是乎玩上了nitrous。  

## nitrous简介
> nitrous可以免费创建*box*， 一个box就是一个简化的linux系统啦，就是没有root权限而已。 
> nitrous带了一个很给力的IDE界面，文本编辑器太好用了

## 安装hexo
> 直接`npm install hexo -g`，我这不到2分钟就安装完了

## 获取我的博客源文件
> 使用`git clone`，导入我的博客源文件，速度还行，基本保持在了400k/s的样子

## 接着就是正常写博客啦，总结下吧
> webIDE潜力很大啊，只要一个有网的地方就能轻松做开发，我这只是小试牛刀而已；  
> 不过安全性就无从知晓了，搞点小开发还是可以的，中大型项目还是自建局域网吧！
