/* 并查集
 * 按秩合并+路径压缩
 */
#ifndef __UNIONFIND_H__
#define __UNIONFIND_H__
#include <stdlib.h>

typedef struct UnionFindNode *UnionFind;
struct UnionFindNode{
	int *father;
	int size;
};

UnionFind CreateUF(int size){
	UnionFind uf = (UnionFind)malloc(sizeof(struct UnionFindNode));
	uf->size = size;
	uf->father = (int*)malloc(sizeof(int)*uf->size);
	for(int i = 0; i < uf->size; ++i){
		uf->father[i] = -1;
	}
	return uf;
}

int Find(UnionFind uf, int x){
	if(uf->father[x] < 0){
		return x;
	}else{
		uf->father[x] = Find(uf, uf->father[x]);
		return uf->father[x];
	}
}

int Union(UnionFind uf, int x, int y){
	int xr = Find(uf, x), yr = Find(uf, y);
	if(xr != yr){
		if(uf->father[xr] < uf->father[yr]){
			uf->father[xr] += uf->father[yr];
			uf->father[yr] = xr;
		}else{
			uf->father[yr] += uf->father[xr];
			uf->father[xr] = yr;
		}
		return 0;
	}
	return -1;
}

void DestoryUF(UnionFind uf){
	free(uf->father);
	free(uf);
}

#endif
