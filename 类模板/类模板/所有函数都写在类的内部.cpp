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
	Father(const Father& that)/*���캯������*/
	{
		this->m_t = that.m_t;
	}
	void PrintNum()
	{
		cout << this->m_t << endl;
	}
	/*����һԪ�����------>  !a  -a  ++a  a++  a--*/
	/*a++(ǰ�������)*/
	Father& operator++()
	{
		this->m_t++;
		return *this;
	};
	/*���������  ++a*/
	Father operator++(int num)
	{
		Father temp = *this;
		this->m_t++;
		return temp;/*�ֲ����������� ֻ�ܿ���*/
	}
	/*����+˫Ŀ�����*/
	Father operator-(const Father& that)
	{
		return Father(this->m_t + that.m_t);
	}
	/*����=�����*/
	Father& operator=(const Father& that)/*ȷ����ͨ��that�ı�ԭ��father�����ֵ*/
	{
		this->m_t = that.m_t;
		return *this;
	}
	/*��ϵ����������� == >  <  !=*/
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
/*��*����Ϊȫ�ֺ���*/
Father operator*(Father& f1, Father& f2)/*f1*f2*/
{
	return Father(f1.m_t*f2.m_t);
}
/*���������Ϊȫ�ֺ����������ĸ�������������ĸ����������������������������Ϊ��Ա���� �����ĸ����������������Ŀ-1*/
/*�ض���<<�����*/

/*������������������*/
/*C������ʹ��������ȡ�����>>�Լ�������<<����������������������������õ��������ͣ���
���ǿ�������>>����<<����������������Զ�����������*/
ostream& operator<<(ostream& out, Father& that)
{
	out << "�ߴ磺" << that.m_t << endl;
	return out;
}
/*�������������*/
istream& operator>>(istream& in, Father& that)
{
	string temp;
	in >> temp;/*string�����ṩ����ȡ��v�����������*/

}

/*�����ⶨ�庯��Ҫָ������ ͬʱ������ģ��Ĳ���������*/
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
	Father&& father_3 = father_1 + father_2;/*��ʱ������ֵ*/
	father_3.Print();
	return 0;
}