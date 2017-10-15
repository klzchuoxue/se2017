# 1 实验内容

改写实验2中的程序，将其改为模块化编写的程序，并要求用链表实现。要求具有扩展性，各模块间互相独立，实现各模块间高内聚，低耦合。

# 2 实验步骤

(1) 设计程序的各部分；

(2) 确定各部分的实现方式；

(3) 完成各部分的编写；

(4) 对程序进行测试。

# 3 实验内容

## 3.1 设计程序的各部分

在第三次实验中我使用了面向对象的方法，为此使用了c++语言。但c语言是不支持面向对象的。于是我们改变思路，使用结构体体存储函数指针的方式实现可扩展性。

类似第三次实验，将程序分为三个部分：一是对各个命令的处理，二是对于命令的命名和调用，三是程序的逻辑和交互。三个部分之间耦合性极低，可以独立修改某一部分而对另外的两个部分只做极少且明显的修改。

各部分之间低耦合，高内聚。可扩展性极强。

![](http://imglf5.nosdn.127.net/img/ekx2Wk55b0tGRUNHY2JzY2ErWnFmMHgwUmwrR1FsSTluYStwcjB1T3hRb1drM1RpMHV3L1J3PT0.png?imageView&thumbnail=1779y480&type=jpg&quality=96&stripmeta=0&type=jpg)

图3.1 各部分示意图

## 3.2 确定各部分的实现方式；

### 3.2.1 对各个命令的处理

在本程序中，可扩展性的要求主要体现在命令和相对应的功能的扩展上。这里采用结构体体存储函数指针的方式来实现。在接口体内规定函数原型。在需要添加命令时添加它的相应的与接口结构相符合的函数。

### 3.2.2 对命令的定义和调用

这里使用到了链表。

其中:
1. 命令的定义可以在链表生成时进行，链表存储字符串和相对应的处理函数。
2. 命令的调用也同样使用链表来实现。编写findNode遍历链表，若没找到则显示空值，否则返回与输入命令相符合的结点。这就实现了命令的调用；

### 3.2.3 程序的逻辑与交互

在前两个部分已经做完的情况下，我们已经知道不需要再关心命令的实现细节，而注重于程序的逻辑和交互。本程序比较简单，这一部分的逻辑只有：提示输入->输入->对输入进行处理三部分。

1. 提示输入和输入分别使用printf和gets（可能会输入空格等）;
2. 由于c语言不分共有私有，对输入的处理放到第二部分没有太大的意义。直接在输入时进行处理，第二部分得到的是对命令的调用和参数的输入，这一部分除了其主要功能外还有错误处理，即输入了非预定的输入时的错误提示信息。

## 3.3 完成各部分的编写

### 3.3.1 对各个命令的处理

如3.2.1中设计的，设计一个结构体ftn，含有名称和执行函数接口。next参数是为了将结构体构建成链表结构。而执行函数需要另外定义。

![](http://imglf6.nosdn.127.net/img/ekx2Wk55b0tGRUJJbk9RZWxJdGx6TFpqMkZwQ1JXRlhrcVRONXpKcmU5YjBtWUIzbGNEZWxBPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.2(a) 结构体的定义

![](http://imglf6.nosdn.127.net/img/ekx2Wk55b0tGRUJJbk9RZWxJdGx6RDdZcWlsV3BIcnFMTFYrUEp1eW96U0ZQbTJVQTNjZ3ZRPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.2(b) 执行函数的定义

### 3.3.2 对命令的定义和调用

1. 如3.2.2中设计的，在链表生成时进行函数的定义。并利用链表的遍历寻找进行函数的调用。

![](http://imglf4.nosdn.127.net/img/ekx2Wk55b0tGRUJJbk9RZWxJdGx6RVJGd1ZUcWVKVG9JaGt5ZEEzNENYRjJnOUNxUVFzcmNBPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.3(a) 链表的生成和删除

![](http://imglf3.nosdn.127.net/img/ekx2Wk55b0tGRUJJbk9RZWxJdGx6Q3RyVDFuNkR2eUZoUjBRaVBzQytNYVZoTzZtYmFtUnFRPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.3(b) 结点的添加和删除

![](http://imglf4.nosdn.127.net/img/ekx2Wk55b0tGRUJJbk9RZWxJdGx6RUxVaU84QzJrSDhwUUFQeGNaVmtQaUIvSTdjWmYyQmhBPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.3(c) 对结点的查找

![](http://imglf6.nosdn.127.net/img/ekx2Wk55b0tGRUJJbk9RZWxJdGx6RzFQTlVOazc5UDlZRFVXZDduMEwvVGs1WUljUDBEWWNnPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.4 对命令的定义

2. 如3.2.2中设计的，findNode作为主要的调用函数，showEmptyInput和showWrongInput作为错误处理方法。

![](http://imglf3.nosdn.127.net/img/ekx2Wk55b0tGRUJJbk9RZWxJdGx6R01IUFZuVUtwQ0VYWXBxZUlVSXh0T3d1dTFUNVBRSWdRPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.5 对命令的调用

### 3.3.3 程序的逻辑与交互

如图，完成逻辑功能

![](http://imglf3.nosdn.127.net/img/ekx2Wk55b0tGRUJJbk9RZWxJdGx6RzBFbXl4VUFyRHVqK3NVRFRBL1h6WitKRWRjRGdra1FnPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.6 程序的逻辑与交互以及输入的错误处理

## 3.4 对程序进行测试 

输入：
1. 预定义命令

>`com1 para` 
>
>`com2`
>
>`com3`
>
>`-h`
>
>`-help`

![](http://imglf4.nosdn.127.net/img/ekx2Wk55b0tGRUJJbk9RZWxJdGx6TzI0N0F4UGw3WXlSa1lzZDdvZlRtRkhiV2Rld1QzMzdnPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.7(a) 预定义命令结果

2. 缺少参数的预定义命令

>`com1`

![](http://imglf5.nosdn.127.net/img/ekx2Wk55b0tGRUJJbk9RZWxJdGx6Q1hMR3p0VzJUUDR5dlhLK0UvYmJNUitHQTlUQVdkMjN3PT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.7(b) 缺少参数的预定义命令

3. 空命令

>` `(直接回车)

![](http://imglf5.nosdn.127.net/img/ekx2Wk55b0tGRUJJbk9RZWxJdGx6RnViQ0FaZkdJWFNWalNSZGJRTWVjejdNMmVVV1VwZURnPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.7(c) 空命令

4. 非预定义命令

>`test`

![](http://imglf6.nosdn.127.net/img/ekx2Wk55b0tGRUJJbk9RZWxJdGx6RXdFOHc1Vmk5RWswQjBmenFrUFpwVVpzcFpsbGFEOGlBPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.7(d) 非预定义命令

# 4 实验总结

c语言中可以实现和面向对象编程类似的结果，同样高效快捷，但编写复杂，人为参与部分过大，也几乎没有信息隐藏。相对于面向对象编程还是有一定的劣势。
另：代码的有注释版本位于本仓库的se2017/lab4中