#include "netfilter.h"
#include "hashmap.h"

void make_mal_list(map_int_t  * m)
{    
    map_set(m, "test.gilgil.net", md5_crypt("test.gilgil.net"));
    map_set(m, "kitribob.wiki", md5_crypt("kitribob.wiki"));
    //printf("debug make mal list \n");
}

int find_url(const u_char * Buffer, map_int_t *mal)
{
    uint16_t iphdrlen;    
     
    struct iphdr *iph = (struct iphdr *)Buffer;
    iphdrlen = iph->ihl*4;
     
    struct tcphdr *tcph=(struct tcphdr*)(Buffer + iphdrlen);             
    int header_size =  iphdrlen + tcph->doff*4;      

    char *str_host;
    char *url;
    static char tok[2]= {0x0d,0x0a}; 
    char *tok_str;
    
/*    regex_t    preg;
    char       *string;
    char       *pattern = "Host: ([^\x0d\x0a]*)";
    int        rc;
    size_t     nmatch = 2;
    regmatch_t pmatch[2];
 
    if (0 != (rc = regcomp(&preg, pattern, 0)))
    {
        printf("regcomp() failed, returning nonzero (%d)\n", rc);
        return EXIT_FAILURE;
    }
 
    if (0 != (rc = regexec(&preg, string, nmatch, pmatch, 0)))
    {
        printf("Failed to match '%s' with '%s',returning %d.\n",
            string, pattern, rc);
    }
    else
    {
        printf("With the whole expression, "
            "a matched substring \"%.*s\" is found at position %d to %d.\n",
            pmatch[0].rm_eo - pmatch[0].rm_so, &string[pmatch[0].rm_so],
            pmatch[0].rm_so, pmatch[0].rm_eo - 1);
        printf("With the sub-expression, "
            "a matched substring \"%.*s\" is found at position %d to %d.\n",
            pmatch[1].rm_eo - pmatch[1].rm_so, &string[pmatch[1].rm_so],
            pmatch[1].rm_so, pmatch[1].rm_eo - 1);
   }
   regfree(&preg);
*/
    //char *mal_site = "test.gilgil.net";   
    //strstr(Buffer + header_size,mal_site);

    str_host = strstr(Buffer + header_size,"Host: ");
    tok_str = strtok(str_host,tok);
    strtok(tok_str," ");
    url = strtok(NULL," ");

    //printf("hashmap key : %s\n", url);
    if(url == NULL) {
        return EXIT_FAILURE; 
    }
    
    int *val = map_get(mal, url);
    
    //printf ("\nmal_site : %s\n", mal_site);
    //printf ("url : %s\n", url);


    //if( memcmp(url,mal_site,sizeof(url)) == 0 )
    if(val)
    {
        printf("* Drop the url : %s \n", url);
        return EXIT_SUCCESS;         
    }
    else
    {
        //printf("FAILE TO FIND MAL SITRE\n");
        return EXIT_FAILURE;        
    }
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
    srand (time(NULL));
    seed[0] = rand();
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





    

