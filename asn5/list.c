#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "memory.h"

void add(List list, Key key, Data data);

//returns a pointer to a dynamically allocated an initialized list//
List list_ini(void) {
	List_node *head= (List_node *) simu_malloc( sizeof(List_node) ); 
	head->next = NULL;
	return head;
}

//Input: 'list' a list
//effect: returns the address of keys associated data in list//
Data* list_search(List list, Key key) {
	if(list == NULL) return NULL;
	if(key_comp(list->key, key) == 0) return &list->data;
	return list_search(list->next, key);
}

//Input: 'list' a list
//Effect: adds a key with data to the front of the list//
void list_add(List list, Key key, Data data) {
	if(list_search(list, key) != NULL) return;
	List nl = (List)simu_malloc(sizeof(List_node));
	if(nl == NULL) printf("malloc failed\n");
	List l = list;
	nl->key = key;
	nl->data = data;
	nl->next = l->next;
	l->next = nl;
}

//Input: 'list' a list
//Effect: deleted the node in the list//
void list_delete(List list, Key key) {
	if(list == NULL) printf("LIST IS NULL\n");
	if(list->next == NULL) return;

	if(!key_comp(list->next->key,key)){
	List np = list->next;
	List nnp = list->next->next;
	simu_free(np); 
	list->next = nnp;
	simu_free(nnp);
	printf("deleted\n\n");
	return;
	}
	printf("delete failed: %d\n\n", list->key);
	list_delete(list->next, key);
}

//Input: 'list' a list
//Effect: linearly traverses the list and prints each node's key and data//
void list_print(List list) {
	List tmp = list;
	while(tmp != NULL){
		if(!(tmp->key == 0 && tmp->data == 0))
			print_list_node(tmp);
		tmp = tmp->next;
	}
}

//Input: 'list' a list
//Effect: frees all the dynamically allocated memory of list//
void list_free(List list) {
	List np = list;
	while(np != NULL){
		simu_free(list); //use this or simu_free?
		np = np->next;
	}
}

