#include "MySort.h"
#include <iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

/*
reference http://www.cnblogs.com/eniac12/p/5329396.html
*/
/**************************************************
Function: MySortTest
Desc:  Sort的测试
Input:
* @param  -
Output:	nullptr
Return:	nullptr
Others:	nullptr
*******************************************************/
void MySortTest(void)
{
	int array[] = { 6,5,3,1,8,7,2,4};
	int len = sizeof(array) / sizeof(int);
	//InsertionSort(array, len);
	//InsertionSortDichotomy(array, len);
	//ShellSort(array, len);
	BubbleSort(array, len);
	//CocktailSort(array, len);
	//SeletionSort(array, len);
	//MergeSortRecursion(array, 0, len - 1);
	//MergeSortIteration(array, len);
	//HeapifySort(array, len);

	//sort(a,a+n) 表示对a[0] a[1] a[2] ... a[n-1] 排序
	//sort(array, array + len);

	for (int i = 0; i < len; i++)
		cout << array[i];
	cout << endl;

	for (int i = 0; i < len; i++)
		printf("%d", array[i]);
	printf("\n");
}

/**************************************************
Function: void Swap1(int *i, int *j)
Desc:  交换
Input: int *i, int *j
* @param  *i - 待交换数i的指针或者引用(C++才可以用引用)
* @param  *j - 待交换数j的指针或者引用
Output:	nullptr
Return:	nullptr
Others:
*******************************************************/
bool Compare(int a, int b)
{
	return a > b;
}

/**************************************************
Function: void Swap1(int *i, int *j)
Desc:  交换
Input: int *i, int *j
* @param  *i - 待交换数i的指针或者引用(C++才可以用引用)
* @param  *j - 待交换数j的指针或者引用
Output:	nullptr
Return:	nullptr
Others:
*******************************************************/
static void Swap1(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}
/**************************************************
Function: void Swap2(int &i, int &j)
Desc:  交换
Input: int &i, int &j
* @param  &i - 待交换数i的指针或者引用
* @param  &j - 待交换数j的指针或者引用
Output:	nullptr
Return:	nullptr
Others:
*******************************************************/
static void Swap2(int &i, int &j)
{
	int temp = i;
	i = j;
	j = temp;
}

/**************************************************
Function: void Swap3(int array[],int i, int j)
Desc:  交换
Input: int array[],int i, int j
* @param  array[] - 待交换数所在的数组
* @param  i - 待交换数所在的数组下标i
* @param  j - 待交换数所在的数组下标j
Output:	nullptr
Return:	nullptr
Others:
*******************************************************/
static void Swap3(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
/**************************************************
Function: InsertionSort
Desc:  插入排序
Input: array[],n
* @param  array[] - 待排序的数组
* @param  n - 待排序数组元素的大小
Output:	nullptr
Return:	nullptr
Others:	
****最坏情况为输入序列是降序排列的,此时时间复杂度O(n^2)
****最好情况为输入序列是升序排列的,此时时间复杂度O(n)
****平均时间复杂度 ---- O(n^2)
****所需辅助空间 ------ O(1)   //带插入的一个缓存空间如下程序的 get；
****稳定性 ------------ 稳定
****应用 --- 插入排序不适合对于数据量比较大的排序应用。但是，如果需要排序的数据量很小，比如量级小于千，那么插入
排序还是一个不错的选择。 插入排序在工业级库中也有着广泛的应用，在STL的sort算法和stdlib的qsort算法中，都将插入
排序作为快速排序的补充，用于少量元素的排序（通常为8个或以下）。 
*******************************************************/
static void InsertionSort(int array[], int n)
{
	for(int i=1; i < n; i++)
	{
		int get = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > get)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = get;
		
	}
}

/**************************************************
Function: void InsertionSortDichotomy(int array[], int n)
Desc:  二分插入排序（插入排序的改进）
Input: array[],n
* @param  array[] - 待排序的数组
* @param  n - 待排序数组元素的大小
Output:	nullptr
Return:	nullptr
Others:
****最坏情况为输入序列是降序排列的,此时时间复杂度O(n^2)
****最优时间复杂度 ---- O(nlogn)
****平均时间复杂度 ---- O(n^2)
****所需辅助空间 ------ O(1)   
****稳定性 ------------ 稳定
****应用 --- 当n较大时，二分插入排序的比较次数比直接插入排序的最差情况好得多，但比直接插入排序的最好情况要差，
所当以元素初始序列已经接近升序时，直接插入排序比二分插入排序比较次数少。二分插入排序元素移动次数与直接插入
排序相同，依赖于元素初始序列。
*******************************************************/
static void InsertionSortDichotomy(int array[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int get = array[i];
		int left = 0;
		int right = i - 1;		
		while (left <= right)
		{
			int min = (left + right) / 2;
			if (array[min] > get)
				right = min - 1;
			else
				left = min + 1;
		}
		
		int j = i - 1;
		while (j >= left)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[left] = get;
		/*
		for (int j = i -1; j >= left; j--)
		{
			array[j + 1] = array[j];
		}
		array[left] = get;
		*/
	}
}

/**************************************************
Function:void ShellSort(int array[], int n)
Desc:  希尔排序（插入排序的改进）
Input: array[],n
* @param  array[] - 待排序的数组
* @param  n - 待排序数组元素的大小
Output:	nullptr
Return:	nullptr
Others:
****最差时间复杂度 ---- 根据步长序列的不同而不同。已知最差的为O(n(logn)^2)
****最优时间复杂度 ----  O(n)
****平均时间复杂度 ---- 根据步长序列的不同而不同
****所需辅助空间 ------ O(1)
****稳定性 ------------ 不稳定
*******************************************************/
static void ShellSort(int array[], int n)
{
	int h = 0;
	while (h <= n)           //生成增量
	{
		h = 3 * h + 1;
	}

	while (h >= 1)
	{
		for (int i = h; i < n; i++)
		{
			int j = i - h;
			int get = array[i];
			while (j >= 0 && array[j] > get)
			{
				array[j + h] = array[j];
				j = j - h;
			}
			array[j + h] = get;
		}
		h = (h - 1) / 3;   //递减增量
	}
}
/**************************************************
Function: void BubbleSort(int array[], int n)
Desc:  冒泡排序
Input: array[],n
* @param  array[] - 待排序的数组
* @param  n - 待排序数组元素的大小
Output:	nullptr
Return:	nullptr
Others:
****最优时间复杂度 ---- 如果能在内部循环第一次运行时,使用一个旗标来表示有无需要交换的可能,
可以把最优时间复杂度降低到O(n)
****最差时间复杂度 ---- O(n^2)
****平均时间复杂度 ---- O(n^2)
****所需辅助空间 ------ O(1)
****稳定性 ------------ 稳定
*******************************************************/
static void BubbleSort(int array[], int n)
{
	for (int i = 0; i< n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i ; j++)
		{
			if (array[j] > array[j + 1])
				Swap3(array,j,j + 1); //不能用Swap1()orSwap1(),因为 &(array[j])非常量引用的初始值必须为左值
		}
	}	

	/*交换排序*/
	//for (int i = 0; i < n - 1; i++)
	//{
	//	for (int j = i + 1 ; j < n; j++)
	//	{
	//		if(array[j] < array[i])
	//			Swap3(array, i, j);
	//	}
	//}
}

/**************************************************
Function: void CocktailSort(int array[], int n)
Desc:  鸡尾排序（冒泡排序的改进）
Input: array[],n
* @param  array[] - 待排序的数组
* @param  n - 待排序数组元素的大小
Output:	nullptr
Return:	nullptr
Others:
****最优时间复杂度 ---- 如果序列在一开始已经大部分排序过的话,会接近O(n)
****最差时间复杂度 ---- O(n^2)
****平均时间复杂度 ---- O(n^2)
****所需辅助空间 ------ O(1)
****稳定性 ------------ 稳定
*******************************************************/
static void CocktailSort(int array[], int n)
{
	int left = 0;
	int right = n - 1;
	while(left < right)
	{
		for (int i = left; i < right; i++)
		{
			if (array[i] > array[i + 1])
				Swap3(array, i, i + 1);
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (array[i - 1] > array[i])
				Swap3(array, i - 1, i);
		}
		left++;
	}
}

/**************************************************
Function: void SeletionSort(int array[], int n)
Desc:  选择排序 
****    选择排序与冒泡排序的区别：冒泡排序通过依次交换相邻两个顺序不合法的元素位置，从而将当前最小（大）元素放到合适
****的位置；而选择排序每遍历一次都记住了当前最小（大）元素的位置，最后仅需一次交换操作即可将其放到合适的位置。
Input: array[],n
* @param  array[] - 待排序的数组
* @param  n - 待排序数组元素的大小
Output:	nullptr
Return:	nullptr
Others:
****最优时间复杂度 ---- 如果序列在一开始已经大部分排序过的话,会接近O(n)
****最差时间复杂度 ---- O(n^2)
****平均时间复杂度 ---- O(n^2)
****所需辅助空间 ------ O(1)
****稳定性 ------------ 不稳定 （如果两个数相同，计算的时候，不能改变他们的相对位置）
比如序列：{ 5, 8, 5, 2, 9 }，一次选择的最小元素是2，然后把2和第一个5进行交换，从而改变了两个元素5的相对次序。
*******************************************************/
static void SeletionSort(int array[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
			Swap3(array, min, i);
	}
}

/**************************************************
Function: static void Merge(int array[], int left, int mid, int right)
Desc:  合并两个已排好序的数组A[left...mid]和A[mid+1...right]
Input: array[],n
* @param  array[] - 待排序的数组
* @param  n - 待排序数组元素的大小
Output:	nullptr
Return:	nullptr
Others:
****最优时间复杂度 ---- 如果序列在一开始已经大部分排序过的话,会接近O(n)
****最差时间复杂度 ---- O(n^2)
****平均时间复杂度 ---- O(n^2)
****所需辅助空间 ------ O(1)
****稳定性 ------------ 不稳定 （如果两个数相同，计算的时候，不能改变他们的相对位置）
比如序列：{ 5, 8, 5, 2, 9 }，一次选择的最小元素是2，然后把2和第一个5进行交换，从而改变了两个元素5的相对次序。
*******************************************************/
static void Merge(int array[], int left, int mid, int right)
{
	int len = right - left + 1;
	int *temp = new int[len];
	int index = 0;
	int i = left;
	int j = mid + 1;
	while (i <= mid && j <= right)
	{
		temp[index++] = array[i] <= array[j] ? array[i++] : array[j++];//带等号保证归并的稳定性
	}
	while (i <= mid)
	{
		temp[index++] = array[i++];
	}
	while (j <= right)
	{
		temp[index++] = array[j++];
	}

	//int k = len;
	while(index--)
	{
		array[right--] = temp[index];
	}
	/*
	for (int k = 0; k < len; k++)
	{
		array[left++] = temp[k];
	}
	*/
	delete temp;
}

/**************************************************
Function: static void MergeSortRecursion(int array[], int left, int right)
Desc:   递归实现的归并排序(自顶向下)
Input: array[],left,right
* @param  array[] - 待排序的数组
* @param  left - 待排序数组元素的左端
* @param  right - 待排序数组元素的右端
Output:	nullptr
Return:	nullptr
Others:
****最优时间复杂度 ---- O(nlogn)
****最差时间复杂度 ---- O(nlogn)
****平均时间复杂度 ----O(nlogn)
****所需辅助空间 ------ O(n)
****稳定性 ------------ 稳定 
*******************************************************/
 static void MergeSortRecursion(int array[], int left, int right)   
{
	if (left == right)
		return;
	int mid = (left + right) / 2;
	MergeSortRecursion(array, left, mid);
	MergeSortRecursion(array, mid+1, right);
	Merge(array, left, mid, right);
}

 /**************************************************
 Function: static void MergeSortIteration(int array[], int len)
 Desc:   非递归实现的归并排序(自底向上)
 Input: array[],len
 * @param  array[] - 待排序的数组
 * @param  len - 待排序数组元素的大小
 Output:	nullptr
 Return:	nullptr
 Others:
 ****最优时间复杂度 ---- O(nlog(n))
 ****最差时间复杂度 ---- O(nlog(n))
 ****平均时间复杂度 ---- O(nlog(n))
 ****所需辅助空间 ------ O(n)  //用户合并
 ****稳定性 ------------ 稳定 
 *******************************************************/
static void MergeSortIteration(int array[], int len)
{
	int left, mid, right;// 子数组索引,前一个为A[left...mid]，后一个子数组为A[mid+1...right]
	for (int i = 1; i < len; i *= 2)// 子数组的大小i初始为1，每轮翻倍
	{
		left = 0;
		while (left + i < len) // 后一个子数组存在(需要归并)
		{
			mid = left + i - 1;
			right = mid + i < len ? mid + i : len - 1;// 后一个子数组大小可能不够
			Merge(array, left, mid, right);
			left = right + 1; // 前一个子数组索引向后移动
		}
	}
}

/**************************************************
Function: static void MergeSortIteration(int array[], int len)
Desc:   非递归实现的归并排序(自底向上)
Input: array[],len
* @param  array[] - 待排序的数组
* @param  len - 待排序数组元素的大小
Output:	nullptr
Return:	nullptr
Others:
****最优时间复杂度 ---- O(nlog(n))
****最差时间复杂度 ---- O(nlog(n))
****平均时间复杂度 ---- O(nlog(n))
****所需辅助空间 ------ O(n)  //用户合并
****稳定性 ------------ 稳定
*******************************************************/
void Heapify(int array[], int i, int size)
{
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;//int rightChild = 2 *(i+!);
	int max = i;

	if (leftChild<size&&array[leftChild]>array[max])
		max = leftChild;

	if (rightChild<size&&array[rightChild]>array[max])
		max = rightChild;

	if (max != i)
	{
		Swap3(array, i, max);
		Heapify(array, max, size);
	}
}

/**************************************************
Function: static void MergeSortIteration(int array[], int len)
Desc:   非递归实现的归并排序(自底向上)
Input: array[],len
* @param  array[] - 待排序的数组
* @param  len - 待排序数组元素的大小
Output:	nullptr
Return:	nullptr
Others:
****最优时间复杂度 ---- O(nlog(n))
****最差时间复杂度 ---- O(nlog(n))
****平均时间复杂度 ---- O(nlog(n))
****所需辅助空间 ------ O(n)  //用户合并
****稳定性 ------------ 稳定
*******************************************************/
int BuildHeapify(int array[], int n)
{
	int heapifySize = n;
	for (int i = heapifySize / 2 - 1; i >= 0; i--)
	{
		Heapify(array, i, heapifySize);
	}
	return heapifySize;
}

/**************************************************
Function: static void MergeSortIteration(int array[], int len)
Desc:   非递归实现的归并排序(自底向上)
Input: array[],len
* @param  array[] - 待排序的数组
* @param  len - 待排序数组元素的大小
Output:	nullptr
Return:	nullptr
Others:
****最优时间复杂度 ---- O(nlog(n))
****最差时间复杂度 ---- O(nlog(n))
****平均时间复杂度 ---- O(nlog(n))
****所需辅助空间 ------ O(n)  //用户合并
****稳定性 ------------ 稳定
*******************************************************/
void HeapifySort(int array[], int n)
{
	int heapifySize = BuildHeapify(array, n);
	while (heapifySize > 1)
	{
		Swap3(array, 0, --heapifySize);
		Heapify(array, 0, heapifySize);
	}
}
/**************************************************
Function: int Partition(int array[], int left, int right)
Desc:   划分函数
Input: int array[], int left, int right
* @param  array[] - 待排序的数组
* @param
Output:	nullptr
Return:	nullptr
Others:
*******************************************************/
int Partition(int array[], int left, int right)
{
	int pivot = array[right];  //pivot 中轴 ，中心点  这里每次都选择最后一个元素作为基准
	int tail = left - 1;       // tail为小于基准的子数组最后一个元素的索引
	for (int i = left; i < right; i++)// 遍历基准以外的其他元素
	{
		if (array[i] <= pivot)// 把小于等于基准的元素放到前一个子数组末尾
		{
			Swap3(array, ++tail, i);
		}

	}
	Swap3(array, tail + 1, right);   // 最后把基准放到前一个子数组的后边，剩下的子数组既是大于基准的子数组
									 // 该操作很有可能把后面元素的稳定性打乱，所以快速排序是不稳定的排序算法
	return tail + 1;				 // 返回基准的索引
}

/**************************************************
Function: void QuickSort(int array[], int left, int right)
Desc:   快速排序
Input: array[],len
* @param  array[] - 待排序的数组
* @param
Output:	nullptr
Return:	nullptr
Others:
****最优时间复杂度 ---- O(nlog(n)) 每次选取的基准都是中位数，这样每次都均匀的划分出两个分区，只需要logn次划分就能结束递归，时间复杂度为O(nlogn)
****最差时间复杂度 ---- O(n^2) 每次选取的基准都是最大（或最小）的元素，导致每次只划分出了一个分区，需要进行n-1次划分才能结束递归，时间复杂度为O(n^2)
****平均时间复杂度 ---- O(nlog(n))
****所需辅助空间 ------主要是递归造成的栈空间的使用(用来保存left和right等局部变量)，取决于递归树的深度，一般为O(logn)，最差为O(n)
****稳定性 ------------ 不稳定
*******************************************************/
void QuickSort(int array[], int left, int right)
{
	if (left >= right)
		return;

	int pivot_index = Partition(array, left, right);// 基准的索引
	QuickSort(array, left, pivot_index - 1);
	QuickSort(array, pivot_index + 1, right);

}