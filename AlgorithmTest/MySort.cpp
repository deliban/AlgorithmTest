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
Desc:  Sort�Ĳ���
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

	//sort(a,a+n) ��ʾ��a[0] a[1] a[2] ... a[n-1] ����
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
Desc:  ����
Input: int *i, int *j
* @param  *i - ��������i��ָ���������(C++�ſ���������)
* @param  *j - ��������j��ָ���������
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
Desc:  ����
Input: int *i, int *j
* @param  *i - ��������i��ָ���������(C++�ſ���������)
* @param  *j - ��������j��ָ���������
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
Desc:  ����
Input: int &i, int &j
* @param  &i - ��������i��ָ���������
* @param  &j - ��������j��ָ���������
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
Desc:  ����
Input: int array[],int i, int j
* @param  array[] - �����������ڵ�����
* @param  i - �����������ڵ������±�i
* @param  j - �����������ڵ������±�j
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
Desc:  ��������
Input: array[],n
* @param  array[] - �����������
* @param  n - ����������Ԫ�صĴ�С
Output:	nullptr
Return:	nullptr
Others:	
****����Ϊ���������ǽ������е�,��ʱʱ�临�Ӷ�O(n^2)
****������Ϊ�����������������е�,��ʱʱ�临�Ӷ�O(n)
****ƽ��ʱ�临�Ӷ� ---- O(n^2)
****���踨���ռ� ------ O(1)   //�������һ������ռ����³���� get��
****�ȶ��� ------------ �ȶ�
****Ӧ�� --- ���������ʺ϶����������Ƚϴ������Ӧ�á����ǣ������Ҫ�������������С����������С��ǧ����ô����
������һ�������ѡ�� ���������ڹ�ҵ������Ҳ���Ź㷺��Ӧ�ã���STL��sort�㷨��stdlib��qsort�㷨�У���������
������Ϊ��������Ĳ��䣬��������Ԫ�ص�����ͨ��Ϊ8�������£��� 
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
Desc:  ���ֲ������򣨲�������ĸĽ���
Input: array[],n
* @param  array[] - �����������
* @param  n - ����������Ԫ�صĴ�С
Output:	nullptr
Return:	nullptr
Others:
****����Ϊ���������ǽ������е�,��ʱʱ�临�Ӷ�O(n^2)
****����ʱ�临�Ӷ� ---- O(nlogn)
****ƽ��ʱ�临�Ӷ� ---- O(n^2)
****���踨���ռ� ------ O(1)   
****�ȶ��� ------------ �ȶ�
****Ӧ�� --- ��n�ϴ�ʱ�����ֲ�������ıȽϴ�����ֱ�Ӳ���������������õö࣬����ֱ�Ӳ��������������Ҫ�
������Ԫ�س�ʼ�����Ѿ��ӽ�����ʱ��ֱ�Ӳ�������ȶ��ֲ�������Ƚϴ����١����ֲ�������Ԫ���ƶ�������ֱ�Ӳ���
������ͬ��������Ԫ�س�ʼ���С�
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
Desc:  ϣ�����򣨲�������ĸĽ���
Input: array[],n
* @param  array[] - �����������
* @param  n - ����������Ԫ�صĴ�С
Output:	nullptr
Return:	nullptr
Others:
****���ʱ�临�Ӷ� ---- ���ݲ������еĲ�ͬ����ͬ����֪����ΪO(n(logn)^2)
****����ʱ�临�Ӷ� ----  O(n)
****ƽ��ʱ�临�Ӷ� ---- ���ݲ������еĲ�ͬ����ͬ
****���踨���ռ� ------ O(1)
****�ȶ��� ------------ ���ȶ�
*******************************************************/
static void ShellSort(int array[], int n)
{
	int h = 0;
	while (h <= n)           //��������
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
		h = (h - 1) / 3;   //�ݼ�����
	}
}
/**************************************************
Function: void BubbleSort(int array[], int n)
Desc:  ð������
Input: array[],n
* @param  array[] - �����������
* @param  n - ����������Ԫ�صĴ�С
Output:	nullptr
Return:	nullptr
Others:
****����ʱ�临�Ӷ� ---- ��������ڲ�ѭ����һ������ʱ,ʹ��һ���������ʾ������Ҫ�����Ŀ���,
���԰�����ʱ�临�ӶȽ��͵�O(n)
****���ʱ�临�Ӷ� ---- O(n^2)
****ƽ��ʱ�临�Ӷ� ---- O(n^2)
****���踨���ռ� ------ O(1)
****�ȶ��� ------------ �ȶ�
*******************************************************/
static void BubbleSort(int array[], int n)
{
	for (int i = 0; i< n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i ; j++)
		{
			if (array[j] > array[j + 1])
				Swap3(array,j,j + 1); //������Swap1()orSwap1(),��Ϊ &(array[j])�ǳ������õĳ�ʼֵ����Ϊ��ֵ
		}
	}	

	/*��������*/
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
Desc:  ��β����ð������ĸĽ���
Input: array[],n
* @param  array[] - �����������
* @param  n - ����������Ԫ�صĴ�С
Output:	nullptr
Return:	nullptr
Others:
****����ʱ�临�Ӷ� ---- ���������һ��ʼ�Ѿ��󲿷�������Ļ�,��ӽ�O(n)
****���ʱ�临�Ӷ� ---- O(n^2)
****ƽ��ʱ�临�Ӷ� ---- O(n^2)
****���踨���ռ� ------ O(1)
****�ȶ��� ------------ �ȶ�
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
Desc:  ѡ������ 
****    ѡ��������ð�����������ð������ͨ�����ν�����������˳�򲻺Ϸ���Ԫ��λ�ã��Ӷ�����ǰ��С����Ԫ�طŵ�����
****��λ�ã���ѡ������ÿ����һ�ζ���ס�˵�ǰ��С����Ԫ�ص�λ�ã�������һ�ν����������ɽ���ŵ����ʵ�λ�á�
Input: array[],n
* @param  array[] - �����������
* @param  n - ����������Ԫ�صĴ�С
Output:	nullptr
Return:	nullptr
Others:
****����ʱ�临�Ӷ� ---- ���������һ��ʼ�Ѿ��󲿷�������Ļ�,��ӽ�O(n)
****���ʱ�临�Ӷ� ---- O(n^2)
****ƽ��ʱ�临�Ӷ� ---- O(n^2)
****���踨���ռ� ------ O(1)
****�ȶ��� ------------ ���ȶ� �������������ͬ�������ʱ�򣬲��ܸı����ǵ����λ�ã�
�������У�{ 5, 8, 5, 2, 9 }��һ��ѡ�����СԪ����2��Ȼ���2�͵�һ��5���н������Ӷ��ı�������Ԫ��5����Դ���
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
Desc:  �ϲ��������ź��������A[left...mid]��A[mid+1...right]
Input: array[],n
* @param  array[] - �����������
* @param  n - ����������Ԫ�صĴ�С
Output:	nullptr
Return:	nullptr
Others:
****����ʱ�临�Ӷ� ---- ���������һ��ʼ�Ѿ��󲿷�������Ļ�,��ӽ�O(n)
****���ʱ�临�Ӷ� ---- O(n^2)
****ƽ��ʱ�临�Ӷ� ---- O(n^2)
****���踨���ռ� ------ O(1)
****�ȶ��� ------------ ���ȶ� �������������ͬ�������ʱ�򣬲��ܸı����ǵ����λ�ã�
�������У�{ 5, 8, 5, 2, 9 }��һ��ѡ�����СԪ����2��Ȼ���2�͵�һ��5���н������Ӷ��ı�������Ԫ��5����Դ���
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
		temp[index++] = array[i] <= array[j] ? array[i++] : array[j++];//���Ⱥű�֤�鲢���ȶ���
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
Desc:   �ݹ�ʵ�ֵĹ鲢����(�Զ�����)
Input: array[],left,right
* @param  array[] - �����������
* @param  left - ����������Ԫ�ص����
* @param  right - ����������Ԫ�ص��Ҷ�
Output:	nullptr
Return:	nullptr
Others:
****����ʱ�临�Ӷ� ---- O(nlogn)
****���ʱ�临�Ӷ� ---- O(nlogn)
****ƽ��ʱ�临�Ӷ� ----O(nlogn)
****���踨���ռ� ------ O(n)
****�ȶ��� ------------ �ȶ� 
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
 Desc:   �ǵݹ�ʵ�ֵĹ鲢����(�Ե�����)
 Input: array[],len
 * @param  array[] - �����������
 * @param  len - ����������Ԫ�صĴ�С
 Output:	nullptr
 Return:	nullptr
 Others:
 ****����ʱ�临�Ӷ� ---- O(nlog(n))
 ****���ʱ�临�Ӷ� ---- O(nlog(n))
 ****ƽ��ʱ�临�Ӷ� ---- O(nlog(n))
 ****���踨���ռ� ------ O(n)  //�û��ϲ�
 ****�ȶ��� ------------ �ȶ� 
 *******************************************************/
static void MergeSortIteration(int array[], int len)
{
	int left, mid, right;// ����������,ǰһ��ΪA[left...mid]����һ��������ΪA[mid+1...right]
	for (int i = 1; i < len; i *= 2)// ������Ĵ�Сi��ʼΪ1��ÿ�ַ���
	{
		left = 0;
		while (left + i < len) // ��һ�����������(��Ҫ�鲢)
		{
			mid = left + i - 1;
			right = mid + i < len ? mid + i : len - 1;// ��һ���������С���ܲ���
			Merge(array, left, mid, right);
			left = right + 1; // ǰһ����������������ƶ�
		}
	}
}

/**************************************************
Function: static void MergeSortIteration(int array[], int len)
Desc:   �ǵݹ�ʵ�ֵĹ鲢����(�Ե�����)
Input: array[],len
* @param  array[] - �����������
* @param  len - ����������Ԫ�صĴ�С
Output:	nullptr
Return:	nullptr
Others:
****����ʱ�临�Ӷ� ---- O(nlog(n))
****���ʱ�临�Ӷ� ---- O(nlog(n))
****ƽ��ʱ�临�Ӷ� ---- O(nlog(n))
****���踨���ռ� ------ O(n)  //�û��ϲ�
****�ȶ��� ------------ �ȶ�
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
Desc:   �ǵݹ�ʵ�ֵĹ鲢����(�Ե�����)
Input: array[],len
* @param  array[] - �����������
* @param  len - ����������Ԫ�صĴ�С
Output:	nullptr
Return:	nullptr
Others:
****����ʱ�临�Ӷ� ---- O(nlog(n))
****���ʱ�临�Ӷ� ---- O(nlog(n))
****ƽ��ʱ�临�Ӷ� ---- O(nlog(n))
****���踨���ռ� ------ O(n)  //�û��ϲ�
****�ȶ��� ------------ �ȶ�
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
Desc:   �ǵݹ�ʵ�ֵĹ鲢����(�Ե�����)
Input: array[],len
* @param  array[] - �����������
* @param  len - ����������Ԫ�صĴ�С
Output:	nullptr
Return:	nullptr
Others:
****����ʱ�临�Ӷ� ---- O(nlog(n))
****���ʱ�临�Ӷ� ---- O(nlog(n))
****ƽ��ʱ�临�Ӷ� ---- O(nlog(n))
****���踨���ռ� ------ O(n)  //�û��ϲ�
****�ȶ��� ------------ �ȶ�
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
Desc:   ���ֺ���
Input: int array[], int left, int right
* @param  array[] - �����������
* @param
Output:	nullptr
Return:	nullptr
Others:
*******************************************************/
int Partition(int array[], int left, int right)
{
	int pivot = array[right];  //pivot ���� �����ĵ�  ����ÿ�ζ�ѡ�����һ��Ԫ����Ϊ��׼
	int tail = left - 1;       // tailΪС�ڻ�׼�����������һ��Ԫ�ص�����
	for (int i = left; i < right; i++)// ������׼���������Ԫ��
	{
		if (array[i] <= pivot)// ��С�ڵ��ڻ�׼��Ԫ�طŵ�ǰһ��������ĩβ
		{
			Swap3(array, ++tail, i);
		}

	}
	Swap3(array, tail + 1, right);   // ���ѻ�׼�ŵ�ǰһ��������ĺ�ߣ�ʣ�µ���������Ǵ��ڻ�׼��������
									 // �ò������п��ܰѺ���Ԫ�ص��ȶ��Դ��ң����Կ��������ǲ��ȶ��������㷨
	return tail + 1;				 // ���ػ�׼������
}

/**************************************************
Function: void QuickSort(int array[], int left, int right)
Desc:   ��������
Input: array[],len
* @param  array[] - �����������
* @param
Output:	nullptr
Return:	nullptr
Others:
****����ʱ�临�Ӷ� ---- O(nlog(n)) ÿ��ѡȡ�Ļ�׼������λ��������ÿ�ζ����ȵĻ��ֳ�����������ֻ��Ҫlogn�λ��־��ܽ����ݹ飬ʱ�临�Ӷ�ΪO(nlogn)
****���ʱ�临�Ӷ� ---- O(n^2) ÿ��ѡȡ�Ļ�׼������󣨻���С����Ԫ�أ�����ÿ��ֻ���ֳ���һ����������Ҫ����n-1�λ��ֲ��ܽ����ݹ飬ʱ�临�Ӷ�ΪO(n^2)
****ƽ��ʱ�临�Ӷ� ---- O(nlog(n))
****���踨���ռ� ------��Ҫ�ǵݹ���ɵ�ջ�ռ��ʹ��(��������left��right�Ⱦֲ�����)��ȡ���ڵݹ�������ȣ�һ��ΪO(logn)�����ΪO(n)
****�ȶ��� ------------ ���ȶ�
*******************************************************/
void QuickSort(int array[], int left, int right)
{
	if (left >= right)
		return;

	int pivot_index = Partition(array, left, right);// ��׼������
	QuickSort(array, left, pivot_index - 1);
	QuickSort(array, pivot_index + 1, right);

}