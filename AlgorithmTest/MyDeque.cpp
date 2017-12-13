#include"MyDeque.h"
#include<deque>
#include <iostream>

using namespace std;

int MyDequeTest(void)
{
    deque<int> deqInt;
    deqInt.push_back(1);  //在容器尾部加入一个元素
    deqInt.push_back(3);  //移除容器中最后一个元素
    deqInt.push_back(5);
    deqInt.push_back(7);
    deqInt.push_back(9);
    deqInt.push_front(123);
    deqInt.pop_back();
    for (deque<int>::iterator it = deqInt.begin(); it != deqInt.end(); ++it)
    {
        cout << *it;
        cout << " ";
    }
    cout << endl;
    for (deque<int>::reverse_iterator rit = deqInt.rbegin(); rit != deqInt.rend(); ++rit) //反向输出
    {
        cout << *rit;
        cout << " ";
    }
   int size = deqInt.size();
    cout << endl<<"deqInt size is : "<<size<<endl;
    //int iA = deqInt.at(10);
    
    return 0;
}
/*****************************/
/**********
Deque简介
	deque是“double-ended queue”的缩写，和vector一样都是STL的容器，deque是双端数组，而vector是单端的。
	deque在接口上和vector非常相似，在许多操作的地方可以直接替换。
	deque可以随机存取元素（支持索引值直接存取， 用[]操作符或at()方法，这个等下会详讲）。
	deque头部和尾部添加或移除元素都非常快速。但是在中部安插元素或移除元素比较费时。
	#include <deque>
deque对象的默认构造
deque采用模板类实现，deque对象的默认构造形式：deque<T> deqT;
deque <int> deqInt;            //一个存放int的deque容器。
deque <float> deq Float;     //一个存放float的deque容器。
deque <string> deq String;     //一个存放string的deque容器。
...
//尖括号内还可以设置指针类型或自定义类型。

deque末尾的添加移除操作
理论知识:
	deque.push_back(elem);	//在容器尾部添加一个数据
	deque.push_front(elem);	//在容器头部插入一个数据
	deque.pop_back();    		//删除容器最后一个数据
	deque.pop_front();		//删除容器第一个数据

deque的数据存取
理论知识:
	deque.at(idx);  //返回索引idx所指的数据，如果idx越界，抛出out_of_range。
	deque[idx];  //返回索引idx所指的数据，如果idx越界，不抛出异常，直接出错。
	deque.front();   //返回第一个数据。
	deque.back();  //返回最后一个数据

deque与迭代器
理论知识
	deque.begin();  //返回容器中第一个元素的迭代器。
	deque.end();  //返回容器中最后一个元素之后的迭代器。
	deque.rbegin();  //返回容器中倒数第一个元素的迭代器。
	deque.rend();   //返回容器中倒数最后一个元素之后的迭代器。

deque对象的带参数构造
理论知识
	deque(beg,end);    //构造函数将[beg, end)区间中的元素拷贝给本身。注意该区间是左闭右开的区间。
	deque(n,elem);   //构造函数将n个elem拷贝给本身。
	deque(const deque  &deq);  //拷贝构造函数。

deque的赋值
理论知识
	deque.assign(beg,end);    //将[beg, end)区间中的数据拷贝赋值给本身。注意该区间是左闭右开的区间。
	deque.assign(n,elem);  //将n个elem拷贝赋值给本身。
	deque& operator=(const deque &deq);	//重载等号操作符
	deque.swap(deq);  // 将vec与本身的元素互换

deque的大小
理论知识
	deque.size();	   //返回容器中元素的个数
	deque.empty();	   //判断容器是否为空
	deque.resize(num);   //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
	deque.resize(num, elem);  //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。

deque的插入
理论知识
	deque.insert(pos,elem);   //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
	deque.insert(pos,n,elem);   //在pos位置插入n个elem数据，无返回值。
	deque.insert(pos,beg,end);   //在pos位置插入[beg,end)区间的数据，无返回值。

deque的删除
理论知识
	deque.clear();	//移除容器的所有数据
	deque.erase(beg,end);  //删除[beg,end)区间的数据，返回下一个数据的位置。
	deque.erase(pos);    //删除pos位置的数据，返回下一个数据的位置。


****************/