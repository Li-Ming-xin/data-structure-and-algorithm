#ifndef __MBFS_H__
#define __MBFS_H__

#include "MGraph.h"
#include "Queue.h"

void visit(Vertex V){
	printf("%d ", V);
}

static int visited[MaxVertexNum];
void BFS(MGraph Graph, Vertex V){
	Queue Q;
	Q = CreateQueue(2);
	Push(Q, V);
	visit(V);
	visited[V] = 1;
	while(!IsEmpty(Q)){
		Vertex W = Pop(Q);
		Vertex i;
		for(i = 0; i < Graph->Nv; ++i){
			if(!visited[i] && Graph->G[W][i] < INFINITY){
				Push(Q, i);
				visit(i);
				visited[i] = 1;
			}
		}
	}
	DestoryQueue(Q);
}

#endif
