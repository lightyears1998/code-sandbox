#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in.txt", "w", stdout);
	for (int i=0; i<100; ++i)
	{
		cout << rand()*rand()%1000000 << ' ' << rand()*rand()%1000000 << ' '
		     << rand()*rand()%1000000 << ' ' << rand()*rand()%1000000000 << endl;
	}
}
