# all : netfilter_test

# netfilter_test : netfilter.o main.o hashmap.o 
# 	gcc -lpcap -lnetfilter_queue -lcrypt -o netfilter_test netfilter.o main.o hashmap.o

# hashmap.o: hashmap.c hashmap.omake netfilter.h
#  	gcc -c -o hashmap.c hashmap.c 

# # hashtable.o : hashtable.c netfilter.h
# # 	gcc -c -o hashtable.o hashtable.c

# netfilter.o : netfilter.c netfilter.h hashmap.h hashmap.c
# 	gcc -lpcap -lnetfilter_queue -lcrypt  -c -o netfilter.o netfilter.c 

# main.o : main.c netfilter.h hashmap.h hashmap.c
# 	gcc -lpcap -lnetfilter_queue -lcrypt -c -o main.o main.c

# clean :
# 	rm *.o netfilter_test

netfilter_test: main.c netfilter.c hashmap.c
	gcc -o netfilter_test main.c netfilter.c hashmap.c -lcrypt -lnetfilter_queue