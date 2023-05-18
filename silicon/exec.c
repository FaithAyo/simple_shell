#include "shell.h"

void exec(char **argv)
{
	if (fork() == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		perror("");
	}
	else
	{
		wait(NULL);
		_getline();
	}
}