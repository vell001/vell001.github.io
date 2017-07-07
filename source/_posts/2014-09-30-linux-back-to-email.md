---
layout: post
title: "linux服务器备份到邮箱"
date: 2014/9/30 13:37:35 +0800 
updated: 2014/9/30 13:37:38 +0800 
comments: true
categories: [linux]
tags: [linux]
---
## 前言
之前做V&View（维视）博客的时候是放在linux的vps上，vps不稳定，可能随时都会不用了，所以需要定时将整个网站都备份一下，以防万一。由于用的是linux，我可以使用**mutt**直接备份到我的邮箱里面，于是乎研究了下shell编程，当时用一个小时摸索出来的代码，今天拿出来晒晒。  
因为昨天我又做了我们宿舍用的一个微信公共号版的会员管理系统，也是放在linux服务器上的，所以翻出来了这段代码，废话不多说，上代码吧

## 代码
``` lang:sh
#!/bin/bash  

#初始化参数
#总备份文件夹
backup_all_dir="/home/backup"
#这次备份文件夹
backup_dir="V&View-backup"-$(date +"%Y%m%d%h%m%s")
backup_file=$backup_dir.tar.gz

# 进入到备份总文件夹 
cd $backup_all_dir
# 创建存放备份文件和数据库的文件夹，并修改权限为777 
mkdir -m 777 -p ./$backup_dir
# 将需要备份的文件复制到备份文件夹内 
cp -r /usr/local/tomcat/vview ./$backup_dir/vview
# 导出数据库到备份文件夹内 
/usr/bin/mysqldump -uroot -p123456 vview > ./$backup_dir/vview.sql
# 压缩存放备份文件和数据库的文件夹 
tar zcvf ./$backup_file ./$backup_dir
# 以附件形式发送压缩包到指定邮箱 
echo "Backup file for vview.vell001.ml" | mutt -s "V&View(维视)-Backup$(date +%Y-%m-%d)" vell001@qq.com -a ./$backup_file
# 删除备份文件夹
rm -rf ./$backup_dir 
# 删除三天前备份压缩包
find $backup_all_dir -mtime +3 -exec rm -f {} \;
```

## 使用方法
1. 安装mutt :  
    `yum -y install mutt`
2. 把脚本复制到 `/root/BackupToMail.sh`
3. 给脚本添加执行权限：  
    `chmod +x /root/BackupToMail.sh`
4. 测试手动执行脚本：  
    `sh /root/BackupToMail.sh`
5. 借助vixie-cron自动执行：
    `crontab -e`
    添加如下内容：
    `59 23 * * * /root/BackupToMail.sh`
    每天的23:59分会自动执行
## 备注
脚本使用之前必须对脚本进行配置，对于不同的人不同的配置，我就不详解了