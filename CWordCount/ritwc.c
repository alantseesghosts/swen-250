#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define FALSE (0)
#define TRUE  (1)

int main() {
	int tot_chars = 0 ;	/* total characters */
	int tot_lines = 0 ;	/* total lines */
	int tot_words = 0 ;	/* total words */

	int space = 1;
    int character, last = '\n';

	while ((character = getchar()) != EOF) {
        last = character;
        tot_chars++;
        if (isspace(character)) {
            space = 1;
            if (character == '\n') {
                tot_lines++;
            }
        } 
	else {
            tot_words += space;
            space = 0;
        }
    }
    if (last != '\n') {
        /* count last line if not linefeed terminated */
        tot_lines++;
    }

    printf("Lines, Words, Characters\n");
    printf("%3d     %3d       %3d\n", tot_lines, tot_words, tot_chars);
    return 0 ;
}
