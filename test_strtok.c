#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

                memcpy(token, first_tok, tok_len);
                token[tok_len] = '\0';
                ++next_tok;
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

        memcpy(token, first_tok, tok_len);
        token[tok_len] = '\0';
        next_tok = NULL;
        return token;
    }

    return NULL;
}

int main(void)
{
    char *str1;
    char *delim;
    char *stok;
    int i = 0;
    char **av;

    str1 = strdup("my father has a little lamb");  // Create a writable copy
    delim = " \n";
    stok = cf_strtok(str1, delim);

    av = malloc(sizeof(char*) * 6);

    while (stok)
    {
        av[i] = stok;
        printf("%s ", stok);  // Print each token
        stok = cf_strtok(NULL, delim);
        i++;
    }
    printf("\n");  // Print a newline after all tokens are printed

    av[i] = NULL;

    free(str1);  // Free the allocated copy of the string

    return 0;
}

