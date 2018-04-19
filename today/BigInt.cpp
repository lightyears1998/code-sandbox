#include <bits/stdc++.h>
using namespace std;

struct BigInt
{
	int v[1010], d; // 各位数值和长度 
	
	BigInt() {
		memset(v, 0, sizeof(v));
		d = 0;
	}
	
	BigInt operator +(const BigInt b) const {
		BigInt rslt;
		int ent = 0;
		for (int i=0; i<=d||i<=b.d||ent; ++i) {
			int l = i<=d ? v[i] : 0;
			int r = i<=b.d ? b.v[i] : 0;
			int sum = l+r+ent;
			ent = sum/10;
			sum = sum%10;
			rslt.v[d=i]=sum;
		}
		return rslt;
	}
	
	BigInt operator -(const BigInt b) const {
		BigInt rlst; 
		int ent = 0; 
	} 
	
	void print() {
		for (int i=d; i>=0; --i) {
			printf("%d", v[i]);
		}
	}
}

int main()
{
	
}
