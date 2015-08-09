#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct BiNode{
	int data;
	struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

BiTree CreatTree(){
	int t;
	BiNode *node;
	scanf("%d",&t);
	if(0!=t){			//if node is not leaf,its data equals 0
		node=(BiNode *)malloc(sizeof(BiNode));
		node->data=t;
		node->lchild=NULL;
		node->rchild=NULL;
	}
	else{
		node=(BiNode *)malloc(sizeof(BiNode));
		
		node->lchild=CreatTree();
		node->rchild=CreatTree();
	}
	return node;
}

int count_wpl(BiTree T,int level){
	int total=0;
	if(T->lchild==NULL&&T->rchild==NULL)
		return level*T->data;
	if(T->lchild!=NULL)
		total+=count_wpl(T->lchild,level+1);
	if(T->rchild!=NULL)
		total+=count_wpl(T->rchild,level+1);
	return total;
}
int main(void){
	int result=0;
	BiTree T=CreatTree();
	result=count_wpl(T,0);
	printf("wpl=%d\n",result);
	return 0;
}