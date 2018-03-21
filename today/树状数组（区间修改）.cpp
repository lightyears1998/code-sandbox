#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxN = 100010;

LL bit0[maxN], bit1[maxN];

int lowbit(int x) {
	return x &= -x;
}

void init() {
	memset(bit0, 0, sizeof(bit0));
	memset(bit1, 0, sizeof(bit1));
}

void add(LL *bit, int x, LL val) {
	while (x < maxN) {
		bit[x] += val;
		x += lowbit(x);
	}
}

LL get(LL *bit, int x) {
	LL rslt = 0;
	while (x) {
		rslt += bit[x];
		x -= lowbit(x);
	}
	return rslt;
}

void add(int a, int b, LL val) {
	add(bit0, a, val);
	add(bit0, b+1, -val);
	add(bit1, a, -val*a);
	add(bit1, b+1, val*(b+1));
}

LL get(int x) {
	return get(bit0, x)*(x+1) + get(bit1, x);
}

LL sum(int a, int b) {
	return get(b) - get(a-1);
}

int main()
{
	int n, q;
	while (scanf("%d%d", &n, &q) == 2)
	{
		init();
		
		int n, q; scanf("%d%d", &n, &q);
//		for (int i=1; i<=n; ++i) {
//			LL val; scanf("%lld", &val);
//		}
		
		while (q--) {
			char ch; scanf(" %c", &ch);
			if (ch == 'Q') {
				int a, b; scanf("%d%d", &a, &b);
				printf("%lld\n", sum(a, b));
			}
			if (ch == 'C') {
				int a, b; LL c; scanf("%d%d%lld", &a, &b, &c);
				add(a, b, c);
			}
		}
	}
}
