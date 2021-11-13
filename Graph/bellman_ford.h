/* Bellman Ford algorithm 
 * O(VE)
 * BELLMAN_FORD(G,w,s)
 *
 * for i=1 to |G.V-1|
 * 		for each edge(u,v)
 * 			RELAX(u,v,w)
 *
 * 	for each edge(u,v)
 * 		if v.d > u.d + w(u,v)
 * 			return FALSE
 * 	return TRUE
 */

#ifndef __BELLMAN_FORD_H__
#define __BELLMAN_FORD_H__

#include "LGraph.h"

int BellmanFord(const LGraph const G, Vertex s, int *path, int *d){
	for(int i = 0; i < G->Nv; ++i){
		path[i] = -1;
		d[i] = 0x7f7f7f7f;
	}
	d[s] = 0;

	for(int i = 1; i < G->Nv; ++i){
		for(int v = 0; v < G->Nv; ++v){
			PtrToAdjVNode node = G->G[v].FirstNode;
			while(node){
				if(d[node->AdjV] > d[v] + node->weight){
					d[node->AdjV] = d[v] + node->weight;
					path[node->AdjV] = v;
				}
				node = node->next;
			}
		}
	}

	for(int v = 0; v < G->Nv; ++v){
		PtrToAdjVNode node = G->G[v].FirstNode;
		while(node){
			if(d[node->AdjV] > d[v] + node->weight){
				return -1;
			}
			node = node->next;
		}
	}

	return 0;
}

#endif
