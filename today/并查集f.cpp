#include <cstdio>
#include <iostream>
using namespace std;

const int good = 1, evil = -1, normal = 0;

int n, p1, p2;
int exp;
vector<int> list;
struct word
{
	int x, y; bool is;
} words[1010];

int st[1010];
int cnt1, cnt2;

void init()
{
	exp = 0; list.clear();
	memset(words, 0, sizeof(words));
	memset(st, 0, sizeof(st)); 
	cnt1 = cnt2 = 0;
}

void merge(int x, int diff)
{
	if (diff == good) ++cnt1;
	if (diff == evil) ++cnt2;
	if (st[x] == good) --cnt1;
	if (st[x] == evil) --cnt2;
	st[x] = diff;
}

void judge(int now = 0)
{
	if (exp > 1) return;
	if (now == n) {
		++exp;
		if (exp == 1) for (int i = 1; i <= n; ++i) if (fa[i] == h1) list.push_back(i);
		return;
	}
	
}

int main()
{
	while (scanf("%d%d%d", &n, &p1, &p2) == 3)
	{
		init();
		
		for (int i = 0; i < n; ++i)
		{
			char buf[10]; scanf("%d%d%s", words[i].x, words[i].y, buf);
			words[i].is = buf[0] == 'y';
		}
		
		judge();
		if (exp != 1) puts("no");
		else
		{
			for (unsigned i = 0; i < list.size(); ++i) printf("%d\n", list[i]);
			puts("end");
		}
	}
}

