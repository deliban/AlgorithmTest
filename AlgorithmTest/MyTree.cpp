#include "MyTree.h"
#include<stdio.h>
#include<iostream>
using namespace std;
/**************************************************
Function: PreOrdeTraverse(BiTree T)
Desc:  二叉树的前序（先序）遍历: 根-左-右
Input:	BiTree T
* @param T - 二叉树的指针
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
Desc:  二叉树的中序遍历: 左-根-右
Input:	BiTree T
* @param T - 二叉树的指针
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
Desc:  二叉树的后序遍历: 左-右-根
Input:	BiTree T
* @param T - 二叉树的指针
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
Desc:  按前序输入二叉树中的结点的值（一个字符），#表示空树，构造二叉链表表示二叉树
Input:	BiTree *T
* @param  指针的指针（指向BiTNode的指针的指针），这样可以修改指针的值，传入指针只能修改指针指向的内容
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
			exit(OVERFLOW); //当程序运算出现上溢时，退出程序并报错给主调进程
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}