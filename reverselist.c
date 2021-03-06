#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node,*LinkList;

LinkList CreatList(LinkList pList){
	int i;
	Node *p,*q;
	p=pList;
	scanf("%d",&pList->data);//input length
	for(i=0;i<pList->data;i++){
		q=(Node *)malloc(sizeof(Node));
		scanf("%d",&(q->data));
		p->next=q;
		p=q;
	}
	p->next=NULL;
	return pList;
}

LinkList ReverseList(LinkList pList){
	Node *pre,*p=pList->next,*r=p->next;
	p->next=NULL;
	while(r!=NULL){
		pre=p;
		p=r;
		r=r->next;
		p->next=pre;
	}
	pList->next=p;
	return pList;
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
	ReverseList(pList);
	PrintList(pList);
	return 0;
}
