#include <bits/stdc++.h>
using namespace std;

int main()
{
	srand(time(0));
	freopen("in.txt", "w", stdout);
	
	cout << 200000 << endl;
	for (int i=0; i<200000; ++i)
	{
		cout << rand()*rand() << ' ';
	}
	cout << endl;
}
