#include <bits/stdc++.h>
using namespace std;

const int maxN = 110; 

#define sif(n) scanf("%d", &n)
#define sfc(n) scanf(" %c", &n) 

int mat[maxN][maxN];

int main()
{
	int t; sfi(t);
	while (t--) {
		int h, w; sfi(h), sfi(w);
		for (int i=0; i<h; ++i) {
			for (int j=0; j<w; ++j) {
				sfc(mat[i][j]);
			}
		}
		
		int ans = 0;
		for (int i=0; i<h; ++i) {
			for (int j=0; j<w; ++j) {
				if (mat[i][j] == 'O') ++ans;
				if (i && mat[i][j] ==  && mat[i-1])
				if (i && mat[i][j] == && mat[i-1])
				if (i && .)
			}
		}
	}
}
