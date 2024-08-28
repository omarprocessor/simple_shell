#include "shell.h"

/**
 * tafuta_njia - Find the full path of a command
 * @amri: The command entered by the user
 *
 * Return: The full path of the command, or NULL if not found
 */
char *tafuta_njia(char *amri)
{
char *njia, *njia_nakili, *njia_sehemu;
char *amri_njia = malloc(1024);
struct stat habari;

if (strchr(amri, '/') != NULL)
{
if (stat(amri, &habari) == 0)
return (strdup(amri));
return (NULL);
}

njia = getenv("PATH");
if (!njia)
return (NULL);

njia_nakili = strdup(njia);
njia_sehemu = strtok(njia_nakili, ":");
while (njia_sehemu != NULL)
{
snprintf(amri_njia, 1024, "%s/%s", njia_sehemu, amri);
if (stat(amri_njia, &habari) == 0)
{
free(njia_nakili);
return (amri_njia);
}
njia_sehemu = strtok(NULL, ":");
}

free(njia_nakili);
free(amri_njia);
return (NULL);
}

