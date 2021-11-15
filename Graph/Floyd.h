/* 基于邻接矩阵的多源最短路算法
 * Floyd算法
 * 经过k次迭代，每次迭代求出i->(0...k)->j中的最短路
 * 时间复杂度为O(|V|^3)
 *
 * path:使用二维矩阵存储，path[i][j]存储i~j最短路径上j的前驱节点
 */
#ifndef __FLOYD_H__
#define __FLOYD_H__

#include "MGraph.h"
#include <stdio.h>

void PrintPath(int **path, int i, int j){
	if(i == j) printf("%d ", i);
	else if(path[i][j] == -1) printf("No path from %d to %d exist\n", i, j);
	else{
		PrintPath(path, i, path[i][j]);
		printf("%d ", j);
	}
}

void PrintPathAndDist(int **path, int**dist, int i, int j){
	printf("%d->%d:\npath: ", i, j);
	PrintPath(path, i, j);
	if(dist[i][j] < INFINITY) printf("\ndist: %d\n", dist[i][j]);
}

void Floyd(MGraph G, int **path, int **dist){
	int Nv = G->Nv;
	for(int i = 0; i < Nv; ++i){
		for(int j = 0; j < Nv; ++j){
			path[i][j] = -1;
			if(G->G[i][j] < INFINITY) path[i][j] = i;
			dist[i][j] = G->G[i][j];
			if(i == j) dist[i][j] = 0;
		}
	}

	for(int k = 0; k < Nv; ++k){
		for(int i = 0; i < Nv; ++i){
			for(int j = 0; j < Nv; ++j){
				if(dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
}

#endif
