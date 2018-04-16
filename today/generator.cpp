#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifdef LOCAL
	freopen("data.txt", "w", stdout);
	#endif
	
	const int limit = 1e4;
	for (int i=0; i<limit; ++i)
		cout << (rand()%2?-1:1)*(long long)rand()*rand()*rand()*rand() << endl; 
}
