---
layout: post
title: "腾讯一面程序题回顾"
date: 2014/9/16 22:05:17 +0800 
updated: 2014/9/16 22:05:20 +0800 
comments: true
categories: [C/C++]
tags: [C/C++,tencent]
---
## 前言

今天参加了腾讯校园招聘的面试（一面），开始感觉还不错，面试官是个年轻帅气的小伙，稍微小紧张，再聊完跟项目相关的知识（如：SQL注入问题、正则表达式、过滤器等）后，面试官给我抽了一道写程序的题；写代码的时候就真正紧张了，因为题是一个多叉树循环先根遍历的，话说我还没有用循环写过对树的遍历呢，更不用说多叉树了！写了我估计有半个小时，因为开始没听明白他的意思："循环实现"，我先写了一个递归实现的，他给挑了几个毛病，把我思绪打乱了，后来画图说明白了整个递归遍历过程后让我看了下他的答案的函数定义，我记得大概是这个样子的：`Node *next(Node *node)`，说递归没有办法在遍历过程中返回每个节点的指针，坚持让我写一个循环的实现，我硬着头皮在纸上又画了一个图去理理思路，每写了一点代码就给他说一遍思绪，大概3-4次后写得差不多了，可是还有两个重大问题没有解决：1. 函数退出条件；2. 遍历兄弟结点条件（这样说有点抽象，等会上代码），后来就让我回去再想想了，整个技术部分的考察也就算是结束了，聊了点生活方面的面试就结束了。回到宿舍休息了下，就准备好好想一下它的实现，后来发现问题很大啊！先上题目

## 题目
```
struct Node{
    int value;
    struct Node *parentNode;
    struct Node *brotherNode;
    struct Node *childNode;
}
```  
> 一颗多叉树，给定上面的结点，写一个先根遍历函数`next`，可以在循环里面调用`next`进行整个树的遍历  

突然发现我在面试的时候写的第一个递归遍历实现的代码是对的！！！完全没有任何错误啊~~~结果被面试官忽悠!~（哎，其实怪我没有抵住面试官的问题啊！），后来还给改错了，⊙﹏⊙b汗！！！，我当时的代码就差不多是这个样子的：  

```
void recursion(Node *node){
    if(node == NULL) return;
    
    cout << node->value << " ";
    
    recursion(node->childNode);
    recursion(node->brotherNode);
}
```

回宿舍画了一个差不多包含了全部情况的多叉树的图：  
![](/images/tencent_interview/20140916224931.png)
> 正确的先根遍历应该是：`1 2 4 7 8 9 10 11 5 6 3`

用循环去实现遍历，先写一个`next`函数，写这个函数时非常纠结，记得面试时大概是这样子写的

```
Node *next(Node *node){
	if(node == NULL) return NULL;
    if(node->childNode != NULL)
        return node->childNode;
    else if(node->brotherNode != NULL)
        return node->brotherNode;
    else if(node->parentNode != NULL)
        return next(node->parentNode->brotherNode); // 这个退出问题很严重啊
}

Node *node = tree;
while(node != NULL){
    cout << node->value << " ";
    node = next(node);
}
```

> 这个代码存在不严谨的退出问题，遍历结果是：`1 2 4 7 8 9 10 11`，丢失了`5 6 3`这三个数，也就遇见兄弟结点为空的时候就退出了，没有再继续去找父亲结点了，为了解决这个问题，我还没有想到特别好的方法，就是想到了一个能解决的方法，不过感觉上还是觉得代码不够好，上修改后的`next`代码：

```
Node *next(Node *node, int flag=0){
    if(flag != 0){
        if(node->brotherNode != NULL)
            return node->brotherNode;
        else if(node->parentNode != NULL)
            return next(node->parentNode, 1);
        else 
            return NULL;
    }
    if(node->childNode != NULL)
        return node->childNode;
    else if(node->brotherNode != NULL)
        return node->brotherNode;
    else if(node->parentNode != NULL)
        return next(node->parentNode, 1);
}
```

> 我加入了一个`flag`参数，用来判断当前结点的`childNode`是否被遍历过了，`flag`默认是** 0 **，如果传入为非零就代表`node`的`childNode`被遍历过了，直接去遍历`brotherNode`，如果没有`brotherNode`就继续往上，也就是说`node`的`parentNode`的`childNode`全部遍历完了~~~（有点绕，其实也就是一个递归的过程）  
> 谁想到了更好的实现方法请第一时间告诉我啊！！！我的邮箱：[vell001@qq.com](mailto:vell001@qq.com)

## 结束语
在等腾讯的二面通知呀~很着急啊，不知道情况咋样呀！要是过了的话就继续分享一些我的经历吧，没过就当纪念了。。。先要感谢杨哥从大三找实习就一直在帮助我，给我提了很多笔试面试的技巧；再要感谢宣哥帮我内推到腾讯，给我说了很多腾讯相关的东西，让我更了解腾讯，也更了解工作；感谢所有在默默帮助我找工作的朋友~真心说声**"谢谢"**了~

## 附加
我回宿舍做的全部代码：  

{% include_code lang:cpp tencent_interview/multiwayTree.cpp %}

