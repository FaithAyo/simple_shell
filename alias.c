#include "shell.h"

int shellby_alias(char **args, char __attribute__((__unused__)) **front);
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);

/**
 * shellby_alias - Builtin command that either prints all aliases, specific
 * aliases, or sets an alias.
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */
int shellby_alias(char **args, char __attribute__((__unused__)) **front)
{
	alias_t *tem = aliases;
	int a, retn = 0;
	char *val;

	if (!args[0])
	{
		while (tem)
		{
			print_alias(tem);
			tem = tem->next;
		}
		return (retn);
	}
	for (a = 0; args[a]; a++)
	{
		tem = aliases;
		val = _strchr(args[a], '=');
		if (!val)
		{
			while (tem)
			{
				if (_strcmp(args[a], tem->name) == 0)
				{
					print_alias(tem);
					break;
				}
				tem = tem->next;
			}
			if (!tem)
				retn = create_error(args + a, 1);
		}
		else
			set_alias(args[a], val);
	}
	return (retn);
}

/**
 * set_alias - Will either set an existing alias 'name' with a new value,
 * 'value' or creates a new alias with 'name' and 'value'.
 * @var_name: Name of the alias.
 * @value: Value of the alias. First character is a '='.
 */
void set_alias(char *var_name, char *value)
{
	alias_t *tem = aliases;
	int length, a, b;
	char *new_val;

	*value = '\0';
	value++;
	length = _strlen(value) - _strspn(value, "'\"");
	new_val = malloc(sizeof(char) * (length + 1));
	if (!new_val)
		return;
	for (a = 0, b = 0; value[a]; a++)
	{
		if (value[a] != '\'' && value[a] != '"')
			new_val[b++] = value[a];
	}
	new_val[a] = '\0';
	while (tem)
	{
		if (_strcmp(var_name, tem->name) == 0)
		{
			free(tem->value);
			tem->value = new_val;
			break;
		}
		tem = tem->next;
	}
	if (!tem)
		add_alias_end(&aliases, var_name, new_val);
}

/**
 * print_alias - Prints the alias in the format name='value'.
 * @alias: Pointer to an alias.
 */
void print_alias(alias_t *alias)
{
	char *alias_str;
	int length = _strlen(alias->name) + _strlen(alias->value) + 4;

	alias_str = malloc(sizeof(char) * (length + 1));
	if (!alias_str)
		return;
	_strcpy(alias_str, alias->name);
	_strcat(alias_str, "='");
	_strcat(alias_str, alias->value);
	_strcat(alias_str, "'\n");

	write(STDOUT_FILENO, alias_str, length);
	free(alias_str);
}
/**
 * replace_aliases - Goes through the arguments and replace any matching alias
 * with their value.
 * @args: 2D pointer to the arguments.
 *
 * Return: 2D pointer to the arguments.
 */
char **replace_aliases(char **args)
{
	alias_t *tem;
	int a;
	char *new_val;

	if (_strcmp(args[0], "alias") == 0)
		return (args);
	for (a = 0; args[a]; a++)
	{
		tem = aliases;
		while (tem)
		{
			if (_strcmp(args[a], tem->name) == 0)
			{
				new_val = malloc(sizeof(char) * (_strlen(tem->value) + 1));
				if (!new_val)
				{
					free_args(args, args);
					return (NULL);
				}
				_strcpy(new_val, tem->value);
				free(args[a]);
				args[a] = new_val;
				a--;
				break;
			}
			tem = tem->next;
		}
	}

	return (args);
}
