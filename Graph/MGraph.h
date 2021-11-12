/* 图的邻接矩阵表示 */
#ifndef __MGRAPH_H__
#define __MGRAPH_H__

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100
#define INFINITY 65536
typedef int Vertex;
typedef int Weight;

/* 边的定义 */ 
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1, V2;
	Weight weight;
}; 
typedef PtrToENode Edge;

/* 图的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;
	int Ne;
	Weight G[MaxVertexNum][MaxVertexNum];
}; 
typedef PtrToGNode MGraph;

/**
* 初始化一个只有VertexNum个节点没有边的图  
* @para VertexNum -> 图中节点个数
* @return MGraph -> 创建的图 
*/
MGraph CreateGraph(int VertexNum){
	int V, W;
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for(V = 0; V < Graph->Nv; ++V)
		for(W = 0; W < Graph->Nv; ++W)
			Graph->G[V][W] = INFINITY;
	return Graph;
} 

/**
* 向图中插入一条边
* @para Graph -> 图
* @para Edge -> 欲向图中插入的边 
*/

void InsertEdge(MGraph Graph, Edge E){
	Graph->G[E->V1][E->V2] = E->weight;
	//若为无向图
#ifdef UNDIRECTION
	Graph->G[E->V2][E->V1] = E->weight;
#endif 
} 

MGraph BuildGraph(){
	MGraph Graph;
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

void DestoryGraph(MGraph Graph){
	free(Graph);
}

#endif 
/*__MGRAPH_H__*/
