#include <iostream>
using namespace std;

class Incomec
{
private:
	double wage, income;
public:
	void setWage(double m) {
		wage = m;
	}
	static void calIncome(Incomec &p) { 
		if (p.wage <= 2000) p.income = p.wage;
		else if (p.wage <= 4000) p.income = p.wage*0.95;
		else if (p.wage <= 7000) p.income = p.wage*0.90;
		else if (p.wage <= 12000) p.income = p.wage*0.75;
		else p.income = p.wage*0.80;
	}
	friend ostream& operator <<(ostream&, Incomec);
};

ostream& operator <<(ostream& out, Incomec ic) {
	out << "职工工资：" << ic.wage << " 税后收入：" << ic.income; 
	return out;
}

int main()
{
	Incomec ia, ib, ic, id, ie;
	
	ia.setWage(1200); ib.setWage(2500);
	ic.setWage(4500); id.setWage(6000);
	ie.setWage(12000);
	
	Incomec::calIncome(ia); Incomec::calIncome(ib);
	Incomec::calIncome(ic); Incomec::calIncome(id); 
	Incomec::calIncome(ie);
	
	cout << ia << endl; cout << ib << endl;
	cout << ic << endl; cout << id << endl;
	cout << ie << endl;
}
