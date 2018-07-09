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
	int r, n; //根的位置和结点数
};

/*孩子结点*/
typedef struct CTNote
{
	int child;
	struct CTNote *next;
}*ChildPtr;

/*表头*/
typedef struct
{
	TElemType data;
	ChildPtr firstchild;
}CTBox;

/*树结构*/
typedef struct
{
	CTBox node[MAX_TREE_SIZE];
	int r, n; //根得的位置和结点数
}CTree;

/*树的兄弟表示法*/
typedef struct CSNode
{
	TElemType data;
	struct CSNode  *firstchild, *rightsib;
}CSNode, *CSTree;

/*二叉树的表示*/
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;







