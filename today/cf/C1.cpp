#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+10;

int n, p;
int pre[256];
int col[maxN];
bool dye[256];

void init()
{
	iota(pre, pre+256, 0);
}

int find(int x) 
{
	return pre[x]==x ? pre[x] : pre[x]=find(pre[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	pre[b] = a;
}

int main()
{
	init();
	
	cin >> n >> p;
	for (int i=0; i<n; ++i) {
		cin >> col[i];
	} 
	
	for (int i=0; i<n; ++i) {
		int st = find(col[i]);
		if (!dye[col[i]]) {
			int bst = max(col[i]-p+1, 0);
			while (bst <= col[i]) {
				int hhead = find(bst);
				if (col[i]-hhead+1<=p) {
					for (int k=hhead; k<=col[i]; ++k) {
						merge(hhead, k);
						dye[k] = true;
					}
					col[i] = hhead;
					break;
				}
				++bst;
			}
		}
		else col[i] = st;
	}
	
	for (int i=0; i<n; ++i) {
		cout << col[i] << ' ';
	}
	cout << endl;
}
