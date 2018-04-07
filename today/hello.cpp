#include <bits/stdc++.h>
using namespace std;

const int maxN = 300300;

string str[maxN];

bool cmp(string &L, string &R, int len)
{
    if (len == 0) return true;
    for (int i=0; i<len; ++i) {
        if (L[L.length()-len+i] != R[i])
            return false;
    }
    return true;
}


int query(int l, int r)
{
    string &L = str[l], &R = str[r];
    int len = min(L.length(), R.length());
    while (!cmp(L, R, len)) --len;
    return len;
}

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif 
	
    int n; cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> str[i];
    }
    
    int q; cin >> q;
    while (q--)
    {
        int l, r; cin >> l >> r;
        cout << query(l-1, r-1) << endl;
    }
}
