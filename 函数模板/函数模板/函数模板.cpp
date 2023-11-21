// 函数模板.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>

using namespace std;

template<typename T>
/*函数模板不存在隐式类型转换*/
/*但是普通函数可以进行隐式类型转换*/
int Max(T&& a, T&& b)
{
	cout << "调用函数模板Max(T&& a, T&& b)" << endl;
	return a > b ? a : b;
}

int Max(int&& a, int&& b)
{
	cout << "调用普通函数Max(int&& a, int&& b)" << endl;
	return a > b ? a : b;
};
/*第一个报错是因为：直接插入2,3为右值 会造成右值引用 所以需要&&来实现*/
int main()
{
	//函数模板与普通函数重载(都符合调用规则
	
	//优先选择普通函数，当参数的类型与普通函数的参数类型相同时
	Max(2, 3);
	//如果显式调用函数模板 需要在函数名称后面加上<>
	Max<>(2, 3);
	int retval = Max('a', 100);/*普通函数可以进行隐式类型转换*/
	cout << retval << endl;
    std::cout << "Hello World!\n";
}

