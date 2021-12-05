/* 二叉搜索树的基本操作，不包含插入和删除 */
#ifndef __BASIC_H__
#define __BASIC_H__
#include "Tree.h"
#include <stdio.h>

static void InorderTraverseHelper(Tree T, Node root){
	if(root == T->nil) return;
	InorderTraverseHelper(T, root->left);
	printf("%d ", root->val);
	InorderTraverseHelper(T, root->right);
}

/* print element by increase */
void InorderTraverse(Tree T){
	Node root = T->root;
	InorderTraverseHelper(T, root);
	printf("\n");
}

Node Search(Tree T, ElementType val){
	Node x = T->root;
	while(x != T->nil){
		if(x->val < val) x = x->right;
		else if(x->val > val) x = x->left;
		else break;
	}
	return x;
}

Node Minimum(Tree T, Node x){
	if(x == T->nil) return NULL;
	while(x->left != T->nil){
		x = x->left;
	}
	return x;
}

Node Maximum(Tree T, Node x){
	if(x == T->nil) return NULL;
	while(x->right != T->nil){
		x = x->right;
	}
	return x;
}

Node TreeSuccessor(Tree T, ElementType val){
	Node x = Search(T, val);
	if(x == T->nil) return NULL;
	if(x->right != T->nil) return Minimum(T, x->right);
	else{
		Node y = x->parent;
		while(y != T->nil && x == y->right){
			x = y;
			y = x->parent;
		}
		return y;
	}
}

Node TreePredecessor(Tree T, ElementType val){
	Node x = Search(T, val);
	if(x == T->nil) return NULL;
	if(x->left != T->nil) return Maximum(T, x->left);
	else{
		Node y = x->parent;
		while(y != T->nil && y->left == x){
			x = y;
			y = x->parent;
		}
		return y;
	}
}

#endif
