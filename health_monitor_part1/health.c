/*
* Health Monitoring System
*/

#include <stdio.h>
#include <ctype.h>

#define MAXPATIENTS 5
#define MAXREADINGS 10
#define MAXTYPES 5
#define MAXTIME 8

/* One health type reading: timestamp + actual value */
typedef struct{
	char timestamp[MAXTIME+1];
	int value;
}Element;

/* Circular buffer of health type readings */
typedef struct{
	int start;	/* index of oldest reading */
	int end;	/* index of most current reading */
	Element reading[MAXREADINGS];
}CircularBuffer;

/* Patient's health chart: ID + multiple health type readings */
typedef struct{
	int id;
	CircularBuffer buffer[MAXTYPES];
}Chart;


/*
* Health records for all patients defined here.
* The variable record is visible to all functions
* in this file, i.e. it is global.
*/
Chart record[MAXPATIENTS];	

void main(){
int i = 0;
int j = 0;

/* initialize health data records for each patient */

for( i=0; i < MAXPATIENTS; i++ ){
    record[i].id = i + 1;
    for( j=0; j < MAXTYPES; j++ ){
        record[i].buffer[j].start = 0;
	record[i].buffer[j].end = 0;
        }
    }
printf("Welcome to the Health Monitoring System \n");

int id;
int hours;
int mins;
int secs;
int type;
int value;
get_field(&id, &hours, &mins, &secs, &type, &value);
printf("Readings for Patient ID = %d \n", id);
if (type == 1){
	printf("Temperature: \n");
	printf("%d:%d:%d:  %d \n", hours, mins, secs, value);
}
if (type == 2){
	printf("Heart Rate: \n");
	printf("%d:%d:%d:  %d \n", hours, mins, secs, value);
}
if (type == 3){
	printf("Systolic Pressure: \n");
	printf("%d:%d:%d:  %d \n", hours, mins, secs, value);
}
if (type == 4){
	printf("Diastolic Pressure: \n");
	printf("%d:%d:%d:  %d \n", hours, mins, secs, value);
}
if (type == 5){
	printf("Respiration Rate: \n");
	printf("%d:%d:%d:  %d \n", hours, mins, secs, value);
}
if (type == 6){
	printf("%d, %d:%d:%d, %d, %d \n", id, hours, mins, secs, type, value);
}

printf("\nEnd of Input\n");
}
int get_field(int* id, int* hours, int* mins, int* secs, int* type, int* value){
        //get the patient ID
        int z = getchar();
        *id = z;
        getchar();
        getchar();

        //this gets the hour

        char j[MAXTIME];
        int m,n = 0;
        while ((m < (MAXTIME - 1)) && ((n=getchar()) != '\n')){
                j[m] = n;
                m++;
        }
        *hours = atoi(j);

        //this gets the mins

        char k[MAXTIME];
        n = 0;
        m = 0;
        while ((m < (MAXTIME - 1)) && ((n=getchar()) != ':')){
                k[m] = n;
                m++;
        }
        *mins = atoi(k);

        // this gets the seconds

        char l[MAXTIME];
        n = 0;
        m = 0;
        while ((m < (MAXTIME - 1)) && ((n=getchar()) != ':')){
                l[m] = n;
                m++;
        }
        *secs = atoi(l);

        getchar();
        getchar();

        // this gets the field

        z = getchar();
        *type = z;
        getchar();
        getchar();

        // this gets the score

        m = 0;
        n = 0;
        char x[MAXTIME];
        while ((m < (MAXTIME - 1)) && ((n=getchar()) != '\n')){        
		x[m] = n;
                m++;
        }
        *value = atoi(x);
        return 0;
}
