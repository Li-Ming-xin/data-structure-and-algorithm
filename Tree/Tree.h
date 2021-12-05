/* 树的表示，为方便红黑树的实现，在节点中加入了color属性 */
#ifndef __TREE_H__
#define __TREE_H__
#include <stdlib.h>
#define RED 0
#define BLACK 1

typedef int ElementType;
typedef struct TreeNode *PtrToTreeNode;
struct TreeNode{
	ElementType val;
	PtrToTreeNode left;
	PtrToTreeNode right;
	PtrToTreeNode parent;
	int color;
};
typedef PtrToTreeNode Node;

typedef struct TreeRoot *Tree;
struct TreeRoot{
	Node root;
	Node nil;
};

Tree CreateTree(){
	Tree T = (Tree)malloc(sizeof(struct TreeRoot));
	T->nil = (Node)malloc(sizeof(struct TreeNode));
	T->nil->color = BLACK;
	T->root = T->nil;
	return T;
}

static void DestoryNode(Tree T, Node node){
	if(node == T->nil) return;
	DestoryNode(T, node->left);
	DestoryNode(T, node->right);
	free(node);
}

void DestoryTree(Tree T){
	DestoryNode(T, T->root);
	free(T->nil);
	free(T);
}

#endif
