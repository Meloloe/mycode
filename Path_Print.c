#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include"queue.h"
#include"stack.h"
#include"AdjList.h"
/*
	基于深度优先遍历，打印图中两点之间的路径
*/
void Print(int Path[], int d){
	int i;
	for(i=0;i<=d;++i){
		printf("%d ",Path[i]);
	}
	printf("\n");
}

void Path_Print(Graph *G, int v, int t, int Path[], int d){
	int w;
	visited[v]=1;
	Path[d]=v;
	if(v==t){
		Print(Path, d);
		exit(0);
	}
	for(w=FirstAdjVex(G, v);w>=0;w=NextAdjVex(G, v, w)){
		if(!visited[w])
			Path_Print(G, w, t, Path, ++d);
	//	visited[w]=0;	//取消访问标记，使该顶点可重新使用（此语句置于for循环外亦可）
	}
	visited[w]=0;
}

int main(){
	int v;
	Graph *G=(Graph *)malloc(sizeof(Graph));
	int Path[100]={0};
	InitGraph(G, 7, 8);
	InsertArc(G, 0, 1);
	InsertArc(G, 0, 2);
	InsertArc(G, 1, 3);
	InsertArc(G, 2, 3);
	InsertArc(G, 3, 4);
	InsertArc(G, 3, 5);
	InsertArc(G, 4, 6);
	InsertArc(G, 5, 6);
	for(v=0;v<G->vexnum;v++)
		visited[v]=0;
	Path_Print(G, 0, 6, Path, 0);
	printf("\n");
	return 0;
}