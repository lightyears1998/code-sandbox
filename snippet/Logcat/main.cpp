#include "logcat.h"

#include <afxwin.h>
#include <iostream>


int main()
{
	CLogcat cat;
	std::cout << cat.GetLogFilePath();
}