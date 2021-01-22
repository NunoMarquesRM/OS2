#include "shell.h"

int parse(char *buf, char **args)
{
    int c = 0;
	
    while('\0' != *buf)
    {

      /* strip whitespace. Usa um NULL para indicar que o argumento anterior e. o ultimo */
        while(isspace((unsigned char)*buf))
	        *buf++ = '\0';

        *args++ = buf;
	    c++;		/* salvaguarda argumento */


        while((*buf != '\0') && (!isspace((unsigned char)*buf)))	/* salta sobre o argumento */
	       buf++;
    }
    *args = (char*) NULL;	/* o ultimo argumento e. NULL */

    if(debug)
        fprintf(stderr,"int parse numargs = %d\n",c);
    return c;
}