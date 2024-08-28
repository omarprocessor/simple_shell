#include "shelly.h"
/**
 * execute_command - Forks a process and executes the command
 * @cmd: Command to execute
 */
void execute_command(char *cmd)
{
pid_t pid;
int status;
char *argv[2]; /* Declare the argv array with two elements */
argv[0] = cmd; /* Assign the command as the first argument */
argv[1] = NULL; /* The last element is NULL */
pid = fork();
if (pid == -1)
{
perror("Error:");
}
else if (pid == 0)
{
/* Child process executes the command */
if (execve(cmd, argv, environ) == -1)
{
chora("./hsh: No such file or directory\n");
}
_exit(EXIT_FAILURE); /* Use _exit instead of exit in child */
}
else
{
/* Parent process waits for the child to finish */
wait(&status);
}
}
/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char *cmd;
while (1)
{
promptly();  /* Display the shell prompt */
cmd = soma();  /* Read user input */
if (cmd == NULL) /* Handle EOF (Ctrl+D) */
{
free(cmd);
exit(0);
}
execute_command(cmd); /* Execute the command */
free(cmd); /* Free the allocated memory for the command */
}
return (0);
}

