#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

float get_float(unsigned int bit_pattern){
  union ieee_single num;
  num.irep = bit_pattern;
  return num.frep;
}

int get_int(float f){
  union ieee_single num;
  num.frep = f;
  return num.irep;
}

float get_infinity(){
  return get_float(0x7f800000);
}

float get_nan(){
  return get_float(0x7fffffff);
}

float get_max_normal(){
  return get_float(0x7f7fffff);
}

float get_min_normal(){
  return get_float(0x00800000);
}

float get_max_denormal(){
  return get_float(0x007fffff);
}

float get_min_denormal(){
  return get_float(0x00000001);
}

int is_negative( float f ){
  unsigned int num = get_int(f);
  if ((num >> 31) == 0x00000001){
    return 1;         
  }
    return 0;
}
   

int is_infinity( float f){
  if (get_int(f) == 0x7f800000 || get_int(f) == 0xff800000){
    return 1; 
  }
  return 0;
}


// When the biased exponent field is all 1s and the fraction field is not all 0s
int is_nan( float f ){
  if( (((get_int(f) & 0x7f800000) >> 23) == 0xff) && ((get_int(f) &
    0x007fffff) != 0x00000000) ){
    return 1;
  }
  return 0;
}

int is_zero( float f ){
  if (get_int(f) == 0x00000000 || get_int(f) == 0x80000000){
    return 1;
  }
  return 0;
}

// When the biased exponent field is all 0s
int is_denormal( float f ){
  if (((get_int(f) & 0x7f800000) >> 23) == 0x00000000){
    return 1;
  }
  return 0;
}


float negate( float f ){
  if (is_negative(f)){
    return get_float(get_int(f) ^ 0x80000000);
  }
  return get_float(get_int(f) | 0x80000000);
}

float absolute( float f ){
  if (is_negative(f)){
    return negate(f);
  }
  return f;
}

