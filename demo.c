#include <stdio.h>
char* cf_strdup(char *strings);
char* cf_strdup(char *strings);
int cf_strcmp(char *first_str, char *second_str);

int main()
{
char str1[] = "Run";
char str2[] = "Runto";
int str3;
str3 = cf_strcmp(str1,str2);
printf("%d\n", str3);
return (0);
}
