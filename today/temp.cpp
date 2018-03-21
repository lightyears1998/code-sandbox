#include <bits/stdc++.h>
using namespace std;

long long num[200050];

int main()
{
	num[1] = 1, num[2] = 2;
	for (int i=3; i<=100000; ++i) {
		num[i] = num[i-1] + num[i-2];
	}
	cout << num[100000] << endl;
} 
