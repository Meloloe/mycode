#define MAX_VERTEX_NUM 100
#define VertexType int

typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode;

typedef struct {
	VertexType data;
	ArcNode *firstarc;
}VNode;

typedef struct Graph {
	VNode AdjList[MAX_VERTEX_NUM];
	int vexnum, arcnum;
}Graph;

int visited[MAX_VERTEX_NUM]={0};
/*
void InsertVex(Graph G, int v){
	
}
*/
void InitGraph(Graph *G, int i, int j){
	int v;
	G->vexnum=i;
	G->arcnum=j;
	for(v=0;v<G->vexnum;v++)
		G->AdjList[v].firstarc=NULL;
}

void InsertArc(Graph *G, int v, int w){
	ArcNode *p=G->AdjList[v].firstarc;
	if(p==NULL){
		G->AdjList[v].firstarc=(ArcNode *)malloc(sizeof(ArcNode));
		p=G->AdjList[v].firstarc;
	}
	else{
		while(p->nextarc!=NULL)
			p=p->nextarc;
		p->nextarc=(ArcNode *)malloc(sizeof(ArcNode));
		p=p->nextarc;
	}
	
	p->adjvex=w;
	p->nextarc=NULL;
}

int FirstAdjVex(Graph *G, int v){
	if(G->AdjList[v].firstarc==NULL)
		return -1;
	return G->AdjList[v].firstarc->adjvex;
}

int NextAdjVex(Graph *G, int v, int w){
	ArcNode *p=G->AdjList[v].firstarc;
	while(p->adjvex!=w&&p->nextarc!=NULL)
		p=p->nextarc;
	if(p->nextarc==NULL)
		return -1;
	p=p->nextarc;
	return p->adjvex;
}

