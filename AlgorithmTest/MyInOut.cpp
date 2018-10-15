#include"MyInOut.h"
#include <stdarg.h> //va_list 的头文件是stdarg.h
#include <cstdio>  //vsprintf 在C++中的头文件是cstdio
#include<iostream>
#include<fstream>
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

/**************************************************
Function: MyInOut
Desc:  Sort的测试
Input:
* @param  -
Output:	nullptr
Return:	nullptr
Others:	nullptr
*******************************************************/
void MyInOut(void)
{
	char ch;
	while ((ch = cin.get()) != EOF) //输入一个字符计算一次
	{
		/*my code*/
	}

	fstream myFile;
	myFile.open("d:\\2.txt", ios::app);//或者fstream myFile("d:\\2.txt", ios::app);
	if (!myFile) 
	{
		cout << "Open File Error!" << endl;
	}

}
