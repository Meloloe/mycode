#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct LinkNode{
	int data;
	struct LinkNode *pNext;
}LinkNode,*LinkList;

void CreatList(LinkList L){
	int i;
	LinkList T=L;
	for(i=0;i<10;i++){
		T->pNext=(LinkNode *)malloc(sizeof(LinkNode));
		T=T->pNext;
		scanf("%d",&(T->data));
	}
	T->pNext=NULL;
}

int Print(LinkList L){
	LinkList T=L;
	if(T=NULL)//wrong
		return 0;
	while(T->pNext!=NULL){
		T=T->pNext;
		printf("%d ",T->data);
	}
	return 1;
}

int DeleteRepeatedNum(LinkList L){
	int mark[100]={0};
	LinkList T=L,p;
	if(T=NULL)//wrong
		return 0;
	while(T->pNext!=NULL){
		T=T->pNext;
		if(mark[T->data]==1){//wrong,if T points to the last one.
			p=T->pNext;
			T->data=p->data;
			T->pNext=p->pNext;
			free(p);
		}
		else if(T->data<0)
			mark[-(T->data)]=1;
			else
				mark[T->data]=1;
	}
	return 1;
}

int main(void){
	LinkList pHead;
	pHead=(LinkNode *)malloc(sizeof(LinkNode));
	CreatList(pHead);
	Print(pHead);
	DeleteRepeatedNum(pHead);
	Print(pHead);
	return 0;
}