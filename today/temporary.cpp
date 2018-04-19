#include <bits/stdc++.h>
using namespace std;

const int maxN = 500500;
char str[maxN];

// 1-based: scanf("%s", str+1);
int solve()
{
	int i = 0, mx = 1; str[0] = '*';
	while (str[i])
	{
		int p = i;
		while (str[i+1] == str[i]) ++i;
		int q = i;  // q之前不可能有更强的回文中心
		
		while (str[p-1]==str[q+1]) --p, ++q;
		mx = max(mx, q-p+1);
		
		++i;
	}
	return mx;
}

int main()
{
	while (scanf("%s", str+1) == 1) {
		printf("%d\n", solve());
	}
}

