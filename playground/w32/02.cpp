#include <windows.h>
#include <iostream>
using namespace std;

HANDLE hStdout;
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

int main()
{
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOldColorAttributes;

    GetConsoleScreenBufferInfo(hStdout, &csbiInfo);
    wOldColorAttributes = csbiInfo.wAttributes;

    cout << wOldColorAttributes << endl;
}
