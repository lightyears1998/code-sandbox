#include <iostream>

#include <windows.h>

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, PSTR szCmdLine, int nCmdShow)
{
	MessageBox(nullptr, TEXT("Hello, World!"), TEXT("Hello"), 0);
}
