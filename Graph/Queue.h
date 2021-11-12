#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdlib.h>
#include <string.h>

typedef int ElementType;
typedef struct QNode *PtrToQNode;
struct QNode{
	int size, capacity;
	int head, tail;//head:队列的头，直接从head处取；tail:队列的尾，直接放到tail处 
	ElementType *Element;
};
typedef PtrToQNode Queue;

Queue CreateQueue(int capacity){
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->capacity = capacity;
	Q->size = 0;
	Q->head = 0;
	Q->tail = 0;
	Q->Element = (ElementType*)malloc(sizeof(ElementType)*Q->capacity);
}

int IsEmpty(Queue Q){
	return Q->size == 0;
}

int IsFull(Queue Q){
	return Q->size == Q->capacity;
}

void Push(Queue Q, ElementType E){
	if(IsFull(Q)){
		Q->capacity *= 2;
		ElementType *tmp = (ElementType*)malloc(sizeof(ElementType)*Q->capacity);
		memcpy(tmp, Q->Element + Q->head, sizeof(ElementType)*(Q->capacity - Q->head));
		memcpy(tmp + (Q->size - Q->head), Q->Element, sizeof(ElementType)*Q->head);
		free(Q->Element);
		Q->Element = tmp;
		Q->head = 0, Q->tail = Q->size;
	}
	Q->Element[Q->tail] = E;
	++Q->size;
	Q->tail = (Q->tail+1)%Q->capacity;
}

ElementType Pop(Queue Q){
	ElementType E;
	E = Q->Element[Q->head];
	--Q->size;
	Q->head = (Q->head+1)%Q->capacity;
	return E;
}

void DestoryQueue(Queue Q){
	free(Q->Element);
	free(Q);
}

#endif
