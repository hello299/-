#include<iostream>
#include<string>
using namespace std;
class MotionArray
{
public:
	MotionArray(int size =0);
	MotionArray(MotionArray& that);

	/*尾部添加元素*/
	void push_element(char a);

	/*重载下标访问数组*/
	char& operator[](int i)const;

	/*用于数组赋值*/
	MotionArray& operator=(const MotionArray& that);
	virtual ~MotionArray();

	/*类型转换运算符的重载*/
	/*类型转换运算符的函数模板
	operator data_type()
	{
		return xxxx ;//返回值的类型即为data_type，不需要再次加入返回值类型声明
	}
	*/
	operator int()
	{
		return this->m_size;
	}/*转换为int类型的转换类型函数*/
	operator char*()
	{
		return this->p_str;
	}


	/*重载自增自减运算符*/
	/*前自增  ++i*/
	MotionArray& operator++(int i)
	{
		this->m_size++;
		return *this;
	} 
	/*后自增 d++*/
	MotionArray& operator++()
	{
		MotionArray temp = *(this);
		this->m_size++;
		return temp;
	}

private:
	int m_size;
	char* p_str;
	friend istream& operator>>(istream& is, MotionArray& that);
};
MotionArray& MotionArray::operator=(const MotionArray& that)
{
	/*防止数组自身赋值*/
	if (/*自身赋值：数组地址相同*/this->p_str == that.p_str)
	{
		cout << "实现数组自身赋值" << endl;
		return *this;
	}
	else
	{
		/*that传入的数组为空*/
		if (that.p_str == nullptr)
		{
			delete[] this->p_str;
			this->p_str = nullptr;
			this->m_size = 0;
			return *this;
		};
		/*数组元素不为零*/
		if (that.m_size != 0)
		{
			this->m_size = that.m_size;
			this->p_str = new char[that.m_size];
			memcpy(this->p_str, that.p_str, sizeof(char)*that.m_size);
			return *this;
		};
	}
}
MotionArray::MotionArray(int size):m_size(size)
{
}
MotionArray::MotionArray(MotionArray& that)
{
	this->m_size = that.m_size;
	this->p_str = new char[that.m_size];
	*(this->p_str) = *(that.p_str);
}
char& MotionArray::operator[](int i)const
{
	return this->p_str[i - 1];
}
void MotionArray::push_element(char a)
{
	/*是否为第一个元素*/
	if (this->p_str == nullptr)
	{
		/*创建临时的新指针存放新数据*/
		char* temp_p = new char[this->m_size + 1];
		/*旧数据复制到新数组*/
		memcpy(temp_p, this->p_str, sizeof(char)*(this->m_size));
		/*释放原来的指向数组*/
		delete[] this->p_str;
		/*添加元素*/
		temp_p[this->m_size++] = a;
		/*指针转换*/
		p_str = temp_p;

	}
	else
	{
		this->p_str = new char[1];
		this->p_str[this->m_size++] = a;

	}
}
MotionArray::~MotionArray()
{
	delete p_str;
}

istream& operator>>(istream& is, MotionArray& that)
{
	/*5+"我是赵博俊"*/
	string temp;
	is >> temp;
	int pos = temp.find("+", 0);
	that.m_size = stoi(temp.substr(0, pos));
	that.p_str =(char*)temp.substr(pos + 1).c_str();
	return is;
}