#pragma once
#include<string>
using namespace std;
static bool StringCompare(const char *pa, const char *pb);
static int LengthOfCommon(const char *p1, const char *p2);
/*因为有string 需要包含string或者vector头文件，并且申明命名空间std，才可以否则会产生编译错误*/
string longestRepeatedSubstring(string s); 
