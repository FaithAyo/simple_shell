#include "shell.h"

char **tokenizer(char* cmd)
{
	char * cmdcpy, *token;
	char **argv;
	int argc = 0, i = 0;

	cmdcpy = strdup(cmd);
	/* for argc*/
	token = strtok(cmd, " \n");
	while(token)
	{
		token = strtok(NULL, " \n");
		argc++;
	}

	/* for argv*/
	argv = malloc(sizeof(char)* argc);
	token = strtok(cmdcpy, " \n");
	while(token)
	{
		argv[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	argv[i] = NULL;

	exec(argv);

}