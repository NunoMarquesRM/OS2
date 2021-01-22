#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <dirent.h>
#include <math.h>

// variáveis globais
#define BUFFSIZE 128
#define debug 0
#define BG 0
#define FG 1 

int parse(char *buf, char **args);

void execute(int numArgs, char **args);

int builtin(int n, char **args);

int redirects(int numargs, char *args[]);
