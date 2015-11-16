#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define SElemType int

typedef struct{
	SElemType* base;
	SElemType* top;
	int stacksize;
}Stack;

int InitStack(Stack* S){
	S->base=(SElemType* )malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S->base)
		return 0;
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return 1;
}

int GetTop(Stack* S, SElemType* e){
	if(S->top==S->base)
		return 0;
	*e=*(S->top-1);
	return 1;
}

int Push(Stack* S, SElemType e){
	if(S->top-S->base>=S->stacksize){
		S->base=(SElemType* )realloc(S->base, (S->stacksize+STACKINCREMENT)*sizeof(SElemType));
	if(!S->base)
		return 0;
	S->top=S->base+S->stacksize;
	S->stacksize+=STACKINCREMENT;
	}
	*S->top++=e;
	return 1;
}

int Pop(Stack* S, SElemType* e){
	if(S->top==S->base)
		return 0;
	*e=* --S->top;
	return 1;
}