#include "shell.h"

char prompt[100];

int main()
{
    int len;
    char buf[1024];		/* um comando */
    char *args[64];		/* com um maximo de 64 argumentos */

    strcpy (prompt, "SOSHELL: Introduza um comando : prompt> ");
    
    while(1)
    {
        printf("%s", prompt);
        if(fgets(buf,1023,stdin) == NULL)
        {
            printf ("\n");
            exit (0);
        }
        
        len = strlen(buf);
        
        if(1 == len) 
            continue;  // string is only a barra n
        
        if(buf[len-1] == '\n')
            buf[len-1] ='\0';
        
        int numArgs = parse(buf, args);	/* particiona a string em argumentos */
    
        if(!builtin(numArgs, args))
            execute(numArgs, args);		/* executa o comando */
    }

    return 0;
}

// comandos embutidos na shell
int builtin(int numArgs, char *args[])
{
    switch(numArgs)
    {
        case 1:
            if(strcmp(args[0], "cd") != 0 && strcmp(args[0], "ls") != 0)
            {
                if(strcmp(args[0], "sair") == 0 || strcmp(args[0], "exit") == 0)
                {
                    exit(0);
                    return 1;
                }
                if(strcmp(args[0], "42") == 0)
                {
                    printf("42 is the answer to life in then universe and everything\n");
                    return 1;
                }
                if(strcmp(args[0], "obterinfo") == 0)
                {
                    printf("SOShell 2019 versão 1.0\n");
                    return 1;
                }
                if(strcmp(args[0], "quemsoueu") == 0)
                {
                    system("id");
                    return 1;
                }
                if(strlen(args[0]) > 4 && 0 == strncmp(args[0], "PS1=",4) )
                {
                    strcpy(prompt,args[0]+4);
                    return 1;
                }
            }
            break;

        case 2:
            if(strcmp(args[0], "isJPEG") == 0)
            {
                isJPEG(open(args[1], O_RDONLY));  
                return 1;
            }
            break;

        case 3:
            if(strcmp(args[0], "socp") == 0)
            {
                socp(args[1], args[2]);
                return 1;
            }
            break;

        case 4:
            if(strcmp(args[0], "calc") == 0)
            {
                calc(args[1], args[2], args[3]);
                return 1;
            }
            if(strcmp(args[0], "bits") == 0)
            {
                bits(args[1], args[2], args[3]);
                return 1;
            }
            break;

            default:
                printf("\nO comando nao existe ou excede o numero de argumentos\n");
                break;
    }

    if(strcmp(args[0], "cd") == 0)
    {
        int err;
        if ((NULL == args[1]) || (strcmp(args[1], "~") == 0))
            err=chdir(getenv("HOME"));
        else
            err=chdir(args[1]);
        if (err<0)
            perror("chdir failed");
        return 1; //comando embutido
    }

    return 0;
}