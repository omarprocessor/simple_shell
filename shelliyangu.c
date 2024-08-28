#include "shelliyangu.h"

/**
 * main - Entry point for the shell program
 *
 * Return: Always 0
 */
int main(void)
{
char *amri;
size_t urefu = 0;
ssize_t saizi;
int hali = 1;

while (hali)
{
if (isatty(STDIN_FILENO))
printf("#cisfun$ ");
saizi = getline(&amri, &urefu, stdin);
if (saizi == -1)
{
if (isatty(STDIN_FILENO))
printf("\n");
break;
}
if (amri[saizi - 1] == '\n')
amri[saizi - 1] = '\0';
hali = shughulikia_amri(amri);
}

free(amri);
return (0);
}
