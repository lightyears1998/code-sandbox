#include <iostream>
using namespace std;

int main()
{
    freopen("ex1.in", "r", stdin);

    double a, b;
    while (cin >> a >> b && a * b)
    {
        cout << 2 * a * b / (a+b) << endl;
    }
}
