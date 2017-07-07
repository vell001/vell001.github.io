---
layout: post
title: "install_ruby"
date: 2014-03-24 13:24:05 +0800
comments: true
categories: ruby
---

### Install rvm
```
$ curl -L get.rvm.io | bash -s stable
$ source ~/.bashrc
$ source ~/.bash_profile
```
### 修改 RVM 的 Ruby 安装源到淘宝
```
$ sed -i -e 's/ftp\.ruby-lang\.org\/pub\/ruby/ruby\.taobao\.org\/mirrors\/ruby/g' ~/.rvm/config/db
```
### Install ruby 1.9.3
```
rvm install 1.9.3
```
<!-- more -->
### 使用 ruby 1.9.3
```
rvm use 1.9.3
```
### 设置默认ruby
```
rvm use 1.9.3 --default 
```

> 参考至：[RubyChina](http://ruby-china.org/wiki/rvm-guide)
