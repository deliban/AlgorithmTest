#include"MyInOut.h"
#include <stdarg.h> //va_list ��ͷ�ļ���stdarg.h
#include <cstdio>  //vsprintf ��C++�е�ͷ�ļ���cstdio
#include<iostream>

using namespace std;
void Mysprintf(char *s, const char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vsprintf(s, fmt, ap);
	//����ʹ�������Ϊ��������Ĳ����б�ֻ�̶ܹ���д���������ǿɱ�Ĳ����б����Ǻ�vsprintf������
	//sprintf(s, fmt, ap);
	va_end(ap);
	cout << s << endl;
}