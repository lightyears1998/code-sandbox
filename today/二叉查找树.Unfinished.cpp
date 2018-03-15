#include <bits/stdc++.h>
using namespace std;

// Trouble deleting elements.
// How do I manage the nodes of tree?

const int maxN = 1e8+7;

int head, tot;
vector<int> cache;

struct Node {
	int val;
	int l, r, fa;
} node[maxN];

// Clean up.
void init()
{
	tot = 0;
	memset(node, 0, sizeof(node));
}

// Assign new node with father and value.
int assign(int fa, int val) 
{
	Node &cur = node[++tot];
	cur.fa = fa, cur.val = val;
	return tot;
}

// Insert certain value into the tree.
void insert(int x)
{
	if (head == 0) {
		head = assign(0, x);
		return;
	}
	int cur = head;
	while (true)
	{
		if (node[cur].val == x) return;
		if (node[cur].val > x) {
			int nxt = node[cur].l;
			if (!nxt) {
				node[cur].l = assign(cur, x);
				return;
			}
			else cur = nxt;
		}
		else {
			int nxt = node[cur].r;
			if (!nxt) {
				node[cur].r = assign(cur, x);
			}
			else cur = nxt;
		}
	}
}

// Return true when find the specific value in the tree.
bool find(int x)
{
	if (head == 0) return false;
	int cur = head;
	while (true)
	{
		if (x == node[cur].val) return true;
		if (x > node[cur].val) {
			int nxt = node[cur].r;
			if (!nxt) return false;
			cur = nxt;
		} 
		else {
			int nxt = node[cur].l;
			if (!nxt) return false;
			cur = nxt;
		}
	}
}

// Replace destination node with source node.
void replace(int src, int dst)
{
	
}

// Delete certain element from tree.
void remove(int x)
{
	if (head == 0) return;
	
	int cur = head;
	while (true)
	{
		if (x == node[cur].val) {
			break;
		}
		if (x > node[cur].val) {
			int nxt = node[cur].r;
			if (!nxt) return;
			fa = cur, cur = nxt;
		}
		else 
		{
			int nxt = node[cur].l;
			if (!nxt) return;
			fa = cur, cur = nxt;
		}
	}
}

void walk(int rt = head)
{
	if (node[rt].l != 0) walk(node[rt].l);
	cache.push_back(node[rt].val);
	if (node[rt].r != 0) walk(node[rt].r);
}

void show()
{
	int cnt = 0;
	for (int x : cache)
	{
		cout << x;
		++cnt;
		cout << (cnt % 5 ? ' ' : '\n');
	}
	if (cnt % 5) cout << endl;
}

int main()
{
	int n; cin >> n;
	while (n--) insert(rand());
	
	walk();
	show();
} 
