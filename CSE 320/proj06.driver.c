#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

float get__float(unsigned int bit_pattern){
  union ieee_single num;
  num.irep = bit_pattern;
  return num.frep;
}

int get__int(float f){
  union ieee_single num;
  num.frep = f;
  return num.irep;
}


void print_float( float f ){
  printf("Real: %f; Hex integer: %08x\n", f, get__int(f));
}

void print_outcome( int i ){
  if (i == 1){
    printf("true\n");
  }
  else{
    printf("false\n");
  }
}

void test(float f){  
  printf("Original: ");
  print_float(f);
  
  printf("Negation: ");
  print_float(negate(f));
  
  printf("Absolute: ");
  print_float(absolute(f));
                             
  printf("is negative: ");
  print_outcome(is_negative(f));
                                     
  printf("is infinity: ");
  print_outcome(is_infinity(f));
                                             
  printf("is nan: ");
  print_outcome(is_nan(f));
                                                     
  printf("is zero: ");
  print_outcome(is_zero(f));
                                                             
  printf("is denormal: ");
  print_outcome(is_denormal(f));
                                                                     
  printf("\n");
                                                                         
}

int main(){
     
  printf("+inf:\n");
  test(get_infinity());
             
  printf("-inf:\n");
  test(get__float(0xff800000));
                     
  printf("+nan (fraction field all 1's):\n");
  test(get_nan());
                             
  printf("Max normal:\n");
  test(get_max_normal());
                                     
  printf("Min normal:\n");
  test(get_min_normal());
                                             
  printf("Max denormal:\n");
  test(get_max_denormal());
                                                     
  printf("Min denormal:\n");
  test(get_min_denormal());
                                                             
  printf("Positive nan:\n");
  test(get__float(0x7fb28cd3));
                                                                     
  printf("Negative nan:\n");
  test(get__float(0xffcd43c6));
                                                                             
  printf("Positive normal:\n");
                                                                                  test(get__float(0x420c0000));

  printf("Negative normal:\n");
  test(get__float(0xc2860000));
 
  printf("Positive denormal:\n");
  test(get__float(0x00495962));
  
  printf("Negative denormal:\n");
  test(get__float(0x801696d5));
}
