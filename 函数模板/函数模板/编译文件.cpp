#include<iostream>

//�����������ǰѺ���ģ�崦����������ģ�庯��
//�������Ӻ���ģ��ͨ���������Ͳ�����ͬ�ĺ���
//��������Ժ���ģ��������α��룺��1���������ĵط��Ժ���ģ�屾����б��룻2���ڵ��õĵط��Բ����滻��Ĵ�����б���

using namespace std;
template<typename T>
void myswap(T a, T b)
{
	T c = a;
	a = b;
	b = c;
	cout << "Hello ,������ֵת��ģ�庯��" << endl;
}
//����ģ����ƣ����α���ԭ��====>��һ��ͨ��template<typename T>���дʷ����﷨���䷨������������ª�ĺ���ģ��
//======>�ڶ��θ���main��<int>�ľ������ ��������ģ���ԭ��
void main()
{
	int x = 10, y = 20;
	myswap<int>(x, y);
	char a = 'a', b = 'b';
	myswap<char>(a, b);
}