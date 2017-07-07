---
layout: post
title: "把vblog从octopress搬到hexo上了"
date: 2014-04-07 15:33:40 +0800
comments: true
tags: [hexo,vblog,octopress]
---
#换博客的原因： 
1. 前几天一直在用[octopress](http://octopress.org/)，觉得它的设计真不错，很有创意，就是配置文件太多了，有点受不了啊，装个插件费劲死了，光pygments这个东东把我害惨了快~；各种错误，代码高亮太坑爹了
2. 小问题还好解决，就是太繁琐了，可速度慢这个问题真是硬伤啊~我这才不到二十篇帖子，生成的时间有时能到近一分钟~真是奇慢无比啊！这可真受不了，到时上百篇帖子那还得了！果断准备换平台了
3. 最近对[node.js](http://nodejs.org/)很感冒，虽然很是不了解，但非常想了解，真正我google一下node.js的时候奇迹发生了，[hexo](http://hexo.io/)被我发现了,真是发现新大陆了
4. 发现hexo和octopress很像，可以说是兼容octopress了；刚开始觉得它就是node.js版的octopress，不过慢慢发现hexo和octopress就像是linux和unix；
5. hexo更快更简洁，相当给力，一个台湾同胞做的，英文文档也写得很全，虽然现在用户貌似不多，我相信一定会火的！
<!-- more -->

#过程
> 换的过程可以用曲折来描述，不是因为hexo太麻烦（hexo正常安装还是很简单的），而是因为学校网太垃圾，windows太难用，vm下的linux太坑爹~，还有自己git技术太菜  

* 之前费劲周折在centos上安装node.js，最后还是没安装上，疯了快~错误原因居然会是找不见js文件，可是按它提示的路径我手动给找见了，服了~暂时无解，已经把centos删了（vmware里面的）
* 后来图个新鲜，装个linuxmint玩玩，编译安装node.js很简单，就是编译时间有点长，快10分钟了。不过安装hexo的时候就悲剧了：
```
npm install hexo -g
```
我可以说执行这个命令上百遍了，全是卡在了某个下载文件那！还在windows下试了，也是同样！整了我昨天一晚上啊！今天偷偷用了下别人的cmcc居然一下就安装上了~学校网伤不起！！！真想说：**珍爱生命，远离科大~**
* 在linuxmint和windows上都装好了hexo了，开始配置自己的博客了，我使用的是[jacman](https://github.com/wuchong/jacman)这个主题，感觉不错，很喜欢这个主题的配色，随便改了改就拿来用了
* 配置好后在linuxmint下部署到[gitcafe](http://gitcafe.com)上了，一个国内高仿的github。国内速度还不错，使用我的另一个域名发布：[vview.ml](http://vview.ml)
* 正当我用得high了，vmware直接给我来个死机，linuxmint没有任何反应了，和我上次用ubuntu一样，当时正因为ubuntu在vm下老死机才换到centos的，现在换linuxmint了还是难逃厄运。悲催，又不想重启电脑，把vm的进程关了，想想，在windows下应该也能很简单的使用吧。
* 环境换到windows下了，没有死机了，却来了各种莫名的error。windows的命令行不是一般难用啊！换到git的bash也是一样，甚至再装了个cygwin，还是没有linux的干脆。在执行：
```
hexo deploy
```
时有一个永恒的error：  
![error](/images/20140407161850.png)  
google了一大堆解决方法，貌似都是针对linux的，在cygwin下都出错，no idea!虽然我相信这个问题一定有啥办法可以解决，但是太费劲了，windows坑爹啊！
* 这个问题肯定是一个git的问题，而且肯定是身份验证publickey的问题，既然是这样，我就直接使用windows下git默认的gui了，界面版的操作也挺简单的，省去了命令行的繁琐（我更喜欢命令行，前提是不在windows下），直接进*.deploy*文件夹右键找*git gui*，然后~~~
* 最后我在windows下成功发布博客了，这篇博客也将在windows下发布。虽然过程很悲催，至少达到目的了，先歇会，来句口号：珍爱生命，远离windows~（呵呵，仅仅针对对无聊的程序猿）

#结果
* 博客平台更换成功！博客生成速度显著提升：  
![speed](/images/20140407163255.png)  
* 体验到了hexo的简洁高效，再也不想回到octopress了！~
* 再来张本博客的截图吧：
![vblog](/images/20140407163602.png)