#include "shelliyangu.h"

/**
 * chapisha_env - Print all environment variables
 */
void chapisha_env(void)
{
int i = 0;

while (environ[i] != NULL)
{
printf("%s\n", environ[i]);
i++;
}
}
