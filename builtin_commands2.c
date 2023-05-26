#include "main.h"

#include "shell.h"

/**
 * create_env - create a new environment variable
 * @myshell: pointer to struct of variables
 *
 * Return: void
 */
void create_env(cf_data *myshell)
{
	unsigned int i;
	char **newenv;

	for (i = 0; myshell->_environ[i] != NULL; i++)
		;
	newenv = malloc(sizeof(char *) * (i + 2));
	if (newenv == NULL)
	{
		print_error(myshell, NULL);
		myshell->status = 127;
		_exit(myshell);
	}
	for (i = 0; myshell->_environ[i] != NULL; i++)
		newenv[i] = myshell->_environ[i];
	newenv[i] = create_env_str(myshell->av[1], myshell->av[2]);
	if (newenv[i] == NULL)
	{
		print_error(myshell, NULL);
		free(myshell->linept);
		free(myshell->commands);
		free(myshell->av);
		free_envir(vars->_environ);
		free(newenv);
		exit(127);
	}
	newenv[i + 1] = NULL;
	free(myshell->_environ);
	myshell->_environ = newenv;
}


/**
 * create_env_str - create a new environment variable string
 * @first_val: variable name
 * @second_val: variable value
 *
 * Return: pointer to the new string;
 */
char *create_env_str(char *first_val, char *second_val)
{
	unsigned int len1, len2, i, j;
	char *new;

	len1 = _strlen(first_val);
	len2 = _strlen(second_val);
	new = malloc(sizeof(char) * (len1 + len2 + 2));
	if (new == NULL)
		return (NULL);
	for (i = 0; first_val[i] != '\0'; i++)
		new[i] = first_val[i];
	new[i] = '=';
	for (j = 0; second_val[j] != '\0'; j++)
		new[i + 1 + j] = second_val[j];
	new[i + 1 + j] = '\0';
	return (new);
}


/**
 * search_env - finds an environment variable
 * @env: array of environment variables
 * @val: environment variable to find
 *
 * Return: pointer to address of the environment variable
 */
char **search_env(char **env, char *val)
{
	unsigned int i, j, len;

	len = _strlen(key);
	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < len; j++)
			if (val[j] != env[i][j])
				break;
		if (j == len && env[i][j] == '=')
			return (&env[i]);
	}
	return (NULL);
}
