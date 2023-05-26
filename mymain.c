#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
char *cf_strdup(char *strings);
char *cf_strdup(char *strings);
int cf_strcmp(char *first_str, char *second_str);
char *cf_strcat(char *first_str, char *second_str);
char *cf_strtok(char *strings, const char *delim);
int cf_strtok_cmpr(char c, const char *strings);
char *cf_strcpy(char *str_cpy, const char *strings, size_t n);
char *cf_strtok(char *strings, const char *delim);
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

/**
int main(void)
{
    char *str1;
    char *delim;
    char *stok;
    int i = 0;
    char **av;

    str1 = strdup("my father has a little lamb");  // Create a writable copy
    delim = " ";
    stok = cf_strtok(str1, delim);

    av = malloc(sizeof(char*) * 10);

    while (stok)
    {
        av[i] = stok;
        printf("%s", stok);
        stok = cf_strtok(NULL, delim);
        i++;
    }

//    av[i] = NULL;

    free(str1);  // Free the allocated copy of the string

    return 0;
}

/**
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
    printf("just %s\n", stok);

    av = malloc(sizeof(char*) * 10);

    while (stok)
    {
        av[i] = stok;
        printf("%s\n", stok);
        stok = cf_strtok(NULL, delim);
        i++;
    }

    av[i] = NULL;

    free(str1);  // Free the allocated copy of the string

    return 0;
}

/**
int main(void)
{
    char *str1;
    char *delim;
    char *stok;
    int i = 0;
    char **av;

    str1 = "my father has a little lamb";
    delim = " \n";
    stok = cf_strtok(str1, delim);
    printf("just %s\n", stok);

    av = malloc(sizeof(char*) * 10);

    while (stok)
    {
        av[i] = stok;
        stok = cf_strtok(NULL, delim);
        i++;
        printf("%s\n", stok);
    }


    return 0;
}

/**
int main(void)
{        
char *str1;
        char *delim;
char *stok;
int i;
char **av;
str1 = "my father has a little lamb";
delim = " \n";
stok = cf_strtok(str1, delim);
printf("just %s\n", stok);
av = malloc(sizeof(char ) * 10);
while(stok)
{
	av[i] = str1;
	stok = cf_strtok(NULL, delim);
	i++;
	printf("%s\n", stok);
}
av[i] = NULL;
return (0);
}
*/

