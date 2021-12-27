#include <stdio.h>
#include "/user/cse320/Projects/project09.support.h"


// functions that print out the original and final values
void printNegate(int a){
  printf("The negation of %d: %d\n", a, negate(a));
}

void printAbsolute(int a){
  printf("The absolute value of %d: %d\n", a, absolute(a));
}

void printAdd(int a, int b){
  printf("%d + %d = %d\n", a, b, add(a, b));
}

void printSub(int a, int b){
  printf("%d - %d = %d\n", a, b, sub(a, b));
}

void printMul(int a, int b){
  printf("%d * %d = %d\n", a, b, mul(a, b));
}

void printDiv(int a, int b){
  printf("%d / %d = %d\n", a, b, divide(a, b));
}

void printPow(int a, int b){
  printf("%d ^ %d = %d\n", a, b, power(a, b));
}

void printFactorial(int a){
  printf("%d!: %d\n", a, factorial(a));
}


int main(){
  
  // test negate
  printNegate(0);
  printNegate(24);
  printNegate(-86);

  printf("\n");

  // test absolute
  printAbsolute(0);
  printAbsolute(-8);
  printAbsolute(68);

  printf("\n");

  // test add
  printAdd(419, 2);
  printAdd(-67, 5);
  printAdd(76, -4);
  printAdd(0, 0x7fffffff);
  printAdd(1, 0x7fffffff);

  printf("\n");

  //test subtract
  printSub(4, -8);
  printSub(-9, 10);
  printSub(0, 0x7fffffff);
  printSub(-5, 0x7fffffff);

  printf("\n");

  //test mult
  printMul(5, 13);
  printMul(80000, 26844);
  printMul(-6, 8);

  printf("\n");

  //test divide
  printDiv(80, 10);
  printDiv(2176, 32);
  printDiv(1257, 3);

  printf("\n");

  //test power
  printPow(2, 3);
  printPow(1290, 3);
  printPow(1291, 3);
  printPow(-9, 0);
  printPow(8, 0);
  printPow(-4, -5);
  printPow(6, -3);
  printPow(0, 0);

  //test factorial
  printFactorial(5);
  printFactorial(12);
  printFactorial(13);
}
