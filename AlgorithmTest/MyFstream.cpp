#include "MyFstream.h"
#include<fstream>
#include<vector>
#include<iostream>
using namespace std;

int MyFstreamTest(void)
{
    ifstream input("execute.stdin");
    //���ļ���������ݰ����ַ���ȡ�������vector����
    vector<char> strs;
    char ch;
    while (input >> ch)
        strs.push_back(ch);
    rsize_t len = strs.size();

    //���ļ���������ݶ�ȡ�����εĻ������
    int type;
    int k;
    input >> type >> k;
   
    //���ļ���������ͳһ���浽STRING,Ȼ����ת������������
    ifstream myfile("execute.stdin");
    if (!myfile)
    {
        cout << "�ļ�������";
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
        // cout.put(ch);//cout<<ch;��ôдҲ�ǿ��Ե� 
    }
    const char *char_remoteURL = content.c_str();
    sscanf(char_remoteURL, "%s %o %d %x ", bin, &octal, &decimal, &hex);

    //ʮ��������ʽ��ȡ�ļ�
    FILE *Fd;
    int s;
    if ((Fd = fopen("execute.stdin", "r")) == NULL) //�ж��ļ��Ƿ�������
    {
        printf("error!\n");
        return -1;               //��ʧ�ܾ��˳�
    }
    while (!feof(Fd))            //�ļ�û����β
    {
        fscanf(Fd, "%x", &s);	     //ʮ�����Ʒ�ʽ��ȡһ����
        printf("%x\n", s);
        //a = ((0xff << 16)&s) >> 16;     //��ʮ����������ֳ����Ρ�
        //b = ((0xff << 8)&s) >> 8;
        //c = ((0xff << 0)&s) >> 0;
        //printf("0x%x\n", a);
        //printf("0x%x\n", b);
        //printf("0x%x\n", c);
    }
    fclose(Fd);               //������Ϲر��ļ���

    return 0;
}

