#include "main.h"
/**
* cf_strtok - our strtok
* @strings: string to be tokenized
* @delim: delimiter inbetween strings
* Return: NULL or pointer to the next token.
*/
char *cf_strtok(char *strings, const char *delim)
{
	static char *first_tok;
	static char *next_tok;
	unsigned int a;
//	char **alloc
	
	first_tok  = malloc(sizeof(char *) * (cf_strlen(strings) + 1));
	if (strings != NULL)
		next_tok = strings;
	first_tok = next_tok;
	strcpy(first_tok, next_tok);
	if (first_tok == NULL)
		return (NULL);
	for (a = 0; first_tok[a] != '\0'; a++)
	{
	if (cf_strtok_cmpr(first_tok[a], delim) == 1)
		break;
	}
	if (next_tok[a] == '\0' || next_tok[a] == '#')
	{
		next_tok = NULL;
		return (NULL);
	}
	first_tok = next_tok + a;
	first_tok = next_tok;
	for (a = 0; next_tok[a] != '\0'; a++)
	{
	if (cf_strtok_cmpr(next_tok[a], delim) == 1)
		break;
	}
	if (next_tok[a] != '\0')
		next_tok = NULL;
	else
	{
		next_tok[a] = '\0';
		next_tok = next_tok + a + 1;
	}
	if (*next_tok == '\0')
		next_tok = NULL;
	
	free(strings);
	return (first_tok);
}
