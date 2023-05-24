#include "main.h"
/**
* cf_strtok_cmpr -compares strings for string tokenization
* @ch: characters to be compared
* @strings: strings to be compared
* Return: 1 if character is same as string, and 0 if not
*/
int cf_strtok_cmpr(char ch, char *strings)
{
	unsigned int a;

	for (a = 0; strings[a] != '\0'; a++)
	{
	if (ch == strings[a])
	return (1);
	}
	return (0);
}
