/* Topological sort */
#ifndef __TOPSORT_H__
#define __TOPSORT_H__
#include "LGraph.h"
#include "Queue.h"
#include <string.h>
#include <stdlib.h>

int TopSort(LGraph G, int *topArray){
	int *in = (int*)malloc(sizeof(int)*G->Nv);
	memset(in, 0, sizeof(int)*G->Nv);

	for(int i = 0; i < G->Nv; ++i){
		PtrToAdjVNode node = G->G[i].FirstNode;
		while(node){
			++in[node->AdjV];
			node = node->next;
		}
	}

	Queue Q = CreateQueue(5);
	for(int i = 0; i < G->Nv; ++i){
		if(in[i] == 0) Push(Q, i);
	}

	int index = 0;
	while(!IsEmpty(Q)){
		int v = Pop(Q);
		topArray[index++] = v;
		PtrToAdjVNode node = G->G[v].FirstNode;
		while(node){
			--in[node->AdjV];
			if(in[node->AdjV] == 0) Push(Q, node->AdjV);
			node = node->next;
		}
	}

	free(in), DestoryQueue(Q);

	return index == G->Nv ? 0 : -1;
}

#endif
