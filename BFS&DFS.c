#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include"queue.h"
#include"stack.h"
#include"AdjList.h"

void BFS(Graph* G, int v){
	int i, w=v;
	Queue* Q=(Queue* )malloc(sizeof(Queue));
	InitQueue(Q);
	EnQueue(Q, w);
	visited[w]=1;
	while(QueueLength(Q)!=0){
		DeQueue(Q, &w);
		printf("%d ",w);
		for(i=FirstAdjVex(G, w);i>=0;i=NextAdjVex(G, w, i))
			if(!visited[i]){
				EnQueue(Q, i);
				visited[i]=1;
			}
	}
}

void DFS(Graph* G, int v){
	int w;
	visited[v]=1;
	printf("%d ",v);
	for(w=FirstAdjVex(G, v);w>=0;w=NextAdjVex(G, v, w))
		if(!visited[w])
			DFS(G, w);
}

void DFS_Non_Recursive(Graph* G, int v){
		int i, w=v;
	Stack* S=(Stack* )malloc(sizeof(Stack));
	InitStack(S);
	Push(S, w);
	visited[w]=1;
	while(!StackEmpty(S)){
		Pop(S, &w);
		printf("%d ",w);
		for(i=FirstAdjVex(G, w);i>=0;i=NextAdjVex(G, w, i))
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