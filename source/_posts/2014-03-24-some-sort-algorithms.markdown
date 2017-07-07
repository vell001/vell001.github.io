---
layout: post
title: "some_sort_algorithms"
date: 2014-03-24 23:27:26 +0800
comments: true
categories: algorithm 
---
复习下数据结构常用的排序算法，更多内容上[wiki](http://zh.wikipedia.org/wiki/%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95)
<a name="quicksort"/>
## 快速排序（不稳定 O(n log n)）
> 快速排序（Quicksort）是对冒泡排序的一种改进。由C. A. R. Hoare在1962年提出。它的基本思想是：通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。[百度百科](http://baike.baidu.com/view/19016.htm)
<!-- more -->
### **C代码**:  
{% include_code lang:c c_learning/quicksort.c %}
### **Java代码**:
{% codeblock lang:java %}
package arithmetic;

public class QuickSort {

	public static void main(String[] args) {
		int[] a = {6,5,42,3,2,4,67,7,2,9,4};
		a = sort(a, 0, a.length-1);
		for(int i=0; i<a.length; i++){
			System.out.print(a[i] + "  ");
		}
		System.out.println();
	}
		
	public static int[] sort(int[] a, int low, int high){
		if(low < high){
			int p = partition(a, low, high);
			sort(a, low, p-1);
			sort(a, p+1, high);
		}
		return a;
	}
		
	public static int partition(int[] a, int low, int high){
		int key = a[low];
		while(low < high){
			while(low < high && a[high] >= key) high--;
			a[low] = a[high];
			while(low < high && a[low] <= key) low++;
			a[high] = a[low];
		}
		a[low] = key;
		return low;
	}
}
{% endcodeblock %}
2014-03-24 23:22:02 

--------------------------
<a name="bubblesort"/>
## 冒泡排序 （稳定 O(n2)）
> 它重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序错误就把他们交换过来。走访数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。[百度百科](http://baike.baidu.com/view/254413.htm)

### **C代码**:
{% include_code lang:c c_learning/bubblesort.c %}
2014/3/23 11:58:29 

-------------------
<a name="shellsort"/>
## 希尔排序（不稳定 O(n log n)）
> 希尔排序(Shell Sort)是插入排序的一种。是针对直接插入排序算法的改进。该方法又称缩小增量排序，因DL．Shell于1959年提出而得名。

> 先取一个小于n的整数d1作为第一个增量，把文件的全部记录分成d1个组。所有距离为d1的倍数的记录放在同一个组中。先在各组内进行直接插入排序；然后，取第二个增量d2<d1重复上述的分组和排序，直至所取的增量dt=1(dt<dt-l<…<d2<d1)，即所有记录放在同一组中进行直接插入排序为止 [百度百科](http://baike.baidu.com/view/178698.htm)
### **C代码**:
{% include_code lang:c c_learning/shell_sort.c %}
2014/3/23 13:20:05 

-------------------
<a name="heapsort"/>
## 堆排序（不稳定 O(n log n)）
> 堆排序(Heapsort)是指利用堆积树（堆）这种数据结构所设计的一种排序算法，可以利用数组的特点快速定位指定索引的元素。

> 堆排序（HeapSort）是一树形选择排序。堆排序的特点是：在排序过程中，将R\[l..n\]看成是一棵完全二叉树的顺序存储结构，利用完全二叉树中双亲结点和孩子结点之间的内在关系（参见二叉树的顺序存储结构），在当前无序区中选择关键字最大（或最小）的记录 [百度百科](http://baike.baidu.com/view/157305.htm)
### **c代码**:
{% include_code lang:c c_learning/heap_sort.c %}
2014-03-24 23:54:03 

-----------------
<a name="mergesort"/>
## 归并排序（稳定 O(n log n) 需要O(n)额外空间）
> 归并操作(merge)，也叫归并算法，指的是将两个已经排序的序列合并成一个序列的操作。归并排序算法依赖归并操作。[wiki](http://zh.wikipedia.org/wiki/%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F)
### **c代码**:
{% include_code lang:c c_learning/merge_sort.c %}
2014-03-25 15:48:58 

-----------------
## vell001.h (我的小工具库)
{% include_code lang:c c_learning/vell001.h %}


