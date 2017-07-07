---
layout: post
title: "Android WebView注入js方式总结"
date: 2017/1/4 22:49:00 +0800 
updated: 2017/1/4 22:49:00 +0800 
comments: true
categories: [Android]
tags: [Javascript,Html,Android,WebView]
---

# Android WebView注入js方式总结
## 第一种
通过webview.loadUrl("javascript:")注入，如：
```java
webview.loadUrl("javascript: alert('hello');");
```
### 缺点：
会有最大字符限制，不同内核会有不同限制大小，目前发现TBS内核超过大概1024字节就注入不成功了，原生webview比较大，是2097152字节 (即：2M)，pc端情况如下：

|游览器|	最大长度（字符数）|   备注|
| ------------- |:-------------:| -----:|
| Internet Explorer | 2083 | 如果超过这个数字，提交按钮没有任何反应|
| Firefox	| 65,536 | |	 
| chrome | 8182 ||
| Safari | 	80,000 ||
| Opera | 190,000 ||
| curl（linux下指令）| 8167||	 

## 第二种
类似于第一种，同样通过webview.loadUrl("javascript:")方式注入，但注入的内容是一个script块，在script块里引入外部js，如：
```js

javascript:try{

if(document.head && !document.getElementById('UTEST_injectScript')) {

	varinjectScript = document.createElement('script');
	
	injectScript.src='file:///sdcard/inject.js';
	
	injectScript.id='UTEST_injectScript';
	
	document.head.appendChild(injectScript);

}

}catch(e) {}

```
这段代码就相当于在html页面里引入了 `/sdcard/inject.js` 

## 第三种
第二种方法看似可行，但是如果你是注入别人的网站，而非你自己放在sdcard的html页面的话是会有报错的：
```js
Not allowed to load local resource: file:///sdcard/inject.js
```
解决方法参考：
[https://groups.google.com/forum/#!topic/android-developers/4g6H0vr5_0E](https://groups.google.com/forum/#!topic/android-developers/4g6H0vr5_0E)  

使用webview.loadDataWithBaseURL接口注入
```java
String data = "<script>alert('hello');<script>";
webview.loadDataWithBaseURL( null, data, "text/html", "utf-8", null );
```

### 缺点：
这种方式看似完美，但还是有问题，每次调用loadDataWithBaseURL时都会触发WebChromeClient#onProgressChanged()方法，就是进度条是会变化的

# 综上所述
最稳妥的方法是将大的js **按功能模块拆分** 成小js，通过 `webview.loadUrl` 一个一个注入.

