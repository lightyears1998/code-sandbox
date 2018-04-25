#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
 
map<char, int> priority {
	{'~', 9}, {'*', 8}, {'+', 6},
	{'%', 6}, {'>', 4}, {'^', 2},
};  // ������������ȼ� 
// �Ҳ���һЩ���ϣ�û�в鵽��Щ����������ȼ��������ģ�(lll�V�ةV) 
// ����C++����������ȼ�����Щ��������������ǵ����ȼ� 

vector<char> symbols;  // ����������� 

void print(const string&); 
void print(const vector<bool>&, bool);
string convert(const string&);
bool calculate(const string&, const map<char, bool>&);

int main()
{
	int n;
	cin >> n; symbols.resize(n);
	for (int i=0; i<n; ++i) {
		cin >> symbols[i];
	}
	
	string infix_exp; cin >> infix_exp;  // ȡ���������׺���ʽ 
	string postfix_exp = convert(infix_exp);  // ������Ӧ��ǰ׺���ʽ 
	
	print(infix_exp);  // ��ӡ��ͷ 
	
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
		bool rslt = calculate(postfix_exp, mp);
		print(value, rslt);
	}
} 

// �����ֵ���ͷ
void print(const string &expression)
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

// ������׺���ʽ��Ӧ��ǰ׺���ʽ 
string convert(const string &infix_exp)
{
	string postfix_exp;
	stack<char> rslt, oprt;  // �м���ջ��������ջ
	
	for (int i=infix_exp.size()-1; i>=0; --i)
	{
		if (find(symbols.begin(), symbols.end(), infix_exp[i]) != symbols.end()) {
			// �����������м���ջ 
			rslt.push(infix_exp[i]);
		}
		else if (infix_exp[i]=='(' || infix_exp[i]==')')
		{
			if (infix_exp[i] == ')') {
				// ���������м���ջ 
				oprt.push(infix_exp[i]);
			}
			else {
				// ������һ��������֮ǰ�Ĳ������������������ 
				while (oprt.top() != ')') {
					rslt.push(oprt.top());
					oprt.pop();
				}
				oprt.pop();
			}
		}
		else {
			// �������������ȼ���ѡ����� 
			while (!oprt.empty() && oprt.top()!=')' && priority[infix_exp[i]] < priority[oprt.top()]) 
			{
				rslt.push(oprt.top());
				oprt.pop();
			}
			oprt.push(infix_exp[i]);
		}
	}
	
	while (!oprt.empty()) {
		rslt.push(oprt.top());
		oprt.pop();
	}
	
	while (!rslt.empty()) {
		postfix_exp.push_back(rslt.top());
		rslt.pop();
	}
	return postfix_exp;
}

// ���ݸ������ŵ���ټ���ǰ׺���ʽ����� 
bool calculate(const string &exp, const map<char, bool> &mp)
{
	stack<char> stk;
	for (int i=exp.size()-1; i>=0; --i)
	{
		if (find(symbols.begin(), symbols.end(), exp[i]) != symbols.end()) {
			// ������ֱ����ջ
			stk.push(mp.find(exp[i])->second); 
		}
		else {
			// һԪ���㣨ֻ�С�~���� 
			if (exp[i] == '~') {
				bool cur = stk.top(); stk.pop();
				cur = !cur;
				stk.push(cur); continue;
			}
			
			// ��Ԫ����
			bool lhs = stk.top(); stk.pop();
			bool rhs = stk.top(); stk.pop();
			bool rslt; 
			switch (exp[i]) {
				case '*': rslt = lhs && rhs; break; 
				case '+': rslt = lhs || rhs; break;
				case '%': rslt = lhs ^ rhs; break;
				case '>': rslt = ((lhs==rhs)||(lhs<rhs)); break;
				case '^': rslt = !(lhs^rhs); break;
			}
			stk.push(rslt);
		}
	}
	return stk.top();
}

