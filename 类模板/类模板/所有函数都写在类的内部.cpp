#include<iostream>
#include<string>
using namespace std;
class Father
{
public:
	Father(int t);
	void Print();
	Father operator+(/*this*/ Father& that)
	{
		return Father(this->m_t + that.m_t);
	}
	Father(const Father& that)/*构造函数重载*/
	{
		this->m_t = that.m_t;
	}
	void PrintNum()
	{
		cout << this->m_t << endl;
	}
	/*重载一元运算符------>  !a  -a  ++a  a++  a--*/
	/*a++(前置运算符)*/
	Father& operator++()
	{
		this->m_t++;
		return *this;
	};
	/*后置运算符  ++a*/
	Father operator++(int num)
	{
		Father temp = *this;
		this->m_t++;
		return temp;/*局部变量的引用 只能拷贝*/
	}
	/*重载+双目运算符*/
	Father operator-(const Father& that)
	{
		return Father(this->m_t + that.m_t);
	}
	/*重载=运算符*/
	Father& operator=(const Father& that)/*确保不通过that改变原来father对象的值*/
	{
		this->m_t = that.m_t;
		return *this;
	}
	/*关系运算符的重载 == >  <  !=*/
	bool operator== (Father& that)
	{
		if (this->m_t == that.m_t)
		{
			return true;
		}
		else
		{
			return false;
		}
		{

		}
	}
private:
	int m_t;
	friend Father operator*(Father& f1, Father& f2);
	friend ostream& operator<<(ostream& out, Father& that);
};
/*将*重载为全局函数*/
Father operator*(Father& f1, Father& f2)/*f1*f2*/
{
	return Father(f1.m_t*f2.m_t);
}
/*运算符重载为全局函数：参数的个数等于运算符的个数（操作数个数）；运算符重载为成员函数 参数的个数等于运算符的数目-1*/
/*重定义<<运算符*/

/*输入输出运算符的重载*/
/*C语言能使用流来提取运算符>>以及流插入<<运算符来进行输入和输出！！！内置的数据类型！！
我们可以重载>>或者<<运算符来炒作对象自定义数据类型*/
ostream& operator<<(ostream& out, Father& that)
{
	out << "尺寸：" << that.m_t << endl;
	return out;
}
/*重载输入运算符*/
istream& operator>>(istream& in, Father& that)
{
	string temp;
	in >> temp;/*string类中提供了提取六v运算符的重载*/

}

/*在类外定义函数要指定域名 同时加上类模板的参数化条件*/
Father::Father(int t)
{
	this->m_t = t ;
};
void Father::Print()
{
	cout << this->m_t << endl;
};

int main( void)
{
	Father father_1(1), father_2(2);
	Father&& father_3 = father_1 + father_2;/*临时对象右值*/
	father_3.Print();
	return 0;
}