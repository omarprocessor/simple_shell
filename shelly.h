#ifndef SHELLY_H
#define SHELLY_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void chora(const char *str);
void promptly(void);
char *soma();




#endif /* SHELLY_H */
