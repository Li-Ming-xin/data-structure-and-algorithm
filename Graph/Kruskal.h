/* 最小生成树算法 ：Kruskal */
#ifndef __KRUSKAL_H__
#define __KRUSKAL_H__
#define UNDIRECTION
#include "UnionFind.h"
#include "MinHeapOfEdge.h"
#include "LGraph.h"

void Kruskal(LGraph G, LGraph T){
	int Nv = G->Nv;
	UnionFind uf = CreateUF(Nv);
	Heap h = CreateHeap();
	Edge e;
	for(int i = 0; i < Nv; ++i){
		PtrToAdjVNode node = G->G[i].FirstNode;
		while(node){
			e = (Edge)malloc(sizeof(struct ENode));
			e->V1 = i, e->V2 = node->AdjV, e->weight = node->weight;
			Push(h, e);
			node = node->next;
		}
	}
	while(!IsEmpty(h)){
		Edge tmp = Pop(h);
		if(Union(uf, tmp->V1, tmp->V2) == 0){
			InsertEdge(T, tmp);
		}
		free(tmp);
	}
	DestoryHeap(h);
	DestoryUF(uf);
}

void TestKruskal(){
	LGraph G = BuildGraph();
	LGraph T = CreateGraph(G->Nv);
	Kruskal(G, T);
	for(int i = 0; i < T->Nv; ++i){
		printf("%d : ", i);
		PtrToAdjVNode node = T->G[i].FirstNode;
		while(node){
			printf("%d ", node->AdjV);
			node = node->next;
		}
		printf("\n");
	}
	DestoryGraph(G);
	DestoryGraph(T);
}

#endif
