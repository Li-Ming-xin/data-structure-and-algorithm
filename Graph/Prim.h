/* Prim算法，用于求解最小生成树
 * 最小生成树：在给定的无向图G=(V,E)中，找到E的子集T，使得(V,T)为树，且权重和最小。
 */

#ifndef __PRIM_H__
#define __PRIM_H__
#define UNDIRECTION

#include "MinHeapOfEdge.h"
#include "LGraph.h"
#include <string.h>
#include <stdlib.h>

void Prim(LGraph G, Vertex s, int *path){
	Heap H = CreateHeap();
	int *key = (int*)malloc(sizeof(int)*G->Nv);

	memset(key, 0x7f, sizeof(int)*G->Nv);
	key[s] = 0;
	for(int i = 0; i < G->Nv; ++i) path[i] = -1;

	Edge e = (Edge)malloc(sizeof(struct ENode));
	e->V1 = e->V2 = e->weight = 0;
	Push(H, e);

	while(!IsEmpty(H)){
		Edge tmp = Pop(H);
		Vertex v = tmp->V2;
		key[v] = 0;
		free(tmp);
		PtrToAdjVNode node = G->G[v].FirstNode;
		while(node){
			if(key[node->AdjV] != 0 && node->weight < key[node->AdjV]){
				key[node->AdjV] = node->weight;
				path[node->AdjV] = v;
				e = (Edge)malloc(sizeof(struct ENode));
				e->V1 = v, e->V2 = node->AdjV, e->weight = node->weight;
				Push(H, e);
			}
			node = node->next;
		}
	}
	DestoryHeap(H);
	free(key);
}


void printP(int *path, int i, int j){
	if(i == j){
		printf("%d ", i);
	}else if(path[j] == -1){
		printf("no path from %d to %d\n", i, j);
	}else{
		printP(path, i, path[j]);
		printf("%d ", j);
	}
}

void TestPrim(){
	LGraph G = BuildGraph();
	int *path = (int*)malloc(sizeof(int)*G->Nv);
	Vertex s = 0;
	Prim(G, s, path);
	for(int i = 0; i < G->Nv; ++i){
		printf("%d : ", i);
		printP(path, s, i);
		printf("\n");
	}
	DestoryGraph(G);
	free(path);
}

#endif
