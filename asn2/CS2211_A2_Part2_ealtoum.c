#include <stdio.h>
#include <stdlib.h>
//function headers//
float exp_Calculator(float b, int e);

// main takes base and exponenet input, and returns the result//
//INPUT: float base, integer exponent//
//OUTPUT: the float result//
int main(void) {
  float b;
  int e;
  //this loop checks to see if the base is a positive number//
  //returns error if negative base entered, returns to input again//
  do {
    printf("Please enter a base: ");
    scanf(" %f", &b);
    if (b < 0)
      printf("Invalid Entry: base must be positive\n");
  } while( b < 0);
  //this loop check to see if the exponent is a positive number//
  //returns error if negative exponent entered, returns to input again//
  do {
    printf("Please enter an exponent: ");
    scanf(" %d", &e);
    if (e < 0)
      printf("Invalid Entry: exponent must be positive\n");
  } while( e< 0);
  //prints the result by calling the recusrive exponent function//
  printf("%f^%d = %f", b, e, exp_Calculator(b, e));

}
//this function calculates the exponential function result through recursive call//
//INPUT: float base, integer exponent 
//OUTPUT:exponential result
float exp_Calculator(float b, int e){
  if ( e > 1)
    if(e % 2 == 0) 
      return (exp_Calculator(b, e/2)*exp_Calculator(b, e/2));
    else
      return b*(exp_Calculator(b, (e-1)/2)*exp_Calculator(b, (e-1)/2));

  else if (e == 1)
    return b;
  else
    return 1;
}
