#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__

#include "MinHeap.h"
#include "LGraph.h"
#include <string.h>

void Dijkstra(const LGraph const Graph, Vertex V, int *path, int *d){
	int i;
	for(i = 0; i < Graph->Nv; ++i)
		path[i] = -1;
	Heap H = CreateHeap();
	Element E;
	memset(d, 0x7f, sizeof(Weight)*Graph->Nv);
	d[V] = 0;
	E = (Element)malloc(sizeof(struct Node));
	E->V = V, E->weight = 0;
	Push(H, E);
	while(!IsEmpty(H)){
		Element tmp = Pop(H);
		Vertex W = tmp->V;
		Weight w = tmp->weight;
		free(tmp);
		PtrToAdjVNode node = Graph->G[W].FirstNode;
		while(node){
			if(node->weight + d[W] < d[node->AdjV]){
				path[node->AdjV] = W;
				d[node->AdjV] = node->weight + d[W];
				E = (Element)malloc(sizeof(struct Node));
				E->V = node->AdjV, E->weight = d[node->AdjV];
				Push(H, E);
			}
			node = node->next;
		}
	}
	DestoryHeap(H);
}

#endif
