//#define UNDIRECTION
//#include "LDFS.h"
//#include "MBFS.h"
//#include "Queue.h"
//#include "MinHeap.h"
//#include "Dijkstra.h"
//#include "bellman_ford.h"
//#include "TopSort.h"
//#include "DAGShortest.h"
#include "Floyd.h"

void printDandP(int *path, int *dist, int len){

	for(int i = 0; i < len; ++i){
		printf("%d ", dist[i]);
	}
	printf("\n");
	for(int i = 0; i < len; ++i){
		int j = i;
		printf("%d : ", i);
		while(path[j] != -1){
			printf("%d <- ", j);
			j = path[j];
		}
		printf("%d\n", j);
	}
}

int main(){
	MGraph Graph = BuildGraph();
	/*
	int *path = (int*)malloc(sizeof(int)*Graph->Nv);
	int *d = (int*)malloc(sizeof(int)*Graph->Nv);
	*/
	/*
	Dijkstra(Graph, 0, path, d);
	printDandP(path, d, Graph->Nv);
	DAGShortest(Graph, 0, path, d);
	printDandP(path, d, Graph->Nv);
	BellmanFord(Graph, 0, path, d);
	printDandP(path, d, Graph->Nv);
	*/
	/*
	int *top = (int*)malloc(sizeof(int)*Graph->Nv);
	int ret = TopSort(Graph, top);
	if(ret){
		for(int i = 0; i < Graph->Nv; ++i) printf("%d ", top[i]);
		printf("\n");
	}
	else printf("There is a circle in graph!\n");
	free(top);
	*/
	int **path = (int**)malloc(sizeof(int*)*Graph->Nv);
	int **dist = (int**)malloc(sizeof(int*)*Graph->Nv);
	for(int i = 0; i < Graph->Nv; ++i){
		path[i] = (int*)malloc(sizeof(int)*Graph->Nv);
		dist[i] = (int*)malloc(sizeof(int)*Graph->Nv);
	}
	Floyd(Graph, path, dist);
	for(int i = 0; i < Graph->Nv; ++i){
		for(int j = 0; j < Graph->Nv; ++j){
			PrintPathAndDist(path, dist, i, j);
		}
	}
	for(int i = 0; i < Graph->Nv; ++i){
		free(path[i]);
		free(dist[i]);
	}
	free(path), free(dist);
	
	DestoryGraph(Graph);
	//free(path), free(d);
	//TestQueue();
	//TestHeap();
	return 0;
}
