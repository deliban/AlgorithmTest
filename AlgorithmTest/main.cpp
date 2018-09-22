/**************************************************
Function:main 
Desc:  Algorithm Test
Input:	nullptr
* @param a -
* @param b -
Output:	nullptr
Return:	nullptr
Others:	nullptr
*******************************************************/
#include<iostream>
#include <stdlib.h>
#include "MyString.h"
#include "MyVector.h"
#include"MyDeque.h"
#include"MyConversion.h"
#include <stdio.h>
#include <vector>
#include<iostream>
#include "HMAC_SHA1.h"
#include "MySort.h"

using namespace std;

void func(char **ptr)
{
	*ptr = NULL;
}

int main(void)
{

	char a = 'a';
	char *ptr = &a;
	func(&ptr);
	cout << ptr << endl;
	cout << a << endl;
	system("pause");
	return 0;
}

