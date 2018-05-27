#include <bits/stdc++.h>
using namespace std;

int cnt[6];

int main()
{
	int n; scanf("%d", &n);
	while (n--) 
	{
		int cur; scanf("%d", &cur);
		cnt[cur]++;
	}
	
	int ans = 0;
	ans += cnt[5]; cnt[5] = 0;
	ans += cnt[4]; cnt[1] -= min(cnt[1], cnt[4]);
	
	{
		ans += cnt[3]; int dr = min(cnt[2], cnt[3]);
		cnt[2] -= dr; cnt[3] -= dr;
		if (cnt[3]) {
			int dr = min(cnt[3]*2, cnt[1]);
			cnt[1] -= dr;
		}
	}
	
	{
		int gp = cnt[2] / 2; ans += gp;
		cnt[1] -= min(cnt[1], gp);
		if (cnt[2] % 2 == 1) {
			++ans;
			cnt[1] -= min(cnt[1], 3); 
		}
	}
	
	{
		int gp = cnt[1]/5; ans += gp;
		if (cnt[1] % 5 != 0) {
			++ans;
		}
	}
	
	printf("%d\n", ans);
} 
