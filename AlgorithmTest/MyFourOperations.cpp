#include"MyFourOperations.h"
#include<iostream>

using namespace std;

/**************************************************
Function: MyTreeTest
Desc:  树的测试
Input:
* @param  -
Output:	nullptr
Return:	nullptr
Others:	nullptr
*******************************************************/
void MyFourOperations(void)
{
	int remainde = 0xffffffff;
	cout << Add(14, 7)<<endl;
	cout << Subtract0(14, 7) << endl;
	cout << Subtract1(14, 7) << " " << Subtract1(7, 14) << endl;
	cout << "14*5=" << Multiply(14, 5) << endl;
	cout << "14/3=" << Divide(14, 3, &remainde) <<"......"<< remainde <<endl;
}
/**************************************************
Function: static int Add(int a, int b)
Desc:  不用加减乘除做加法：第一步先各位相加不计进位（或运^算），第二步记下进位（&远算在<<1）
****再把进位和不进位相加，直到没有进位为止。
Input:int a, int b
* @param  a - 加数
* @param  b - 被加数
Output:	nullptr
Return:	int  返回相加结果
Others:	nullptr
*******************************************************/
static int Add(int a, int b)
{
	int sum = a ^ b; 
	int carry = a & b;
	while (carry != 0)
	{
		a = sum;
		b = carry << 1;
		sum = a ^ b;
		carry = a & b;
	}
	return sum;
}

/**************************************************
Function: static int Subtract(int a, int b)
Desc:  不用加减乘除做减法：减去一个数等于加上这个数的相反数（负数的补码等于它绝对值的反码+1）
Input:int a, int b
* @param  a - 被减数
* @param  b - 减数
Output:	nullptr
Return:	int  返回相减结果
Others:	nullptr
*******************************************************/
static int Subtract0(int a, int b)
{
	int oppositeNumber = Add(~b, +1);
	return Add(a, oppositeNumber);
}

/**************************************************
Function: static int Subtract(int a, int b)
Desc:  
****1、首先，如果减数为0，则被减数即为减法的结果，运算结束。
****但如果减数不为0，我们可以先把被减数和减数上同为1的位从两个数上去除。至于如何分离出值同为1的位，则可以通过求位与操作来做到；而把这些1分别中被减数和减数中去除，
****则可以通过按位异或来的操作来实现。
****2、经步骤1处理后，被减数和减数在对应的位上，将或者通为0，或者分别为0和1，却不会同为1。此时：
****如果对应位被减数=1，而减数=0，则所得结果对应位也为1；
****如果对应位被减数=0，而减数=1，则所得结果对应位还是1，但此时须向前一位借1；
****即，通过被减数与减数作位异或的操作得到临时结果，和通过对减数左移一位得到需从临时结果中减去的借数。
****3、于是，经过步骤2后，原来的减法变成了要求：临时结果 - 借数
****很明显，只要以临时结果为被减数，借数为减数，重复步骤1~3即可。
Input:int a, int b
* @param  a - 被减数
* @param  b - 减数
Output:	nullptr
Return:	int  返回相减结果
Others:	nullptr
*******************************************************/
static int Subtract1(int a, int b)
{
	while (b != 0)
	{
		int sameBits  = a & b;
		a ^= sameBits;
		b ^= sameBits;
		a |= b;
		b <<= 1;

	}
	return a;
}

/**************************************************
Function: int OppositeNumber(int n)
Desc:  求数的相反数（负数的补码等于它绝对值的反码+1）
Input:int n
* @param 
* @param 
Output:	nullptr
Return:	int  
Others:	nullptr
*******************************************************/
int OppositeNumber(int n)
{
	return Add(~n, 1);
}
#define BITS_OF_ONE_BYTE     8
#define SIGN_BIT_FLAG_FOR_BYTE   0x80     // for signed byte/char

/**************************************************
Function: int SignBitFlagOfInt(void)
Desc:  为了能同时适应32位和64位的整形数，在取符号信息与设置溢出判断位时，使用了以下的辅助宏和函数。
Input:
* @param
* @param
Output:	nullptr
Return:	int
Others:	nullptr
*******************************************************/
int SignBitFlagOfInt(void)
{
	static int signBitFlag = 0;

	static bool bIs1stCalled = true;
	if (bIs1stCalled)
	{
		int temp = SIGN_BIT_FLAG_FOR_BYTE;
		while (temp != 0)
		{
			signBitFlag = temp;
			temp <<= BITS_OF_ONE_BYTE;
		}
		bIs1stCalled = false;
	}

	return signBitFlag;
}

/**************************************************
Function: int Multiply(int a, int b)
Desc:  为了能同时适应32位和64位的整形数，在取符号信息与设置溢出判断位时，使用了以下的辅助宏和函数。
****7=111; 5=101  
****14*7 = 14+14*2+14*4 ;14*5 = 14+14*4 
Input:
* @param
* @param
Output:	nullptr
Return:	int
Others:	nullptr
*******************************************************/
int Multiply(int a, int b)
{
	int signStatA = a & SignBitFlagOfInt();
	if (signStatA != 0)
	{
		a = OppositeNumber(a);
	}

	int signStatB = b & SignBitFlagOfInt();
	if (signStatB != 0)
	{
		b = OppositeNumber(b);
	}

	int overFlowFlag = SignBitFlagOfInt(); // used for checking if the signed int data overflowed.
	int product = 0; // the result of |a| * |b|
	for (int curBitPos = 1; curBitPos != 0; curBitPos <<= 1)
	{
		if ((b & curBitPos) != 0)
		{
			product = Add(product, a);
			if (((a & overFlowFlag) != 0)
				|| ((product & overFlowFlag) != 0))
			{
				throw std::exception("The result data war overflowed.");
			}
		}
		a <<= 1;
	}

	return ((signStatA ^ signStatB) == 0) ? product : OppositeNumber(product);
}

/**************************************************
Function: int Divide(int a, int b, int * pRem )//
Desc:  为了能同时适应32位和64位的整形数，在取符号信息与设置溢出判断位时，使用了以下的辅助宏和函数。
Input:
* @param
* @param
Output:	int * pRem   余数
Return:	int
Others:	nullptr
*******************************************************/
int Divide(int a, int b, int * pRem /*= NULL*/)
{
	if (b == 0)
	{
		throw std::exception("Invalid divisor!! (The divisor can't be 0!)");
	}

	int signStatA = a & SignBitFlagOfInt();
	if (signStatA != 0)
	{
		a = OppositeNumber(a);
	}

	int signStatB = b & SignBitFlagOfInt();
	if (signStatB != 0)
	{
		b = OppositeNumber(b);
	}

	int quotient = 0;
	int backupB = b;
	while (a >= b)
	{
		int tempB = b << 1;
		int tempQ = 1;
		while ((tempB <= a) && ((tempB & SignBitFlagOfInt()) == 0))
		{
			b = tempB;
			tempQ <<= 1;
			tempB <<= 1;
		}

		a = Subtract1(a, b);
		quotient |= tempQ;
		b = backupB;
	}

	if (pRem != NULL)
	{
		*pRem = a;
	}

	if ((signStatA != 0) && (a != 0))
	{
		quotient = Add(quotient, 1);
		if (pRem != NULL)
		{
			*pRem = Subtract1(b, *pRem);
		}
	}

	return ((signStatA ^ signStatB) == 0) ? quotient : OppositeNumber(quotient);
}