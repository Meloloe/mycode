#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include"AdjList.h"
/*
	判断一个无向图是否为一棵树(根据边数与顶点数的关系)
*/
void DFS_Judge(Graph *G, int v, int *v_count, int *a_count){
	int w;
	visited[v]=1;
	(*v_count)++;
//	printf("%d ",v);
	for(w=FirstAdjVex(G, v);w>=0;w=NextAdjVex(G, v, w)){
		if(!visited[w])
			DFS_Judge(G, w, v_count, a_count);
		(*a_count)++;
	}
}

int main(){
	int v, v_count=0, a_count=0;
	Graph *G=(Graph *)malloc(sizeof(Graph));
	InitGraph(G, 10, 12);
	InsertArc(G, 0, 1);
	InsertArc(G, 0, 2);
	InsertArc(G, 1, 3);
	InsertArc(G, 2, 3);
	InsertArc(G, 3, 4);
	InsertArc(G, 3, 5);
	InsertArc(G, 4, 6);
	InsertArc(G, 5, 6);
	InsertArc(G, 6, 7);
	InsertArc(G, 6, 8);
	InsertArc(G, 7, 9);
	InsertArc(G, 8, 9);
	for(v=0;v<G->vexnum;v++)
		visited[v]=0;
	DFS_Judge(G, 0, &v_count, &a_count);
	printf("%d, %d\n",v_count, a_count);
	v_count!=(a_count--) ? printf("Not Tree\n") : printf("Tree\n");
	return 0;
}