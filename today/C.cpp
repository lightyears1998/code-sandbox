#include <bits/stdc++.h>
using namespace std;

struct ant
{
	int id, pos, dir;
	bool operator <(const ant &b) const {
		return pos < b.pos;
	}
} a[101000];

int seq[101000];

bool cmp(const ant &a, const ant &b) {
	if (a.pos > b.pos) swap(seq[a.id], seq[b.id]);
	return a.pos < b.pos;
}

int main()
{
	int t; cin >> t;
	for (int kase = 1; kase <= t; ++kase)
	{
		if (kase != 1) cout << endl;
		cout << "Case #" << kase << ":" << endl;
		
		int L, T, n; cin >> L >> T >> n;
		iota(seq, seq+n, 0);
		for (int i=0; i<n; ++i) {
			char ch; cin >> a[i].pos >> ch;
			a[i].id  = i;
			a[i].dir = (ch == 'R' ? 1 : -1); 
		} 
		sort(a, a+n, cmp);
		
		for (int i=0; i<n; ++i) {
			a[i].pos += a[i].dir*T;
		}
		sort(a, a+n);
		
		for (int i=0; i<n; ++i) {
			int tar = seq[i];
			cout << a[tar].pos << ' ';
			
			if (a[tar].pos <= 0 || a[tar].pos >= L) {
				cout << "Fell off" << endl; continue;
			}
			
			bool sp = ((tar>0 && a[tar-1].pos==a[tar].pos) || (tar<n-1 && a[tar+1].pos == a[tar].pos));
			if (sp) cout << "Turning" << endl;
			else cout << (a[tar].dir==1 ? "R" : "L") << endl;
		}
	}
}
