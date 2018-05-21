#### 重载(overload)

函数参数重载的时候是依据于参数的类型，但是不能靠返回类型来判断。

```
void print(int val) {
	cout << "void print(int val) " << endl;
}

void print(float val) {
	cout << "void print(float val) " << endl;
}

void print(string val) {
	cout << "void print(string val) " << endl;
}

print(1);
float val = 1.1;
print(val);
print("123");

#输出
void print(int val)
void print(float val)
void print(string val)
```

但是，要注意一点加上const的参数和不加const的参数是不可以重载的
```
void print(string val) {
	cout << "void print(string val) " << endl;
}

void print(const string val) {   // 无法通过编译
	cout << "void print(string val) " << endl;
} 
```

对于重载的很多的函数，究竟要调用哪一个？这个过程叫做 “函数匹配” 。

```
void f();
void f(int);
void f(int,int);
void f(double,double=3.14);

f(5.6);   // 执行哪一个函数？
// 答案是：void f(double,double=3.14);

//第一步确定可行函数 void f(int); 和 void f(double,double=3.14); 可行

//第二部确定最优选择 void f(double,double=3.14); 因为它避免了类型转换

（但在重载函数设计的时候，一定要尽量避免出现类型转换的情况，这样很容易出现二义性的错误）

//问题2：
f(5,3.12);  //执行哪一个调用？

//答案：编译器报错，二义性  详见c++ primer 函数重载 /函数匹配 这一部分
```

#### 重载(overload) / 重写(override,也称覆盖) / 重定义(redefine,也称隐藏)

一、重载（overload）

指函数名相同，但是它的参数表列个数或顺序，类型不同。但是不能靠返回类型来判断。

（1）相同的范围（在同一个作用域中） ；

（2）函数名字相同；

（3）参数不同；

（4）virtual 关键字可有可无。

（5）返回值可以不同；

二、重写（也称为覆盖 override）

是指派生类重新定义基类的虚函数，特征是：

（1）不在同一个作用域（分别位于派生类与基类） ；

（2）函数名字相同；

（3）参数相同；

（4）基类函数必须有 virtual 关键字，不能有 static 。

（5）返回值相同（或是协变），否则报错；<—-协变这个概念我也是第一次才知道…

（6）重写函数的访问修饰符可以不同。尽管 virtual 是 private 的，派生类中重写改写为 public,protected 也是可以的

三、重定义（也成隐藏）

（1）不在同一个作用域（分别位于派生类与基类） ；

（2）函数名字相同；

（3）返回值可以不同；

（4）参数不同。此时，不论有无 virtual 关键字，基类的函数将被隐藏（注意别与重载以及覆盖混淆） 。

（5）参数相同，但是基类函数没有 virtual关键字。此时，基类的函数被隐藏（注意别与覆盖混淆） 。

```
#include <iostream>
#include <complex>
using namespace std;

class Base
{
public:
    virtual void a(int x)    {    cout << "Base::a(int)" << endl;      }
    // overload the Base::a(int) function
    virtual void a(double x) {    cout << "Base::a(double)" << endl;   }
    virtual void b(int x)    {    cout << "Base::b(int)" << endl;      }
    void c(int x)            {    cout << "Base::c(int)" << endl;      }
};

class Derived : public Base
{
public:
    // redefine the Base::a() function
    void a(complex<double> x)   {    cout << "Derived::a(complex)" << endl;      }
    // override the Base::b(int) function
    void b(int x)               {    cout << "Derived::b(int)" << endl;          }
    // redefine the Base::c() function
    void c(int x)               {    cout << "Derived::c(int)" << endl;          }
};

int main()
{
    Base b;
    Derived d;
    Base* pb = new Derived;
    // ----------------------------------- //
    b.a(1.0);                              // Base::a(double)
    d.a(1.0);                              // Derived::a(complex)
    pb->a(1.0);                            // Base::a(double), This is redefine the Base::a() function
    // pb->a(complex<double>(1.0, 2.0));   // clear the annotation and have a try
    // ----------------------------------- //
    b.b(10);                               // Base::b(int)
    d.b(10);                               // Derived::b(int)
    pb->b(10);                             // Derived::b(int), This is the virtual function
    // ----------------------------------- //
    delete pb;

    return 0;
}


/*
1.Base类中的第二个函数a是对第一个的重载
2.Derived类中的函数b是对Base类中函数b的重写，即使用了虚函数特性。
3.Derived类中的函数a是对Base泪中函数a的隐藏，即重定义了。
4.pb指针是一个指向Base类型的指针，但是它实际指向了一个Derived的空间，这里对pd调用函数的处理(多态性)取决于是否重写(虚函数特性)了函数，若没有，则依然调用基类。
5.只有在通过基类指针或基类引用 间接指向派生类类型时多态性才会起作用。
6.因为Base类的函数c没有定义为virtual虚函数，所以Derived类的函数c是对Base::c()的重定义。
*/
```

#### union

同一个内存段可以用来存放几种不同类型的成员，但在每一个时刻只能存在其中一种，而不是同时存放几种。也就是说，每一瞬间只有一个成员起作用，其它的成员不起作用，即不是同时都存在和起作用。

```
union test
{
	char mark;
	long num;
	float score;
}a;

int main()
{
	// cout<<a<<endl; // wrong
	a.mark = 'b';
	cout << a.mark << endl; // 输出'b'
	cout << a.num << endl; // 98 字符'b'的ACSII值
	cout << a.score << endl; // 输出错误值

	a.num = 10;
	cout << a.mark << endl; // 输出换行 非常感谢suxin同学的指正
	cout << a.num << endl; // 输出10
	cout << a.score << endl; // 输出错误值

	a.score = 10.0;
	cout << a.mark << endl; // 输出空
	cout << a.num << endl; // 输出错误值
	cout << a.score << endl; // 输出10



	return 0;
}
```

#### 右值引用