#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main()
{
	LL n, m;
	while (scanf("%lld%lld", &n, &m) == 2 && ~n)
	{
		m %= n;
		if (m==0) {
			cout << "POOR Haha" << endl; continue;
		}
		if (m==1) {
			cout << "YES" << endl; continue;
		}
		if (n%m==0) 
			cout << "POOR Haha" << endl;
		else 
			cout << "YES" << endl;
	}
}
