#include <iostream>
#include <vector>
using namespace std;

class SolutionInsertSort
{//插入排序(insert sort)
public:
	template <typename Comparable>
	void insertionSort( vector<Comparable> & a)
	{
		for (int p = 1; p < a.size(); ++p)
		{
			Comparable tmp = std::move( a[p] );
			
			int j;
			for (j = p; j > 0 && a[j-1] > tmp; --j)
			{//较大元素向右移动一位
				a[j] = std::move( a[j-1] );
			}
			a[j] = move(tmp);//tmp置于正确位置
		}
	}
	//STL版
	template <typename Iterator>
	void insertionSort( const Iterator & begin, const Iterator & end )//重载
	{
		insertionSort(begin, end, less<decltype(*begin)>() );
	}
	
	template <typename Iterator, typename Comparable>
	void insertionSort( const Iterator & begin, const Iterator & end, Comparable lessThan )
	{
		if ( begin == end ) return;
		
		Iterator j;
		for ( Iterator p = begin + 1; p != end; ++p )
		{
			auto tmp = std::move( *p );
			for ( j = p; j != begin && lessThan( tmp, *( j-1 ) ); --j )
				*j = std::move( *(j-1) );
			*j = std::move( tmp );	
		}
	}
};

class SolutionShellSort
{//shellsort
public:
	template <typename Comparable>
	void shellsort( vector<Comparable> & a )
	{
		for (int gap = a.size() / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < a.size(); ++i)
			{
				Comparable tmp = std::move( a[i] );
				
				int j = i;
				for (; j >= gap && tmp < a[j - gap]; j -= gap)
					a[j] = std::move( a[j - gap]);
				a[j] = std::move( tmp );				
			}
		}
	}
};

class SolutionHeapSort
{//heapsort
public:
	template <typename Comparable>
	void heapSort( vector<Comparable> & a )
	{
		//build heap
		for (int i = a.size() / 2 - 1; i >=0; --i)//层层构建
			percDown( a, i, a.size() );
		//delete Max
		for (int j = a.size() - 1; j > 0; --j)
		{
			std::swap(a[0], a[j]);
			percDown(a, 0, j);
		}
	}
	inline int leftChild( int i )
	{
		return 2 * i + 1;
	}
	
	template <typename Comparable>
	void percDown( vector<Comparable> & a ,int i, int n )
	{
		int child = 0;
		Comparable tmp;
		
		for ( tmp = std::move( a[i] );leftChild(i) < n; i = child)
		{
			child = leftChild( i );
			if (child != n - 1 && a[child] < a[child + 1])
				++child;
			if (tmp < a[child])
				a[i] = std::move( a[child] );
			else
				break;
		}
		a[i] = std::move( tmp );
	}	
};

class SolutionMergeSort
{//归并merge sort
public:
	template <typename Comparable>
	void mergeSort( vector<Comparable> & a )
	{
		vector<Comparable> tmpArray( a.size() );//使用了tmpArray 空间复杂度上升
		mergeSort(a, tmpArray, 0, a.size() - 1);//重载
	}
	
	template <typename Comparable>
	void mergeSort( vector<Comparable> & a, vector<Comparable> & tmpArray, int left, int right )
	{
		if (left < right)
		{
			int center = (left + right) / 2;
			mergeSort(a, tmpArray, left, center);
			mergeSort(a, tmpArray, center + 1, right);
			merge(a, tmpArray, left, center + 1, right);
		}
	}
	template <typename Comparable>
	void merge( vector<Comparable> & a, vector<Comparable> & tmpArray, int leftPos, int rightPos, int rightEnd )
	{
		int leftEnd = rightPos - 1;
		int tmpPos = leftPos;
		int numElements = rightEnd - leftPos + 1;
		
		//主循环
		while ( leftPos <= leftEnd && rightPos <= rightEnd )
			if ( a[ leftPos ] <= a[ rightPos ] )
				tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
			else
				tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );
		
		while ( leftPos <= leftEnd )//前半部分剩余元素
			tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );\
		
		while ( rightPos <= rightEnd )//后半部分剩余元素
			tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );
			
		 for ( int i = 0; i < numElements; ++i , --rightEnd)
			a[ rightEnd ] = std::move( tmpArray[ rightEnd ] ); 
	}
};

class Solution
{//快排
public:
	template <typename Comparable>
	void SORT( vector<Comparable> & items )
	{//选中间元素作为枢纽元
		if ( items.size() > 1 )
		{
			vector<Comparable> smaller, same, larger;
			auto chooseItem = items[ items.size() / 2 ];
			
			for ( auto & i : items )
			{
				if ( i < chooseItem )
					smaller.push_back( std::move( i ) );
				else if ( i > chooseItem )
					larger.push_back( std::move( i ) );
				else
					same.push_back( std::move( i ) );
			}
			
			SORT( smaller );
			SORT( larger );
			
			std::move(begin( smaller ), end( smaller ), begin( items ));
			std::move(begin( same ), end( same ), begin( items ) + smaller.size());
			std::move(begin( larger ), end( larger ), end(items) - larger.size());
		}
	}
	
	template <typename Comparable>
	void quicksort( vector<Comparable> & a )
	{
		quicksort(a, 0, a.size() - 1);
	}
	template <typename Comparable>
	const Comparable & median3(vector<Comparable> & a, int left, int right)
	{//返回三项中的中值
		int center = (left + right) / 2;
		
		if ( a[center] < a[left] ) std::swap( a[center], a[left] );
		if ( a[right] < a[left] ) std::swap( a[right], a[left] );
		if ( a[right] < a[center] ) std::swap( a[right], a[center] );
		
		std::swap( a[center], a[right - 1] );
		return a[right - 1];
	}
	template <typename Comparable>
	void quicksort( vector<Comparable> & a, int left, int right )
	{
		SolutionInsertSort s;
		if (left + 10 <= right)
		{
			const Comparable & pivot = median3(a, left, right);
			int i = left, j = right - 1;
			for ( ; ; )
			{
				while ( a[++i] < pivot) {}
				while ( pivot < a[--j]) {}
				if (i < j) std::swap( a[i], a[j]);
				else break;
			}
			std::swap( a[i], a[right - 1]);//恢复枢纽元
			
			quicksort(a, left, i - 1);
			quicksort(a, i + 1, right);
		}
		else
			s.insertionSort( begin(a) + left, begin(a) + right + 1);
	}
};

bool compare(const string a,const string b) 
{ //sort中的compare函数编写
	if (a.size() == b.size()) return a < b;//降序
	else return a.size() < b.size();//以size降序排列
}

//int main()
//{
//	vector<int> vec{ 97,31,58,41,26,59,53,1,12,123  };
//	Solution s;
//	s.quicksort( vec );
//	for (auto & i : vec) cout << i << " " ;
//}













