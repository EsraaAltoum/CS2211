#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "list.h"
#include "memory.h"

int main(){
  int size_mem;
  Key k;
  Data* d;
  int take_nxt = scanf(" %d", &size_mem);
  mem_ini(size_mem);
  List l = list_ini();

  while(take_nxt){
    // printf("%d", take_nxt);
    take_nxt = scanf(" %d", &k);
    if(k==0) break;
    d = list_search(l, k);
    if(d == NULL){
      list_add(l, k, 1);
    }
    else{
      List tmp = l;
      while(tmp->key != k) tmp = tmp->next;
      tmp->data = tmp->data+1;
    }
  }

  printf("Integer\tOccurrence\n");
  list_print(l);
  list_free(l);
  mem_free();

}

