#include <bits/stdc++.h>
using namespace std;

#define sfi(n) scanf("%d", &n)

int main()
{
	int t; sfi(t);
	while (t--) {
		int pos[6], label[6];
		for (int i=1; i<=5; ++i) {
			int d, b[5]; sfi(d), sfi(b[1]), sfi(b[2]), sfi(b[3]), sfi(b[4]);
			switch (i) {
				case 1: {
					switch (d) {
						case 1: pos[i]=2, label[i]=b[1]; break;
						case 2: pos[i]=2, label[i]=b[2]; break;
						case 3: pos[i]=3, label[i]=b[3]; break;
						case 4: pos[i]=4, label[i]=b[4]; break;
					}
					break;
				}
				case 2: {
					switch (d) {
						case 1: 
							label[i] = 4;
							if (b[1] == 4) pos[i] = 1;
							if (b[2] == 4) pos[i] = 2;
							if (b[3] == 4) pos[i] = 3;
							if (b[4] == 4) pos[i] = 4;
							break;
						case 2: pos[i]=pos[1]; label[i]=b[pos[i]]; break;
						case 3: pos[i]=1, label[i]=b[pos[i]]; break; 
						case 4: break;
					}
					break;
				}
				case 3: {
						switch (d) {
						case 1: break;
						case 2: break;
						case 3: break;
						case 4: break;
					}
					break;
				}
				case 4: {
						switch (d) {
						case 1: break;
						case 2: break;
						case 3: break;
						case 4: break;
					}
					break;
				}
			}
			printf("%d %d\n", pos[i], label[i]);
		}
	} 
}
