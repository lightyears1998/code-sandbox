#include <bits/stdc++.h>
using namespace std;

int n; 
char one[15][15];
char two[15][15];

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> one[i][j];
		}
	}
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> two[i][j]; 
		}
	}
	
	bool same = false; 
	if (!same) {
		bool flag = true;
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j)
			if (one[i][j] != two[i][j]) {
				flag = false;
			}
		same = flag;
	}
		
	if (!same) {
		bool flag = true;
		for (int i1=0, j2=n-1; i1<n; ++i1, --j2) {
			for (int j1=0, i2=0; j1<n; ++j1, ++i2) {
				if (one[i1][j1] != two[i2][j2]) {
					flag = false;
				}
			}
		}
		same = flag;	
	}
	
	if (!same) {
		bool flag = true;
		for (int i1=0, i2=n-1; i1<n; ++i1, --i2) {
			for (int j1=0, j2=n-1; j1<n; ++j1, --j2) {
				if (one[i1][j1] != two[i2][j2]) {
					flag = false;
				}
			}
		}
		same = flag;
	}
	
	if (!same) {
		bool flag = true;
		for (int i1=0, j2=0; i1<n; ++i1, ++j2) {
			for (int j1=0, i2=n-1; j1<n; ++j1, --i2) {
				if (one[i1][j1] != two[i2][j2]) {
					flag = false;
				}
			}
		}
		same = flag;
	}
	
	cout << (same ? "Yes" : "No") << endl;
} 
