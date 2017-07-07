---
layout: post
title: "C++ 拷贝构造函数要点"
date: 2014/9/9 12:10:44 +0800 
updated: 2014/9/9 12:10:47 +0800 
comments: true
categories: [C/C++]
tags: [C/C++]
---
C++ Copy Constructor
=========================

## C++里初始化时"()"和"="是同一个意思

	int i = 1
	int i(1);

## 拷贝构造函数就是拿一个存在的对象初始化另一个对象

	Person p2 = p1;
	Person p2(p1);

> 都是调用了Person(const Person&)构造函数，而不是Person(Person p)，这样的话就无限递归了~因为Person(Person p)调用时，p的初始化还是要调用拷贝构造函数

## 默认拷贝构造函数
默认拷贝构造函数是递归调用成员变量的拷贝构造。是成员变量级别的拷贝，不是字节拷贝
> 也就是说，基本类型的话就是纯字节拷贝了，对象的话就是调用拷贝构造函数了  
> 
- 如果存在指针的话，在新对象和旧对象里面的指针指向同一片内存  
- 这样会出现一个问题，当旧对象在析构函数里面delete了那片内存，新对象里就会出现指针错误，而且析构的时候肯定出错！
- 所以理想状态下是指针也拷贝一份内存，也就是要自己去实现一个拷贝构造函数了  
![](/images/cpp/copy_constructor.png)  
左边的就是默认构造函数，右边的是理想状态  

## 调用场景

### 对象初始化

	Person p = p1;
	Person p(p1);

### 函数调用（参数是一个对象，不是引用，也不是指针时）

	void function(Person p);

### 函数返回

	Person function();
	Person p = function();

> 由于编译器的不同，大多数编译器会进行一些优化，调用次数也许会不同，如：
> 
	Person function(int i){
	    return Person(i);
	}
	Person p = function(1);

> 这样的话大部分编译器会直接合并成：p = Persion(1);

## 尽量不要依赖系统给的拷贝构造函数
> 也就说，一个好习惯就是，当你创建一个类时，自己添加至少一下三个函数
> 
- 默认构造函数
- virtual析构函数
- 拷贝构造函数