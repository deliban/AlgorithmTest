#include"MyLongRepeatedSubstring.h"
#include<algorithm>
#include<vector>
/**
* StringCompare �ַ����Ƚ�
* pa���ַ���a��ͷָ�� ����
* pb���ַ���b��ͷָ�� ���
* return��true or false
* ˵����aС��b���� true��a���ڵ���b���� false
*/
bool StringCompare(const char *pa, const char *pb)
{
	while (*pa != '\0' && *pb != '\0' && *pa == *pb)
	{
		pa++;
		pb++;
	}

	if (*pa == '\0' && *pb != '\0') /* С�� */
		return true;
	else if (*pb == '\0') /* ���ڵ��� */
		return false;
	else
		return *pa < *pb;
}

/**
* LengthOfCommon ���������ַ�����ͷ��ʼ��������г���
* p1���ַ���1��ͷָ��  ����
* p2���ַ���2��ͷָ��  ����
* return����ͷ��ʼ�����Ӵ��ĳ���
*/
int LengthOfCommon(const char *p1, const char *p2)
{
	int length = 0;
	while (p1[length] != '\0' && p2[length] != '\0' && p1[length] == p2[length])
		length++;

	return length;
}

/**
* longestRepeatedSubstring �����ַ����е���ظ�������
* s�������ַ��� ����
* return������ַ���
*/
string longestRepeatedSubstring(string s)
{
	string result; // ������

				   /* �����׺���� */
	vector<const char*> pStr;
	const char *str = s.c_str();
	for (int i = 0; i < s.size(); i++)
	{
		pStr.push_back(str);
		str++;
	}

	/* �Ժ�׺����������� */
	sort(pStr.begin(), pStr.end(), StringCompare);

	/* ���αȽϺ�׺����������������ַ��� */
	int currentMaxLength = 0;
	int currentIndex = 1;
	for (int i = 1; i < pStr.size(); i++)
	{
		int length = LengthOfCommon(pStr[i - 1], pStr[i]);
		if (length > currentMaxLength)
		{
			currentMaxLength = length;
			currentIndex = i;
		}
	}

	/* ��ȡ�������ַ��� */
	for (int i = 0; i < currentMaxLength; i++)
	{
		result += pStr[currentIndex][i];
	}

	/*���������ظ��ִ�*/
	//cin >> str;
	//cout << longestRepeatedSubstring(str).c_str() << endl;
	//string result1 = longestRepeatedSubstring(str).c_str();
	//int pos = 0;
	//int size = result1.size();
	//int cout = 0;
	//int temp = 0;
	//pos = str.find(result1, pos);
	//do {
	//	cout++;
	//	pos = size + temp;
	//	temp = str.find(result1, pos);
	//	if ((temp - pos) != 1)
	//		break;
	//} while (pos>0);

	//size = size * cout;
	//printf("%d", size);

	return result;
}