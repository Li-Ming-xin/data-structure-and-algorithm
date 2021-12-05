/* red black tree */
/** A red-black tree is a binary search tree satisfies the following red-black properties
 * 1. Every node is red or black.
 * 2. The root is black.
 * 3. Every leaf(T->nil) is black.
 * 4. If a node is black, then both its children are black.
 * 5. For each node, all simple path from the ndoe to descendant leaves contain the same number of black nodes.
 */
#ifndef __RBT_H__
#define __RBT_H__
#include "Tree.h"
#include "BasicOperate.h"

static void RightRotate(Tree T, Node x){
	Node y = x->left;
	//turn y's right subtree into x's left subtree
	x->left = y->right;
	if(x->left != T->nil) x->left->parent = x;
	//link x's parent to y
	y->parent = x->parent;
	if(x == T->root) T->root = y;
	else if(x->parent->left == x) x->parent->left = y;
	else x->parent->right = y;
	//put x on y's right
	y->right = x;
	x->parent = y;
}

static void LeftRotate(Tree T, Node x){
	Node y = x->right;
	//turn y's left subtree into x's right subtree
	x->right = y->left;
	if(x->right != T->nil) x->right->parent = x;
	//link x's parent to y
	y->parent = x->parent;
	if(x == T->root) T->root = y;
	else if(x->parent->left == x) x->parent->left = y;
	else x->parent->right = y;
	//put x on y's left
	y->left = x;
	x->parent = y;
}

static void RBInsertFixup(Tree T, Node z){
	while(z->parent->color == RED){
		if(z->parent->parent->left == z->parent){
			Node y = z->parent->parent->right;
			//case 1 : z's uncle is a red node.
			if(y->color == RED){
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else{
				//case 2 : z's uncle is a black node, and z is the right child of its parent.
				//turn case 2 into case 3.
				if(z->parent->right == z){
					z = z->parent;
					LeftRotate(T, z);
				}
				//case 3 : z's uncle is a black node, and z is the left child of its parent.
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				RightRotate(T, z->parent->parent);
			}
		}
		else{
			Node y = z->parent->parent->left;
			if(y->color == RED){
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
			else{
				if(z->parent->left == z){
					z = z->parent;
					RightRotate(T, z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				LeftRotate(T, z->parent->parent);
			}
		}
	}
	T->root->color = BLACK;
}

void RBInsert(Tree T, Node z){
	Node y = T->nil, x = T->root;
	while(x != T->nil){
		y = x;
		if(x->val > z->val) x = x->left;
		else if(x->val < z->val) x = x->right;
		else{
			free(z);
			return;
		}
	}
	z->parent = y;
	if(y == T->nil) T->root = z;
	else if(y->val > z->val) y->left = z;
	else y->right = z;
	z->left = z->right = T->nil;
	z->color = RED;
	RBInsertFixup(T, z);
}

static void RBDeleteFixup(Tree T, Node x){
	while(x != T->root && x->color == BLACK){
		if(x == x->parent->left){
			Node w = x->parent->right;
			//case 1 : x's brother is a red node.
			//turn case 1 into case 2 3 or 4.
			if(w->color == RED){
				w->color = BLACK;
				w->parent->color = RED;
				LeftRotate(T, w->parent);
				w = x->parent->right;
			}
			//case 2 : x's brother is a black node, and both children of x's brother are black nodes.
			if(w->left->color == BLACK && w->right->color == BLACK){
				w->color = RED;
				x = x->parent;
			}
			else{
				//case 3 : x's brother is a black node, and right child of x's brother is a black node and the left one is a red node..
				//turn case 3 into case 4.
				if(w->right->color == BLACK){
					w->color = RED;
					w->left->color = BLACK;
					RightRotate(T, w);
					w = x->parent->right;
				}
				//case 4 : x's brother is a black node, and right child of x's brother is a red node.
				w->right->color = BLACK;
				w->color = w->parent->color;
				w->parent->color = BLACK;
				LeftRotate(T, w->parent);
				x = T->root;
			}
		}
		else{
			Node w = x->parent->left;
			if(w->color == RED){
				w->color = BLACK;
				w->parent->color = RED;
				RightRotate(T, w->parent);
				w = x->parent->left;
			}
			if(w->left->color == BLACK && w->right->color == BLACK){
				w->color = RED;
				x = x->parent;
			}
			else{
				if(w->left->color == BLACK){
					w->right->color = BLACK;
					w->color = RED;
					LeftRotate(T, w);
					w = x->parent->left;
				}
				w->color = w->parent->color;
				w->parent->color = BLACK;
				w->left->color = BLACK;
				RightRotate(T, w->parent);
				x = T->root;
			}
		}
	}
	x->color = BLACK;
}

static void RBTransplant(Tree T, Node u, Node v){
	if(u == T->root) T->root = v;
	else if(u == u->parent->left) u->parent->left = v;
	else u->parent->right = v;
	v->parent = u->parent;
}

void RBDelete(Tree T, Node z){
	Node y = z, x;
	int yOrignalColor = y->color;
	if(z->left == T->nil){
		x = z->right;
		RBTransplant(T, z, z->right);
	}
	else if(z->right == T->nil){
		x = z->left;
		RBTransplant(T, z, z->left);
	}
	else{
		y = Minimum(T, z->right);
		yOrignalColor = y->color;
		x = y->right;
		if(y != z->right){
			RBTransplant(T, y, x);
			y->right = z->right;
			y->right->parent = y;
		}else{
			x->parent = y;
		}
		RBTransplant(T, z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	if(yOrignalColor == BLACK) RBDeleteFixup(T,x);
	free(z);
}

void RBDeleteByKey(Tree T, ElementType key){
	Node x = Search(T, key);
	if(x != T->nil) RBDelete(T, x);
}

void TestRBT(){
	Tree T = CreateTree();
	int nums[10] = {9, 0, 2, 34, 3, 1, 54, 63, 12, 99};
	for(int i = 0; i < 10; ++i){
		Node node = (Node)malloc(sizeof(struct TreeNode));
		node->val = nums[i];
		node->left = node->right = node->parent = T->nil;
		RBInsert(T, node);
	}
	InorderTraverse(T);
	for(int i = 0; i < 10; ++i){
		RBDeleteByKey(T, nums[i]);
		InorderTraverse(T);
	}
	DestoryTree(T);
}

#endif // __RBT_H__
