#include"MyDeque.h"
#include<deque>
#include <iostream>

using namespace std;

int MyDequeTest(void)
{
    deque<int> deqInt;
    deqInt.push_back(1);  //������β������һ��Ԫ��
    deqInt.push_back(3);  //�Ƴ����������һ��Ԫ��
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
    for (deque<int>::reverse_iterator rit = deqInt.rbegin(); rit != deqInt.rend(); ++rit) //�������
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
Deque���
	deque�ǡ�double-ended queue������д����vectorһ������STL��������deque��˫�����飬��vector�ǵ��˵ġ�
	deque�ڽӿ��Ϻ�vector�ǳ����ƣ����������ĵط�����ֱ���滻��
	deque���������ȡԪ�أ�֧������ֱֵ�Ӵ�ȡ�� ��[]��������at()������������»��꽲����
	dequeͷ����β����ӻ��Ƴ�Ԫ�ض��ǳ����١��������в�����Ԫ�ػ��Ƴ�Ԫ�رȽϷ�ʱ��
	#include <deque>
deque�����Ĭ�Ϲ���
deque����ģ����ʵ�֣�deque�����Ĭ�Ϲ�����ʽ��deque<T> deqT;
deque <int> deqInt;            //һ�����int��deque������
deque <float> deq Float;     //һ�����float��deque������
deque <string> deq String;     //һ�����string��deque������
...
//�������ڻ���������ָ�����ͻ��Զ������͡�

dequeĩβ������Ƴ�����
����֪ʶ:
	deque.push_back(elem);	//������β�����һ������
	deque.push_front(elem);	//������ͷ������һ������
	deque.pop_back();    		//ɾ���������һ������
	deque.pop_front();		//ɾ��������һ������

deque�����ݴ�ȡ
����֪ʶ:
	deque.at(idx);  //��������idx��ָ�����ݣ����idxԽ�磬�׳�out_of_range��
	deque[idx];  //��������idx��ָ�����ݣ����idxԽ�磬���׳��쳣��ֱ�ӳ���
	deque.front();   //���ص�һ�����ݡ�
	deque.back();  //�������һ������

deque�������
����֪ʶ
	deque.begin();  //���������е�һ��Ԫ�صĵ�������
	deque.end();  //�������������һ��Ԫ��֮��ĵ�������
	deque.rbegin();  //���������е�����һ��Ԫ�صĵ�������
	deque.rend();   //���������е������һ��Ԫ��֮��ĵ�������

deque����Ĵ���������
����֪ʶ
	deque(beg,end);    //���캯����[beg, end)�����е�Ԫ�ؿ���������ע�������������ҿ������䡣
	deque(n,elem);   //���캯����n��elem����������
	deque(const deque  &deq);  //�������캯����

deque�ĸ�ֵ
����֪ʶ
	deque.assign(beg,end);    //��[beg, end)�����е����ݿ�����ֵ������ע�������������ҿ������䡣
	deque.assign(n,elem);  //��n��elem������ֵ������
	deque& operator=(const deque &deq);	//���صȺŲ�����
	deque.swap(deq);  // ��vec�뱾���Ԫ�ػ���

deque�Ĵ�С
����֪ʶ
	deque.size();	   //����������Ԫ�صĸ���
	deque.empty();	   //�ж������Ƿ�Ϊ��
	deque.resize(num);   //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
	deque.resize(num, elem);  //����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����

deque�Ĳ���
����֪ʶ
	deque.insert(pos,elem);   //��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
	deque.insert(pos,n,elem);   //��posλ�ò���n��elem���ݣ��޷���ֵ��
	deque.insert(pos,beg,end);   //��posλ�ò���[beg,end)��������ݣ��޷���ֵ��

deque��ɾ��
����֪ʶ
	deque.clear();	//�Ƴ���������������
	deque.erase(beg,end);  //ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
	deque.erase(pos);    //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�


****************/