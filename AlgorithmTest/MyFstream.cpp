#include "MyFstream.h"
#include<fstream>
#include<vector>
#include<iostream>
using namespace std;

int MyFstreamTest(void)
{
    ifstream input("execute.stdin");
    //把文件里面的内容按照字符读取到缓存的vector里面
    vector<char> strs;
    char ch;
    while (input >> ch)
        strs.push_back(ch);
    rsize_t len = strs.size();

    //把文件里面的内容读取到整形的缓存变量
    int type;
    int k;
    input >> type >> k;
   
    //把文件的内容先统一缓存到STRING,然后再转换成其他类型
    ifstream myfile("execute.stdin");
    if (!myfile)
    {
        cout << "文件读错误";
        system("pause");
        exit(1);
    }
    //char ch;
    int octal, decimal, hex;
    char  bin[33];
    string  content;
    while (myfile.get(ch))
    {
        // if(ch=='\n')

        content += ch;
        // cout.put(ch);//cout<<ch;这么写也是可以的 
    }
    const char *char_remoteURL = content.c_str();
    sscanf(char_remoteURL, "%s %o %d %x ", bin, &octal, &decimal, &hex);

    //十六进制形式读取文件
    FILE *Fd;
    int s;
    if ((Fd = fopen("execute.stdin", "r")) == NULL) //判断文件是否正常打开
    {
        printf("error!\n");
        return -1;               //打开失败就退出
    }
    while (!feof(Fd))            //文件没到结尾
    {
        fscanf(Fd, "%x", &s);	     //十六进制方式读取一个数
        printf("%x\n", s);
        //a = ((0xff << 16)&s) >> 16;     //将十六进制数拆分成三段。
        //b = ((0xff << 8)&s) >> 8;
        //c = ((0xff << 0)&s) >> 0;
        //printf("0x%x\n", a);
        //printf("0x%x\n", b);
        //printf("0x%x\n", c);
    }
    fclose(Fd);               //操作完毕关闭文件。

    return 0;
}

