#include <stdio.h>
char* cf_strdup(char *strings);
char* cf_strdup(char *strings);
int cf_strcmp(char *first_str, char *second_str);
char *cf_strcat(char *first_str, char *second_str);

int main()
{
char str1[] = "Run";
char str2[] = "Runto";
char *str3;
str3 = cf_strcat(str1,str2);
printf("%s\n", str3);
return (0);
}
