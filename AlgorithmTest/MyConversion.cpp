#include"MyConversion.h"
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<deque>

using namespace std;

static void BinConversionDecimal(string s);

int MyConversionTest(void)
{
    //int i = 19;
    //char array[32] = { 0 };

    //_itoa(i, array, 2);
    //cout << array << endl;
    //_itoa(i, array, 8);
    //cout << array << endl;
    //_itoa(i, array, 16);
    //cout << array << endl;

    DecimalConversionBin(23);
    //cout << endl;
    string ss("101011");
    BinConversionDecimal(ss);

    //deque<char> deqString{ 'a','b' };
    //deque<int> d{ 1,2,3,4,5 };

    char array2[32] = "101011";
    BinConversionDecimal(array2);
    
    cout << endl;
    return 0;
}

static void DecimalConversionBin(int num)
{
    if (!num)
    {
        return ;
    }
    else
    {
        DecimalConversionBin(num / 2);
        cout << num % 2;
    }
    
}
static void BinConversionDecimal(string s)
{
    int  sum;
    size_t len;
    len =s.length();
    sum = 0;
    for (int i = 0; i<len; i++)
    {
        if (s[i] - '0' == 1)    //从高位依次判断二进制数是否为 1
            sum = sum + (int) pow(2, len - 1 - i);
    }

    cout << sum << endl;
}
static void BinConversionDecimal(char *s)
{
    int sum;
    size_t len;
    len = strlen(s);
    sum = 0;
    for (int i = 0; i<len; i++)
    {
        if (s[i] - '0' == 1)    //从高位依次判断二进制数是否为 1
            sum = sum + (int)pow(2, len - 1 - i);
    }

    cout << sum << endl;
}
//#include <iostream> 
//#include <fstream> 
//#include <string> 
//#include <algorithm>
//#include<stdio.h>
//using namespace std;
//int main()
//{
//
//    ifstream myfile("execute.stdin");
//    if (!myfile)
//    {
//        cout << "文件读错误";
//        system("pause");
//        exit(1);
//    }
//    char ch;
//    int ox1, d1, xx;
//    char  hex2[33];
//    string  content;
//    while (myfile.get(ch))
//    {
//        // if(ch=='\n')
//
//        content += ch;
//        // cout.put(ch);//cout<<ch;这么写也是可以的 
//    }
//    const char *char_remoteURL = content.c_str();
//    sscanf(char_remoteURL, "%s %o %d %x ", hex2, &ox1, &d1, &xx);
//    int line_int = 1, i = 0, line2_int = 0;
//    while (hex2[i])
//    {
//        i++;
//
//    }
//    i--;
//    while (i >= 0)
//    {
//
//        if (hex2[i] % 2)
//        {
//            line2_int = line2_int + line_int;
//
//        }
//        line_int = line_int * 2;
//
//        i--;
//    }
//    i = 0;
//
//    printf("%o %d %x\n", line2_int, line2_int, line2_int);
//
//    int line3;
//    line3 = ox1;
//    char  hex3[33];
//    while (line3)
//    {
//        if (line3 % 2)
//        {
//            hex3[i] = '1';
//            //printf("1");
//        }
//
//        else
//        {
//            hex3[i] = '0';
//            // printf("0");
//        }
//
//        line3 = line3 >> 1;
//        i++;
//    }
//    i--;
//    //printf("\n");
//    while (i >= 0)
//    {
//        if (hex3[i] == '1')
//        {
//            //hex3[i] = '1';
//            printf("1");
//        }
//
//        else
//        {
//            // hex3[i] = '0';
//            printf("0");
//        }
//
//        // line3 = line3 >> 1;
//        i--;
//    }
//    printf(" %d %x\n", ox1, ox1);
//    for (i = 0; i < 33; i++)
//        hex3[i] = 0;
//
//    i = 0;
//    int line4;
//    line4 = d1;
//    while (line4)
//    {
//        if (line4 % 2)
//        {
//            hex3[i] = '1';
//            // printf("1");
//        }
//
//        else
//        {
//            hex3[i] = '0';
//            // printf("0");
//        }
//
//        line4 = line4 >> 1;
//        i++;
//    }
//    i--;
//    // printf("\n");
//    while (i >= 0)
//    {
//        if (hex3[i] == '1')
//        {
//            //hex3[i] = '1';
//            printf("1");
//        }
//
//        else
//        {
//            // hex3[i] = '0';
//            printf("0");
//        }
//
//        // line3 = line3 >> 1;
//        i--;
//    }
//    printf(" %o %x\n", d1, d1);
//    for (i = 0; i < 33; i++)
//        hex3[i] = 0;
//
//
//    i = 0;
//    int line5;
//    line5 = xx;
//    while (line5)
//    {
//        if (line5 % 2)
//        {
//            hex3[i] = '1';
//            // printf("1");
//        }
//
//        else
//        {
//            hex3[i] = '0';
//            // printf("0");
//        }
//
//        line5 = line5 >> 1;
//        i++;
//    }
//    i--;
//    // printf("\n");
//    while (i >= 0)
//    {
//        if (hex3[i] == '1')
//        {
//            //hex3[i] = '1';
//            printf("1");
//        }
//
//        else
//        {
//            // hex3[i] = '0';
//            printf("0");
//        }
//
//        // line3 = line3 >> 1;
//        i--;
//    }
//    printf(" %o %d\n", xx, xx);
//    for (i = 0; i < 33; i++)
//        hex3[i] = 0;
//
//    /* reverse(hex3, hex3 + i);
//    printf("%s", hex3);*/
//
//    myfile.close();
//    //    cout << content<<endl;
//    //   system("pause");
//    return 0;
//}