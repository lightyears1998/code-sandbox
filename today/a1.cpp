#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int maxN = 1e5+10;

int tail;
priority_queue<int> team;
priority_queue<int, vector<int>, greater<int>> room[maxN];
int nxt[maxN];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) {
		int ths; scanf("%d", &ths);
		team.push(ths);
	}
	for (int i=0; i<m; ++i) {
		int rm, pc; scanf("%d%d", &rm, &pc);
		room[rm].push(pc);
		tail = max(tail, rm);
	}
	
	nxt[tail] = -1;
	for (int i=tail-1; i>=0; --i) {
		nxt[i] = tail;
		if (room[i].size()) {
			tail = i;
		}
	}
	
	LL ans = 0;
	while (team.size()) {
		int now = team.top(); team.pop();
		
		int bst = -1, idx = -1, back=nxt[now-1];
		for (int i=nxt[now-1]; i!=-1; back=i, i=nxt[i]) {	
			if (room[i].size()) {
				if (bst == -1 || bst > room[i].top()) {
					bst = room[i].top(); idx = i;
				}
			}
			else nxt[back] = nxt[i];
		}
		
		if (bst == -1) {
			team.push(now); break;
		}
		else {
			ans += room[idx].top(); room[idx].pop();
		}
	}
	
	if (team.size() == 0) 
		printf("%lld\n", ans);
	else puts("-1");
}
