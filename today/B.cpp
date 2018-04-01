#include <bits/stdc++.h>
using namespace std;

string ans[10];

int main()
{
	for (int i=0; i<10; ++i) {
		cout << i << endl;
		getline(cin, ans[i]);
		
		for (unsigned j=0; j<ans[i].size(); ++j) ans[i] = char(tolower(ans[i][j]));
	}
	
	bool normal = false;
	for (string &s : ans)
	{
		if (s == "cool") normal = true;
	}
	
	cout << (normal ? "normal" : "grumpy") << endl;
}
