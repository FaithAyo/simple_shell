#include "main.h"
/**
 * cf_check_4path - checks in the cmd is in the path
 * @buf: the variables
 * Return: void
 */
void cf_check_4path(cf_data *buf)
{
	char *path, *dup_path = NULL, *check = NULL;
	unsigned int a = 0, b = 0;
	char **tok_path;
	struct stat var;

	if (cf_check_4dir(buf->av[0]))
		b = cf_execute_cwd(buf);
	else
	{
		path = cf_path_finder(buf->env);
		if (path != NULL)
		{
			dup_path = cf_strdup(path + 5);
			tok_path = cf_tokenize(dup_path, ":");
			for (a = 0; tok_path && tok_path[a]; a++, free(check))
			{
				check = cf_strcat(tok_path[a], buf->av[0]);
				if (stat(check, &var) == 0)
				{
					b = cf_execute_path(check, buf);
					free(check);
					break;
				}
			}
			free(dup_path);
			if (tok_path == NULL)
			{
				buf->status = 127;
				cf_exit(buf);
			}
		}
		if (path == NULL || tok_path[a] == NULL)
		{
			cf_print_error(buf, ": not found\n");
			buf->status = 127;
		}
		free(tok_path);
	}
	if (b == 1)
		cf_exit(buf);
}

/**
 * cf_path_finder - path variable finder
 * @environ: the environment variable array
 * Return: pointer to the path node or NULL on failure
 */
char *cf_path_finder(char **environ)
{
	char *path = "PATH=";
	unsigned int a, b;

	for (a = 0; environ[a] != NULL; a++)
	{
		for (b = 0; b < 5; b++)
			if (path[b] != environ[a][b])
				break;
		if (b == 5)
			break;
	}
	return (environ[a]);

}

/**
 * cf_execute_path - the fxn executes a path's command
 * @cmd: the full path to the command
 * @buf: the pointer to the struct of variables
 * Return: 0 when successful and 1 on failure
 */
int cf_execute_path(char *cmd, cf_data *buf)
{
	pid_t c_pid;

	if (access(cmd, X_OK) == 0)
	{
		c_pid = fork();
		if (c_pid == -1)
			cf_print_error(buf, NULL);
		if (c_pid == 0)
		{
			if (execve(cmd, buf->av, buf->env) == -1)
				cf_print_error(buf, NULL);
		}
		else
		{
			wait(&buf->status);
			if (WIFEXITED(buf->status))
				buf->status = WEXITSTATUS(buf->status);
			else if (WIFSIGNALED(buf->status) && WTERMSIG(buf->status) == SIGINT)
				buf->status = 130;
			return (0);
		}
		buf->status = 127;
		return (1);
	}
	else
	{
		cf_print_error(buf, ": Permission denied\n");
		buf->status = 126;
	}
	return (0);
}
