//#define UNDIRECTION
//#include "LDFS.h"
//#include "MBFS.h"
//#include "Queue.h"
//#include "MinHeap.h"
//#include "Dijkstra.h"
//#include "bellman_ford.h"
//#include "TopSort.h"
//#include "DAGShortest.h"
//#include "Floyd.h"
//#include "Johnson.h"
//#include "Prim.h"
#include "Kruskal.h"

void printPath(int *path, int i, int j){
	if(i == j){
		printf("%d ", i);
	}else if(path[j] == -1){
		printf("no path from %d to %d\n", i, j);
	}else{
		printPath(path, i, path[j]);
		printf("%d ", j);
	}
}

void printDandP(int *path, int *dist, int len, int s){

	for(int i = 0; i < len; ++i){
		printf("%d -> %d: \npath: ", s, i);
		printPath(path, s, i);
		printf("\ndist: ");
		printf("%d \n", dist[i]);
	}
}

int main(){
	TestKruskal();
//	TestPrim();
	//LGraph Graph = BuildGraph();
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
//	int **path = (int**)malloc(sizeof(int*)*Graph->Nv);
//	int **dist = (int**)malloc(sizeof(int*)*Graph->Nv);
//	for(int i = 0; i < Graph->Nv; ++i){
//		path[i] = (int*)malloc(sizeof(int)*(Graph->Nv+1));
//		dist[i] = (int*)malloc(sizeof(int)*(Graph->Nv+1));
//	}
//	Johnson(Graph, path, dist);
//	int Nv = Graph->Nv - 1;
//	for(int i = 0; i < Nv; ++i){
////		for(int j = 0; j < Graph->Nv; ++j){
//		//	PrintPathAndDist(path, dist, i, j);
//		printDandP(path[i], dist[i], Nv, i);
////		}
////		printf("\n");
//	}
//	for(int i = 0; i < Nv; ++i){
//		free(path[i]);
//		free(dist[i]);
//	}
//	free(path), free(dist);
//	
//	DestoryGraph(Graph);
	//free(path), free(d);
	//TestQueue();
	//TestHeap();
	return 0;
}
