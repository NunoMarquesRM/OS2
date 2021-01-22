#include "shell.h"

//redirects are handled in reverse order
// 2>  >> > <
int redirects(int numargs, char *args[])
{
    //redirect stdout >
    if(numargs <3) 
        return numargs;

    if(strcmp(args[numargs - 2] , ">") == 0)  || (strcmp(args[numargs-2], ">>") == 0)
    {
        int fd = creat(args[numargs -1], FILE_MODE); 
        if(fd < 0)
        { 
            perror(NULL); 
            return -1; /*indicar um erro*/ 
        }
        dup2(fd, STDOUT_FILENO);  
        close(fd);
        args[numargs -2] = NULL;
        numargs = numargs - 2;
    }

    else if(0 == strcmp(args[numargs-2], "2>"))
    {
    int fd = creat(args[numargs-1], S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if(fd < 0)
    {
      return -1;
    }
    //numero negative para indicar um erro
    dup2(fd, STDERR_FILENO);
    close(fd);
    args[numargs-2] = NULL;
    numargs=numargs-2;
    }


    else if(strcmp(args[numargs-2], "<") == 0)
    {
    int fd = open(args[numargs-1], O_RDONLY);

    if(fd < 0)
    {
      return -1;
    }

    //numero negative para indicar um erro
    dup2(fd, STDIN_FILENO);
    close(fd);
    args[numargs-2] = NULL;
    numargs=numargs-2;
    }

    return  numargs;
}
