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
	Chartptr chart;//Pointer to make sure that the chart of the patient doesn't equal NULL
	CBuffptr patientPrint; //A bufferpointer used during the print case

//A while loop that will keep scanning until the input is "End of File"
while(scanf("%i, %8[^,], %i, %i", &id, &time[MAXTIME + 1], &type, &value)!= EOF){
//switches the case based on the type
switch(type){
	//type to reset the patient values
	case 0:
		printf("--------------------------------------------------\n");
		printf("%s: Patient ID = %i reset data\n", &time[MAXTIME + 1], id);
		printf("--------------------------------------------------\n");
		//calls a function that just removes the health values but keeps the chart intact
		removeHealthBuff(id);
		break;
	//To avoid  redundancy and set all the cases will to drop until case 5. Here the action will take place.
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
				chart = getChart(id);
				//Checks to see if the chart is NULL
				if(chart == NULL){
					break;
				}
				//if not NULL, it  will get the health type buffer
				patientHealth = getHealthType(id, type);
				//if it isn't NULL, then it will add the health reading
				if(patientHealth != NULL){
					addHealthReading(patientHealth, &time[MAXTIME + 1], value);
				}
				break;		


}
}
printf("\nEnd of Input\n");

}
