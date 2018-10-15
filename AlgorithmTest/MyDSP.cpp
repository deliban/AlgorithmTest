#include"MyDsp.h"
#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include< string.h>

using namespace std;

typedef union
{
	char ch;
	int data;
}MyUnion;

static union
{
	char c[4];
	unsigned long mylong;

} endian_test = { { 'l', '?', '?', 'b' } };
#define ENDIANNESS ((char)endian_test.mylong)
/**************************************************
Function: void JudgeEndian(void)
Desc:  大小端判断 采用联合体union来判断
Input:
* @param  -
Output:	nullptr
Return:	nullptr
Others:	nullptr
*******************************************************/
void JudgeEndian(void)
{
	MyUnion temp;
	temp.data = 0x12345678;
	if (temp.ch == 0x78)
		cout << "Little-Endian" << endl;
	else
		cout << "Big-Endian" << endl;

	/*Linux操作系统的源码中的判断*/
	if (ENDIANNESS == 'l')
		cout << "Little-Endian" << endl;
	else
		cout << "Big-Endian" << endl;


}

/**************************************************
Function: void JudgeEndian1(void)
Desc:  大小端判断，采用类型转换时截断的方式来判断
Input:
* @param  -
Output:	nullptr
Return:	nullptr
Others:	nullptr
*******************************************************/
void JudgeEndian1(void)
{
	int data = 0x12345678;
	char * p = (char*)&data;

	if (*p == 0x78)
		cout << "Little-Endian" << endl;
	else
		cout << "Big-endian" << endl;
}

char base64_map[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
char base64_decode_map[256] = 
{
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 62, 255, 255, 255, 63, 52, 53, 54, 55, 56, 57, 58, 59, 60,61, 255, 255,
	255, 0, 255, 255, 255, 0,1,  2,3,4,5,6,7,8,9,10,11,12,13,14,
	15,16,17,18,19,20,21,22,23,24,25, 255, 255, 255, 255, 255, 255,26,27,28,
	29,30,31,32,33,34,35,36,7,38,39,40,41,42,43,44,45,46,47,48,
	49,50,51, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 
};

unsigned char test[100] = "testsecret&";
unsigned char test1[100] = "testsecret&";
unsigned char encode[100], decode[100];
unsigned char test2[100] = "Y9eWn4nF8QPh3c4zAFkM/k/u7eA=";

/***********************************************************************
Function:base64_encode                 //函数名字
Desc:    编码                  //函数功能描述
Input:                         //要输入的参数
* @param                       //参数说明
Output:  无                        // 对输出参数的说明。
Return:  无                        // 函数返回值的说明
Others:  无                        // 其它说明；没有就用nullptr表示
**************************************************************************/
void base64_encode(const char *src, int src_len, char *dst)
{
	int i = 0, j = 0;
	for (i; (src_len - i) / 3; i += 3)
	{
		dst[j++] = base64_map[(src[i] >> 2) & 0x3f];
		dst[j++] = base64_map[((src[i] << 4) | (src[i + 1] >> 4)) & 0x3f];
		dst[j++] = base64_map[((src[i + 1] << 2) | (src[i + 2] >> 6)) & 0x3f];
		dst[j++] = base64_map[src[i + 2] & 0x3f];
	}

	/*不足3的倍数*/
	if (src_len % 3 == 1)
	{
		dst[j++] = base64_map[(src[i] >> 2) & 0x3f];
		dst[j++] = base64_map[(src[i] << 4) & 0x3f];
		dst[j++] = '=';
		dst[j++] = '=';
	}
	else if (src_len % 3 == 2) 
	{
		dst[j++] = base64_map[(src[i] >> 2) & 0x3f];
		dst[j++] = base64_map[((src[i] << 4) | (src[i + 1] >> 4)) & 0x3f];
		dst[j++] = base64_map[(src[i + 1] << 2) & 0x3f];
		dst[j++] = '=';
	}
	dst[j] = '\0';
}

/***********************************************************************
Function:base64_decode                 //函数名字
Desc:    解码                 //函数功能描述
Input:                         //要输入的参数
* @param                       //参数说明
Output:  无                        // 对输出参数的说明。
Return:  无                        // 函数返回值的说明
Others:  无                       若是不是4的倍数，强制解码 
**************************************************************************/
void base64_decode(const char *src, int src_len, char *dst)
{
	int i = 0, j = 0;
	if (src_len % 4 != 0)
	{
		printf("sound code is not four time\n");
		exit(1);
	}

	for (i; (src_len - i) / 4; i += 4) 
	{
		dst[j++] = base64_decode_map[src[i]] << 2 | \
			base64_decode_map[src[i + 1]] >> 4;
		dst[j++] = base64_decode_map[src[i + 1]] << 4 | \
			base64_decode_map[src[i + 2]] >> 2;
		dst[j++] = base64_decode_map[src[i + 2]] << 6 | \
			base64_decode_map[src[i + 3]];
	}
	dst[j] = '\0';
}

/***********************************************************************
Function:MyBase64Test                 //函数名字
Desc:    测试base64编解码                  //函数功能描述
Input:                         //要输入的参数
* @param                       //参数说明
Output:  无                        // 对输出参数的说明。
Return:  无                        // 函数返回值的说明
Others:  无                        // 其它说明；没有就用nullptr表示
**************************************************************************/
void MyBase64Test(void)
{

	base64_encode((char*)test, strlen((char*)test), (char*)encode);
	printf("%s\n", encode);

	printf("%s\n", test1);
	base64_encode((char*)test1, strlen((char*)test1), (char*)encode);
	printf("%s\n", encode);

	base64_decode((char*)test2, strlen((char*)test2), (char*)decode);
	printf("%s\n", decode);

}

/***********************************************************************
Function:Verfy                 //函数名字
Desc:    验证                  //函数功能描述
Input:                         //要输入的参数
* @param                       //参数说明
Output:  无                        // 对输出参数的说明。
Return:  无                        // 函数返回值的说明
Others:  无                        // 其它说明；没有就用nullptr表示
**************************************************************************/
void Verfy(void)
{
	char *str1 = "hello";
	cout << str1 << endl;
	str1[0] = 'H';        //char *str1 = "hello"; 相当于const char *str1 = "hello",常量字符串，赋值后不能修改
	cout << str1 << endl;
}
/***********************************************************************
Function:ConvertIntToByteArray                 //函数名字
Desc:    整型数据转成字节数组                  //函数功能描述
Input:    int data, char array[]                     //要输入的参数
* @param  data - 要转换的整数                   //参数说明
* @param  array - 转换后存储的数组
Output:  无                        // 对输出参数的说明。
Return:  无                        // 函数返回值的说明
Others:  无                        // 其它说明；没有就用nullptr表示
**************************************************************************/
void ConvertIntToByteArray(int data, char array[])
{
	int size = sizeof(data);
	for (int i = 0; i < size; ++i)
	{
		array[i] = data >> (8 * i);
		cout << array[i];
	}
}

/***********************************************************************
Function: char * findcommon2(char a[], char b[])          
Desc:                    
Input:                        
* @param   -         
* @param   - 
Output:  无                       
Return:  无                       
Others:  无                       
**************************************************************************/
char * findcommon2(char a[], char b[])
{
	int size1 = strlen(a);
	int size2 = strlen(b);
	int size3 = size1 > size2 ? size1 : size2;

	char *c = (char*)malloc(size3);

	int i = 0, j = 0, k = 0;
	while (i<size1 && j<size2)
	{
		if (a[i] == b[j])
		{
			*c = a[i];
			c++;
			i++;
			j++;
		}
			
		if (a[i]>b[j])
			j++;
		if (a[i]<b[j])
			i++;
	}
	return c;
}

/***********************************************************************
输出1-1000000中所有中间两位数字相等的回文数
**************************************************************************/
void Palindromic(void)
{
	for (int i = 1; i < 10; i++)
	{
		printf("%d,", i); //一位数
		printf("%d%d,", i, i);//两位数
		printf("%d%d%d,", i, i, i);//三位数
		printf("\n");
		for (int j = 0; j < 10; j++)
			printf("%d%d%d%d,", i, j, j, i);//四位数

		for (int j = 0; j < 10; j++)
			printf("%d%d%d%d%d,", i, j, j, j, i);//五位数

		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				printf("%d%d%d%d%d%d,", i, j, k, k, j, i);//六位数

		printf("\n");//为方便阅读结果，加一个换行。
	}
}
/***********************************************************************
Function:  char FindFirstChar(char str[])            //函数名字
Desc:    找出字符串中第一个只出现一次的字符         //函数功能描述
Input:    char str[]                               //要查询的字符串
* @param  str[]  -要查询的字符串                   //参数说明
Output:  无 char                                  // 
Return:  char                                     // 返回字符串中第一个只出现一次的字符，没有则返回 '\0'
Others:  无                                      //
** C/C++字符使用Ascii编码，一个字符占一个字节即可以表示2的8次方个数，那么C/C++字符可以表示的256个字符，
** 因此可以用一个256的数组来保存各个字符出现的次数，当然256个字符的Ascii值是0-255之间的所有数，而且
** ’\0’的Ascii值0，所以可以用数组的下标来表示记录的是哪一个字符的个数。然后再遍历一次字符串，找出
** 第一个只出现一次的字符。本文来自 Ego_Bai 的CSDN 博客 ，全文地址请点击：https://blog.csdn.net/ego_bai/article/details/80461304?utm_source=copy
** 其他方法1：暴力求解O(n^2)

---------------------

本文来自 Ego_Bai 的CSDN 博客 ，全文地址请点击：https://blog.csdn.net/ego_bai/article/details/80461304?utm_source=copy 
**************************************************************************/
char FindFirstChar(char str[])
{
	if (str == NULL || str[0] == '\0')
	{
		return '\0';
	}

	int count[256] = { 0 };
	int i = 0;
	while (str[i])
	{
		count[str[i]]++;
		i++;
	}

	i = 0;
	while (str[i])
	{
		if (count[str[i]] == 1)
		{
			return str[i];
		}
		i++;			
	}

	return '\0';

}

/***********************************************************************
输出数组中第几大数字在数组中的位置
**************************************************************************/
/*
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;

bool cmp(int x, int y)
{
	return x>y;
}
int removeDel(int s[], int count)
{
	int newlen = 0;
	int j = 0;
	for (int i = 0, j = 0; i < count && j < count; i++)
	{
		while (j < count &&s[i] == s[j])
			j++;
		if (j>i + 1 && j<count)
			s[i + 1] = s[j];
		newlen++;
	}
	return newlen;
}
int main(void)
{
	int original[100] = { 0 };

	int n = 0, i;
	char c;
	int number = 0;
	int len;
	if (scanf("%d", &original[n]) == 1)
	{
		n++;
	}

	while (1)
	{
		scanf("%c", &c);
		if (c != ',')
		{
			if (c == ' ')
			{
				scanf("%d", &number);

			}
			break;
		}
		if (scanf("%d", &original[n]) == 1)
		{
			n++;
		}
		else
		{
			break;
		}
	}
	int newSort[100];

	//for (int i = 0; i < n; i++)
	//	newSort[i] = original[i];

	memcpy(newSort,original,sizeof(original[0])*n);

	sort(newSort, newSort + n, cmp);

	//len = removeDel(s, n);

	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (original[i] == newSort[number - 1])
		{
			index = i;
			break;
		}

	}

	printf("%d", index + 1);

	system("pause");

	return 0;
}

*/

/*检测IP是否合法*/
/*
//bool isIpFormatRiht(char *ipAddress)
//
//{//判断IP地址是否合法
//
//	int a, b, c, d;
//
//	if ((sscanf(ipAddress, "%d.%d.%d.%d", &a, &b, &c, &d) == 4)
//
//		&& (a >= 0 && a <= 255)
//
//		&& (b >= 0 && b <= 255)
//
//		&& (c >= 0 && c <= 255)
//
//		&& (d >= 0 && d <= 255))
//
//	{
//
//		return 1;
//
//	}
//
//	return 0;
//
//}
*/


//#include<iostream>
//
//#include<vector>
//
//#include<string>
//
//#include<algorithm>
//
//#include<map>
//
//#include<queue>
//
//#include<functional>
//
//using namespace std;
//
////递归找出长度为pwdLen的组合
//
//void comB(string str, vector<string> &res, string &temp, int m, int pwdLen)
//
//{
//
//	if (temp.size() == pwdLen) //达到长度，则保存，否则递归
//
//	{
//
//		res.push_back(temp);
//
//	}
//
//	else
//
//	{
//
//		if (m < str.size())
//
//		{
//
//			temp.push_back(str[m]);
//
//			comB(str, res, temp, m + 1, pwdLen);
//
//			temp.pop_back();
//
//			comB(str, res, temp, m + 1, pwdLen);
//
//		}
//
//	}
//
//}
//
//vector<string> getpasswd(string userName, string motherName, int pwdLen)
//
//{
//
//	//先求出公共子集，不区分大小写
//
//	map<char, int> hash, hash1;
//
//	int l1 = userName.size(), l2 = motherName.size();
//
//	for (int i = 0; i < l1; ++i)
//
//	{
//
//		if (userName[i] >= 'A' && userName[i] <= 'Z')
//
//			userName[i] += 32;
//
//		hash[userName[i]] ++;
//
//	}
//
//	for (int i = 0; i < l2; ++i)
//
//	{
//
//		if (motherName[i] >= 'A' && motherName[i] <= 'Z')
//
//			motherName[i] += 32;
//
//		hash1[motherName[i]] ++;
//
//	}
//
//	cout << userName << endl;
//
//	cout << motherName << endl;
//
//	string strSame;
//
//	for (auto v : hash)
//
//	{
//
//		if (hash1.find(v.first) != hash1.end())
//
//			strSame.push_back(v.first);
//
//	}
//
//	cout << strSame << endl;
//
//	int n = strSame.size();
//
//	if (n < pwdLen)  //长度不够，直接输出{}
//
//		return{};
//
//	vector<string> res;
//
//	string temp;
//
//	comB(strSame, res, temp, 0, pwdLen);
//
//	return res;
//
//}
//
//int main()
//
//{
//
//	string str("RadheGupta");
//
//	string str1("RADHIKA");
//
//	int m = 3;
//
//	vector<string> res;
//
//	string temp;
//
//	res = getpasswd(str, str1, m);
//
//	for (auto v : res)
//
//		cout << v << "	";
//
//
//	system("pause");
//	return 0;
//
//}
/*class A {
public:A();
	   virtual~A();
	   virtual void fun1()
	   {
		   printf("123");
	   }
};
A::A() {}
A::~A()
{
	printf("Delete class A\n");
}

class B : public A
{
public:B();
	   ~B();
	   void fun2()
	   {
		   printf("123456");
	   }
};

B::B() { }
B::~B()
{
	printf("Delete class B\n");
}

A *a = new B;
//B *b=new A; //无法从“A *”转换为“B *”

B *c = new B;
A *d = new A;

int main(void)
{

	//MySortTest();
	B *b = new B();
	A *a = b;

	delete a;
	system("pause");
	return 0;
}
*/