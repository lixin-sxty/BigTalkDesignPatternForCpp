# 原型模式

原型模式：用原型实例指定创建对象的种类，并且通过拷贝原型创建新的对象

好处在于可以保留对象的当前状态，而且可以避免调用初始构造函数（如果构造函数包括多个复杂参数或执行时间较长时优势明显）。

- 与拷贝构造的区别

二者都是可以产生对象的复制品，原型模式实现的是一个clone接口，能够通过基类指针来复制派生类对象。拷贝构造函数只能实现静态对象类型的复制。

UML图<br>
![factory_method](prototype.png)