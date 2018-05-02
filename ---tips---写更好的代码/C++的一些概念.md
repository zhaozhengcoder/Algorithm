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