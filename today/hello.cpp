#include <bits/stdc++.h>
using namespace std;

int num[100010];

int main()
{
    int n; cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> num[i];
    }
    for (int i=0, j=n-1; i<=j; ) {
    	cout << num[i] << endl, ++i;
    	if (i<j) cout << num[j] << endl, --j;
    	if (i<j) cout << num[j] << endl, --j;
    	if (i<j) cout << num[i] << endl, ++i;
	}
}
