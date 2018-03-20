#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxN = 100010;

LL bit0[maxN], bit1[maxN];

int lowbit(int x)
{
	return x &= -x;
}

void init()
{
	memset(bit0, 0, sizeof(bit0));
	memset(bit1, 0, sizeof(bit1));
}

// Sum of [1, x] 
LL get(int x)
{
	
}

// Sum of [a, b]
LL sum(int a, int b)
{
	
}

int main()
{
	int n, q;
	while (scanf("%d%d", &n, &q) == 2)
	{
		
	}
} 
