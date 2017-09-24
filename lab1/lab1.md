# 1 实验内容
(1) 编写一个c程序，在linux环境下编译并运行，功能为输出字符串”Hello, world!"；

(2) 创建github仓库，将该c程序代码上传到github中，位置为master/lab1文件夹。

# 2 实验步骤

(1) 注册github账号，创建一个仓库；

(2) 在本地运行git clone+仓库地址，将仓库同步到本地；

(3) 设置git参数；

(3) 编写、编译并运行程序；

(4) 设置上传和注释；

(5) 上传。

# 3 实验内容

(1) 注册github账号。在本学期本课程中以klzchuoxue为用户名注册账号，创建仓库se2017：

![](http://imglf1.nosdn.127.net/img/ekx2Wk55b0tGRUJrWm5kQ1RSWUJIWHo5QjhRUXFpSjc1bmNIZnNtcHdpRmVLZ1BpbnVOUU5RPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.1 注册、创建并上传后的仓库（网页展示）

(2) 在本地运行命令：

>`git clone https://github.com/klzchuoxue/se2017`

![](http://imglf0.nosdn.127.net/img/ekx2Wk55b0tGRUJrWm5kQ1RSWUJIVW5VM1JUUXI4aWI4M0tVbTdmUDZPazdjWXZNd1g5YkZnPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.2 本地仓库

(3) 设置git参数：

![](http://imglf2.nosdn.127.net/img/ekx2Wk55b0tGRUJrWm5kQ1RSWUJIVGJ5bDNmYXhaOSs3azdZemlMZVY0alNnNkRoQkZuSUVnPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.3 设置完毕的参数内容

(4) 编写、编译并运行程序：

![](http://imglf2.nosdn.127.net/img/ekx2Wk55b0tGRUJrWm5kQ1RSWUJIZmpBeWJXRGwvZzhBeFltaFN4TVMrckVYYlUyUzV4MHNRPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.4  程序代码和运行效果

(5) 设置上传和注释并上传

![](http://imglf2.nosdn.127.net/img/ekx2Wk55b0tGRUJrWm5kQ1RSWUJIWDlGQVJvQVc3cWR4elBxS0g0V2FRMDdPcWxaSVNQR1dRPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.5 跟踪、缓存和上传并添加注释

# 4 实验总结

git作为版本控制工具在软件开发方面有着极大的用途。在短暂的使用中可以看到两个特点：

> ### (1) 每一次的文件变化都会留下记录和快照，便于回滚
>
> 可以看到在图3.1中左上方commit栏中13条记录。这是在熟悉git过程中对仓库中文件进行上传和删除操作留下的记录。同时可以看到被改动的文件内容，包括已经被删除的代码文件。这便于在开发过程中恢复到上一个可用状态，即进行回滚。
>
> ![](http://imglf2.nosdn.127.net/img/ekx2Wk55b0tGRUJrWm5kQ1RSWUJIVW84OEIyWTJUMFJvZnpqb25rNnNYSVBWWWJ0RHNBUG9BPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)
>
> 图4.1 commit
>
> ![](http://imglf1.nosdn.127.net/img/ekx2Wk55b0tGRUJrWm5kQ1RSWUJIZlJacUtVM00xeDgvZU1DSmVtcmJIaGlUbVlJQm8rS2hBPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)
>
> 图4.2 删除操作的记录快照
>
>### (2) 可以多人操作后进行合并，便于团队合作
>
>在测试移动文件中进行了网页操作，导致了本地与网页不同步，于是自动进行了合并操作。这对于团队合作是很重要的。

这两点决定了无论是小规模的个人开发还是大型的团队项目，git都成为了不可或缺的工具