#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define FALSE (0)
#define TRUE  (1)

int main() {
	int tot_chars = 0 ;	/* total characters */
	int tot_lines = 0 ;	/* total lines */
	int tot_words = 0 ;	/* total words */

	int in_space = 1;
    	int c, last = '\n';

	while ((c = getchar()) != EOF) {
        last = c;
        tot_chars++;
        if (isspace(c)) {
            in_space = 1;
            if (c == '\n') {
                tot_lines++;
            }
        } 
	else {
            tot_words += in_space;
            in_space = 0;
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
