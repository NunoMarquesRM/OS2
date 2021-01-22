#include "shell.h"

int isJPEG(int file)
{
    unsigned char b[4];

    read(file, b, 4);
    lseek(file, 0L, 0);

    if(b[0] == 0xff && b[1]==0xd8 && b[2] == 0xff && b[3] == 0xe0)
	{
    	printf("\n O ficheiro e do tipo jpeg\n");
    	return 1;
	}
    else
    {
    	printf("\n O ficheiro nao e do tipo jpeg");
    	return 0;
    }
}