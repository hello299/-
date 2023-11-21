#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Students
{
	int m_ID;
	char* m_name[20];
};

int main(void)
{
	//vector:是集合或者动态数组 我们可以把若干相同的对象放到里面去！！必同对象
	//vector能把其他对象装进来，也称为容器

	vector<int> v_set;/*表明v_Set里面存储整型数据*/

	/*<nt>：模板，vector本身是个类模板，<int>是类模板的实例化过程*/
	//vector<int>表明：在vector中保存整型信息

	vector<Students> v_stu_set;
	vector<vector<string>> stulist;

	//vector<int & > v_student;//不能定义引用类型的vector

	//定义和初始化vector对象
	vector<string> mystr_1;
	mystr_1.push_back("abcd");/*push_back()函数*/
	mystr_1.push_back("efgh");
	cout << mystr_1[1] << endl;

	//元素拷贝的初始化方式
	vector<string> mystr_2(mystr_1);/*将mystr_1里面的元素拷贝到mystr_2里面*/
	vector<string> mystr_3 = mystr_1;/*与上面的拷贝初始化类型相同*/

	/*c:列表初始化方式，给容器初始化赋值{}*/
	vector<string> mystr_4 = { "Zhao","Bo","Jun" };

	/*创建指定元素的vector 往往用圆括号*/
	vector<int> vec_int(15);/*容量为15的vector，元素的值为-200*/
	vector<string> vec_str(20);
	vector<string> vec_str_1{ "Hello"};
	vector<string> vec_str_2{ 10 };/*将{10}处理成了元素数量<==>vec_str_2是一个10个元素的string类型的vector*/
	vector<string> vec_str_3{ 10,"Hello" };/*创建10个元素 每个元素为字符串hello*/

	vector<int> vec_int_1(10, 1);/*创建10个元素的vector，每个元素为1*/
	vector<int> vec_int_2{ 10,1 };
	/*e)多种初始化方式:()一般表示元素数量，{}表示元素内容*/

	/*判断容器是否为空值*/
	cout<<mystr_1.empty()<<endl;/*返回bool类型*///值为空表示1
	//if (vec_int_1.empty())
	//{
	//	cout << "vec_int_1为空" << endl;
	//}
	//else
	//{
	//	cout << "vec_int_1非为空" << endl;
	//}
	//if (mystr_1.empty())
	//{
	//	cout << "mystr_1为空" << endl; 
	//}
	//else
	//{
	//	cout << "mystr_1为非空" << endl;
	//}
	//mystr_1.push_back("Hello");
	//mystr_1.push_back("ZhaoBoJun");

	//cout << "mystr_1的vector元素的个数为" << mystr_1.size() << endl;
	//mystr_1.clear();
	//cout << "mystr_1的vector尺寸" << mystr_1.size() << endl;

	/*范围for语句的应用*/
	for (auto &var:vec_int_1)
	{
		var *= 2;
	}
	for (auto &var:vec_int_1)
	{
		cout << var << endl;
	}

	return 0;
}