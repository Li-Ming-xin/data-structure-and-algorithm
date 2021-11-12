/* ͼ���ڽӾ����ʾ */
#ifndef __MGRAPH_H__
#define __MGRAPH_H__

#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100
#define INFINITY 65536
typedef int Vertex;
typedef int Weight;

/* �ߵĶ��� */ 
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1, V2;
	Weight weight;
}; 
typedef PtrToENode Edge;

/* ͼ�Ķ��� */
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;
	int Ne;
	Weight G[MaxVertexNum][MaxVertexNum];
}; 
typedef PtrToGNode MGraph;

/**
* ��ʼ��һ��ֻ��VertexNum���ڵ�û�бߵ�ͼ  
* @para VertexNum -> ͼ�нڵ����
* @return MGraph -> ������ͼ 
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
* ��ͼ�в���һ����
* @para Graph -> ͼ
* @para Edge -> ����ͼ�в���ı� 
*/

void InsertEdge(MGraph Graph, Edge E){
	Graph->G[E->V1][E->V2] = E->weight;
	//��Ϊ����ͼ
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
