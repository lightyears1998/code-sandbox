#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+10;

int n, p;
int arr[maxN];

struct color
{
	int val, key, idx;
	
	bool operator< (const color &oth) const {
		return val < oth.val;
	}
} col[maxN];

bool place (const color &lhs, const color &rhs) {
	return lhs.idx < rhs.idx;
}

int main()
{
	
	cin >> n >> p;
	for (int i=0; i<n; ++i) {
		cin >> col[i].val;
		col[i].idx = i;
	}
	// sort(col, col+n);
	
	memset(arr, -1, sizeof(arr));
	for (int i=0; i<n; ++i) {
		int bst = 0;
		for (int j=0; j<p; ++j) {
			if (col[i].val-j >= 0 && arr[col[i].val-j] == -1) {
				++bst;
			} 
			else break;
		}
		if (bst == 0) {
			col[i].key = arr[col[i].val];
		}
		else {
			col[i].key = col[i].val-bst+1;
			for (int k = 0; k<p; ++k) {
				arr[col[i].key+k] = col[i].key;
			}
		}
	}
	
	// sort(col, col+n, place);
	for (int i=0; i<n; ++i) {
		cout << col[i].key << ' ';
	}
	cout << endl;
}
