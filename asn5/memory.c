#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

static unsigned char *memory;
static BStree bst;

//Initialize an unsigned char array of size elements and initialize a binary search tree//
void mem_ini(unsigned int size) {
	memory = (unsigned char *) malloc(size);
	bst = bstree_ini(size/5); // size/5 is large enough
	bstree_insert(bst, 0, size);
}
//frees memory for array and binary search tree//
void mem_free(void) {
	bstree_free(bst);
	free(memory);
}

//alocating space for data //
void *simu_malloc(unsigned int size) {
	Key* k = bstree_data_search(bst, size + 4);
	if(k != NULL){
		Data* dp = bstree_search(bst, *k);
		bstree_delete(bst, *k);

		if(*k - size + 4 != 0){
			int diff= *dp - (size + 4);
			if(diff > 0) bstree_insert(bst, *k + size + 4, diff);
			memory[*k] = size;
			return (void*)(&memory[*k + 4]);		
		}
	}
	return NULL;
}

// puts the allocated memory pointed by ptr back into free memory//
void simu_free(void *ptr) {
	if(ptr == NULL) return;
	Key* k = (Key*)((unsigned char*)ptr - 4);
	Key nk = *bstree_data_search(bst, *k);
	Data d = *k + 4;
	bstree_insert(bst, nk - (*k + 4), d);
}

// prints all the free memory blocks//
void mem_print(void) {
	bstree_traversal(bst);
}


