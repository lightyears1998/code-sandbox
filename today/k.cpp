#include <bits/stdc++.h>
using namespace std;
using LL = long long;

// Reference: 
// https://blog.csdn.net/keepcoral/article/details/79851129

const int maxN = 40;

int n, x, y; LL sum;
int a[maxN], b[maxN];
map<LL, LL> mp;

void one(LL ta, LL tb, int step, int end)
{
	if (step == end) {
		mp[ta*y-tb*x]++; return;
	}
	
	one(ta, tb, step+1, end);
	one(ta+a[step], tb+b[step], step+1, end);
}

void two(LL ta, LL tb, int step, int end)
{
	if (step == end) {
		sum += mp[-(ta*y-tb*x)]; return;
	} 
	
	two(ta, tb, step+1, end);
	two(ta+a[step], tb+b[step], step+1, end);	
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	int t; scanf("%d", &t);
	while (t--)
	{
		sum = 0;
		mp.clear();
		
		scanf("%d%d%d", &n, &x, &y);
		for (int i=0; i<n; ++i) {
			scanf("%d%d", &a[i], &b[i]);
		}
		
		one(0, 0, 0, n/2);
		two(0, 0, n/2, n);
		printf("%d\n", sum-1);
	}
} 
