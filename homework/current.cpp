#include <bits/stdc++.h>
using namespace std;

class Base {
public:
	Base() = default;
	Base(int v) {
		val = v;
	}
protected:
	int val;
};

class Child : public Base {
	Child() = default;  // 可选，让编译器生成无参数的默认构造函数
	Child(const Base &base) {
		val = base.val;
	}

	Child operator =(const Base &base) {
		val = base.val;
		return *this;
	}
};

int main()
{
	Base base;
}