#include <bits/stdc++.h>
using namespace std;

// 不能出现负数
// 构造函数中memset是必须的，因为需要排除前导零 
struct bint
{
	int v[1010];  // 低位在前存放各个位置上的数据
	int d;  // v中最后一位有效数字的下标
	
	bint() {
		memset(v, 0, sizeof(v));
		d = 0;
	}
	
	bint(const char *str, int len) {
		memset(v, 0, sizeof(v)); d = len-1;
		for (int i=0; i<len; ++i) {
			v[i] = str[len-1-i]-'0';
		}
		while (d>0 && v[d]==0) --d;
	}
	
	bint(long long num) {
		memset(v, 0, sizeof(v)); d = 0;
		while (num) {
			v[d++] = num%10;
			num /= 10;
		}
		while (d>0 && v[d]==0) --d;
	}
	
	void print() {
		for (int i=d; i>=0; --i) {
			printf("%d", v[i]);
		}
		putchar('\n');
	}
}; 

bint operator +(const bint &a, const bint &b) {
	bint rslt;
	for (int i=0, ent=0; i<=a.d||i<=b.d||ent; ++i) {
		int l = i<=a.d ? a.v[i] : 0;
		int r = i<=b.d ? b.v[i] : 0;
		int sum = l+r+ent;
		ent = sum/10;
		sum = sum%10;
		rslt.v[rslt.d=i]=sum;
	}
	while (rslt.v[rslt.d]==0 && rslt.d!=0) --rslt.d;
	return rslt;
}
	
bint operator -(const bint &a, const bint &b) {
	bint rslt;
	return rslt;
}

int main()
{
	
}
