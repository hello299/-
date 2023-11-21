// 类模板.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//类模板用于实现类所需要的数据的类型参数化
//类模板在表示如数组，表，图等数据结构显得特别重要，这些结构的表示和算法不受所包含的元素类型的控制。
#include <iostream>
using namespace std;
//单个类
/*class与typename相同*/
template <typename T>
class module_A
{
public:
	module_A(T t)/*含有默认的T类型的参数的构造函数*/
	{
		this->m_t = t;
	};
	T& getT()
	{
		cout << typeid(m_t).name() << endl;
		return m_t;
	};
protected:
	T m_t;
};

/*从模板类派生时候需要具体化模板类*/

/*C++编译器需要知道父类的数据类型  知道父类所占的内存大小 只有数据类型固定下来 才知道如何分配内存*/

/*从模板类派生普通类*/
class Son_module_A:public module_A<int>/*具体化模板类也就是将<>内部填写上具体的类型*/
{
public:
	/*定义子类的构造函数 为父类的构造函数传递参数 这样 才能够不报错：删除的构造函数*/
	Son_module_A(int a, int b) :module_A<int>(a)
	{
		this->m_b = b;
	};
	void PrintSon()
	{
		/*子类只能通过调用父类的接口访问父类的私有成员 */
		/*可以通过在子类的构造函数的成员初始化列表中通过父类对象进行初始化 访问父类私有成员*/
		/*通过在子类成员函数中调用父类的protected和public接口 实现此目的*/
		cout << this->m_b << "是子类的成员的值" << module_A::m_t << "是父类的成员的值" << endl;
	};
private:
	int m_b;
};


/*从模板类派生模板类*/
template<typename T,typename C>
class Son_Template_C:public module_A<T>
{
	/*关注T，与C错位书写的弊端！会使得module_A的类型不能推断*/
public:
	Son_Template_C(C c, T a):module_A<T>(a)
	{
		this->m_c = c;
	}
	void Print()
	{
		cout << "从模板类继承的模板类成员m_c的值为：" << this->m_c << endl;
	}
private:
	T m_c;
};


/*参数 编译器 要求具体的类 所以类模板要有具体的数据类型的参数*/
void PrintTemplate(module_A<int>&/*规定module_A类的具体类型<int>*/ module_a)/*报错：使用模板类需要具体的定义参数列表！参数的具体类型 int，double...*/
{
	cout << module_a.getT() << endl;
}
/*创建module_A这个类，必须具体告诉编译器创建A的类的参数的具体类型----->才能生成相应的内存空间*/

#include <iostream>

int main()
{
	/*创建A类的具体类型*/
	/*需要进行类型具体化----->让模板类生成具体类----->再用具体类定义具体类型的对象*/
	module_A<int> obj_a(100);/*用100的具体的T=int类型的实际参数对module_A的具体对象obj_a进行初始化*/
	int retval = obj_a.getT();
	cout << retval << endl;

	/*类模板做函数参数*/
	PrintTemplate(obj_a);

	/*定义继承类的对象Son_module_A的子类的对象*/
	Son_module_A son(10,20);/*直接这么写报错  无法引用默认构造函数*/
	son.PrintSon();

	/*从模板类继承模板类*/
	Son_Template_C<double,int> son_template_c(10, 20.5);
	son_template_c.Print();
	double& d = son_template_c.getT();
	
	cout << d << endl;
    std::cout << "Hello World!\n";
}

/*！！！注意如果父类重定义了有参数的构造函数 那么子类继承父类的构造函数 必须也要定义子类自己的构造函数 为父类的构造函数传递参数 将父类初始化*/