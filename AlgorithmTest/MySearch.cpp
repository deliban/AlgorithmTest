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
Desc:  Sort的测试
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

	//数组转vector
	vector<int> lVecInt2(array,array+sizeof(array)/sizeof(int)) ;

	//vector 转数组
	int *array1 = new int[lVecInt.size()];

	for (int i = 0; i<lVecInt.size(); i++)
		array1[i] = lVecInt.at(i);

	//二分查找的前提是数组为有序数组
	BinarySearch(array1, lsearch, 6);
	if (binary_search(lVecInt.begin(), lVecInt.end(), 7))
	{
		cout << "This number exists" << endl;
	}
	else
	{
		cout << "This number doesn't exists" << endl;
	}

	//在iterator对标识元素范围内，查找一对相邻重复元素，找到则返回指向这对元素的第一个元素的迭代器。否则返回past-the-end。
	vIterator it = adjacent_find(lVecInt.begin(), lVecInt.end());

}

/**************************************************
Function: int BinarySearch(int a[], const int& x, int n)
Desc:  二分查找，前提数组须为升序
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
