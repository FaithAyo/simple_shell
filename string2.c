#include "main.h"

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
