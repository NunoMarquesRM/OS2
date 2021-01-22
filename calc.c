#include "shell.h"

void calc(char *value1, char *operator, char *value2)
{    
    float primeiro = atof(value1);
    float segundo = atof(value2);
    float aux = 0;
    
    switch(*operator)
    {
        case '+':
            aux = primeiro + segundo;
            printf("\nSoma: %s + %s = %f\n",value1, value2, aux);
            break;

        case '-':
            aux = primeiro - segundo;
            printf("\nSubtracao: %s - %s = %f\n",value1, value2, aux);
            break;
        
        case '/':
            if(segundo == 0.0)
            {
                printf("\nErro: nao e possivel realizar a divisao pelo 0\n");
                return;
            }
            aux = primeiro / segundo;
            printf("\nDivisao: %s / %s = %f\n",value1, value2, aux);
            break;
        
        case '*':
            aux = powf(primeiro, segundo);
            printf("\nPotencia: %s / %s = %f\n",value1, value2, aux);
            break;

        default:
            printf("\nErro: o operador nao e suportado.\n");
            break;
    }
}

void bits(char *value1, char *operator, char *value2)
{
    int primeiro = atoi(value1);
    int segundo = atoi(value2);
    int aux = 0;
    
    switch(*operator)
    {
        case '&':
            aux = primeiro&segundo;
            printf("\nBitwise AND: %s & %s = %d\n",value1, value2, aux);
            break;

        case '|':
            aux = primeiro|segundo;
            printf("\nBitwise Inclusive OR: %s | %s = %d\n",value1, value2, aux);
            break;
        
        case '^':
            aux = primeiro^segundo;
            printf("\nBitwise Exclusive OR: %s ^ %s = %d\n",value1, value2, aux);
            break;

        default:
            printf("\nErro: o operador nao e suportado.\n");
            break;
    }
}
