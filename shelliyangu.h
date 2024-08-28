#ifndef SHELLIYANGU_H
#define SHELLIYANGU_H

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Prototypes */
int shughulikia_amri(char *amri);
char *tafuta_njia(char *amri);
void tekeleza_amri(char *programu, char *vigezo[]);
void chapisha_env(void);

#endif /* SHELLIYANGU_H */

