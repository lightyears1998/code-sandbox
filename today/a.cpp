#include <bits/stdc++.h>
using namespace std;

const int maxN = 10101010;

int dp[maxN];
int v[maxN], g[maxN], tot; // 第i件物品的价值和重量，物品总数

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		tot = 0;
		
		int n, m;  // 钻石数量，背包容量
		scanf("%d%d", &n, &m);
		
		while (n--) {
			int vi, gi, ai; //　单位钻石价值，单位钻石质量，钻石数量
			scanf("%d%d%d", &vi, &gi, &ai);
			
			// 按二进制分拆物品，转换为0-1背包问题
			int base = 1;
			while (ai >= base) {
				v[tot]=base*vi, g[tot]=base*gi, ai -= base;
				base <<= 1, ++tot;
			}
			if (ai) {
				v[tot]=ai*vi, g[tot]=ai*gi; ++tot;
			}
		}
		
		// 01背包问题的求解思路
		for (int i=0; i<tot; ++i)
		{
			for (int j=m; j>=g[i]; --j)
			{
				dp[j] = max(dp[j], dp[j-g[i]]+v[i]);
			}
		}
		
		printf("%d\n", *max_element(dp, dp+m+1));
	}
}
