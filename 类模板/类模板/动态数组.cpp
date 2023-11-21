#include<iostream>
#include<string>
using namespace std;
class MotionArray
{
public:
	MotionArray(int size =0);
	MotionArray(MotionArray& that);

	/*β�����Ԫ��*/
	void push_element(char a);

	/*�����±��������*/
	char& operator[](int i)const;

	/*�������鸳ֵ*/
	MotionArray& operator=(const MotionArray& that);
	virtual ~MotionArray();

	/*����ת�������������*/
	/*����ת��������ĺ���ģ��
	operator data_type()
	{
		return xxxx ;//����ֵ�����ͼ�Ϊdata_type������Ҫ�ٴμ��뷵��ֵ��������
	}
	*/
	operator int()
	{
		return this->m_size;
	}/*ת��Ϊint���͵�ת�����ͺ���*/
	operator char*()
	{
		return this->p_str;
	}


	/*���������Լ������*/
	/*ǰ����  ++i*/
	MotionArray& operator++(int i)
	{
		this->m_size++;
		return *this;
	} 
	/*������ d++*/
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
	/*��ֹ��������ֵ*/
	if (/*����ֵ�������ַ��ͬ*/this->p_str == that.p_str)
	{
		cout << "ʵ����������ֵ" << endl;
		return *this;
	}
	else
	{
		/*that���������Ϊ��*/
		if (that.p_str == nullptr)
		{
			delete[] this->p_str;
			this->p_str = nullptr;
			this->m_size = 0;
			return *this;
		};
		/*����Ԫ�ز�Ϊ��*/
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
	/*�Ƿ�Ϊ��һ��Ԫ��*/
	if (this->p_str == nullptr)
	{
		/*������ʱ����ָ����������*/
		char* temp_p = new char[this->m_size + 1];
		/*�����ݸ��Ƶ�������*/
		memcpy(temp_p, this->p_str, sizeof(char)*(this->m_size));
		/*�ͷ�ԭ����ָ������*/
		delete[] this->p_str;
		/*���Ԫ��*/
		temp_p[this->m_size++] = a;
		/*ָ��ת��*/
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
	/*5+"�����Բ���"*/
	string temp;
	is >> temp;
	int pos = temp.find("+", 0);
	that.m_size = stoi(temp.substr(0, pos));
	that.p_str =(char*)temp.substr(pos + 1).c_str();
	return is;
}