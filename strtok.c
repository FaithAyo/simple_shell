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
	if (cf_strtok_cmpr(first_tok[a], delim) == 0)
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


/**
 * cf_tokenize - tokenize a buffer with a delimiter
 * @buf: buffer to tokenize
 * @delim: delimeter to tokenize
 * Return: pointer ro an array of the tokens
 */
char **cf_tokenize(char *buf, char delim)
{
	char **tok = NULL;
	size_t a = 0, count = 10;

	if (buf == NULL)
		return (NULL);
	tok = malloc(sizeof(char *) * count);
	if (tok == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tok[a] = cf_strtok(buf, delim)) != NULL)
	{
		a++;
		if (i == count)
		{
			tok = cf_malloc(tok, count);
			if(tok == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		buffer = NULL;
	}
		return (tok);
}