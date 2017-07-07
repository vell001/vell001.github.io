---
layout: post
title: "C++ const详解"
date: 2014/9/8 11:15:53 +0800 
updated: 2014/9/8 11:15:57 +0800 
comments: true
categories: [C/C++]
tags: [C/C++]
---
C++ const
=========================

### const 变量使用问题
> C++内的各种限制关键字都是在编译期间由编译器去做处理的而不是运行期间。如下代码：  

	int x;
	cin >> x;
	const int size = x;
	int array[size]; // error!!!

> 这段代码里面看似没啥问题，其实问题很显然。` size `是一个const，但它的值却是` x `来的，是个不确定的值。用` size `去定义数组大小，在编译期间编译器就不知道给` array `分配多少内存了！

### const 定义指针问题
> 如果const在修饰一个指针时，出现两种情况：1. 指针是const、2. 指针指向的对象是const  
> 怎么区分这两种情况呢？看代码:

	Person p("VellBibi", 21);
	const Person *ptr = &p; 
	Person const* ptr = &p;
	Person *const ptr = &p;
	Person const*const ptr = &p;

> 有木有一种虐心的感角，当我第一次看见这样子的代码时，想跳楼啊~我记得java里面就一个` final `关键字，我当时没咋学就会用了，这C++搞得这么让人头疼！不过其实这些都是表象，java只是对C++做了几个减法，C++才真正体现了编程的灵活性。  
> 回到主题，怎么区分？

1. 指针是const  
` const `在` * `后，如：  
` Person *const ptr = &p; `   
意义： ` ptr `指针的值不能变，像` ptr++; `就会报错；但` ptr `指向对象的值可以变，如：` ptr->setName("Vell001") `。

2. 指针指向的对象是const
`const`在`*`前，如： 
` const Person *ptr = &p; `  
` Person const* ptr = &p; `  
意义： ` ptr `指向的对象不能通过` ptr `进行改变，如：` ptr->setName("Vell001") `编译会报错，但不是说`ptr`指向的对象不能被改变了，它还可以用其他方式修改，如：` p.setName("Vell001") `。

3. 以上两种都存在  
也就是在` * `前后都有` const `  
` Person const*const ptr = &p; `  
意义： ` ptr `指针的值不能变， ` ptr `指向的对象不能通过` ptr `进行改变  

### const 指针赋值问题
	
	const int x = 1;
	int *p1 = &x; // error!
	const int *y = &x;
	int *p2 = y; // error!

- 以上代码分析：` const `的变量不能赋值给非` const `变量，这样会破坏原有变量的` const `属性！  
- 强制转换： 使用` const_cast `去转换，如：  
` int *p3 = const_cast<int *>(y); `  

### const 字符串指针问题

	char *str = "hello vell001";
    str[0] = 'v';

- 代码分析： 这段代码编译的时候只给了一个**warning**，说String到char *的用法是deprecated的了。但运行时却直接出错退出了！
- 原因： ` "hello vell001" `是一个静态字符串，一般放在代码段，这部分内存是不能通过程序修改的，也就是`str[0] = 'v'`这句话肯定是出错的。
- 正确写法：  
` const char *str = "hello vell001"; `  这样就保证`str`是不能修改`"hello vell001"`的了！  
如果你是想要得到一个能修改的char数组： `char str[] = "hello vell001";`

### const 函数
在类的定义里面，成员函数定义如：` void function() const； `  
表示在`function`函数里面不能改变类的成员变量，也就是相当于在`function`函数里把整个对象const了！  
**注意：**在定义这样的函数时，.h文件和.cpp文件都要带上`const`，因为编译器是单独编译.h和.cpp文件的~

### const 类

	const Person p("vell001", 21);
	p.setName("vell002"); // error!

- 代码分析： 定义了一个const的Person对象p，也就是说p的成员变量是不可改变的，而第二句话是调用了p的setName方法，改变了p的name属性，这是不科学的啊，所以肯定会报错啊！  
- 问题： 那么怎样才能保证调用Person的方法是安全的呢？ 
- 解决： 在函数定义的时候，将不改变Person成员变量的方法后加上const，也就是const 函数如：` void function() const； `