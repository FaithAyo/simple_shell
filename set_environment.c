#include "main.h"

/**
 * set_env - make the shell environment from the environment
 * @env: environment passed to main
 *
 * Return: pointer to the new environment
 */

char **set_env(char **env)
{
	char **new_env = NULL;
	size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	new_env = malloc(sizeof(char *) * (i + 1));
	if (new_env == NULL)
	{
		perror("Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		new_env[i] = cf_strdup(env[i]);
	new_env[i] = NULL;
	return (new_env);
}

/**
 * free_envir - free the shell's environment
 * @env: shell's environment
 *
 * Return: void
 */

void free_envir(char **env)
{
	unsigned int i;

	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);
}
