#include <bits/stdc++.h>
using namespace std;
using LL = long long; 

bool judge(LL a, LL b)
{
	if (a > b) swap(a, b);
	LL k = b-a;
	return a == LL(floor(k*(1.0L+sqrt(5.0L))/2.0L));
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		LL a, b; scanf("%lld%lld", &a, &b);
		puts(judge(a, b) ? "B" : "A");
	}
}
