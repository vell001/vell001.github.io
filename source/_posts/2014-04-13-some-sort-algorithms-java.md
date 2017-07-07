---
layout: post
title: "java 复习003 之排序篇"
date: 2014-04-13 09:12:04 +0800
updated: 2014-04-13 11:26:41 +0800
comments: true
categories: [java]
tags: [java,algorithm]
---
# java 复习003 之排序篇
> 由[java 复习003](http://vblog.vell001.ml/2014/04/13/java_review003.html)跳转过来的  
>C语言实现版见[some-sort-algorithms](http://vblog.vell001.ml/2014/03/24/some-sort-algorithms.html)

1. 快速排序（不稳定 O(n log n)）
{% include_code lang:java java_review/QuickSort.java %}
2. 冒泡排序 （稳定 O(n2)）
{% include_code lang:java java_review/BubbleSort.java %}
3. 希尔排序（不稳定 O(n log n)）
{% include_code lang:java java_review/ShellSort.java %}
4. 堆排序（不稳定 O(n log n)）
{% include_code lang:java java_review/HeapSort.java %}
5. 归并排序（稳定 O(n log n) 需要O(n)额外空间）
{% include_code lang:java java_review/MergeSort.java %}
6. vell001.java (我的小工具库)
{% include_code lang:java java_review/vell001.java %}