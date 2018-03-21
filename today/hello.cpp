#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int maxN = 100;

LL num[maxN];

int lowbit(int x) {
	return x &= -x;
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

int main()
{
	add(num, 1, 100);
	add(num, 2, 1000);
	add(num, 3 , -110);
	add(num, 10, 99);
	cout << get(num, 90) << endl;
}
