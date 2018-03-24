#include <bits/stdc++.h>

using namespace std;

string des;

int main()
{
    regex reg1(".*([aeiou]{3}|[^aeiou]{3}).*");
    regex reg2(".*[aeiou]+.*");
    regex reg3(".*([^eo])\\1.*");
    while (cin >> des) {
        if (des == "end")
            break;
        if (!regex_match(des, reg1) && regex_match(des, reg2) && !regex_match(des, reg3))
            cout << "<" + des << "> is acceptable." << endl;
        else
            cout << "<" + des << "> is not acceptable." << endl;
    }
    return 0;
}
