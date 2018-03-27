#include <bits/stdc++.h>
using namespace std;

const int maxN = 10101010;

int tot;
bool conflict[maxN];

int main()
{
	int n, m;
	
	while (scanf("%d%d", &n, &m) == 2) 
	{
		memset(conflict, 0, sizeof(conflict));
		tot = n;
		
		int pos = 0;
		while (tot) {
			pos = (pos+m) % n;
			if (conflict[pos]) {
				cout << "CF" << endl;
				break;
			}
			else {
				conflict[pos] = true; --tot;
				continue;
			}
		}
		cout << "End" << endl;
	}
}
