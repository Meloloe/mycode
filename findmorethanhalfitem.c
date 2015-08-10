#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#define Maxsize 50
typedef struct List{
	int Length;
	int data[Maxsize];
}List;

void Init(List *p){
	int i;
	printf("intput the number of items:");
	scanf("%d\n",&p->Length);
	for(i=0;i<p->Length;i++){
		scanf("%d",&p->data[i]);
	}
}

void Print(List *p){
	int i;
	for(i=0;i<p->Length;i++){
		printf("%d",p->data[i]);
	}
	printf("\n");
}

int Find(List *p){
	int count=0,i=0,retval;
	while(i<p->Length){
		if(count==0)
			retval=p->data[i];
		if(p->data[i]==retval)
			count++;
		else
			count--;
		i++;
		return retval;
	}
}

int main(void){
	List *test=(List *)malloc(sizeof(List));
	Init(test);
	Print(test);
	printf("the result is:%d\n",Find(test));
	return 0;
}