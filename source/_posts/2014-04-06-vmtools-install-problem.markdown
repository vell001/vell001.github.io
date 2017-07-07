---
layout: post
title: "vmtools 共享文件夹问题 "
date: 2014-04-05 00:22:48 +0800
comments: true
categories: linux
tags: [vmtools,linux,linuxmint]
---
#问题描述
> 安装vmware tools(VMwareTools-9.x.x...)时，出现以下错误:  

```
/tmp/modconfig-9y1RHM/vmhgfs-only/inode.c: In function ‘HgfsPermission’:
/tmp/modconfig-9y1RHM/vmhgfs-only/inode.c:1893:29: error: ‘struct dentry’ has no member named ‘d_count’
          int dcount = dentry->d_count;
                             ^
make[2]: *** [/tmp/modconfig-9y1RHM/vmhgfs-only/inode.o] 错误 1
make[2]: *** 正在等待未完成的任务....
make[1]: *** [_module_/tmp/modconfig-9y1RHM/vmhgfs-only] 错误 2
make[1]:正在离开目录 `/usr/src/linux-headers-3.11.0-12-generic'
make: *** [vmhgfs.ko] 错误 2
make:离开目录“/tmp/modconfig-9y1RHM/vmhgfs-only”

```

> 导致*vmhgfs*模块安装失败，无法再vmware中使用共享文件夹。
<!-- more -->

#问题原因
> vmtools在linux内核高于3.8.x版本的linux发行版好像都有bug，我用的是linuxmint，内核版本为3.11.x，这个版本的bug和3.8.x的bug又有不同，不过解决方法一样，都是打补丁嘛，呵呵，就是补丁不一样啦

#问题解决
创建一个文件夹，将'vmhgfs-fix.sh', 'vmtools.inode.c.patch' 和 'VMwareTools-9.x.x.tar.gz' 放到里面，执行./vmhgfs-fix.sh 自动打补丁, 然后按照原来的安装方法安装就行了  
vmhgfs-fix.sh,内容为：  
```
#!/bin/bash
#
# Patch to fix VMware-Tools installation
#

# Get VMwareTools file (it should be in the default format VMwareTools-9.x.x...)
VMFILE=`ls | grep VMwareTools-9.*`

if [[ ! $VMFILE ]]
then
  printf "\nERROR: \nVMwareTools-9.(...).tar.gz not found.\n\nYou should place it in the current folder and/or \nRename it as VMwareTools-9... (default format name)\n\n"
  exit
fi

# Check for vmware-tools-distrib folder
if [[ ! -d vmware-tools-distrib ]]
then
  printf "\nExtracting VMware-tools...\n"
  # Extract VMware Tools
  tar xf $VMFILE
else
  printf "\n/vmware-tools-distrib already exists.\nPlease remove it before applying this patch.\n\n"
  exit
fi

# Record the current directory
PATCH_DIR=$PWD

printf "\nApplying patch to VMware-Tools...\n\n"
sleep 3
pushd vmware-tools-distrib/lib/modules/source

# Make a backup of vmhgfs.tar
cp vmhgfs.tar vmhgfs.tar.backup
# Extract vmhgfs.tar
tar xf vmhgfs.tar
# Go to extracted vmhgfs.tar
pushd vmhgfs-only/
# Apply patch
patch -p1 < $PATCH_DIR/vmtools.inode.c.patch
popd
# Remove old vmhgfs.tar
rm -rf vmhgfs.tar
# Repack new vmhgfs.tar
tar cf vmhgfs.tar vmhgfs-only
# Remove vmhgfs-only dir which is not needed
rm -rf vmhgfs-only
popd

printf "\nPatch Applied!\n"
printf "Now try to install VMware-Tools.\n\n"
```

vmtools.inode.c.patch文件内容:
1. 3.8.x:
```
--- ./inode.c	2013-02-26 02:18:24.000000000 +0000
+++ ./inode.c	2013-05-03 00:34:59.995053850 +0100
@@ -885,7 +885,8 @@
    ASSERT(inode);
 
    LOG(4, (KERN_DEBUG "VMware hgfs: HgfsTruncatePages: entered\n"));
-   result = compat_vmtruncate(inode, newSize);
+	 //result = compat_vmtruncate(inode, newSize);
+   result = 0; // Fix for kernels 3.8.x due to an error in truncate function
    if (result) {
       LOG(4, (KERN_DEBUG "VMware hgfs: HgfsTruncatePages: vmtruncate failed "
               "with error code %d\n", result));
```
2. 3.11.x:
```
--- vmhgfs-only/inode.c 2013-08-15 22:32:22.000000000 -0700
+++ vmhgfs-only.patched/inode.c 2013-09-16 21:31:12.323041668 -0700
@@ -31,6 +31,9 @@
 #include <linux/namei.h>
 #endif
 #include <linux/highmem.h>
+#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 11, 0)
+#include <linux/dcache.h>
+#endif

 #include "compat_cred.h"
 #include "compat_fs.h"
@@ -1890,7 +1893,11 @@
 #endif
                            &inode->i_dentry,
                            d_alias) {
+#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 11, 0)
+ int dcount = d_count(dentry);
+#else
          int dcount = dentry->d_count;
+#endif
          if (dcount) {
             LOG(4, ("Found %s %d \n", dentry->d_name.name, dcount));
             return HgfsAccessInt(dentry, mask & (MAY_READ | MAY_WRITE | MAY_EXEC));
@@ -1943,10 +1950,12 @@
       list_for_each(pos, &inode->i_dentry) {
          int dcount;
          struct dentry *dentry = list_entry(pos, struct dentry, d_alias);
-#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 38)
- dcount = atomic_read(&dentry->d_count);
-#else
+#if LINUX_VERSION_CODE >= KERNEL_VERSION(3, 11, 0)
+ dcount = d_count(dentry);
+#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2, 6, 38)
          dcount = dentry->d_count;
+#else
+ dcount = atomic_read(&dentry->d_count);
 #endif
          if (dcount) {
             LOG(4, ("Found %s %d \n", (dentry)->d_name.name, dcount));
```

> 更多补丁见：[github](https://github.com/rasa/vmware-tools-patches/tree/master/patches/vmhgfs)

2014/4/6 20:17:08 

