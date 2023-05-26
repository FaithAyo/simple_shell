#include "main.h"

/**
 * _exit - a commmand that exit a program
 * @myshell: the variable to work on
 *
 * Return: void
 */
void __exit(cf_data *myshell)
{
	int status;

	if (cf_strcmp(myshell->av[0], "exit") == 0 && myshell->av[1] != NULL)
	{
		status = str_int(myshell->av[1]);
		if (status == -1)
		{
			myshell->status = 2;
			print_error(myshell, ": wrong digit: ");
			_puts(myshell->av[1]);
			_puts("\n");
			free(myshell->commands);
			myshell->commands = NULL;
			return;
		}
		myshell->status = status;
	}
	free(myshell->linept);
	free(myshell->av);
	free(myshell->commands);
	free_envir(myshell->_environ);
	exit(myshell->status);
}

/**
 * _env - prints the current working environment
 * @myshell: the variables
 *
 * Return: void.
 */
void _env(cf_data *myshell)
{
	unsigned int i;

	for (i = 0; myshell->_environ[i]; i++)
	{
		cf_prints(myshell->_environ[i]);
		cf_prints("\n");
	}
	myshell->status = 0;
}

/**
 * _setenv - create a new environment variable, or edit an existing variable
 * @myshell: struct of variables
 *
 * Return: void
 */
void _setenv(cf_data *myshell)
{
	char **buf;
	char *val;

	if (myshell->av[1] == NULL || myshell->av[2] == NULL)
	{
		print_error(myshell, ": check your no of arguments\n");
		myshell->status = 2;
		return;
	}
	buf = create_env(myshell->_environ, myshell->av[1]);
	if (buf == NULL)
		create_env_str(myshell);
	else
	{
		val = search_env(myshell->av[1], myshell->av[2]);
		if (val == NULL)
		{
			print_error(myshell, NULL);
			free(myshell->linept);
			free(myshell->commands);
			free(myshell->av);
			free_envir(myshell->_environ);
			exit(127);
		}
		free(*buf);
		*buf = val;
	}
	vars->status = 0;
}

/**
 * _unsetenv - remove an environment variable
 * @myshell: pointer to a struct of variables
 *
 * Return: void
 */
void _unsetenv(cf_data *myshell)
{
	char **val, **newenv;

	unsigned int i, j;

	if (myshell->av[1] == NULL)
	{
		print_error(myshell, ": wrong number of arguments\n");
		myshell->status = 2;
		return;
	}
	val = create_env(myshell->_environ, myshell->av[1]);
	if (val == NULL)
	{
		print_error(myshell, ": No variable");
		return;
	}
	for (i = 0; myshell->_environ[i] != NULL; i++)
		;
	newenv = malloc(sizeof(char *) * i);
	if (newenv == NULL)
	{
		print_error(myshell, NULL);
		myshell->status = 127;
		__exit(myshell);
	}
	for (i = 0; myshell->_environ[i] != *val; i++)
		newenv[i] = myshell->_environ[i];
	for (j = i + 1; myshell->_environ[j] != NULL; j++, i++)
		newenv[i] = myshell->_environ[j];
	newenv[i] = NULL;
	free(*val);
	free(myshell->_environ);
	myshell->_environ = newenv;
	myshell->status = 0;
}
