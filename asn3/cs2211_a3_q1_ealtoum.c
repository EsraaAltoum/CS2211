#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

float get_num();
char get_op();
float m_exp(float sub_exp, char op);
float s_exp(void);

int main(void){
  char choice = 'Y';
  while(choice == 'Y' || choice == 'y'){
    printf("%f \n", s_exp());
    printf("\nwould you like to enter another expression? (Y/N) : ");
    scanf(" %c", &choice);
  }
	return 0;
}

// Input: none, the s_expression will be read in from stdin
// Effect: the s_expression is evaluated using
// a while loop or a do while loop:
// repeatedly get num with m_exp() and then get op with
// get_op() while op is ’+’ or ’-’; when op is ’\n’, exit loop.
// Output: this function returns the value of the s_expression
float s_exp(void) {
  float f; char ch; 
  char *ops = (char *)malloc(4096);
  float *nums = (float *)malloc(4098);
  int i = 0;
  printf("Please input an expression:");
  do{
    f = get_num();
    ch = get_op();
    
    f = m_exp(f, ch);
    nums[i] = f;

    ch = get_op();

    if(ch == '\n')
      break;

    ops[i] = ch;
    i++;

  }while(ch != 0);
  float ans = nums[0];
  for(int j = 0 ; j < i; j++){
    if(ops[j] == '+')
      ans += nums[j+1];
    if(ops[j] == '-')
      ans -= nums[j+1];
  }

  return ans;
}


// Input: ’sub_exp’: the value of the current sub m_expression
// to the left of ’op’ location in stdin.
// ’op’ : an operator, ’*’ or ’/’. ’op’ could also be
// ’+’, ’-’, or ’\n’ indicating the end of the m_expression.
// "+’, ’-’, or ’\n’ should be pushed back to stdin.
// the rest of the m_expression will be read in from stdin
// Effect: the m_expression is evaluated using recursion:
// get next_num with get_num() and then get next_op with get_op()
// use ’sub_exp op next_num’ and ’next_op’ to do recursive call
// Output: this function returns the value of the current m_expression
float m_exp(float sub_exp, char op) {

  if(op == '*'){
    float f = get_num();
    char c = get_op();
    return m_exp(sub_exp*f, c);
  }
  else if(op == '/'){
    float f = get_num();
    char c = get_op();
    return m_exp(sub_exp/f, c);

  }
  else{

    ungetc(op, stdin);
    return sub_exp;
  }
}

// Input: none, read from stdin
// Effect: get the next operator of the expression
// this operator can be +, -, *, /, or ’\n’
// ’\n’ indicates the end of the expression input
// leading spaces should skipped
// Output: return the next operator of the expression.
char get_op() {
	char ch;
  do{
    scanf("%c", &ch);
  }while(ch == ' ');

  if(ch == '+' || ch == '-' || ch == '*'|| ch == '/'|| ch == '\n'){
    return ch;
  }
  else if(ch >= '0' && ch <= '9'){
    ungetc(ch, stdin);
    return 0;
  }
  printf("ERROR: Invalid Operator: %c\n", ch);
  exit(-1);
}

// Input: none, read from stdin
// Effect: get the next numeric value of the expression
// Output: return the next numeric value of the expression.
float get_num() {
	float fl;
	scanf(" %f", &fl);
	return fl;
}