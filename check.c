#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *cf_strtok(char *str, const char *delim)
{
    static char *next_token = NULL;
    char *token_start = NULL;

    if (str != NULL)
        next_token = str;

    if (next_token == NULL || *next_token == '\0')
        return NULL;

    while (*next_token != '\0') {
        int is_delim = 0;
        for (const char *d = delim; *d != '\0'; ++d) {
            if (*next_token == *d) {
                is_delim = 1;
                break;
            }
        }

        if (!is_delim) {
            if (token_start == NULL)
                token_start = next_token;
        } else {
            if (token_start != NULL) {
                size_t token_len = next_token - token_start;
                char *token = malloc((token_len + 1) * sizeof(char));
                if (token == NULL) {
                    perror("Memory allocation error");
                    exit(EXIT_FAILURE);
                }
                strncpy(token, token_start, token_len);
                token[token_len] = '\0';
                ++next_token;
                return token;
            }
        }

        ++next_token;
    }

    if (token_start != NULL) {
        size_t token_len = next_token - token_start;
        char *token = malloc((token_len + 1) * sizeof(char));
        if (token == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
        strncpy(token, token_start, token_len);
        token[token_len] = '\0';
        next_token = NULL;
        return token;
    }

    return NULL;
}


int main()
{
	char *str1;
	char *delim;
char *stok;
str1 = "my father has a little lamb";
delim = " ";
stok = cf_strtok(str1, delim);
printf("%s\n", stok);
return (0);
}
