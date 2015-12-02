#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include"queue.h"
#include"stack.h"
#include"AdjList.h"

void BFS(Graph* G, int v){
	int i;
	Queue* Q=(Queue* )malloc(sizeof(Queue));
	InitQueue(Q);
	EnQueue(Q, v);
	visited[v]=1;
	while(QueueLength(Q)!=0){
		DeQueue(Q, &v);
		printf("%d ",v);
		for(i=FirstAdjVex(G, v);i>=0;i=NextAdjVex(G, v, i))
			if(!visited[i]){
				EnQueue(Q, i);
				visited[i]=1;
			}
	}
}

void DFS(Graph* G, int v){
	int i;
	visited[v]=1;
	printf("%d ",v);
	for(i=FirstAdjVex(G, v);i>=0;i=NextAdjVex(G, v, i))
		if(!visited[i])
			DFS(G, i);
}

void DFS_Non_Recursive(Graph* G, int v){
		int i;
	Stack* S=(Stack* )malloc(sizeof(Stack));
	InitStack(S);
	Push(S, v);
	visited[v]=1;
	while(!StackEmpty(S)){
		Pop(S, &v);
		printf("%d ",v);
		for(i=FirstAdjVex(G, v);i>=0;i=NextAdjVex(G, v, i))
			if(!visited[i]){
				Push(S, i);
				visited[i]=1;
			}
	}
}

int main(){
	int v;
	Graph* G=(Graph* )malloc(sizeof(Graph));
	G->vexnum=4;
	G->arcnum=4;
	for(v=0;v<G->vexnum;v++)
		G->AdjList[v].firstarc=NULL;
	InsertArc(G, 0, 1);
	InsertArc(G, 0, 2);
	InsertArc(G, 1, 3);
	InsertArc(G, 2, 3);
	for(v=0;v<G->vexnum;v++)
		visited[v]=0;
	DFS(G, 0);
	printf("\n");
	for(v=0;v<G->vexnum;v++)
		visited[v]=0;
	DFS_Non_Recursive(G, 0);
	printf("\n");
	for(v=0;v<G->vexnum;v++)
		visited[v]=0;
	BFS(G, 0);
	printf("\n");
	return 0;
}