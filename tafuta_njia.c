#include "shelliyangu.h"

/**
 * tafuta_njia - Searches for a command in PATH directories
 * @command: The command to find
 *
 * Return: Full path of the command if found, NULL otherwise
 */
char *tafuta_njia(char *command)
{
char *path_copy, *dir, *full_path;
struct stat st;
size_t len;
char *paths = getenv("PATH");

if (!paths)
return (NULL);

path_copy = strdup(paths);
if (!path_copy)
return (NULL);

dir = strtok(path_copy, ":");
while (dir)
{
len = strlen(dir) + strlen(command) + 2;
full_path = malloc(len);
if (!full_path)
{
free(path_copy);
return (NULL);
}
snprintf(full_path, len, "%s/%s", dir, command);
if (stat(full_path, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
{
free(path_copy);
return (full_path);
}
free(full_path);
dir = strtok(NULL, ":");
}
free(path_copy);
return (NULL);
}

