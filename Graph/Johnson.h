/* 多源最短路算法 
 * Johnson
 * 1. 首先创建一个新图，为了防止存在负权重
 * 2. 对所有节点应用一遍Dijkstra
 *
 * 时间复杂度为: O(|V||E|log|V|)
 * 适用于稀疏图
 */
#ifndef __JOHNSON_H__
#define __JOHNSON_H__
#include "LGraph.h"
#include "bellman_ford.h"
#include "Dijkstra.h"

static void BuildNewGraph(LGraph G){
	Edge e = (Edge)malloc(sizeof(struct ENode));
	Vertex V = G->Nv;
	for(int i = 0; i < G->Nv; ++i){
		e->V1 = V;
		e->V2 = i;
		e->weight = 0;
		InsertEdge(G, e);
	}
	++G->Nv;
	free(e);
}

static void ModifyWeight(LGraph G, int *d){
	for(int i = 0; i < G->Nv; ++i){
		PtrToAdjVNode node = G->G[i].FirstNode;
		while(node){
			node->weight += (d[i] - d[node->AdjV]);
			printf("%d -> %d : %d\n", i, node->AdjV, node->weight);
			node = node->next;
		}
	}
}

void Johnson(LGraph G, int **path, int **dist){
	BuildNewGraph(G);
	int *p = (int*)malloc(sizeof(int)*G->Nv);
	int *d = (int*)malloc(sizeof(int)*G->Nv);
	if(BellmanFord(G, G->Nv - 1, p, d) == -1){
		printf("Negetive weight circle exists.\n");
	}else{
		ModifyWeight(G, d);
		for(int i = 0; i < G->Nv - 1; ++i){
			Dijkstra(G, i, path[i], dist[i]);
			for(int j = 0; j < G->Nv - 1; ++j){
				dist[i][j] += (d[j] - d[i]);
			}
		}
	}
	free(p), free(d);
}

#endif
