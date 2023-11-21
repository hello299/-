#include<iostream>

//编译器并不是把函数模板处理成任意类的模板函数
//编译器从函数模板通过具体类型产生不同的函数
//编译器会对函数模板进行两次编译：：1）在声明的地方对函数模板本身进行编译；2）在调用的地方对参数替换后的代码进行编译

using namespace std;
template<typename T>
void myswap(T a, T b)
{
	T c = a;
	a = b;
	b = c;
	cout << "Hello ,我是数值转换模板函数" << endl;
}
//函数模板机制：两次编译原理====>第一次通过template<typename T>进行词法、语法、句法分析，产生简陋的函数模板
//======>第二次根据main中<int>的具体调用 产生函数模板的原型
void main()
{
	int x = 10, y = 20;
	myswap<int>(x, y);
	char a = 'a', b = 'b';
	myswap<char>(a, b);
}