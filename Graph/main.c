//#define UNDIRECTION
//#include "LDFS.h"
//#include "MBFS.h"
//#include "Queue.h"
//#include "MinHeap.h"
//#include "Dijkstra.h"
//#include "bellman_ford.h"
#include "TopSort.h"
#include "DAGShortest.h"

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
	LGraph Graph = BuildGraph();
	int *path = (int*)malloc(sizeof(int)*Graph->Nv);
	int *d = (int*)malloc(sizeof(int)*Graph->Nv);
	/*
	Dijkstra(Graph, 0, path, d);
	printDandP(path, d, Graph->Nv);
*/
	DAGShortest(Graph, 0, path, d);
	printDandP(path, d, Graph->Nv);
/*
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
	
	DestoryGraph(Graph);
	free(path), free(d);
	//TestQueue();
	//TestHeap();
	return 0;
}
