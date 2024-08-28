#include "shelliyangu.h"

/**
 * shughulikia_amri - Process and execute the user's command
 * @amri: The command entered by the user
 *
 * Return: 1 to continue the loop, 0 to exit
 */
int shughulikia_amri(char *amri)
{
char *programu;
char *vigezo[100];
int i = 0;

vigezo[i] = strtok(amri, " ");
while (vigezo[i] != NULL)
vigezo[++i] = strtok(NULL, " ");

if (vigezo[0] == NULL)
return (1);

if (strcmp(vigezo[0], "exit") == 0)
return (0);
if (strcmp(vigezo[0], "env") == 0)
chapisha_env();
return (1);
programu = tafuta_njia(vigezo[0]);

if (programu == NULL)
{
perror(vigezo[0]);
return (1);
}

tekeleza_amri(programu, vigezo);

free(programu);
return (1);
}

