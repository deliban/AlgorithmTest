#include "MyTest.h"
#include <iostream>
using namespace std;
void FileFunc()
{
	cout << "File" << endl;
}
void EditFunc()
{
	cout << "Edilt" << endl;
}
void MyTestFunctionPointer(void)
{
	typedef void(funcp)();
	funcp *pfun = FileFunc;
	pfun();
	pfun = EditFunc;
	pfun();

	cout << "another way" << endl;

	typedef void(*funcpX)();
	funcpX pfunX = FileFunc;
	pfunX();
	pfunX = EditFunc;
	pfunX();
}

