#include <stdio.h>
#include <string.h>
#include "/user/cse320/Projects/project05.support.h"

int convert(const char ch[], int base, int* result){
  
    if (base < 2 || base > 36){
        return 1;
    }
    
    int is_negative = 0;
    int is_value = 0;
    *result = 0;
  
    int i = 0;
    while (ch[i] != 0){
        
        // checks for white space
        if (ch[i] == ' ' || ch[i] == '\n' || ch[i] == '\t'){			
		    if (is_value == 1){	
		        return 1;
		    }
	    }
	    
	    //checks for + and -
	    else if (ch[i] == '+'){
            if (is_value == 1){
			    return 1;
		    }
	    }
	    else if (ch[i] == '-'){	
		    if (is_value == 1){
			    return 1;	
		    }
		    else{
			    is_negative = 1;
		    }
	    }
	    
	    //checks if the character is a digit
	    else if ((ch[i] >= '0') && (ch[i] <= '9')){
		    int current = (ch[i] - '0');
		    if (current >= base){
			    if (is_value == 0){
			        return 0;
			    }
			    break;
		    }
		    is_value = 1;
		    *result = (base * (*result)) + current;
	    }
	    
	    //checks if the character is an upper-case letter
	    else if ((ch[i] >= 'A') && (ch[i] <= 'Z')){
		    int current = ((ch[i] - 'A') + 10);
		    if (current >= base){
			    if (is_value == 0){
				    return 0;
			    }
			    break;
		    }
		    is_value = 1;
		    *result = (base * (*result)) + current;
	    }
	    
	    //checks if the character is a lower-case letter
	    else if ((ch[i] >= 'a') && (ch[i] <= 'z')){
		    int current = ((ch[i] - 'a') + 10);
		    if (current >= base){
			    if (is_value == 0){
			        return 0;
			    }
			    break;
		    }
		    is_value = 1;
		    *result = (base * (*result)) + current;
	    }
	    
	    else{
		    if (is_value == 0){
		        return 0;
		    }
		    return 1;
	    }
	    
	    i++;
	    
    }
    
    // makes the number negative if is_negative is set to 1 (true)
    if (is_negative == 1){
		*result = 0 - (*result);
	}
    return 1;
}
