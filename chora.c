#include "shelly.h"
/**
 * chora - Prints a string to stdout
 * @str: The string to print
 */
void chora(const char *str)
{
int len = 0;
while (str[len] != '\0')
{
len++;
}
write(1, str, len);
}

