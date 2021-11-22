/* MaxHeap 小顶堆（优先队列） */
#ifndef __MINHEAPOFEDGE_H__ 
#define __MINHEAPOFEDGE_H__
#include "LGraph.h"
#include <string.h>

#define MAXCAPACITY 500
typedef Edge Element;
typedef struct HNode *Heap;
struct HNode{
	Element elements[MAXCAPACITY];
	int size;
};

Heap CreateHeap(){
	Heap H;
	H = (Heap)malloc(sizeof(struct HNode));
	memset(H->elements, 0, MAXCAPACITY*sizeof(Element));
	H->size = 0;
	return H;
}

void Push(Heap H, Element E){
	++H->size;
	int index = H->size;
	while(index/2){
		if(H->elements[index/2]->weight > E->weight){
			H->elements[index] = H->elements[index/2];
			index /= 2;
		} 
		else break;
	}
	H->elements[index] = E;
}

int IsEmpty(Heap H){
	return H->size == 0;
}

Element Pop(Heap H){
	Element Min = H->elements[1];
	Element tmp = H->elements[H->size--];
	int index = 1;
	while(index*2 <= H->size){
		int child = index*2;
		if(child < H->size && H->elements[child+1]->weight < H->elements[child]->weight){
			++child;
		}
		if(tmp->weight > H->elements[child]->weight){
			H->elements[index] = H->elements[child];
			index = child;
		}
		else break;
	}
	H->elements[index] = tmp;
	return Min;
}

void DestoryHeap(Heap H){
	free(H);
} 
#endif
