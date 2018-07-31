#include "MyTree.h"
#include<stdio.h>
#include<iostream>
using namespace std;
/**************************************************
Function: PreOrdeTraverse(BiTree T)
Desc:  ��������ǰ�����򣩱���: ��-��-��
Input:	BiTree T
* @param T - ��������ָ��
Output:	nullptr
Return:	nullptr
Others:	nullptr
*******************************************************/
void PreOrdeTraverse(BiTree T)
{
	if (T == nullptr)
	{
		return;
	}
	printf("%c", T->data);
	cout <<T->data;
	PreOrdeTraverse(T->lchild);
	PreOrdeTraverse(T->rchild);
}

/**************************************************
Function: InOrdeTraverse
Desc:  ���������������: ��-��-��
Input:	BiTree T
* @param T - ��������ָ��
Output:	nullptr
Return:	nullptr
Others:	nullptr
*******************************************************/
void InOrdeTraverse(BiTree T)
{
	if (T == nullptr)
		return;
	InOrdeTraverse(T->lchild);
	printf("%c", T->data);
	cout << T->data;
	InOrdeTraverse(T->rchild);
}

/**************************************************
Function: PostOrdeTraverse
Desc:  �������ĺ������: ��-��-��
Input:	BiTree T
* @param T - ��������ָ��
Output:	nullptr
Return:	nullptr
Others:	nullptr
*******************************************************/
void PostOrdeTraverse(BiTree T)
{
	if (T == nullptr)
		return;

	PostOrdeTraverse(T->lchild);
	PostOrdeTraverse(T->rchild);
	printf("%c", T->data);
	cout << T->data;
}

/**************************************************
Function: CreateBiTree
Desc:  ��ǰ������������еĽ���ֵ��һ���ַ�����#��ʾ������������������ʾ������
Input:	BiTree *T
* @param  ָ���ָ�루ָ��BiTNode��ָ���ָ�룩�����������޸�ָ���ֵ������ָ��ֻ���޸�ָ��ָ�������
Output:	nullptr
Return:	nullptr
Others:	nullptr
*******************************************************/
void CreateBiTree(BiTree *T)
{
	TElemType ch;
	scanf("%c", &ch);
	cin >> ch;
	if (ch == '#')
		*T = nullptr;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
			exit(OVERFLOW); //�����������������ʱ���˳����򲢱������������
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}