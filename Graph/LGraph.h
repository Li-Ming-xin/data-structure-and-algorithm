/* 图的邻接表表示 */

#ifndef __LGRAPH_H__
#define __LGRAPH_H__

#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100
typedef int Vertex;
typedef int Weight;

/* 边的定义 */ 
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1, V2;
	Weight weight;
};
typedef PtrToENode Edge;

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
	Vertex AdjV;
	Weight weight;
	PtrToAdjVNode next;
};

/* 顶点表头结点的定义 */
typedef struct VNode{
	PtrToAdjVNode FirstNode;
} AdjList[MaxVertexNum];

/* 图的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv, Ne;
	AdjList G;
}; 
typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum){
	LGraph Graph;
	int V;
	Graph = (LGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for(V = 0; V < MaxVertexNum; ++V){
		Graph->G[V].FirstNode = NULL;
	}
	return Graph;
}

void InsertEdge(LGraph Graph, Edge E){
	PtrToAdjVNode p;
	Vertex V1 = E->V1, V2 = E->V2;
	Weight w = E->weight;
	
	p = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	p->AdjV = V2;
	p->weight = w;
	p->next = Graph->G[V1].FirstNode;
	Graph->G[V1].FirstNode = p;
#ifdef UNDIRECTION
	p = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	p->AdjV = V1;
	p->weight = w;
	p->next = Graph->G[V2].FirstNode;
	Graph->G[V2].FirstNode = p;
#endif 
}

LGraph BuildGraph(){
	LGraph Graph;
	int Nv, i;
	Edge E;
	printf("please enter num of vertex:\n");
	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);
	printf("please enter num of edge:\n");
	scanf("%d", &Graph->Ne);
	
	if(Graph->Ne){
		printf("please enter begin,end and weight of edge:\n");
		E = (Edge)malloc(sizeof(struct ENode)); 
		for(i = 0; i < Graph->Ne; ++i){
			scanf("%d %d %d", &E->V1, &E->V2, &E->weight);
			InsertEdge(Graph, E);
		}
		free(E);
	}
	
	return Graph;
}

void DestoryGraph(LGraph Graph){
	int i;
	PtrToAdjVNode Adj, next;
	for(i = 0; i < Graph->Nv; ++i){
		Adj = Graph->G[i].FirstNode;
		while(Adj){
			next = Adj->next;
			free(Adj);
			Adj = next;
		}
		Graph->G[i].FirstNode = NULL;
	}
	free(Graph);
	Graph = NULL;
}

#endif
/* __LGRAPH_H__ */
