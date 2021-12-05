/* binary search tree */
#ifndef __BST_H__
#define __BST_H__
#include "Tree.h"
#include "BasicOperate.h"
#include <stdio.h>

void Insert(Tree T, Node node){
	if(T->root == T->nil) T->root = node;
	else{
		Node x = T->root, y = T->root;
		while(x != T->nil){
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
	if(x->parent == T->nil) T->root = y;
	else{
		if(x == x->parent->left) x->parent->left = y;
		else x->parent->right = y;
	}
	if(y != T->nil){
		y->parent = x->parent;
	}
}

void Delete(Tree T, ElementType val){
	Node x = Search(T, val);
	if(x == T->nil) return;
	if(x->left == T->nil){
		Transplant(T, x, x->right);
	}
	else if(x->right == T->nil){
		Transplant(T, x, x->left);
	}
	else{
		Node y = Minimum(T, x->right);
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
		node->left = node->right = node->parent = T->nil;
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
