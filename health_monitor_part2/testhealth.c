#include "health.h"
#include "simplectest.h"

Chartptr patientList;

// Each of the following tests should run independently without any shared
// state.
START_TESTS()


/* Tests adding new patient to an empty  patient list
*/
START_TEST("add one chart to an empty patient list")
	int testid = 101;
	patientList = NULL;
	addPatient( testid );
    ASSERT_EQUALS( testid, patientList->id );
	ASSERT_EQUALS( NULL, patientList->buffer );
	ASSERT_EQUALS( NULL, patientList->next );
END_TEST()

/* Tests finding a new patient after adding to empty patient list
*/
START_TEST("find patient after adding to empty list")
	int testid = 101;
	patientList = NULL;
	Chartptr searchResult = NULL;
	
	addPatient( testid );
	searchResult = getChart( testid );
    ASSERT_EQUALS( testid, searchResult->id );
END_TEST()

/* Tests adding new data type to a patient 
*/
START_TEST("add new health data type to only patient in patientList")
	int testid = 101;
	int datatype = 1;
	patientList = NULL;
	Chartptr chart = NULL;
	
	addPatient( testid );
	addHealthType( testid, datatype );
	chart = getChart( testid );
	ASSERT_EQUALS( datatype, chart->buffer->type);
	ASSERT_EQUALS( 0, chart->buffer->start);
	ASSERT_EQUALS( 0, chart->buffer->end);
	ASSERT_EQUALS( NULL, chart->buffer->next);
END_TEST()

END_TESTS()
