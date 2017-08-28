#include "packet.h"
 
int find_url(const u_char * Buffer, int Size, char *mal_site)
{
    uint16_t iphdrlen;
     
    struct iphdr *iph = (struct iphdr *)Buffer;
    iphdrlen = iph->ihl*4;
     
    struct tcphdr *tcph=(struct tcphdr*)(Buffer + iphdrlen);             
    int header_size =  iphdrlen + tcph->doff*4;      

    char *str_host;
    char *url;
    char tok[2]= {0x0d,0x0a};  	
    char *tok_str;
    int tok_size=6;     	
   
    //strstr(Buffer + header_size,mal_site);
    str_host = strstr(Buffer + header_size,"Host: ");
      printf("debug-1111 \n");
    url = strtok(str_host,tok);
    printf("debug-11 \n");

    //strncpy(url,tok_str + tok_size,sizeof(url));


  /*  str_host = strstr(tok_str," ");
    printf ("str_host : %s\n", str_host);
    url = strstr(NULL," ");*/

    printf ("\nmal_site : %s\n", mal_site);
    printf ("url : %s\n", url);

    if(url == NULL)
    	return EXIT_FAILURE; 

    if( memcmp(url,mal_site,sizeof(url)) == 0 )
    {
    	printf("FIND MAL SITE\n");
    	return EXIT_SUCCESS;     	 
    }
    else
    {
    	printf("FAILE TO FIND MAL SITRE\n");
    	return EXIT_FAILURE;     	
    }
} 


    

