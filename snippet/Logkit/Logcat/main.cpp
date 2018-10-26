#include "logcat.h"

#include <afxwin.h>
#include <iostream>


int main()
{
	Logcat cat("log.txt", true);
	CString tag("Main");
	cat.V(tag, "This is a verbose.");
	cat.D(tag, "This is a debug.");
	cat.I(tag, "This is an info.");
	cat.W(tag, "This is a warn.");
	cat.E(tag, "This is an error.");
	cat.I("这是一个中文的标签", "这是一句的中文对白。");
	cat.I(tag, "Function normally.");
}