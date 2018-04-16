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
		cout << "���������Ա����Ϣ��" << endl;
		cin >> name >> number >> basicSalary;
	}
	void print()
	{
		cout << "������" << name << '\t' << "���:" << number << '\t' << "һ��Ա����н��" << basicSalary << endl;
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
	Salesman(const Employee &em) : Employee(em)  // ����Employee�ĸ��ƹ��캯����ʼ��Salesman�м̳���Employee�����ݳ�Ա��Ҳ����basicSalary 
	{
		sales = 0;
	}
	void input()
	{
		cout << "����������Ա����Ϣ��" << endl;
		cin >> name >> number ;
		cout << "�����뱾�¸������۶";
		cin >> sales;
	}
	void pay()
	{
		salary = basicSalary + sales * commrate;
	}
	void print()
	{
		cout << "������" << name << '\t' << "���:" << number << '\t' << "����Ա����н��" << salary << endl;
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
	Salesmanager(const Salesman &sm) : Salesman(sm)  // ͬ�� 
	{
		jobSalary = 0;
	}
	void input()
	{
		cout << "���������۾������Ϣ��" << endl;
		cin >> name >> number ;
		cout << "���۾���ĸ�λ���ʣ�" << endl;
		cin >> JSsales;
	}
	void pay()
	{
		jobSalary = basicSalary + JSsales + sales * commrate;
	}
	void print()
	{
		cout << "������" << name << '\t' << "���:" << number << '\t' << "���۾�����н��" << salary << endl;
	}
protected:
	double JSsales;
	double jobSalary;
};

int main()
{
	// A, B, C���໥�����Ķ��� 
	// ����Salesman�������̳���Employee������󣬵���A��B�Ƕ����Ķ��󣬱˴˵�����֮��û��ֱ�ӵ���ϵ��
	// Ҳ���ǣ�A�������޸Ĳ���Ӱ��B�������A1���޸Ĳ���Ӱ��A2һ���� 
	// ������Ҫ�ֶ����ݲ����������Ĵ��ݿ���ͨ���вι��캯��������� 
	
	Employee A;
	A.input();
	A.print();
	Salesman B(A);  // ��A���ݵĻ����ϴ���B 
	B.input();
	B.pay();
	B.print();
	Salesmanager C(B);  // ��B���ݵĻ����ϴ���C 
	C.input();
	C.pay();
	C.print();
	system("pause");
}
