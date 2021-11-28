/* binary search tree */
#ifndef __BST_H__
#define __BST_H__
#include "Tree.h"
#include <stdio.h>

static void InorderTraverseHelper(Node root){
	if(root == NULL) return;
	InorderTraverseHelper(root->left);
	printf("%d ", root->val);
	InorderTraverseHelper(root->right);
}

/* print element by increase */
void InorderTraverse(Tree T){
	Node root = T->root;
	InorderTraverseHelper(root);
	printf("\n");
}

Node Search(Tree T, ElementType val){
	Node x = T->root;
	while(x){
		if(x->val < val) x = x->right;
		else if(x->val > val) x = x->left;
		else break;
	}
	return x;
}

Node Minimum(Node x){
	if(!x) return NULL;
	while(x->left){
		x = x->left;
	}
	return x;
}

Node Maximum(Node x){
	if(!x) return NULL;
	while(x->right){
		x = x->right;
	}
	return x;
}

Node TreeSuccessor(Tree T, ElementType val){
	Node x = Search(T, val);
	if(x == NULL) return NULL;
	if(x->right) return Minimum(x->right);
	else{
		Node y = x->parent;
		while(y && x == y->right){
			x = y;
			y = x->parent;
		}
		return y;
	}
}

Node TreePredecessor(Tree T, ElementType val){
	Node x = Search(T, val);
	if(x == NULL) return NULL;
	if(x->left) return Maximum(x->left);
	else{
		Node y = x->parent;
		while(y && y->left == x){
			x = y;
			y = x->parent;
		}
		return y;
	}
}

void Insert(Tree T, Node node){
	if(T->root == NULL) T->root = node;
	else{
		Node x = T->root, y = T->root;
		while(x){
			y = x;
			if(x->val < node->val) x = x->right;
			else if(x->val > node->val) x = x->left;
			else return;
		}
		if(y->val > node->val) y->left = node;
		else y->right = node;
		node->parent = y;
	}
}

static void Transplant(Tree T, Node x, Node y){
	if(x->parent == NULL) T->root = y;
	else{
		if(x == x->parent->left) x->parent->left = y;
		else x->parent->right = y;
	}
	if(y){
		y->parent = x->parent;
	}
}

void Delete(Tree T, ElementType val){
	Node x = Search(T, val);
	if(!x) return;
	if(x->left == NULL){
		Transplant(T, x, x->right);
	}
	else if(x->right == NULL){
		Transplant(T, x, x->left);
	}
	else{
		Node y = Minimum(x->right);
		if(y != x->right){
			Transplant(T, y, y->right);
			y->right = x->right;
			y->right->parent = y;
		}
		Transplant(T, x, y);
		y->left = x->left;
		y->left->parent = y;
	}
	free(x);
}

void TestBST(){
	Tree T = CreateTree();
	int nums[10] = {9, 0, 2, 34, 3, 1, 54, 63, 12, 99};
	for(int i = 0; i < 10; ++i){
		Node node = (Node)malloc(sizeof(struct TreeNode));
		node->val = nums[i];
		node->left = node->right = node->parent = NULL;
		Insert(T, node);
	}
	InorderTraverse(T);
	for(int i = 0; i < 10; ++i){
		Delete(T, nums[i]);
		InorderTraverse(T);
	}
	DestoryTree(T);
}
#endif
