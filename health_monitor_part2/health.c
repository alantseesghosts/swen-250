#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "health.h"

/*
* Main function for the Health Monitoring System. Primarily responsible for
* processing input of csv lines and printing as required. Data structures are
* maintained using the helper functions in health_util.c
* 
*/

Chartptr patientList = NULL;    /* Define global variable patientList (declared in health.h) */
								/* patientList is globaaly accessible in health_util.c    */

void main(){

printf("Welcome to the Health Monitoring System\n\n");

/*
*  YOUR CODE GOES HERE:
*  (1) Read an input csv line from stdin 
*  (2) Parse csv line into appropriate fields
*  (3) Take action based on input type:
*  		 - Check-in or check-out a patient with a given ID
*        - Add a new health data type for a given patient
*        - Store health data in patient record or print if requested
*  (4) Continue (1)-(3) until EOF
*/

	int id; //variable to keep track of scanf's id imput
	char time[MAXTIME + 1]; //variable to keep track of scanf's time input
	int type; //variable to keep track of the type
	int value; // variable to keep track of the value
	int buffIndex; //variable for print statement to keep track of number of buffers
	int readIndex;//variable for print case to keep track of the readings in the buffer
	CBuffptr patientHealth; //a buffer pointer to get the health records to add in a new health reading
	//a character array to keep track of all of the types of readings
	char* types[] = {"Temperature:", "Heart Rate:", "Systolic Pressure:", "Diastolic Pressure:", "Respiration Rate"};
	Chartptr checking;//Pointer to make sure that the chart of the patient doesn't equal NULL
	CBuffptr patientPrint; //A bufferpointer used during the print case











printf("\nEnd of Input\n");

}
