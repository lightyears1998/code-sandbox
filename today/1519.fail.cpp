// Math - 梯形积分法，是不可能的 

#include <bits/stdc++.h>
using namespace std;

double val(double x) {
	return sin(cos(x));
}

double cal(double a, double b) {
	double cell = (b-a)/13250, ans = 0;
	for (double i=a; i<=b; i+=cell) {
		ans += cell*val(i);
	}
	return abs(ans);
}

int main()
{	
	int t; scanf("%d", &t);
	while (t--) {
		double a, b; scanf("%lf%lf", &a, &b); 
		printf("%.1f\n", cal(a, b));
	}
}
