all : netfilter_test

netfilter_test : packet.o main.o
	gcc -lpcap -o netfilter_test packet.o main.o -lnetfilter_queue

packet.o : packet.c packet.h
	gcc -lpcap -c -o packet.o packet.c -lnetfilter_queue

main.o : main.c packet.h
	gcc -lpcap -c -o main.o main.c -lnetfilter_queue

clean :
	rm *.o netfilter_test