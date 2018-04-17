#include <bits/stdc++.h>
using namespace std;

class Base {
public:
	int b;
	
	virtual void say() {
		cout << "This is base." << endl;
	}
};

class Child : public Base {
public:
	int c;
	
	void say() {
		cout << "This is child." << endl;
	}
}; 

int main()
{
	Child child;
	Base * pbase = &child;
	child.say();
	pbase->say();
	Child *pchild = static_cast<Child*>(pbase);
} 
