#include "shell.h"


char *_getline()
{
	char *cmd = NULL;
	size_t n;
	char *str = "$$  ";
	write(1, str, strlen(str));
	if (getline(&cmd, &n, stdin) == -1)
	{
		free(cmd);
		exit(0);
	}
	tokenizer(cmd);
}