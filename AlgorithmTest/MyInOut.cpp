#include"MyInOut.h"
#include <stdarg.h> //va_list ��ͷ�ļ���stdarg.h
#include <cstdio>  //vsprintf ��C++�е�ͷ�ļ���cstdio
#include<iostream>
#include<fstream>
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

/**************************************************
Function: MyInOut
Desc:  Sort�Ĳ���
Input:
* @param  -
Output:	nullptr
Return:	nullptr
Others:	nullptr
*******************************************************/
void MyInOut(void)
{
	char ch;
	while ((ch = cin.get()) != EOF) //����һ���ַ�����һ��
	{
		/*my code*/
	}

	fstream myFile;
	myFile.open("d:\\2.txt", ios::app);//����fstream myFile("d:\\2.txt", ios::app);
	if (!myFile) 
	{
		cout << "Open File Error!" << endl;
	}

}
