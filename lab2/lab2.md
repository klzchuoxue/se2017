# 1 实验内容

编写一个c程序，在linux环境下编译并运行，功能为处理一个紧接着的命令，如“-help”；

要求：将对命令的处理独立为一个函数，以便日后的扩展，可处理的命令不少于8个，包括help命令

# 2 实验步骤

(1) 确定功能模块和主函数结构；

(2) 确定命令的种类和处理方式；

(3) 完成处理模块的编写；

(4) 对处理模块进行测试 

# 3 实验内容

本实验中只需要对输入的命令进行处理这一功能。

(1) 确定功能模块和主函数结构；

由于只有一个功能，故主函数结构极为简单：输入->处理->结束

![(http://imglf1.nosdn.127.net/img/ekx2Wk55b0tGRUJrWm5kQ1RSWUJIWHo5QjhRUXFpSjc1bmNIZnNtcHdpRmVLZ1BpbnVOUU5RPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.1 主函数代码

(2) 确定命令的种类和处理方式；

由于实验要求中除了“help”命令之外没有明确规定输入的命令，故命令设置及处理如下：

>help命令样式为“-h”或“-help”
>
>处理方法为列出所有有效命令的列表

>其它有效命令为“com1”到“com9”这9个命令；
>
>处理方式为输出“this is”加上命令

>未设定输入统一给出出错提示；

>无输入提示输入命令。

(3) 完成处理模块的编写：

由于输入命令只有一段，故采取最简单的if-else if-else结构，函数名称为menu。

![(http://imglf0.nosdn.127.net/img/ekx2Wk55b0tGRUJrWm5kQ1RSWUJIVW5VM1JUUXI4aWI4M0tVbTdmUDZPazdjWXZNd1g5YkZnPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.3 处理函数代码


(4) 对处理模块进行测试 

输入对四个方面的输入进行了测试，代码

>`./lab2 com1`
>
>`./lab2 com2`
>
>`./lab2 com5`
>
>`./lab2 -h`
>
>`./lab2 `
>
>`./lab2 kes`

![(http://imglf2.nosdn.127.net/img/ekx2Wk55b0tGRUJrWm5kQ1RSWUJIVGJ5bDNmYXhaOSs3azdZemlMZVY0alNnNkRoQkZuSUVnPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.2 本地仓库

(3) 设置git参数：

![(http://imglf2.nosdn.127.net/img/ekx2Wk55b0tGRUJrWm5kQ1RSWUJIVGJ5bDNmYXhaOSs3azdZemlMZVY0alNnNkRoQkZuSUVnPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.3 设置完毕的参数内容

# 4 实验总结

命令行程序可以通过用户在命令行中的输入接收命令。对于用户输入的字符串进行处理是进行任何进一步处理的前提。

对于简单的输入如本程序，if-else结构足以应付。对于更复杂的输入，还需要更复杂的应对方式。