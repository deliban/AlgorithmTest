#pragma once
#define MAX_TREE_SIZE 100
typedef int TElemType;
typedef struct PTNode
{
	TElemType data;
	int parent;
}PTNode;

typedef struct
{
	PTNode node[MAX_TREE_SIZE];
	int r, n; //����λ�úͽ����
};

/*���ӽ��*/
typedef struct CTNote
{
	int child;
	struct CTNote *next;
}*ChildPtr;

/*��ͷ*/
typedef struct
{
	TElemType data;
	ChildPtr firstchild;
}CTBox;

/*���ṹ*/
typedef struct
{
	CTBox node[MAX_TREE_SIZE];
	int r, n; //���õ�λ�úͽ����
}CTree;

/*�����ֵܱ�ʾ��*/
typedef struct CSNode
{
	TElemType data;
	struct CSNode  *firstchild, *rightsib;
}CSNode, *CSTree;

/*�������ı�ʾ*/
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;







