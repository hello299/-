#include <iostream>
using namespace std;

class B
{
public:
	int m_bm;

	B():m_bm(100)
	{
		cout << "B的默认构造函数被执行了" << endl;
		cout << "成员变量的值为m_bm:" << this->m_bm << endl;
	};
	//拷贝构造函数
	B(const B& that) :m_bm(that.m_bm)
	{
		cout << "B的拷贝构造函数被执行了" << endl;
	};
	virtual ~B()
	{
		cout << "类B的析构函数被执行了" << endl;
	}
};

class A
{
public:
	/*定义A的成员 指向B*/
public:
	//默认构造函数 
	//注意此时如何初始化B类的变量m_pb
	A() :m_pb(new B())
	{
		cout << "类A的默认构造函数被执行" << endl;
	};

	//拷贝构造函数
	A(const A& tempA) :m_pb(new B(*tempA.m_pb))
	{
		cout << "类A的拷贝构造函数被执行" << endl;
	};
	virtual ~A()
	{
		cout << "类A的析构函数被执行" << endl;
	};

	//移动构造函数
	A(A && temp_a)/*因为在getA中的return a的a是一个临时变量 这个临时变量不能被修改 当作右值 所以调用了右值引用*/
	{
		m_pb = temp_a.m_pb;//让两个指针指向同一块内存的代码
		
		/*首先将原来的指针置为空在释放*/


		/*旧对象必须先将指针置为空 然后在delete 不然光delete可能把连接的内存同样释放掉*/
		temp_a.m_pb = nullptr;
		delete temp_a.m_pb;/*打断原来的对象a的链子关系*/
		cout << "A的移动构造函数被执行" << endl;
	};
	//拷贝赋值运算符
	A& operator=(const A& that)
	{
		if (this == &that)
		{
			return *this;
		}

		//把别人的内存拷贝到自己的里面
		/*先删除自己的内存
		再把别人的内存对象存储到自己的里面
		返回return *this
		*/
		delete m_pb;
		m_pb = new B(*(that.m_pb));/*调用拷贝构造函数*/
		return *this;
	};
	//移动赋值运算符
	A& operator=(A&& that)noexcept/**/
	{	
		if (this == &that)
		{
			return *this;
		}
		/*先干掉自己的内存
		在用自己的指针 只想别人的内存
		最后return
		*/
		delete m_pb;
		m_pb = that.m_pb;/*指针指向的问题的解释*/
	//斩断原来的指向
		that.m_pb = nullptr;
		delete that.m_pb;
		cout << "类A的移动赋值运算符执行了" << endl;
		return	*this;
	};
	void getInfo()
	{
		cout << (*(this->m_pb)).m_bm<< endl;
	};
private:
	B *m_pb;
};
static A getA()/*static 类型名 函数名（参数列表）*/
{
	A a;
	return a;
};

struct PC
{
	//系统就会构造移动构造函数和移动赋值运算符函数
	int a;
	string str;
};

int main()
{
    //对象移动的概念
	//挑选出无用对象中的有用的部分 进行移动 然后释放对象中无用的部分

	/*移动构造函数与移动赋值运算符函数*/
	//std:move（）强制将左值转换为右值

	/*移动构造函数的展示*/
	//B* p_b_1 = new B();/*调用B的构造函数*/
	//p_b_1->m_bm = 20;
	//B *p_b_2 = new B(*p_b_1);/*调用B 的拷贝构造函数*/ //*p_b_1指向的是o_b_1的对象

	//delete p_b_1, p_b_2;

	//A a_1 = getA();/*调用了一次拷贝构造函数 将临时对象进行拷贝 给了a存放 所以只是调用了一次拷贝构造函数*/
	///*将AgetA中return的a的临时对象的数据 移动给了a_1，调用了移动构造函数*/
	//a_1.getInfo();
	////A a_2(std::move(a_1)/*将左值变成右值，调用移动构造函数*/);

	///*用右值引用来接收右值！可以避免移动构造函数*/
	//A &&a_3(std::move(a_1));/*仅仅调用了一个a_1的默认构造函数*/

	//A &&a = getA();
	///*调用D的构造函数
	//调用B的构造函数
	//调用移动构造函数 
	//调用析构函数
	//
	//*/

	//A a = getA();
	///*A,B的构造函数以及移动拷贝函数*/
	//A a_1;
	//a_1 = a.operator=(a);
	//a_1 = std::move(a);/*调用移动构造赋值运算符*/
	//return 0;


	//合成的移动操作
	/*某些条件下 编译器能合成移动构造函数 和移动赋值运算符函数
	有自己的拷贝构造函数和拷贝赋值运算符 或者自己的析构函数 
	编译器就不会为该类合成移动构造函数 和移动赋值运算符
	所以 有一些类是没有移动构造函数和移动赋值运算符


	如果没有自己的移动构造函数和移动赋值运算符 系统会调用拷贝构造函数和拷贝赋值运算符代替

	只有一个类 没有定义自己的拷贝构造成员 且类的每个非静态成员都可以移动的时候（内置类型可以天然移动 类类型则类要有对应的移动操作相关的操作） 编译器会合成移动构造函数和移动构造运算符
	*/
	PC pc;
	pc.a = 100;
	pc.str = "I LOVE CHINA";
	const char* p_c = pc.str.c_str();
	PC pc_2 = std::move(pc);//导致PC类里面的移动构造函数被执行  srring系统类里面移动构造函数 将pc的I LOVE CHINA 移动到pc_@中
	const char* pc_b = pc_2.str.c_str();

	//总结：尽量给类添加移动构造函数与移动赋值运算符函数 
	/*移动构造函数与移动赋值运算符函数都需要加入noexcept
	指针置空 在进行delete
	nullptr 让被移动对象随时处于被析构的状态
	一个本该调用移动构造函数和移动赋值运算符 会用拷贝代替
	*/



	return 0;
}


