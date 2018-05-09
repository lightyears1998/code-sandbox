#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k; cin >> n >> k;
	
	cout << "YES" << endl;
	if (k % 2 == 0) {
		int mx = k / 2;
		for (int i=0; i<4; ++i) {
			for (int j=0; j<n; ++j) {
				if (i && i+1 != 4 && j && j <= mx) cout << '#';
				else cout << '.';
			}
			cout << endl;
		}
	}
	else {
		for (int i=0; i<n; ++i) cout << '.'; cout << endl;
		if (k > n-2) {
			cout << '.';
			for (int i=1; i<n-1; ++i) cout << '#';
			cout << '.' << endl;
			k -= n-2;
			int mx = k/2;
			for (int j=0; j<n; ++j) {
				if (j && (j <= mx || n-1-j<=mx) && j+1 != n) cout << '#';
				else cout << '.';
			}
			cout << endl;
		}
		else {
			int mx = (k-1)/2;
			for (int i=0; i<n; ++i) {
				if (i && i+1 != n && (i-0<=mx || i==(n-1)/2 || n-1-i<=mx)) {
					cout << '#';
				}
				else cout << '.';
			} cout << endl;
			for (int i=0; i<n; ++i) cout << '.'; cout << endl;
		}
		for (int i=0; i<n; ++i) cout << '.'; cout << endl;
	}
}
