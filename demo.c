#include <stdio.h>
int cf_strlen(char *strings);

int main()
{
int n;
char str[] = "faithchukwu";
n = cf_strlen(str);
printf("%d\n", n);
return (0);
}
