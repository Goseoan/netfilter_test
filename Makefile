all : netfilter_test

netfilter_test : netfilter.o main.o hashmap.o 
	gcc -lpcap -lnetfilter_queue -lcrypt -o netfilter_test netfilter.o main.o hashmap.o

netfilter.o : netfilter.c netfilter.h 
	gcc -lpcap -lnetfilter_queue -lcrypt  -c -o netfilter.o netfilter.c 

main.o : main.c netfilter.h
	gcc -lpcap -lnetfilter_queue -lcrypt -c -o main.o main.c

hashmap.o : hashmap.c hashmap.h
	gcc -c -o hashmap.o hashmap.c

clean :
	rm *.o netfilter_test
