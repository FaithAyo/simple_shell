#include "main.h"
/**
* cf_strlen - displays the length of the string
* @strings: string to be displayed
* Return: length of the string
*/
int cf_strlen(char *strings)
{
	int str_len;

	for (str_len = 0; strings[str_len]; str_len++)
		;

	return (str_len);
}

/**
* cf_strdup - duplicate the string
* @strings: string to duplicate
* Return: Duplicate of the string
*/

char *cf_strdup(char *strings)
{
	char *str_dup;
	int str_len, i;

	str_len = cf_strlen(strings);
	str_dup = malloc(sizeof(char) * (str_len + 1));
	for (i = 0; i <= str_len; i++)
	{
		str_dup[i] = strings[i];
	}

	return (str_dup);
}

/**
* cf_strcmp - compare the individual characters in a string
* @first_str: first tring to be compare
* @second_str: second string to be compared
* Return: 0 on success or any other value on failure
*/
int cf_strcmp(char *first_str, char *second_str)
{
	int i = 0;

	while (first_str[i] == second_str[i])
	{
		if (first_str[i] == '\0')
			return (0);
		i++;
	}
	return (first_str[i] - second_str[i]);
}
