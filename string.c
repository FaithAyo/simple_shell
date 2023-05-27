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
	if (str_dup == NULL)
	{
		return (NULL);
	}
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

/**
* cf_strcat - concatenate two strings
* @first_str: first string
* @second_str: second string to be concatenated
* Return: a new string pointer
*/
char *cf_strcat(char *first_str, char *second_str)
{
	int str_len1, str_len2, total_len;
	int i, j;
	char *new_string;

	str_len1 = cf_strlen(first_str);
	str_len2 = cf_strlen(second_str);
	total_len = str_len1 + str_len2 + 2;
	new_string = malloc(sizeof(char) * total_len);
	if (new_string == NULL)
		return (NULL);
	for (i = 0; i < str_len1; i++)
	{
		new_string[i] = first_str[i];
	}
	new_string[i] = '/';
	for (j = 0; j < str_len2; j++)
	{
		new_string[i + 1 + j] = second_str[j];
	}
	new_string[i + 1 + j] = '\0';

	return (new_string);
}
