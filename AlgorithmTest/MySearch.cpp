#include"MySearch.h"
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef vector<int> vInt;
typedef vector<int>::iterator vIterator;


/*
reference
*/
/**************************************************
Function: void MySearchTest(void)
Desc:  Sort�Ĳ���
Input:
* @param  -
Output:	nullptr
Return:	nullptr
Others:	nullptr
*******************************************************/
void MySearchTest(void)
{
	vector<int> lVecInt;
	int array[] = { 6,5,3,1,8,7,2,4 };
	lVecInt.push_back(1);
	lVecInt.push_back(2);
	lVecInt.push_back(4);
	lVecInt.push_back(4);
	lVecInt.push_back(7);
	lVecInt.push_back(9);

	int lsearch = 5;

	//����תvector
	vector<int> lVecInt2(array,array+sizeof(array)/sizeof(int)) ;

	//vector ת����
	int *array1 = new int[lVecInt.size()];

	for (int i = 0; i<lVecInt.size(); i++)
		array1[i] = lVecInt.at(i);

	//���ֲ��ҵ�ǰ��������Ϊ��������
	BinarySearch(array1, lsearch, 6);
	if (binary_search(lVecInt.begin(), lVecInt.end(), 7))
	{
		cout << "This number exists" << endl;
	}
	else
	{
		cout << "This number doesn't exists" << endl;
	}

	//��iterator�Ա�ʶԪ�ط�Χ�ڣ�����һ�������ظ�Ԫ�أ��ҵ��򷵻�ָ�����Ԫ�صĵ�һ��Ԫ�صĵ����������򷵻�past-the-end��
	vIterator it = adjacent_find(lVecInt.begin(), lVecInt.end());

}

/**************************************************
Function: int BinarySearch(int a[], const int& x, int n)
Desc:  ���ֲ��ң�ǰ��������Ϊ����
Input:
* @param  -
Output:	nullptr
Return:	nullptr
Others:	nullptr
*******************************************************/
//mplate<class Type>
//int BinarySearch(Type a[], const Type& x, int n)
int BinarySearch(int a[], const int& x, int n)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (a[middle] == x)
			return middle;
		if (x >= a[middle])
			left = middle + 1;
		else
			right = middle - 1;
	}
	return -1;
}
