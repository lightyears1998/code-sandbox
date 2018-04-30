#include <bits/stdc++.h> 
using namespace std;

// 上次那个EOF的问题，我试了一下，
// 感觉更好的策略是在输入流尝试读取数据之后检查输入流的错误位
// 也可以直接使用 while (file >> number)，读取完所有有效数据之后循环就会终止 

int main()
{
	fstream file("in.txt");
	
	int n;
	while (!file.eof()) {
		file >> n;
		if (!file.eof()) 
			cout << n << ' ';
	} 
	cout << endl;
}
