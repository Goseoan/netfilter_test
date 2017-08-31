#ifndef __NETFILTER_H__
#define __NETFILTER_H__


#include <pcap.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
 
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <netinet/tcp.h>   
#include <netinet/ip.h>

#include <unistd.h>
#include <netinet/in.h>
#include <linux/types.h>
#include <linux/netfilter.h>        /* for NF_ACCEPT */
#include <errno.h>

#include <libnetfilter_queue/libnetfilter_queue.h>

#include <crypt.h>
#include "hashmap.h"
#include <regex.h>

static u_int32_t print_pkt (struct nfq_data *tb,int *);
//int find_url(const u_char *, map_base_t *);
void make_mal_list(map_int_t *);
char* md5_crypt(char *);

#endif