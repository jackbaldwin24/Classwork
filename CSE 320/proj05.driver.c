#include <stdio.h>
#include "/user/cse320/lib/bitlib.h"
#include "/user/cse320/Projects/project05.support.h"

void test(const char array[], int base, int result){
    int convert_result = convert(&array[0], base, &result);
    if (convert_result == 1){
	    printf( "Value: %s base %d\n", array, base );
	    printf( "Decimal: %d  Hexadecimal: %08x\n\n", result, result);
    }
}

int main (int argc, const char * argv[]) {
  
    char array[]= "\n \t 1a2b3c";	
    int base = 16;
    int result = 0;
    test(array, base, result);
    
  
    char array0[]= "  -abC";		
    int base0 = 16;
    int result0 = 0;
    test(array0, base0, result0);
  
    char array1[]= "11001?";		
    int base1 = 2;
    int result1 = 0;
    test(array1, base1, result1);
  
    char array2[]= "xyZ";	
    int base2 = 36;
    int result2 = 0;
    test(array2, base2, result2);
  
    char array3[]= "abcdef";	
    int base3 = 16;
    int result3 = 0;
    test(array3, base3, result3);
  
    char array4[]= "  +abC";
    int base4 = 16;
    int result4 = 0;
    test(array4, base4, result4);
  
    char array5[]= "  cd74  -+27";
    int base5 = 16;
    int result5 = 0;
    test(array5, base5, result5);
  
    char array6[]= "xy94-^54  ";
    int base6 = 36;
    int result6 = 0;
    test(array6, base6, result6);
  
    char array7[]= "Test";
    int base7 = 36;
    int result7 = 0;
    test(array7, base7, result7);
  
    char array8[]= "1524";		
    int base8 = 10;
    int result8 = 0;
    test(array8, base8, result8);
  
    char array9[]= "2398DEF";		
    int base9 = 16;
    int result9 = 0;
    test(array9, base9, result9);
  
    char array10[]= "1YZ";		
    int base10 = 36;
    int result10 = 0;
    test(array10, base10, result10);
  
    char array11[]= "+101001101100";		
    int base11 = 2;
    int result11 = 0;
    test(array11, base11, result11);
  
    char array12[]= "-419";		
    int base12 = 10;
    int result12 = 0;
    test(array12, base12, result12);
  
    char array13[]= "-DEC23";		
    int base13 = 16;
    int result13 = 0;
    test(array13, base13, result13);
  
    char array14[]= "-Z84";		
    int base14 = 36;
    int result14 = 0;
    test(array14, base14, result14);
  
    char array15[]= "-101001101100";		
    int base15 = 2;
    int result15 = 0;
    test(array15, base15, result15);
  
    char array16[]= "+9C";		
    int base16 = 14;
    int result16 = 0;
    test(array16, base16, result16);
  
    char array17[]= "-9D";		
    int base17 = 14;
    int result17 = 0;
    test(array17, base17, result17);
  
    char array18[]= "+0";		
    int base18 = 21;
    int result18 = 0;
    test(array18, base18, result18);
  
    char array19[]= "-0";		
    int base19 = 19;
    int result19 = 0;
    test(array19, base19, result19);
  
    char array20[]= "  55443322";		
    int base20 = 6;
    int result20 = 0;
    test(array20, base20, result20);
  
    char array21[]= "              31332";		
    int base21 = 4;
    int result21 = 0;
    test(array21, base21, result21);
  
    char array22[]= "39  ";		
    int base22 = 8;
    int result22 = 0;
    test(array22, base22, result22);
  
    char array23[]= "44A!!A";		
    int base23 = 9;
    int result23 = 0;
    test(array23, base23, result23);
  
    char array24[]= "   ";		
    int base24 = 10;
    int result24 = 0;
    test(array24, base24, result24);
  
    char array25[]= "WXYZ";		
    int base25 = 10;
    int result25 = 0;
    test(array25, base25, result25);
  
    char array26[]= "ZZ";		
    int base26 = 37;
    int result26 = 0;
    test(array26, base26, result26);
  
    char array27[]= "ZZ";		
    int base27 = 1;
    int result27 = 0;
    test(array27, base27, result27);
  
    return 0;
  
}

