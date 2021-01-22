#include "shell.h"

void socp(char *fonte, char *destino)
{
    int n, in, out;
    char buf[BUFFSIZE];    
    // verifica se está tudo em ordem
    
    if(((in = open(fonte, O_RDONLY)) > 0) && ((out = creat(destino, S_IRUSR | S_IWUSR)) > 0))
    {     
        while((n = read(in, buf, BUFFSIZE)) > 0)
        {
            fprintf(stderr, "\n*** N=%d dados lidos ***\n", n);
            if (write(out, buf, n) != n)
                perror("Erro de escrita!\n");
        }
        if(n < 0)
            perror("Erro de leitura!\n");
    }
    else if(in <= 0)
    {
        perror("Erro na abertura do ficheiro de origem!\n");
    }
    else
    {
        perror("Erro na criação do ficheiro de destino!");
    }
    // fecha os ficheiros
    close(in);
    close(out);
}
