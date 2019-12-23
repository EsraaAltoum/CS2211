#include <stdio.h>
#include "bst.h"
#include "string.h"
int main(void) {
	BStree bst;
	bst = bstree_ini(256);
	// bstree_insert(bst, key_construct("Once", 1), 11);
	// bstree_insert(bst, key_construct("Upon", 22), 2);
	// bstree_insert(bst, key_construct("a", 3), 33);
	// bstree_insert(bst, key_construct("Time", 4), 44);
	// bstree_insert(bst, key_construct("is", 5), 55);
	// bstree_insert(bst, key_construct("filmed", 6), 66);
	// bstree_insert(bst, key_construct("in", 7), 77);
	// bstree_insert(bst, key_construct("Vancouver", 8), 88);
	// bstree_insert(bst, key_construct("!", 99), 9);
	// bstree_insert(bst, key_construct("Once", 5), 50);
	// bstree_insert(bst, key_construct("Once", 1), 10);

	while(1){
		char name[512];
		int id;
		int data;
		int n = scanf(" %s %d %d", name, &id, &data);
		if(n < 3) break;
		bstree_insert(bst, key_construct(name, id), data);
	}


	bstree_traversal(bst);
	bstree_free(bst);
}