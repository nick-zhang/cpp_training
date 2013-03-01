#Engineering C++ Training

下面是课程大纲和设计时的几点考虑.

* 培训通常以问题来驱动的, 但C++ Gotchas 太多(Effective 55, More Effective 35, Exceptional 40, More Exceptional 47, Exceptional C++ Style 40, C++ Gotchas 99, C++ Coding Standard 101), 但都是几条有限的规则排列组合产生的. 为了在短时间内讲清楚复杂的问题, 我们把注意力放在基础的规则上. 所有问题都由它们排列组合产生或解决
* 对于从托管平台转向native应用的开发者来说, 最大的问题是健壮性. 以前平台帮忙处理的一些问题现在要自己处理了, 处理不好整个进程都会crash. 因此如何写出健壮的C++代码是首先要考虑的
* C++被诟病的是开发效率, 但C++的开发效率并不差, 如果深入理解并合理利用其语法特性的话. 因此继健壮性之后, 第二优先级的就是开发效率
* C++的短板在于大规模应用中的依赖管理, 即物理设计. 这个是重中之重
* C++被津津乐道的是运行效率, 但不是你用了C++, 运行效率就会直接提升. 常用的性能调优原则依然适用, 同时你要了解编译器都有哪些优化, 作为程序员, 你要如何写代码才能是编译器的优化发挥作用

因此, 课程大纲分四部分, 如下:

###健壮性

* ####对象生命周期管理
* ####资源管理
* ####异常安全
* ####const应用
* ####参数传递机制
* ####Sequence Point
* ####了解Unspecified 和 Undefined 陷阱

###开发效率

* ####模板, 泛型编程与模板元编程
* ####标准模板库 (STL)
* ####标准库 (Non STL Part)

###运行效率

* ####inline的应用与陷阱
* ####Return Value Optimization
* ####Prefix and Postfix Increment
* ####Temporaries 临时对象
* ####Understand Containers 了解标准容器和算法的性能约束

###依赖管理

* ####编译模型
* ####头文件最佳实践
* ####PIMPL模式
* ####可见性管理 



