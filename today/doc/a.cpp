#include <bits/stdc++.h>
using namespace std;

const int maxN = 55;

char pic[maxN][maxN];

bool check(int x, int y)
{
	bool f, a, c, e; f = a = c = e = false;
	if (pic[x][y] == 'f' || pic[x][y+1] == 'f' || pic[x+1][y] == 'f' || pic[x+1][y+1] == 'f') f = true;
	if (pic[x][y] == 'a' || pic[x][y+1] == 'a' || pic[x+1][y] == 'a' || pic[x+1][y+1] == 'a') a = true;
	if (pic[x][y] == 'c' || pic[x][y+1] == 'c' || pic[x+1][y] == 'c' || pic[x+1][y+1] == 'c') c = true;
	if (pic[x][y] == 'e' || pic[x][y+1] == 'e' || pic[x+1][y] == 'e' || pic[x+1][y+1] == 'e') e = true;
	return f && a && c && e;
}

int main()
{
	int n, m; cin >> n >> m;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			scanf(" %c", &pic[i][j]);
		}
	}
	
	int ans = 0;
	for (int i=1; i<=n; ++i) {
		for (int j=1; j<=m; ++j) {
			if (check(i, j)) ++ans;
		}
	}
	cout << ans << endl;
} 
