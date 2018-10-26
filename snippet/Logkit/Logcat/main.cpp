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
	cat.I("����һ�����ĵı�ǩ", "����һ������Ķ԰ס�");
	cat.I(tag, "Function normally.");
}