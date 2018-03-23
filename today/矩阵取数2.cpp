#include <bits/stdc++.h>
using namespace std;

// Important�� 
// ����������⣬һ��Ҫ����������������λ��!
// ������bug����ʮ�����࡭��  
// ��һ�������������İ취��
// ���ǵ�����ľ����Ƿ���ʱ�������󲹳��Ϊ����
// ���öԳ��ԣ���ʹ�����Ӧ��ϵ�������յĽ��Ҳ����ȷ�� 
const int maxN = 250;

int n, m;
int bonus[maxN][maxN];
int dp[maxN*2][maxN][maxN]; 

void dump()
{
	for (int s=1; s<= m+n-1; ++s)
	for (int i=1; i<=m; ++i) {
		for (int j=1; j<=m; ++j) {
			cout << dp[s][i][j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	scanf("%d%d", &m, &n);
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			scanf("%d", &bonus[i][j]);
			
	// m = max(m, n); n = max(m, n); // �������õ�С���� 
	int step = m+n-1;
	for (int s=1; s<=step; ++s) 
	{
		for (int x1=s; x1>0; --x1) 
		{
			int y1=s+1-x1;
			if (x1>m || y1>n) continue;
			
			for (int x2=s; x2>0; --x2) 
			{
				int y2=s+1-x2;
				if (x2>m || y2>n) continue;
				
				dp[s][x1][x2] = max(dp[s][x1][x2], dp[s-1][x1][x2]);
				dp[s][x1][x2] = max(dp[s][x1][x2], dp[s-1][x1-1][x2]);
				dp[s][x1][x2] = max(dp[s][x1][x2], dp[s-1][x1][x2-1]);
				dp[s][x1][x2] = max(dp[s][x1][x2], dp[s-1][x1-1][x2-1]);
				
				int extra = bonus[y1][x1]; // �˴�������������ȡ�� 
				if (x1 != x2) extra += bonus[y2][x2];
				dp[s][x1][x2] += extra;
 			}
		}
	}
	printf("%d\n", dp[step][m][m]);
}
