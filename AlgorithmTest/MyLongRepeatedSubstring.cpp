#include"MyLongRepeatedSubstring.h"
#include<algorithm>
#include<vector>
/**
* StringCompare 字符串比较
* pa：字符串a的头指针 输入
* pb：字符串b的头指针 输出
* return：true or false
* 说明：a小于b返回 true；a大于等于b返回 false
*/
bool StringCompare(const char *pa, const char *pb)
{
	while (*pa != '\0' && *pb != '\0' && *pa == *pb)
	{
		pa++;
		pb++;
	}

	if (*pa == '\0' && *pb != '\0') /* 小于 */
		return true;
	else if (*pb == '\0') /* 大于等于 */
		return false;
	else
		return *pa < *pb;
}

/**
* LengthOfCommon 计算两个字符串从头开始的最长子序列长度
* p1：字符串1的头指针  输入
* p2：字符串2的头指针  输入
* return：从头开始公共子串的长度
*/
int LengthOfCommon(const char *p1, const char *p2)
{
	int length = 0;
	while (p1[length] != '\0' && p2[length] != '\0' && p1[length] == p2[length])
		length++;

	return length;
}

/**
* longestRepeatedSubstring 查找字符串中的最长重复子序列
* s：输入字符串 输入
* return：输出字符串
*/
string longestRepeatedSubstring(string s)
{
	string result; // 输出结果

				   /* 构造后缀数组 */
	vector<const char*> pStr;
	const char *str = s.c_str();
	for (int i = 0; i < s.size(); i++)
	{
		pStr.push_back(str);
		str++;
	}

	/* 对后缀数组进行排序 */
	sort(pStr.begin(), pStr.end(), StringCompare);

	/* 依次比较后缀数组的两个相邻子字符串 */
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

	/* 提取公共子字符串 */
	for (int i = 0; i < currentMaxLength; i++)
	{
		result += pStr[currentIndex][i];
	}

	/*输出最长相邻重复字串*/
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