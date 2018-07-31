#include "MyRabbit.h"
#include "iostream"
#include<vector>
using namespace std;
void MyRabbit(void)
{
	int n;
	cin >> n;
	int *id = new int[n]();
	for (int i = 0; i < n; i++)
	{
		cin >> id[i];
	}

	int ID[1000] = { 0 };
	int m = 0;
	vector <int> out;
	for (int i = 0; i < n; i++)
	{
		if (m == 10)
			break;
		if (ID[id[i]] == 0)
		{
			ID[id[i]] = 1;
			m++;
			out.push_back(id[i]);
		}

		cout << m << endl;

		for (auto i : out)
			cout << i << endl;

		delete id;
	}
}