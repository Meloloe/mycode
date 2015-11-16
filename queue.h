#define MAXQSIZE 100
#define QElemType int

typedef struct{
	QElemType* base;
	int front;
	int rear;
}Queue;

int InitQueue(Queue* Q){
	Q->base=(QElemType* )malloc(MAXQSIZE*sizeof(QElemType));
	if(!Q->base)
		return 0;
	Q->front=Q->rear=0;
	return 1;
}

int QueueLength(Queue Q){
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

int EnQueue(Queue* Q, QElemType e){
	if((Q->rear+1)%MAXQSIZE==Q->front)
		return 0;
	Q->base[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXQSIZE;
	return 1;
}

int DeQueue(Queue* Q, QElemType* e){
	if(Q->rear==Q->front)
		return 0;
	*e=Q->base[Q->front];
	Q->front=(Q->front+1)%MAXQSIZE;
	return 1;
}