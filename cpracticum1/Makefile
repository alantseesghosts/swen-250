HEADERS = cpracticum.h unit_tests.h

default: test

test:	cpracticum.o unit_tests.o
	cc -g -o test cpracticum.o unit_tests.o
	
cpracticum.o: cpracticum.c $(HEADERS)
	cc -g -Wall -c cpracticum.c

unit_tests.o: unit_tests.c $(HEADERS)
	cc -g -Wall -c unit_tests.c

clean:
	-rm -f cpracticum.o
	-rm -f unit_tests.o
	-rm -f test
	
