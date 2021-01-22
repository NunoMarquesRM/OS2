#include "shell.h"

void execute(int numArgs, char **args)
{
    int pid, status;
    // verifica se é BG ou FG
    int code = ultimo(numArgs, args);
    if((pid = fork()) < 0) /* cria um processo progenito */
    {    
        perror("fork");   /* NOTE: perror() produz uma pequema mensagem de erro para o stream */
        exit(1);           /* estandardizado de erros que descreve o ultimo erro encontrado */
    }   /* durante uma chamada ao sistema ou funcao duma biblioteca */
    
    if (pid == 0)
    {
        execvp(*args, args);  /* NOTE: as versoes execv() e execvp() de execl() sao uteis quando */
        perror(*args);         /* o numero de argumentos nao e’ conhecido. Os argumentos de  */
        exit(1);                 /* execv() e execvp() sao o nome do ficheiro a ser executado e um */
    }             /* vector de strings que contem os argumentos. */                                                                                                       
    /* O ultimo argumento do string tem de ser seguido por um ponteiro 0.
    
    /* Execução em foreground */
    if(FG == code)
    {
        while (wait(&status) != pid)     /* O progenitor executa a espera */
            ;    
    }

}

int ultimo(int numargs, char **args)
{
    if(args[numargs - 1][0] == '&')
    {
        args[numargs - 1] = NULL;
        return BG;
    }
    return FG;
}