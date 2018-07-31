#include"MyFourOperations.h"
#include<iostream>

using namespace std;

/**************************************************
Function: MyTreeTest
Desc:  ���Ĳ���
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
Desc:  ���üӼ��˳����ӷ�����һ���ȸ�λ��Ӳ��ƽ�λ������^�㣩���ڶ������½�λ��&Զ����<<1��
****�ٰѽ�λ�Ͳ���λ��ӣ�ֱ��û�н�λΪֹ��
Input:int a, int b
* @param  a - ����
* @param  b - ������
Output:	nullptr
Return:	int  ������ӽ��
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
Desc:  ���üӼ��˳�����������ȥһ�������ڼ�����������෴���������Ĳ������������ֵ�ķ���+1��
Input:int a, int b
* @param  a - ������
* @param  b - ����
Output:	nullptr
Return:	int  ����������
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
****1�����ȣ��������Ϊ0���򱻼�����Ϊ�����Ľ�������������
****�����������Ϊ0�����ǿ����Ȱѱ������ͼ�����ͬΪ1��λ����������ȥ����������η����ֵͬΪ1��λ�������ͨ����λ�������������������Щ1�ֱ��б������ͼ�����ȥ����
****�����ͨ����λ������Ĳ�����ʵ�֡�
****2��������1����󣬱������ͼ����ڶ�Ӧ��λ�ϣ�������ͨΪ0�����߷ֱ�Ϊ0��1��ȴ����ͬΪ1����ʱ��
****�����Ӧλ������=1��������=0�������ý����ӦλҲΪ1��
****�����Ӧλ������=0��������=1�������ý����Ӧλ����1������ʱ����ǰһλ��1��
****����ͨ���������������λ���Ĳ����õ���ʱ�������ͨ���Լ�������һλ�õ������ʱ����м�ȥ�Ľ�����
****3�����ǣ���������2��ԭ���ļ��������Ҫ����ʱ��� - ����
****�����ԣ�ֻҪ����ʱ���Ϊ������������Ϊ�������ظ�����1~3���ɡ�
Input:int a, int b
* @param  a - ������
* @param  b - ����
Output:	nullptr
Return:	int  ����������
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
Desc:  �������෴���������Ĳ������������ֵ�ķ���+1��
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
Desc:  Ϊ����ͬʱ��Ӧ32λ��64λ������������ȡ������Ϣ����������ж�λʱ��ʹ�������µĸ�����ͺ�����
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
Desc:  Ϊ����ͬʱ��Ӧ32λ��64λ������������ȡ������Ϣ����������ж�λʱ��ʹ�������µĸ�����ͺ�����
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
Desc:  Ϊ����ͬʱ��Ӧ32λ��64λ������������ȡ������Ϣ����������ж�λʱ��ʹ�������µĸ�����ͺ�����
Input:
* @param
* @param
Output:	int * pRem   ����
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