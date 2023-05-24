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
* 
