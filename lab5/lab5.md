# 1 实验内容

(1) 检查lab5文件夹中的程序，修正程序运行中quit命令不起作用的bug；

(2) 修改原程序，增强其扩展性。

# 2 实验步骤

(1) 找到原程序的bug并加以修正；

(2) 从condition函数出发增强扩展性

# 3 实验内容

## 3.1 找到原程序的bug并加以修正

> (0) pthread on windows
> 我们知道调试代码最简单的方法就是使用现有的ide进行单步调试。而目前功能最强大的ide是windows上的visual studio。但pthread并不直接支持windows。所以如果希望在windows上使用pthread，可以在此处下载ftp://sourceware.org/pub/pthreads-win32/pthreads-w32-2-9-1-release.zip，解压后得到三个文件夹，第一个Pre-build2里有dll，lib和h文件，将其放在相应的位置即可。在使用时加上#pragma comment(lib, "pthreadVC2.lib")

![](http://imglf3.nosdn.127.net/img/ekx2Wk55b0tGRURXUXNic2I4TnBUb1pmZHFmL2IrRm5HTERVTURLZEJmWXhtQVhPK3dwWmlBPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.1 pthead on windows

(1) 程序的bug

本程序的bug是无法运行预设的quit命令，而其它命令没有问题。

![](http://imglf3.nosdn.127.net/img/ekx2Wk55b0tGRURXUXNic2I4TnBUb1pmZHFmL2IrRm5HTERVTURLZEJmWXhtQVhPK3dwWmlBPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.2 bug效果

单步调试发现，输入quit命令后，在遍历链表进行判断时判断为尾结点则直接结束，并不访问尾结点，结果跳过了存在尾结点中的quit。这个bug出现在本仓库/lab5/linktable.c 的149行，即是被注释部分。第150行是它的修正。

(2) bug的修复

判定为尾结点后必须继续访问尾结点，所以判定为node为尾结点的next时结束，改正方式如图3.2。

![](http://imglf4.nosdn.127.net/img/ekx2Wk55b0tGRURXUXNic2I4TnBUdXVnTXJndGg2aWUwdWJDMHhBT0xvN2huZUJrV1VRenZ3PT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.3 本程序的bug及其修复

## 3.2 增强原搜索接口的扩展性

原先程序中，condition作为callback函数传入用户定义的结点搜索条件，然后使用了全局变量cmd进行字符串比较。在这里我们看到可以增强扩展性的点：为condition函数增加参数变量void* args并舍弃全局变量。

结果如下。

![](http://imglf3.nosdn.127.net/img/ekx2Wk55b0tGRURXUXNic2I4TnBUZ3BOVVg0ME5nci80c1BEdDdRRlVSUnVzT0xYVFZzclV3PT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.4(a) 更改完的接口1

![](http://imglf4.nosdn.127.net/img/ekx2Wk55b0tGRURXUXNic2I4TnBUaVMwaDR2ajJ1QThZTjdFWkFZOHRrRytnZ05ZRzBQWDNRPT0.png?imageView&thumbnail=1872y665&type=jpg&quality=96&stripmeta=0&type=jpg)

图3.4(b) 更改完的接口2

# 4 实验总结

callback方法的好处是，它可以忽略它需要调用的某些函数的实现细节而注重于实现效果，只要提供接口，调用函数只要满足接口即可被调用，无需关心被调用函数的实现。在多人协作和代码维护中，这种方法极大地提高了编程效率，降低了代码量，减少了不同开发人员需要的沟通成本
