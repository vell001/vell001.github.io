---
layout: post
title: "在linux上安装octopress博客环境"
date: 2014-04-04 19:24:05 +0800
comments: true
categories: linux
tags: [linux,centos,octopress]
---
> 说明：我之前已经在ubuntu上部署安装过octopress，现在是把环境搬到centos上，本教程适合已经成功安装过octopress的纯屌丝！[更多教程上官网看吧](http://octopress.org/docs)  

##安装全程
* 安装ruby环境（官网是1.9.3）
> 详见：[Install_ruby](http://vblog.vell001.ml/2014/03/24/install-ruby.html)  
``` sh
#!/bin/bash
# install rvm
curl -L get.rvm.io | bash -s stable
source ~/.bashrc
source ~/.bash_profile

# 修改 RVM 的 Ruby 安装源到淘宝
sed -i -e 's/ftp\.ruby-lang\.org\/pub\/ruby/ruby\.taobao\.org\/mirrors\/ruby/g' ~/.rvm/config/db

# Install ruby 1.9.3
rvm install 1.9.3

# 使用 ruby 1.9.3
rvm use 1.9.3

# 设置默认ruby
rvm use 1.9.3 --default 
```

<!-- more -->
* 安装git环境（我的centos自带了）
> 安装详见：[Download Git for Linux and Unix](http://git-scm.com/download/linux)
 
* 安装bundle  
``` sh
gem install bundler
bundle install 
```
> 在*bundle install*的时候可能会报错：*An error occurred while installing nokogiri (1.5.11), and Bundler cannot continue.*  
> 一般直接*gem install nokogiri -v '1.5.11'*就行了，如果还不行，[点我去官网](http://nokogiri.org/tutorials/installing_nokogiri.html)，我使用*sudo yum install -y gcc ruby-devel libxml2 libxml2-devel libxslt libxslt-devel*解决了这个问题。

* 安装pygments(用于语法高亮)
> *sudo yum install python-pygments*  
> 更多详见：[install-pygments](http://vblog.vell001.ml/2014/03/24/install-pygments.html)
> 特别注意，你的python必须是2.x版本的，详情见：[some-problem-with-octopress](http://vblog.vell001.ml/2014/03/23/some-problem-with-octopress.html)

* 整个环境到此结束了，只要*source ~/.bash_profiles*就可以使用rake命令了。

2014/4/5 0:15:58 

