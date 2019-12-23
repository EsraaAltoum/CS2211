#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h> 


int ss_layer(int digit, int layer, bool n_flag);
const char segements[10][3][3] = {
                                  {{' ', '_', ' '},{'|', ' ', '|'},{'|', '_', '|'}},//0
                                  {{' ', ' ', ' '},{' ', ' ', '|'},{' ', ' ', '|'}},//1
                                  {{' ', '_', ' '},{' ', '_', '|'},{'|', '_', ' '}},//2
                                  {{' ', '_', ' '},{' ', '_', '|'},{' ', '_', '|'}},//3
                                  {{' ', ' ', ' '},{'|', '_', '|'},{' ', ' ', '|'}},//4
                                  {{' ', '_', ' '},{'|', '_', ' '},{' ', '_', '|'}},//5
                                  {{' ', '_', ' '},{'|', '_', ' '},{'|', '_', '|'}},//6
                                  {{' ', '_', ' '},{' ', ' ', '|'},{' ', ' ', '|'}},//7         
                                  {{' ', '_', ' '},{'|', '_', '|'},{'|', '_', '|'}},//8
                                  {{' ', '_', ' '},{'|', '_', '|'},{' ', '_', '|'}},//9
};

int main(void){
  bool n_flag = false;
  char* num = (char *)malloc(4096);
  printf("Enter an integer number:  ");
  scanf(" %s", num);

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < strlen(num); j++){
      if(num[j] == '-'){
        n_flag = true;
        j++;
      }
      int dig = num[j] - '0';
      if(ss_layer(dig, i, n_flag) != 0){
        printf("ERROR!\n");
        return -1;
      }
      n_flag = false;
    }
    printf("\n");
  }
  printf("\n");

  return 0;
}

int ss_layer(int digit, int layer, bool n_flag){
  if(digit / 10 > 0 || layer > 2){
    return -1;
  }
  if(n_flag && layer == 1)
    printf("_");
  else if(n_flag)
    printf(" ");
  for(int j = 0; j < 3; j++)
    printf("%c", segements[digit][layer][j]);
  return 0;
}
