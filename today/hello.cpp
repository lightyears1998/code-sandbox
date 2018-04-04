#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int MOD = 1e9 + 7;

LL ans[50050];

LL split(LL n, LL m)
{
	if (n == m && ~ans[n]) return ans[n];
 	if (n == 1 || m == 1) return 1;
	if (n == m) return ans[n] = (1 + split(n, m - 1)) % MOD;
	if (n < m) return split(n, n);
	return (split(n - m, m) + split(n, m - 1)) % MOD; 
}

LL split(LL n)
{
	return ~ans[n] ? ans[n] : ans[n] = split(n, n);
}

int main()
{
	for (int i = 0; i < 50050; ++i)	ans[i] = -1;
	for (int i = 1; i < 50050; ++i) split(i);
	
	LL n;
	while (scanf("%lld", &n) == 1)
	{
		printf("%lld\n", split(n));
	}
} 
