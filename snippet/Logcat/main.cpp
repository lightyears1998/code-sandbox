#include "logcat.h"

#include <afxwin.h>
#include <iostream>


int main()
{
	CLogcat cat("log.txt", true);
	cat.V("This is a verbose.");
	cat.D("This is a debug.");
	cat.I("This is an info.");
	cat.W("This is a warn");
	cat.E("This is an error");
}