#include <bits/stdc++.h> 
using namespace std;

// �ϴ��Ǹ�EOF�����⣬������һ�£�
// �о����õĲ����������������Զ�ȡ����֮�����������Ĵ���λ
// Ҳ����ֱ��ʹ�� while (file >> number)����ȡ��������Ч����֮��ѭ���ͻ���ֹ 

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
