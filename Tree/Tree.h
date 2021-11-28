/* 树的表示 */
#ifndef __TREE_H__
#define __TREE_H__
#include <stdlib.h>

typedef int ElementType;
typedef struct TreeNode *PtrToTreeNode;
struct TreeNode{
	ElementType val;
	PtrToTreeNode left;
	PtrToTreeNode right;
	PtrToTreeNode parent;
};
typedef PtrToTreeNode Node;

typedef struct TreeRoot *Tree;
struct TreeRoot{
	Node root;
};

Tree CreateTree(){
	Tree T = (Tree)malloc(sizeof(struct TreeRoot));
	T->root = NULL;
	return T;
}

static void DestoryNode(Node node){
	if(node == NULL) return;
	DestoryNode(node->left);
	DestoryNode(node->right);
	free(node);
}

void DestoryTree(Tree T){
	DestoryNode(T->root);
	free(T);
}

#endif
