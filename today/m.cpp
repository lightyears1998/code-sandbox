#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL ans;

int main()
{
	LL d, k, a, b, t;
	while (scanf("%lld%lld%lld%lld%lld", &d, &k, &a, &b, &t) == 5)
	{
		if (d <= k)
			ans = d*a;
		else 
		{
			ans = (d/k*k)*a+(d/k-1)*t;
			ans += min((d%k)*a+t, (d%k)*b);
		}
		printf("%lld\n", ans);
	}
}
