#include "main.h"

/**
 * cf_builtins - checks if the command is a builtin
 * @myshell: data to check
 *
 * Return: pointer to the function or NULL
 */
void (*builtins(cf_data *myshell))(cf_data *myshell)
{
	unsigned int i;
	cf_builtin list[] = {
		{"exit", _exit},
		{"env", _env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; list[i].f != NULL; i++)
	{
		if (cf_strcmp(cf_data->av[0], list[i].name) == 0)
			break;
	}
	if (list[i].f != NULL)
		list[i].f(myshell);
	return (list[i].f);
}
