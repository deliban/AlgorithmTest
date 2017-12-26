#include "MyTest.h"
#include <iostream>
using namespace std;

/**
* @brief  快速求取2为底的对数的方法.
* @note   输入须为整形.
* @param  x:
* @retval
**/
int FastLog2(int x)
{
	float fx;
	unsigned long ix, exp;
	fx = (float)x;
	//ix = *(unsigned long*)&fx; 与下面表达式一样
	ix = (unsigned long&)fx;
	exp = (ix >> 23) & 0xFF;
	return exp - 127;
}
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

