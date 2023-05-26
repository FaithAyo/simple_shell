#include "main.h"
/**
 * cf_check_4dir - check is the command is in the path
 * @strings: the commands
 * Return: 1 on sucess and 0 on failure
 */
int cf_check_4dir(char *strings)
{
	unsigned int a;

	for (a = 0; str[a]; a++)
	{
		if (str[a] == '/')
			return (1);
	}
	return (0);
}

}

/**
 * cf_execute_cwd - the fxn executes a cwd command
 * @buf: the pointer to the struct of variables
 * Return: 0 when successful and 1 on failure
 */
int cf_execute_cwd(cf_data *buf)
{
	pid_t c_pid;
	struct stat var;

	if (stat(buf->av[0], &var) == 0)
	{
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
