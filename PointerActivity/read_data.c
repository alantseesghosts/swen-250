/*
 * Implementation of the read_data module.
 *
 * See read_data.h for a description of the read_data function's
 * specification.
 *
 * Note that the parameter declarations in this module must be
 * compatible with those in the read_data.h header file.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "read_data.h"
int *pointerToInt;
double *pointerToDouble;
char *pointerToChar;
char pointers[25];
// Reads the three fields from lines such as W$1349$1.414$ into
// local variables using getchar().
// Converts the two numeric fields to numbers using atoi for the
// integer fields and atof for the double.
// Using a correctly defined set of parameters (use pointers) pass
// those values back to the program that called this function.
void read_data( char *c, int *i, double *d ) {

	int  inp, count;
	char numBuff[21];

	// Assumes well-formed input !!!

	inp = getchar();
	*c = inp;	 // first character read is our character
	inp = getchar(); //skip over first delimiter
	count = 0;
	while( (inp = getchar()) != '$')  // integer number next
		numBuff[count++] = inp;
	numBuff[count] = '\0';
	*i = atoi( numBuff );		// ascii to integer
	count = 0;
	while( (inp = getchar()) != EOF ) // double number last
		numBuff[count++] = inp;
	numBuff[count] = '\0';		
	*d = atof( numBuff );		// ascii to double
	return ;
}

