#include<iostream>
#include<string>
using namespace std;
 
class Employee 
{
public:
	Employee()
	{
		name = '\0'; 
		number = 0;
	}
	void input()
	{
		cout << "请输入基本员工信息：" << endl;
		cin >> name >> number >> basicSalary;
	}
	void print()
	{
		cout << "姓名：" << name << '\t' << "编号:" << number << '\t' << "一般员工月薪：" << basicSalary << endl;
	}
protected:
	string name;
	int number;
	double basicSalary;
};

class Salesman :public Employee
{
public:
	Salesman()
	{
		sales = 0;
	}
	Salesman(const Employee &em) : Employee(em)  // 利用Employee的复制构造函数初始化Salesman中继承自Employee的数据成员，也就是basicSalary 
	{
		sales = 0;
	}
	void input()
	{
		cout << "请输入销售员工信息：" << endl;
		cin >> name >> number ;
		cout << "请输入本月个人销售额：";
		cin >> sales;
	}
	void pay()
	{
		salary = basicSalary + sales * commrate;
	}
	void print()
	{
		cout << "姓名：" << name << '\t' << "编号:" << number << '\t' << "销售员工月薪：" << salary << endl;
	}
protected:
	double salary;
	double sales;
	static double commrate;
};

double Salesman::commrate = 0.005;

class Salesmanager :public Salesman
{
public:
	Salesmanager()
	{
		jobSalary = 0;
	}
	Salesmanager(const Salesman &sm) : Salesman(sm)  // 同上 
	{
		jobSalary = 0;
	}
	void input()
	{
		cout << "请输入销售经理的信息：" << endl;
		cin >> name >> number ;
		cout << "销售经理的岗位工资：" << endl;
		cin >> JSsales;
	}
	void pay()
	{
		jobSalary = basicSalary + JSsales + sales * commrate;
	}
	void print()
	{
		cout << "姓名：" << name << '\t' << "编号:" << number << '\t' << "销售经理月薪：" << salary << endl;
	}
protected:
	double JSsales;
	double jobSalary;
};

int main()
{
	// A, B, C是相互独立的对象， 
	// 尽管Salesman这类对象继承自Employee这类对象，但是A与B是独立的对象，彼此的数据之间没有直接的联系。
	// 也就是，A的数据修改不会影响B，就像对A1的修改不会影响A2一样。 
	// 所以需要手动传递参数，参数的传递可以通过有参构造函数来解决。 
	
	Employee A;
	A.input();
	A.print();
	Salesman B(A);  // 在A数据的基础上创建B 
	B.input();
	B.pay();
	B.print();
	Salesmanager C(B);  // 在B数据的基础上创建C 
	C.input();
	C.pay();
	C.print();
	system("pause");
}
