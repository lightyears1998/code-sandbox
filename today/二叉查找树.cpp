#include <bits/stdc++.h>
using namespace std;

// 不支持重复节点 

const int maxN = 1e8+7;

int tot;
vector<int> cache;

struct {
	int l, r;
	int val;
} node[maxN];

int find(int x)
{
	int cur = 0;
	while (true)
	{
		if (x == node[cur].val) {
			return cur;
		}
		else if (x > node[cur].val) {
			int nxt = node[cur].r;
			if (nxt) {
				cur = nxt;
			}
			else return cur;
		}
		else if (x < node[cur].val) {
			int nxt = node[cur].l;
			if (nxt) {
				cur = nxt;
			}
			else return cur;
		}
	}
	return cur;
}

void insert(int x)
{
	if (tot == 0) {
		node[tot++].val = x;
		return;
	}
	int cur = find(x);
	if (x == node[cur].val) {
		return;
	}
	else if (x < node[cur].val) {
		node[cur].l = ++tot;
		node[tot].val = x;
	}
	else if (x > node[cur].val) {
		node[cur].r = ++tot;
		node[tot].val = x;
	}
}

void midorder(int x = 0)
{
	if (node[x].l) {
		midorder(node[x].l);
	}
	cache.push_back(node[x].val);
	if (node[x].r) {
		midorder(node[x].r);
	}
}

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		insert(rand());
	
	cache.clear();
	midorder();
	
	for (int i : cache)
		cout << i << endl;
} 
