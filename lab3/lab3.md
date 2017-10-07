# 1 实验内容

改写实验2中的程序，将其改为模块化编写的程序。要求具有扩展性，各模块间互相独立，实现各模块间高内聚，低耦合。

# 2 实验步骤

(1) 设计程序的各部分；

(2) 确定各部分的实现方式；

(3) 完成各部分的编写；

(4) 对程序进行测试。

# 3 实验内容

## 3.1 设计程序的各部分

模块化编程的最典型方法是面向对象。面向对象方法是将程序分为多个对象并对对象进行操作。对象间互相独立互不干扰。这符合本实验对于程序的要求。

采取面向对象的实现方法，将程序分为三个部分：一是对各个命令的处理，二是对于命令的命名和调用，三是程序的逻辑和交互。三个部分之间耦合性极低，可以独立修改某一部分而对另外的两个部分只做极少且明显的修改。

各部分之间低耦合，高内聚。可扩展性极强。

![](http://imglf5.nosdn.127.net/img/ekx2Wk55b0tGRUNHY2JzY2ErWnFmMHgwUmwrR1FsSTluYStwcjB1T3hRb1drM1RpMHV3L1J3PT0.png?imageView&thumbnail=1779y480&type=jpg&quality=96&stripmeta=0&type=jpg)

图3.1 各部分示意图

## 3.2 确定各部分的实现方式；

### 3.2.1 对各个命令的处理

在本程序中，可扩展性的要求主要体现在命令和相对应的功能的扩展上。这里采用c++的多态机制来实现。以一个含有一个执行函数的虚拟类为父类，每需要增加一个功能则定义一个他的子类并覆盖父类的执行函数。

这样做的好处是：

1. 父类的指针可以指向子类，实现了多态，提供了扩展性；
2. 父类提供了一个接口，而子类必须加以实现。这使得任何调用它们的函数无需关心实际的子类类型而进行统一处理。

### 3.2.2 对命令的定义和调用

这一部分除了其主要功能有命令的定义和命令的调用外还有错误处理，即输入了非预定的输入时的错误提示星系。

其中:
1. 命令的定义可以用unordered_map这一哈希表容器来实现，为每个执行命令的类分配至少一个字符串。这样完成功能的类就被特定字符串定义了；
2. 命令的调用也同样使用unordered_map来实现。通过find方法将输入的字符串与哈希表中的字符串键值进行对比，若没找到则显示错误信息，否则返回包含字符串和类指针的迭代器。并通过迭代器的second属性进行对类中执行函数的调用。这就实现了命令的调用；
3. 另外，对外提供接口void run(string argv) 使外部可以调用。 

### 3.2.3 程序的逻辑与交互

在前两个部分已经做完的情况下，我们已经知道不需要再关心命令的实现细节，而注重于程序的逻辑和交互。本程序比较简单，这一部分的逻辑只有：提示输入->输入->对输入进行处理三部分。

1. 提示输入和输入分别使用cout和getline（可能会输入空格等）;
2. 对输入进行处理则直接调用第二部分给出的接口run。

## 3.3 完成各部分的编写

### 3.3.1 对各个命令的处理

如3.2.1中设计的，以command为父类，类型为虚拟类，定义了执行函数com。从它继承了commandCom1等子类以执行不同的命令。

![](http://imglf4.nosdn.127.net/img/ekx2Wk55b0tGRUNHY2JzY2ErWnFmOHBqYjJNSStpbDE1cTYvUXk0eG16d1oxUEhzK0gvQUJ3PT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.2(a) 类的定义

![](http://imglf4.nosdn.127.net/img/ekx2Wk55b0tGRUNHY2JzY2ErWnFmMGZkT2o1amxGanVvRGo3RmlqTlJpNldsZ3ZtV3ExT1ZnPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.2(b) 类执行函数的实现

### 3.3.2 对命令的定义和调用

1. 如3.2.2中设计的，创立mainClass类，在其生成函数中创建3.3.1中定义的各子类并将其加入哈希表。

![](http://imglf3.nosdn.127.net/img/ekx2Wk55b0tGRUNHY2JzY2ErWnFmNGNNU0p1dFNFM2N4ZzhJVE1XYU1OUzdSUHExUC90ajJBPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.3 mainClass的定义

![](http://imglf4.nosdn.127.net/img/ekx2Wk55b0tGRUNHY2JzY2ErWnFmMGU1S1I0MXYwVzFpcDdkZWxiTWhpWUwyZmZraHhUOC9BPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.4 对命令的定义

2. 如3.2.2中设计的，在mainClass中定义public run作为调用方法和对外接口，showEmptyInput和showWrongInput作为错误处理方法。

![](http://imglf6.nosdn.127.net/img/ekx2Wk55b0tGRUNHY2JzY2ErWnFmN1p0cEFBdDdKdUZMUloyQ09tSlVjOXdObWY3VDVNM3BRPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.5 对命令的调用和错误处理

### 3.3.3 程序的逻辑与交互

如图，完成逻辑功能

![](http://imglf4.nosdn.127.net/img/ekx2Wk55b0tGRUNHY2JzY2ErWnFmODVqRkFHOWFOV2FWd0IxUGQ5aXRmMU5RV1VJT1pFK093PT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.6 程序的逻辑与交互

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

![](http://imglf5.nosdn.127.net/img/ekx2Wk55b0tGRUNHY2JzY2ErWnFmd3NPZWRUOWNYQWl3Q29GUDlJTGVCVHZWME9sNnliQUFBPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.7(a) 预定义命令结果

2. 缺少参数的预定义命令

>`com1`

![](http://imglf4.nosdn.127.net/img/ekx2Wk55b0tGRUNHY2JzY2ErWnFmL2o3MC9yazdtd1ZnWVgwQnBvZlhyNUptT2JTMkJvVk9RPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.7(b) 缺少参数的预定义命令

3. 空命令

>` `(直接回车)

![](http://imglf3.nosdn.127.net/img/ekx2Wk55b0tGRUNHY2JzY2ErWnFmMkx6NHlnQysxSE9Od3p5LzQ1bTJqdU9RVmh0eHpHS0dBPT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.7(c) 空命令

4. 非预定义命令

>`test`

![](http://imglf3.nosdn.127.net/img/ekx2Wk55b0tGRUNHY2JzY2ErWnFmNkRJc29RQ2pjYzRONlVXV0t1NC9seEtRbDJHMU85Nmd3PT0.png?imageView&thumbnail=1680x0&quality=96&stripmeta=0&type=jpg)

图3.7(d) 非预定义命令

# 4 实验总结

面向对象的编程方法所编写的程序，各部分之间的耦合性极低，可扩展性极强，在大型程序开发和维护及多人协作开发时具有无可比拟的优势。我们都应该深入理解这种编程方式并加以灵活运用。

另外
1. unordered\_map是hash\_map的替代。如果使用hash\_map虽然在visual studio中还可以使用但会被报错。而在linux下则无法编译。
2. unordered\_map不是c++标准库的一部分，在linux下编译时需要添加 -std=gnu++11库进行链接编译。