#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include"stack_for_LRD_Non_Recursive.h"
void visit(BiNode *T){
	printf("%d ",T->data);
}
void LRD_Non_Recursive(BiTree T){
	BiNode *p=T, *r=NULL;
	Stack *S=(Stack *)malloc(sizeof(Stack));
	InitStack(S);
	while(p||!StackEmpty(S)){
		if(p!=NULL){
			Push(S, p);
			p=p->lchild;
		}
		else{
			GetTop(S, &p);
			if((p->rchild!=NULL)&&(p->rchild!=r)){
				p=p->rchild;
			}
			else{
				Pop(S, &p);
				visit(p);
				r=p;
				p=NULL;
			}
		}
	}
}
int main(){
	BiTree T=CreateTree();
	LRD_Non_Recursive(T);
	printf("\n");
	return 0;
}