#include <iostream>
using namespace std;

class Imaginary
{
private:
	double x, y;
public:
	Imaginary(double x, double y) {
		this->x = x, this->y = y; 
	}
	friend Imaginary add(const Imaginary &, const Imaginary&);
	friend Imaginary sub(const Imaginary &, const Imaginary&);
	friend Imaginary mul(const Imaginary &, const Imaginary&);
	friend Imaginary div(const Imaginary &, const Imaginary&); 
	static void show(const Imaginary &i) {
		cout << i.x << '+' << i.y << 'i' << endl;
	}
};

Imaginary add(const Imaginary &a, const Imaginary &b) {
	return Imaginary(a.x+b.x, a.y+b.y);
}

Imaginary sub(const Imaginary &a, const Imaginary &b) {
	return Imaginary(a.x-b.x, a.y-b.y);
}

Imaginary mul(const Imaginary &a, const Imaginary &b) {
	return Imaginary(a.x*b.x-a.y*b.y, a.y*b.x+a.x*b.y);
}

Imaginary div(const Imaginary &a, const Imaginary &b) {
	return Imaginary((a.x*b.x+a.y*b.y)/(b.x*b.x+b.y*b.y), (a.y*b.x-a.x*b.y)/(b.x*b.x+b.y*b.y));
}

int main()
{
	Imaginary a(1, 2); Imaginary b(3, 4);
	Imaginary::show(add(a, b));
	Imaginary::show(sub(a, b));
	Imaginary::show(mul(a, b));
	Imaginary::show(div(a, b));
}
