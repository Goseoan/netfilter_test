#ifndef __PACKET_H__
#define __PACKET_H__


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

int find_url(const u_char *  , int, char *);
void PrintData (const u_char * , int);
static u_int32_t print_pkt (struct nfq_data *tb);
static int cb(struct nfq_q_handle *qh, struct nfgenmsg *nfmsg,
          struct nfq_data *nfa, void *data);

struct ret_pkt{
	u_int32_t id;
	int chk;
};

#endif