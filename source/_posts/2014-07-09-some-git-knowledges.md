---
layout: post
title: "一些git的小知识"
date: 2014-7-9 23:22:45 +0800
updated: 2014-7-9 23:22:45 +0800
comments: true
categories: [git]
tags: [git]
---
> 在这简单列举下git常用的命令，更多关于git的介绍可以参考下：【[廖雪峰的官方网站](http://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000/00137402760310626208b4f695940a49e5348b689d095fc000)】

git简介
------------
![](/images/git_img_001.jpg)
> Git是用于Linux内核开发的版本控制工具。与CVS、Subversion一类的集中式版本控制工具不同，它采用了分布式版本库的作法，不需要服务器端软件，就可以运作版本控制，使得源代码的发布和交流极其方便。Git的速度很快，这对于诸如Linux内核这样的大项目来说自然很重要。Git最为出色的是它的合并追踪（merge tracing）能力。【[更多](http://baike.baidu.com/subview/1531489/12032477.htm)】  

常用的命令
-------------
### 设置全局的用户名和email 
> `git config --global user.name "yourname" `  
> `git config --global user.email "youremail" `  

### 缓存文件（添加文件到缓存区）
> `git add .` : 添加当前文件夹下所有文件  
> `git add -A` : 添加当前文件夹下所有文件，包括删除操作  

### 提交版本（提交缓存区的文件到版本库）
> `git commit -m "your message"`

### 推送到远程（一般用于推送到代码托管服务器）
> `git push origin master` : 将当前版本库中的master分支推送到origin上  
> `git push -u origin master` : -u作用是第一次推送时用于建立远程关联  
> `git push origin master --force` : 强制把当前版本库推送给远程（有一定的风险，要是在此期间同时别人提交了最新代码，这部分代码将丢失），一般用于回滚远程版本库  

### 克隆远程版本库
> `git clone git@github.com:yourname/yourproject.git` : 从*git@github.com:yourname/yourproject.git*这个地址上克隆，一般有*https*和*ssh*两种版本库访问方式

### 切换分支
> `git checkout yourbranch` : 切换到*yourbranch*分支上
> `git checkout -b yourbranch` : 创建*yourbranch*分支并切换

### 合并分支
> `git merge yourbranch` : 合并*yourbranch*分支到当前分支上

