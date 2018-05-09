#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

stack<LL> s;
vector<LL> v;
unordered_map<int, pii> dp;

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	int n; scanf("%d", &n);

	v.resize(n + 5);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &v[i]);
	}

	for (int i = 1; i <= n; i++) {
	    dp[v[i]], dp[v[i] - 1];
		dp[v[i]].first = dp[v[i] - 1].first + 1;
		dp[v[i]].second = i;
	}
	
	int idx = 1;
	for (int i = 2; i <= n; i++) {
		dp[v[idx]], dp[v[i]];
		if (dp[v[idx]].first < dp[v[i]].first) {
			idx = i;
		}
	}

	printf("%lld\n", dp[v[idx]].first);

	LL now = v[idx]; int cnt = dp[v[idx]].first; idx = n;
	while (cnt > 0){
		while (v[idx] != now) --idx;
		s.push(idx); --now; --cnt;
	}
	while (!s.empty()) {
		printf("%lld ", s.top());
		s.pop();
	}
	printf("\n");
}
