#include "shelliyangu.h"

/* Helper Function Prototypes */
int handle_exit(char **vigezo);
int handle_env(char **vigezo);
int handle_command_execution(char **vigezo);

/**
 * shughulikia_amri - Handles a command by breaking it down and executing
 * @amri: The command string to handle
 *
 * Return: 0 to exit the shell, 1 to continue
 */
int shughulikia_amri(char *amri)
{
char *vigezo[100];
int i = 0;

vigezo[i] = strtok(amri, " ");
while (vigezo[i] != NULL)
vigezo[++i] = strtok(NULL, " ");

if (handle_exit(vigezo) == 0)
return (0);

if (handle_env(vigezo) == 1)
return (1);

return (handle_command_execution(vigezo));
}

/**
 * handle_exit - Checks if the command is "exit" and handles it
 * @vigezo: Array of command arguments
 *
 * Return: 0 if the command is "exit", otherwise 1
 */
int handle_exit(char **vigezo)
{
if (strcmp(vigezo[0], "exit") == 0)
return (0);
return (1);
}

/**
 * handle_env - Checks if the command is "env" and prints the environment
 * @vigezo: Array of command arguments
 *
 * Return: 1 if the command is "env", otherwise 0
 */
int handle_env(char **vigezo)
{
if (strcmp(vigezo[0], "env") == 0)
{
chapisha_env();
return (1);
}
return (0);
}

/**
 * handle_command_execution - Handles execution of a command
 * @vigezo: Array of command arguments
 *
 * Return: 1 to continue the shell loop
 */
int handle_command_execution(char **vigezo)
{
char *programu;

if (access(vigezo[0], X_OK) == 0)
tekeleza_amri(vigezo[0], vigezo);
else
{
programu = tafuta_njia(vigezo[0]);
if (programu != NULL)
{
tekeleza_amri(programu, vigezo);
free(programu);
}
else
printf("%s: command not found\n", vigezo[0]);
}
return (1);
}

