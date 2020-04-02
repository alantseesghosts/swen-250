// unit_tests student additions
// Larry L. Kiser Oct. 22, 2015

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#include "analysis.h"
#include "unit_tests_analysis.h"
#include "unit_tests.h"

//////////////////////////////////////////////////////////////////////////
// Begin unit tests //////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// do the unit tests
// returns the number of failed tests.
int test_student()
{	
	int passcount = 0 ;
	int failcount = 0 ;
	struct linked_list list1 ;		// list list pointers for one list
	struct word_entry word;

	// Initialize local stack data
	memset( &list1, 0, sizeof( list1 ) ) ;		// set all pointers to NULL (zero)

	printf( "\n========= student generated tests on MLK excerpt ===============================\n" ) ;

	int result = read_file( &list1, "MLK_dream_excerpt.txt" ) ;
	assert( result == 113,
		"1 read_file processing MLK_dream_excerpt. Expect word count of 113 returned but got %d.", result )
		? passcount++ : failcount++ ;

	// Add a test to verify that the word "day" is used three times in the list.

	find_word(&list1, "day");
	word = get_next_word(&list1);
	word = get_prev_word(&list1);
	assert( word.word_count == 3,
		"2 word day must be used 3 times but got %d\n", word.word_count)
		? passcount++ : failcount++ ;

	// Add a test to verify that the word AFTER the word "have" is the word "heat".

	find_word(&list1, "have");
	word = get_next_word(&list1);
	assert( strcmp(word.unique_word, "heat") == 0,
		"3 word after have must be heat but got %s.", word.unique_word)
		? passcount++ : failcount++ ;

	// Add a test to verify that the last word in the list is "with"

	word = get_last_word(&list1);
	assert( strcmp(word.unique_word, "with") == 0,
		"4 Last word must be with but got %s.", word.unique_word)
		? passcount++ : failcount++ ;

	// Add a test to verify that the next to the last word is "will"

	word = get_prev_word(&list1);
	assert( strcmp(word.unique_word, "will") == 0,
		"5 Word next to last word must be will but got %s.", word.unique_word)
		? passcount++ : failcount++ ;

	result = clear_linked_list( &list1 ) ;
	assert( result == 62,
		"6 clear linked list expected to remove 62 entries but got %d.", result )
		? passcount++ : failcount++ ;

	printf( "\nSummary of analysis unit tests:\n%d tests passed\n%d tests failed\n\n", passcount, failcount ) ;

	return failcount ;
}	
