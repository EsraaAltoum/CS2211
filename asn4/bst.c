// ====== this is in bst.c
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void insert(BStree bst, Key *key, Data data, int p);
void traverse(BStree bst, int p);
void bst_free(BStree bst, int p);
static int new_node(BStree bst, Key *key, Data data);

// Input: ’size’: size of an array
// Output: a pointer of type BStree,
// i.e. a pointer to an allocated memory of BStree_struct type
// Effect: dynamically allocate memory of type BStree_struct
// allocate memory for a Node array of size+1 for member tree_nodes
// allocate memory for an unsigned int array of size+1 for member free_nodes
// set member size to ’size’;
// set entry free_nodes[i] to i
// set member top to 1;
// set member root to 0;
BStree bstree_ini(int size) {
	BStree bst = (BStree_struct *) malloc(sizeof (BStree_struct));
	bst->tree_nodes = (Node *) malloc((size + 1) * sizeof (Node));
	bst->free_nodes = (int *) malloc((size + 1) * sizeof (Node));
	bst->size = size;
	for(int i = 0; i <= size; i++)
		bst->free_nodes[i] = i;
	bst->top = 1;
	bst->root = 0;

	return bst;
}
// Input: ’bst’: a binary search tree
// ’key’: a pointer to Key
// ’data’: an integer
// Effect: ’data’ with ’key’ is inserted into ’bst’
// if ’key’ is already in ’bst’, do nothing
void bstree_insert(BStree bst, Key *key, Data data) {
	insert(bst, key, data, bst->root);

}
void insert(BStree bst, Key *key, Data data, int p){
	if(p == bst->root){
		new_node(bst, key, data);
		if(!p){
			bst->root = bst->top;
			bst->top = bst->free_nodes[bst->top+1];
			return;
		} 
	}

	if(key_comp(bst->tree_nodes[p].key, key) > 0){
		if(bst->tree_nodes[p].left)
			return insert(bst, key, data, bst->tree_nodes[p].left);
		bst->tree_nodes[p].left = bst->top;
		bst->top = bst->free_nodes[bst->top+1];
	}
	
	else if(key_comp(bst->tree_nodes[p].key, key) < 0){
		if(bst->tree_nodes[p].right)
			return insert(bst, key, data, bst->tree_nodes[p].right);
		bst->tree_nodes[p].right = bst->top;
		bst->top = bst->free_nodes[bst->top+1];
	}

	else;
}




// Input: ’bst’: a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst) {
	traverse(bst, bst->root);
}

void traverse(BStree bst, int p){
	if(bst->tree_nodes[p].left)
		traverse(bst, bst->tree_nodes[p].left);

	print_node(bst->tree_nodes[p]);

	if(bst->tree_nodes[p].right)
		traverse(bst, bst->tree_nodes[p].right);
}


// Input: ’bst’: a binary search tree
// Effect: all dynamic memory used by bst are freed
void bstree_free(BStree bst) {
	bst_free(bst, bst->root);
	free(bst->tree_nodes);
	free(bst->free_nodes);
	free(bst);
}

void bst_free(BStree bst, int p){
	if(bst->tree_nodes[p].left)
		bst_free(bst, bst->tree_nodes[p].left);

	if(bst->tree_nodes[p].right)
		bst_free(bst, bst->tree_nodes[p].right);

	free(bst->tree_nodes[p].key);
}


static int new_node(BStree bst, Key *key, Data data){
	bst->tree_nodes[bst->top].key = key;
	bst->tree_nodes[bst->top].data = data;
	bst->tree_nodes[bst->top].left = 0;
	bst->tree_nodes[bst->top].right = 0;

	return bst->top;
}