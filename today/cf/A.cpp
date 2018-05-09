#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

int main()
{
	string s; cin >> s;
	int cntO = 0, cnt_ = 0;
	for (char ch : s) {
		if (ch == 'o') ++cntO;
		if (ch == '-') ++cnt_;
	}
	
	if (cntO == 1) {
		cout << "NO" << endl;
		return 0;
	}
	if (cntO == 0 || cnt_ == 0 || cntO%cnt_ == 0 || cnt_%cntO == 0) {
		cout << "YES" << endl; 
	}
	else cout << "NO" << endl;
}
