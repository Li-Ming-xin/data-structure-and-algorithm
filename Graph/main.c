//#define UNDIRECTION
#include "LDFS.h"
//#include "MBFS.h"
#include "Queue.h"

//void TestQueue(){
//	Queue Q = CreateQueue(5);
//	for(int i = 1; i < 6; ++i)
//		Push(Q, i);
//	if(!IsEmpty(Q)){
//		ElementType E = Pop(Q);
//		printf("%d ", E);
//	}
//	if(!IsEmpty(Q)){
//		ElementType E = Pop(Q);
//		printf("%d ", E);
//	}
//	for(int i = 6; i < 11; ++i)
//		Push(Q, i);
//	for(int i = 0; i < 8; ++i){
//		ElementType E = Pop(Q);
//		printf("%d ", E);
//	}
//	for(int i = 11; i < 31; ++i)
//		Push(Q, i);
//	for(int i = 0; i < 20; ++i){
//		ElementType E = Pop(Q);
//		printf("%d ", E);
//	}
//	DestoryQueue(Q);
//} 

int main(){
	LGraph Graph = BuildGraph();
	DFS(Graph, 0);
	DestoryGraph(Graph);
	//TestQueue();
	return 0;
}
