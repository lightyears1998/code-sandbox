// 扫雷 - 枚举后单调
// Reference - https://blog.csdn.net/Stray_Lambs/article/details/53113676

#incude <bits/stdc++.h>
using namespace std;

const int maxN = 10010;
const int mod  = 100000007;

long long dp[maxN];
int mine[maxN];

char buf[maxN];

int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", buf);
		
		int len = 0;
		for (int i=0; buf[i]; ++i) {
			mine[i+1] = buf[i]-'0';
			++len;
		}
		
		long long ans = 0;
		for (int i=0; i<3; ++i) {
			dp[1]=i;
			dp[2]=mine[] 
		}
	}
} 
