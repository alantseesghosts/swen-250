health: health.o health_util.o
	cc -o health health.o health_util.o
health.o:	health.c health.h
	cc -c health.c
health_util.o:	health_util.c health.h
	cc -c health_util.c
test: testhealth.o health_util.o
	cc -o testhealth testhealth.o health_util.o
testhealth.o: testhealth.c health.h
	cc -c testhealth.c
clean:
	rm -f *.o health
	
