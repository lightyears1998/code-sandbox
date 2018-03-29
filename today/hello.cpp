#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
private:
	int hh, mm;
public:
	Time(const int hour = 0, const int minute = 0) {
		hh = hour, mm = minute;
		if (mm >= 60) hh++, mm%=60;
		if (hh >= 24) hh %= 24; 
	}
	
	Time operator +(const Time &t) {
		return Time(hh+t.hh, mm+t.mm);
	}
	
	friend ostream& operator <<(ostream&, const Time);
};

ostream& operator <<(ostream &out, const Time t)
{
	ostream::fmtflags old = out.flags();
	
	out.fill('0'); 
	out << setw(2) << t.hh << ':' << setw(2) << t.mm;
	
	out.flags(old);
	return out;
}

int main()
{
	for (int i : {1, 2, 3, 4, 5, 6, 7, 8, 9})
	{
		Time a(i, rand()), b(rand(), i);
		cout << "Case " << i << ": " << a << " + " << b << " = " << a+b << endl;
	}	 
}
