---
layout: post
title: "C/C++的一些算法题"
date: 2014-9-2 20:53:51 +0800 
updated: 2014-9-2 20:53:51 +0800 
comments: true
categories: [C/C++]
tags: [QT,C/C++]
---
> 这学期没啥课，所以在网上随便找了一些算法题来做做，希望自己能坚持每天至少做一道的节奏，做完5道更新一篇博客  
> 我的代码全部是在QTCreator下完成的，尽量使用C/C++的基本语法，源代码可以到我的github找到

## 把二元查找树转变成排序的双向链表
题目：
输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。
要求不能创建任何新的结点，只调整指针的指向。

<!-- more -->

	  	 10
	   /    \
	  6      14
 	 /  \   /   \
	4    8 12    16


转换成双向链表
4=6=8=10=12=14=16。

	typedef struct LinkedListNode{
	    DATATYPE data;
	    struct LinkedListNode *lNode;
	    struct LinkedListNode *rNode;
	}LinkedListNode, *LinkedList;
	
	/*
	 * 把tree的结点转换成已head开头和tail结尾的双向循环链表
	 */
	void treeToLinkedList(BinaryTree tree, LinkedListNode *& head, LinkedListNode *& tail){
	    if(tree == NULL) {
	        tail = head;
	        return;
	    }
	    // 申请当前结点的空间
	    LinkedListNode *node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
	    node->data = tree->data;
	
	    // 将左右子树分别转换
	    LinkedListNode *leftTail=NULL, *rightHead=NULL;
	    treeToLinkedList(tree->lChild, head, leftTail); // 将左子树转换
	    treeToLinkedList(tree->rChild, rightHead, tail); // 将右子树转换
	
	    // 将当前结点连入双向链表
	    node->rNode = rightHead;
	    node->lNode = leftTail;
	
	    if(leftTail != NULL) leftTail->rNode = node;
	    else head = node; // 确定头结点
	    if(rightHead != NULL) rightHead->lNode = node;
	    else tail = node; // 确定尾结点
	
	    // 使链表循环
	    head->lNode = tail;
	    tail->rNode = head;
	}
