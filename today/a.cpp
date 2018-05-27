#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int maxN = 1e5+10; 

priority_queue<int> team;

struct hotel
{
	int price, room;
	
	bool operator<(const hotel &rhs) const {
		return price < rhs.price;
	}
} hot[maxN];
vector<int> room;

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i=0; i<n; ++i) {
		int cur; scanf("%d", &cur);
		team.push(cur); 
	}
	for (int i=0; i<m; ++i) {
		int rm, pc; scanf("%d%d", &rm, &pc);
		hot[i] = {rm, pc};
	}
	sort(hot, hot+m); int head = -1;
	
	LL ans = 0;
	
	bool ok = true;
	while (team.size()) {
		int now = team.top(); team.pop();
		if (now > int(room.size())) {
			while (head+1<m && now>int(room.size())) {
				room.push_back(hot[++head].room);
				ans += hot[head].price;
			}
		}
		for (vector<int>::iterator it=room.begin(); it != room.end(); ++it)
		{
			--(*it);
			if (*it == 0) {
				room.erase(it);
			}
		}
	}
	
	if (ok) {
		printf("%lld\n", ans);
	}
	else puts("-1");
}
