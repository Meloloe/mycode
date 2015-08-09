#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct LNode{
	int data;
	struct LNode *pNext;
}LNode,*LinkList;

void CreatList(LinkList T){
	int i,num;
	LinkList HEAD=T;
	printf("Please input the number of nodes:");
	scanf("%d\n",&num);
	T->data=num;
	for(i=0;i<num;i++){
		HEAD->pNext=(LNode *)malloc(sizeof(LNode));
		HEAD=HEAD->pNext;
		scanf("%d",&HEAD->data);
	}
	HEAD->pNext=NULL;
}

void PrintList(LinkList T){
	LinkList P=T->pNext;
	while(P!=NULL){
		printf("%d ",P->data);
		P=P->pNext;
	}
	printf("\n");
}

int Find(LinkList HEAD,int k){
	int count=0;
	LinkList F=HEAD;
	LNode *kth=F->pNext;
	while(F->pNext!=NULL&&count<k){
		F=F->pNext;
		count+=1;
	}
	if(count<k){
		printf("Can't!\n");
		return 0;
	}
	while(F->pNext!=NULL){
		F=F->pNext;
		kth=kth->pNext;
	}
	return kth->data;
}

int main(void){
	int result,k;
	LinkList T=(LinkList)malloc(sizeof(LNode));
	CreatList(T);
	PrintList(T);
	printf("Input k:");
	scanf("%d",&k);
	result=Find(T,k);
	printf("result:%d\n",result);
	return 0;
}