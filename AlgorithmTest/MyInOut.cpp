#include"MyInOut.h"
#include <stdarg.h> //va_list 的头文件是stdarg.h
#include <cstdio>  //vsprintf 在C++中的头文件是cstdio
#include<iostream>

using namespace std;
void Mysprintf(char *s, const char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vsprintf(s, fmt, ap);
	//不是使用这个因为这个函数的参数列表只能固定的写出，不能是可变的参数列表，这是和vsprintf的区别
	//sprintf(s, fmt, ap);
	va_end(ap);
	cout << s << endl;
}