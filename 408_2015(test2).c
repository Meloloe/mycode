#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node,*LinkList;

void CreatList(LinkList L){//test part
	int i;
	LinkList T=L;
	for(i=0;i<10;i++){
		T->next=(Node *)malloc(sizeof(Node));
		T=T->next;
		scanf("%d",&(T->data));
	}
	T->next=NULL;
}

int DeleteRepeatedNum(LinkList L){
	int mark[100]={0},temp;
	LinkList p=L->next;
	LinkList pre=L;
	if(p==NULL)
		return 0;
	while(p!=NULL){
		if(p->data<0)
			temp=-(p->data);
		else
			temp=p->data;
		if(mark[temp]==1){
			if(p->next!=NULL){
				pre->next=p->next;
				free(p);
				p=pre->next;
			}
			else{
				pre->next=NULL;
				free(p);
				p=pre->next;
			}
		}
		else{
			mark[temp]=1;
			p=p->next;
			pre=pre->next;
		}
	}
	return 1;
}

void PrintList(LinkList pList){
	Node *p=pList->next;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int main(void){
	LinkList pList;
	pList=(LinkList)malloc(sizeof(Node));
	CreatList(pList);
	PrintList(pList);
	DeleteRepeatedNum(pList);
	PrintList(pList);
	return 0;
}
