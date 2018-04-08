#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Date {
	int day, month, year;

	Date() = default;
	Date(int d, int m, int y) {
		day = d, month = m, year = y;
	}
	void show() {
		ios::fmtflags old(cout.flags());
		cout.fill('-');
		cout << setw(4) << year << '-' << setw(2) << month << '-' << setw(2) << day;
		cout.flags(old);
	}
};

struct Book {
	string Name;
	Date BorrowDate, ReturnDate;

	Book() = default;
	Book(string name, Date bdate, Date rdate) {
		Name = name;
		BorrowDate = bdate, ReturnDate = rdate;
	} 
};

int main()
{
	Date a(1, 2, 3);
	a.show();

	cout << endl;
	int i = 12;
	cout << setw(12) <<  i << endl;
}