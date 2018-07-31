#include"test1.h"
#include<vector>
#include <iostream>
#include <cstdio>

using namespace std;

int main1() {
	int n;
	cin >> n;
	int *id = new int[n]();
	for (int i = 0; i < n; i++)
	{
		cin >> id[i];
	}
	int ID[1000] = { 0 }, m = 0;
	vector <int> out;
	for (int i = 0; i < n; i++)
	{
		if (m == 10)
		{
			break;
		}

		if (ID[id[i]] == 0)
		{
			ID[id[i]] = 1;
			m++;
			out.push_back(id[i]);
		}

	}
	cout << m << endl;
	/*for (auto i : out)
	{
	cout << i << endl;
	}*/
	vector<int>::const_iterator iter = out.begin();//注意需要用const_iterator,因为容器是const类型  
	while (iter != out.end())
	{
		cout << *iter++ << endl;
	}
	delete id;

	getchar();
	return 0;
}

struct CAT_s
{
	int Id;
	char Color;
	unsigned short Age;
	char *Name;
	void(*Jump)(void); //函数不占空间，但是函数指针类型是个指针变量是占空间的
}Garfield;
void TypeSize(void)
{
	cout << "Garfield size:" << sizeof(int) << endl;
}
