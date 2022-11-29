#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

int intiger_validation(char *str)
{
	long int num ;

	int len =0 , count = 0;
	
	num = atoi(str);
	
	len = strlen(str);
	
	
	if(num <= 0)
	{
		return 1;
	}
	else
	{	
		do {
		
			num /= 10;
			++count;
			
		  }while(num != 0);
		  
		  if(len == count)
		  	return 0;
		  else 
		  	return 1;	
        }
}


int alpha_validator(char *s)
{

        //validation for alphabets
        for(char *p=s;*p!='\0';p++)
        {
                if((!isalpha(*p)) && (*p!=' '))
                {
                	printf("test %c\n",*p);
                        return 0;
                       }
        }
        //validation for length
        if(strlen(s)>=2 && strlen(s) <=15)
        {
                
                return 1;
        }
        else 
        {
        	printf("Enter name within the length of 5 to 15\n");
        return 1;
        }
}
