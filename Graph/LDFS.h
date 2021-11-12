#ifndef __LDFS_H__
#define __LDFS_H__

#include "LGraph.h"

static int visited[MaxVertexNum];

void DFS(LGraph Graph, Vertex V){
	printf("%d ", V);
	visited[V] = 1;
	PtrToAdjVNode adj = Graph->G[V].FirstNode;
	while(adj){
		if(!visited[adj->AdjV]) DFS(Graph, adj->AdjV);
		adj = adj->next;
	}
}

#endif
