test_pointer: read_data.o main.o
	gcc -o test_pointer read_data.o main.o
main.o:	main.c read_data.h
	gcc -c main.c
read_data.o: read_data.c read_data.h
	gcc -c read_data.c
clean:
	rm -f *.o test_pointer
