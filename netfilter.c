#include "netfilter.h"
 
int find_url(const u_char * Buffer, char *m)
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
    char *mal_site = "test.gilgil.net";    	
   
    //strstr(Buffer + header_size,mal_site);
    str_host = strstr(Buffer + header_size,"Host: ");
    tok_str = strtok(str_host,tok);
    strtok(tok_str," ");
    url = strtok(NULL," ");

    //int *val =  map_get(&m, url);


    //printf ("\nmal_site : %s\n", mal_site);
    //printf ("url : %s\n", url);

    if(url == NULL)
    	return EXIT_FAILURE; 

    if( memcmp(url,mal_site,sizeof(url)) == 0 )
    //if(val)
    {
    	//printf("FIND MAL SITE\n");
    	return EXIT_SUCCESS;     	 
    }
    else
    {
    	//printf("FAILE TO FIND MAL SITRE\n");
    	return EXIT_FAILURE;     	
    }
}

void make_mal_list(map_int_t * m)
{
  // map_set(&m, "test.gilgil.net", md5_crypt("test.gilgil.net"));

}

char* md5_crypt(char* msg)
{
    unsigned long seed[2];
    char salt[] = "$1$........";
    const char *const seedchars =
    "./0123456789ABCDEFGHIJKLMNOPQRST"
    "UVWXYZabcdefghijklmnopqrstuvwxyz";
    char *crypt_msg;
    int i;

    /* Generate a (not very) random seed.
       You should do it better than this... */
    seed[0] = time(NULL);
    seed[1] = getpid() ^ (seed[0] >> 14 & 0x30000);

    /* Turn it into printable characters from ‘seedchars’. */
    for (i = 0; i < 8; i++)
      salt[3+i] = seedchars[(seed[i/5] >> (i%5)*6) & 0x3f];

    /* Read in the user’s password and encrypt it. */
    crypt_msg = crypt(msg, salt);

    /* Print the results. */
    printf("\ncrypt_msg : %s \n",crypt_msg);
    return crypt_msg;
}



    

