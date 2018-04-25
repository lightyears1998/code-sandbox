#include <iostream>
#include <vector>
#include <map>
using namespace std;

// �����ֵ���ͷ
void print(const vector<char> &symbols, const string &expression)
{
	int length = 0;
	for (char ch : symbols) {
		cout << ch << ' '; length += 2;
	}
	cout << '|' << ' '; length += 2;
	cout << expression << endl; length += expression.size();
	
	while (length--) cout << '-';
	cout << endl;
}

// �����ֵ���е�һ�� 
void print(const vector<bool> &value, bool rslt)
{
	for (bool val : value) {
		cout << (val ? 'T' : 'F') << ' ';
	}
	cout << '|' << ' ';
	cout << (rslt ? 'T' : 'F') << endl;
}

// ���ݸ������ŵ���ټ�����ʽ����٣�������������ȼ� 
bool calculate(const string &exp, const map<char, bool> &mp)
{
	bool rslt = true; bool rev = false;
	char oprt = '*';
	for (unsigned i=0; i<exp.size(); ++i) 
	{
		if (exp[i] == '~') {
			rev = !rev; continue;
		}
		if (mp.find(exp[i]) != mp.end()) {
			bool cur = mp.find(exp[i])->second;
			if (rev) {
				cur = !cur;
				rev = false;
			}
			switch(oprt) {
				case '*': rslt = rslt && cur; break; 
				case '+': rslt = rslt || cur; break;
				case '%': rslt = rslt ^ cur; break;
				case '>': rslt = ((rslt==cur)||(rslt<cur)); break;
				case '^': rslt = !(rslt^cur); break;
			}
			continue;
		}
		else {
			oprt = exp[i]; continue;
		}
	}
	return rslt;
}

int main()
{
	int n; vector<char> symbols;  // ����������������� 
	
	cin >> n; symbols.resize(n);
	for (int i=0; i<n; ++i) {
		cin >> symbols[i];
	}
	
	string expression; cin >> expression;  // ������ʽ 
	
	print(symbols, expression); 
	
	for (int i=(1<<n)-1; i>=0; --i)  // ö�ٿ��ܵķ���ֵ 
	{
		vector<bool> value;
		for (int j=(1<<(n-1)); j; j>>=1) {
			value.push_back(i&j);
		}
		
		map<char, bool> mp;  // ����������ٶ�Ӧ���� 
		for (unsigned i=0; i<symbols.size(); ++i) {
			mp[symbols[i]] = value[i];
		}
		bool rslt = calculate(expression, mp);
		print(value, rslt);
	}
} 
