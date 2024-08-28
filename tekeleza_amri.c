#include "shelliyangu.h"

/**
 * tekeleza_amri - Execute the command using fork and execve
 * @programu: The path to the executable program
 * @vigezo: The command arguments
 *
 * Return: void
 */
void tekeleza_amri(char *programu, char *vigezo[])
{
pid_t mchakato_id;
int hali;

mchakato_id = fork();
if (mchakato_id == 0)
{
if (execve(programu, vigezo, NULL) == -1)
perror("execve");
exit(EXIT_FAILURE);
}
else if (mchakato_id < 0)
{
perror("fork");
}
else
{
waitpid(mchakato_id, &hali, 0);
}
}
