#include <stdio.h>
#include <string.h>
#include "/user/cse320/Projects/project10.support.h"

int main(){
  char A[] = "the";
  char B[] = "crazy";
  char C[] = "time";
  char D[] = "you";
  char E[] = "got";
  char F[] = "a";
  char G[] = "calculator";

  char H[100];

  printf("Num chars in %s: %d\n", A, length(A));
  printf("Num chars in %s: %d\n", B, length(B));
  printf("Num chars in %s: %d\n", C, length(C));
  printf("Num chars in %s: %d\n", D, length(D));
  printf("Num chars in %s: %d\n", E, length(E));
  printf("Num chars in %s: %d\n", F, length(F));
  printf("Num chars in %s: %d\n", G, length(G));

  copy(H, A);
  printf("A copied to H: %s\n", H);
  copy(H, B);
  printf("B copied to H: %s\n", H);
  copy(H, C);
  printf("C copied to H: %s\n", H);
  copy(H, D);
  printf("D copied to H: %s\n", H);
  copy(H, E);
  printf("E copied to H: %s\n", H);
  copy(H, F);
  printf("F copied to H: %s\n", H);
  copy(H, G);
  printf("G copied to H: %s\n", H);

  append(A, B);
  printf("B appended to A: %s\n", A);
  append(C, D);
  printf("D appended to C: %s\n", C);
  append(E, F);
  printf("F appended to E: %s\n", E);
  append(G, H);
  printf("H appended to G: %s\n", G);

}
