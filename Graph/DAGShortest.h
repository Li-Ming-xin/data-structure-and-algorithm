/* DAG Shortest Pathing
 * 1. topological sort
 * 2. relaxation in order of topological sort
 *
 * O(|V| + |E|)
 */
#ifndef __DAG_H__
#define __DAG_H__

#include "LGraph.h"
#include "TopSort.h"

int DAGShortest(LGraph G, int s, int *path, int *d){
	int *top = (int*)malloc(sizeof(int)*G->Nv);
	int ret = TopSort(G, top);
	if(ret == -1){
		printf("The input graph is not a DAG.\n");
		return -1;
	}

	printf("Topological sort: ");
	for(int i = 0; i < G->Nv; ++i){
		printf("%d ", top[i]);
	}
	printf("\n");

	for(int i = 0; i < G->Nv; ++i){
		path[i] = -1;
		d[i] = 0x7f7f7f7f;
	}
	d[s] = 0;
	int i = 0;
	while(top[i++] != s);
	--i;

	for(; i < G->Nv; ++i){
		PtrToAdjVNode node = G->G[top[i]].FirstNode;
		while(node){
			if(d[node->AdjV] > node->weight + d[top[i]]){
				d[node->AdjV] = node->weight + d[top[i]];
				path[node->AdjV] = top[i];
			}
			node = node->next;
		}
	}

	free(top);
	return 0;
}

#endif
