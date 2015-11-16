#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include"queue.h"
#include"stack.h"
#include"AdjList.h"

int Path[100]={0};
int flag=0;

void Print(int d){
	int i;
	for(i=0;i<=d;++i){
		printf("%d ",Path[i]);
	}
	printf("\n");
}

void Path_Print(Graph* G, int v, int t, int d){
	int w;
	visited[v]=1;
//	printf("%d ",v);
	Path[d]=v;
	if(v==t){
		Print(d);
		flag=1;
		return;
	}
	for(w=FirstAdjVex(G, v);w>=0;w=NextAdjVex(G, v, w)){
		if(!visited[w])
			Path_Print(G, w, t, ++d);
		if(flag==1)
			return;
		visited[w]=0;
	}
}

int main(){
	int v;
	Graph* G=(Graph* )malloc(sizeof(Graph));
	memset(Path, 0, 100*sizeof(int));
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
	Path_Print(G, 0, 3, 0);
	printf("\n");
	return 0;
}