#include <stdio.h>
void conversionOne();
void conversionTwo();
void conversionThree();
void conversionFour();

int main(void) {
  
  // asking user for integer input //%
  int i = 0;
  while (i != 5) {
    printf("Please select one of the following:\n1. conversion between Kilometer and Mile\n2. conversion between Meter and Feet\n3. conversion between Centimetre and Inch\n4. conversion between Celsius and Fahrenheit\n5. quit\n\nChoice: ");
    scanf(" %d", &i);
    if(i == 1){
      conversionOne();
    }
    else if(i == 2){
      conversionTwo();
    }
    else if(i == 3){
      conversionThree();
    } 
    else if(i == 4){
      conversionFour();
    }
    printf("\n\n");
  }

}

// function one: converts between kilometer and mile
 // Input: float value
//  Output: converted value//%
void conversionOne(){
  char c;
  float val;
  printf("\nWhat is the direction of the conversion wanted?(K or M): ");
  scanf(" %c", &c);
  
  printf("\nPlease enter the value to be converted: ");
  scanf(" %f", &val);

  if(c == 'K'){
    printf("\n%f Kilometers is %f Miles ",val, 0.621371*val);
  }
  else if(c == 'M') {
    printf("\n%f Miles is %f Kilometers ",val, 1.60934*val);
  }
  else
  printf("\nError: Invalid character");
}

// function two: converts between meter and feet//%
// Input: float value
//  Output: converted value//%
void conversionTwo(){
  char c;
  float val;
  printf("\nWhat is the direction of the conversion wanted?(M or F): ");
  scanf(" %c", &c);
  
  printf("\nPlease enter the value to be converted: ");
  scanf(" %f", &val);

  if(c == 'F'){
    printf("\n%f Meters is %f Feet ",val, 3.28084*val);
  }
  else if(c == 'M') {
    printf("\n%f Feet is %f Meters ",val, 0.3048*val);
  }
  else
  printf("\nError: Invalid character");
}
// function three: converts between centimeter and inches//%
// Input: float value
//  Output: converted value//%
void conversionThree(){
  char c;
  float val;
  printf("\nWhat is the direction of the conversion wanted?(C or I): ");
  scanf(" %c", &c);
  
  printf("\nPlease enter the value to be converted: ");
  scanf(" %f", &val);

  if(c == 'I'){
    printf("\n%f Centimeters is %f Inches ",val, 0.393701*val);
  }
  else if(c == 'C') {
    printf("\n%f Inches is %f Centimeters ",val, 2.54*val);
  }
  else
    printf("\nError: Invalid character");
}
// function four: converts between celsius and fahrenheit//%
// Input: float value
//  Output: converted value//%
void conversionFour(){
  char c;
  float val;
  printf("\nWhat is the direction of the conversion wanted (C or F): ");
  scanf(" %c", &c);
  
  printf("\nPlease enter the value to be converted: ");
  scanf(" %f", &val);

  if(c == 'F'){
    printf("\n%f Celsius is %f Fahrenheit ",val, (9/5*val)+32);
  }
  else if(c == 'C') {
    printf("\n%f Fahrenheit is %f Celsius ",val, (val-32)*5/9);
  }
  else
    printf("\nError: Invalid character");

}


