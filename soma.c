#include "shelly.h"
/**
 * soma - Reads a line from standard input
 *
 * Return: Pointer to the line read from stdin. Returns NULL on failure.
 */
char *soma()
{
size_t urefu = 0;
char *laini = NULL;
ssize_t soma = getline(&laini, &urefu, stdin);
if (soma == -1)
{
if (feof(stdin))
{
free(laini);
exit(0);
}
perror("getline");
free(laini);
exit(EXIT_FAILURE);
}
if (laini[soma - 1] == '\n')
{
laini[soma - 1] = '\0';
}
return (laini);
}

