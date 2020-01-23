#include <stdio.h>
int main()
{
	int fahrenheit;
	int celsius;
	printf("Fahrenheit - Celsius\n");
	for (int i = 0; i <= 300; i += 20)
	{
	    //Statements to be executed repeatedly
	    fahrenheit = i;
		celsius = (5* (fahrenheit-32))/9;
		
		if (i < 100){
		    printf("  %d            ", fahrenheit);
		    printf("%d\n", celsius);
	    }
	    else{
	        printf("  %d            ", fahrenheit);
		    printf("%d\n", celsius);  
	    }
	}

	return celsius;
}


