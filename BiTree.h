#define ElemType int

typedef struct BiNode{
	ElemType data;
	struct BiNode *lchild, *rchild;
}BiNode, *BiTree;

BiTree CreateTree(){
	int t, isleaf;
	BiNode *node;
	scanf("%d %d",&t, &isleaf);
	if(1==isleaf){
		node=(BiNode *)malloc(sizeof(BiNode));
		node->data=t;
		node->lchild=NULL;
		node->rchild=NULL;
	}
	else{
		node=(BiNode *)malloc(sizeof(BiNode));
		node->data=t;
		node->lchild=CreateTree();
		node->rchild=CreateTree();
	}
	return node;
}