#include "main.h"
/**
* cf_strcpy - copies a string
* @str_cpy: the copy of string
* @strings: original string
* @n: length of string
* Return: the string copy
*/
char *cf_strcpy(char *str_cpy, const char *strings, size_t n)
{
	char *strc_start;

	strc_start = str_cpy;
	while (*strings != '\0' && n > 0)
	{
		*str_cpy = *strings;
		++str_cpy;
		++strings;
		--n;
	}

	while (n > 0)
	{
		*str_cpy = '\0';
		++str_cpy;
		--n;
	}
	return strc_start;
}
char *cf_strtok(char *strings, const char *delim)
{
    char *first_tok;
    char *token;
    size_t tok_len;
    static char *next_tok;
    const char *i;
    int delimitcount;

    first_tok = NULL;
    next_tok = NULL;
    if (strings != NULL)
        next_tok = strings;
    if (next_tok == NULL || *next_tok == '\0')
        return NULL;

    while (*next_tok != '\0')
    {
        delimitcount = 0;
        for (i = delim; *i != '\0'; ++i)
        {
            if (*next_tok == *i)
            {
                delimitcount = 1;
                break;
            }
        }

        if (!delimitcount)
        {
            if (first_tok == NULL)
                first_tok = next_tok;
        }
        else
        {
            if (first_tok != NULL)
            {
                tok_len = next_tok - first_tok;
                token = malloc((tok_len + 1) * sizeof(char));
                if (token == NULL)
                {
                    perror("Error");
                    exit(EXIT_FAILURE);
                }

                cf_strcpy(token, first_tok, tok_len);
                token[tok_len] = '\0';
                ++next_tok; // Move to the next character
                return token;
            }
        }

        ++next_tok;
    }

    if (first_tok != NULL)
    {
        tok_len = next_tok - first_tok;
        token = malloc((tok_len + 1) * sizeof(char));
        if (token == NULL)
        {
            perror("Error");
            exit(EXIT_FAILURE);
        }

        cf_strcpy(token, first_tok, tok_len);
        token[tok_len] = '\0';
        next_tok = NULL;
        return token;
    }

    return NULL;
}

/**
* cf_strtok - function displays the string and delimiter
* @strings: the strings
* @delim: delimiter
* Return: the string and delimiter
*/
/**char *cf_strtok(char *strings, const char *delim)
{
	char *first_tok;
	char *token;
	size_t tok_len;
	static char *next_tok;
	const char *i;
	int delimitcount;

	first_tok = NULL;
	next_tok = NULL;
	if (strings != NULL)
		next_tok = strings;
	if (next_tok == NULL ||*next_tok == '\0')
		return (NULL);

	while (*next_tok != '\0')
		{
		delimitcount = 0;
		for (i = delim; *i != '\0'; ++i)
		{
		if (*next_tok == *i)
		{
			delimitcount = 1;
				break;
		}
		}
		if (!delimitcount)
		{
			if (first_tok == NULL)
				first_tok = next_tok;
		}
			else
			{
			if (first_tok != NULL)
			{
				tok_len = next_tok - first_tok;
				token = malloc((tok_len +1) * sizeof(char *));
			if (token == NULL)
			{
				perror(" Error");
				exit(EXIT_FAILURE);
			}
			cf_strcpy(token, first_tok, tok_len);
			token[tok_len] ='\0';
			++next_tok;
			return (token);
			}
		}
			++next_tok;
		}
	if (first_tok != NULL)
	{
		tok_len = next_tok - first_tok;
		token = malloc((tok_len + 1) * sizeof(char *));
	if (token == NULL)
	{
	perror("Error");
	exit(EXIT_FAILURE);
	}
	cf_strcpy(token, first_tok, tok_len);
	token[tok_len] = '\0';
	next_tok = NULL;
	return (token);
}
	return (NULL);
}*/				
