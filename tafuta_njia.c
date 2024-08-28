#include "shelliyangu.h"

/**
 * tafuta_njia - Finds the full path of the command
 * @amri: Command entered by the user
 *
 * Return: Full path of the command or NULL if not found
 */
char *tafuta_njia(char *amri)
{
char *njia = getenv("PATH");
char *njia_token;
char full_path[1024];

if (amri[0] == '/' || amri[0] == '.')
{
if (access(amri, X_OK) == 0)
return (strdup(amri));
return (NULL);
}

njia_token = strtok(njia, ":");
while (njia_token != NULL)
{
sprintf(full_path, "%s/%s", njia_token, amri);
if (access(full_path, X_OK) == 0)
return (strdup(full_path));
njia_token = strtok(NULL, ":");
}

return (NULL);
}


