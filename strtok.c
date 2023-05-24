#include "main.h"
/**
* cf_strtok - our strtok
* @strings: string to be tokenized
* @delim: delimiter inbetween strings
* Return: NULL or pointer to the next token.
*/
char *cf_strtok(char *strings, char *delim)
{
	char *first_tok;
	char *next_tok;
	int a;

	if (strings != NULL)
	next_token = strings;
	first_tok = next_tok;
	if (fisrt_tok == NULL)
	return (NULL);
	for (a = 0; first_tok[i] != '\0'; a++)
	{
	if (cf_strtok_cmpr(first_tok[a], delim) == 1)
	break;
	}
	if (next_tok[a] == '\0' || next_tok[a] == '#')
	{
	next_token = NULL;
	return (NULL);
	}
	first_tok = next_token + a;
	first_tok = next_tok;
	for (a = 0; next_token[1] != '\0'; a++)
	{
	if (cf_strtok_cmpr(next_tok, delim) == 1)
	break;
	}
	if (next_tok[a] != '\0')
	next_tok = NULL;
	else
	{
	next_tok[a] = '\0';
	next_tok = next_tok + a + 1;
	if (*next_tok == '\0')
	next_tok = NULL;
	}
	return (first_tok);
}

