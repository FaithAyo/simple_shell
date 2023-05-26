#include <stdio.h>
char *cf_strdup(char *strings);
char *cf_strdup(char *strings);
int cf_strcmp(char *first_str, char *second_str);
char *cf_strcat(char *first_str, char *second_str);
char *cf_strtok(char *strings, const char *delim);
int cf_strtok_cmpr(char c, const char *strings);
char *cf_strcpy(char *str_cpy, const char *strings, size_t n);
char *cf_strtok(char *strings, const char *delim);
/**
* main - entry
* Return: 0
*/
int main(void)
//{
//char str1[] = "Run hello hello world";
//char str2[] = "Runto";
//char *delim = " ";
//char *str3;
//char *token;
//str3 = cf_strcat(str1, str2);
//token = cf_strtok(str1, delim);
//printf("%s\n", token);
//printf("%s\n", str3);
//return (0);
//}
{
        char *str1;
        char *delim;
char *stok;
str1 = "my father has a little lamb";
delim = " ";
stok = cf_strtok(str1, delim);
while(stok)
{
	
printf("%swhat is this\n", stok);
return (0);
}
