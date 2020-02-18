#include <stdio.h>
int main()
{
	float fahrenheit;
	float celsius;
	printf("Fahrenheit-Celsius\n");
	for (int i = 0; i <= 300; i += 20)
	{
	    //Statements to be executed repeatedly
	    fahrenheit = i;
		celsius = (5* (fahrenheit-32))/9;
		
		if (i < 100){
		    printf("     %d      ", i);
		    printf("%.1f\n", celsius);
	    }
	    else{
	        printf("     %d     ", i);
		    printf("%.1f\n", celsius);  
	    }
	}

	return 0;
}
