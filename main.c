#include "main.h"

/*global variable for contrl c*/
unsigned int sig_flag;


/**
 * sig_handler  - interrupts the signal
 * @cc: control c signal from the keyboard
 * Return: void
 */
static void sig_handler(int cc)
{
        (void) cc;

        if (sig_flag == 0)
                cf_prints("\ncf$$ ");
        else
                cf_prints("\n");
}
/**
 * main - main function to the shell project
 * @argc: number of arguments count passed to the main function
 * @argv: array of arguments vector passed to main
 * @environ: environment variables
 *
 * Return: 0 or exit status
 */
int main(int argc __attribute__((unused)), char **argv, char **environ)
{
	size_t buf_len;
	unsigned int term, i;
	cf_data myshell = {NULL, NULL, 0, NULL, 0, NULL, NULL};

	buf_len = 0;
	term = 0;
	myshell.argv = argv;
	myshell._environ = set_env(environ);
	signal(SIGINT, sig_handler);
	if (!isatty(STDIN_FILENO))
		term = 1;
	if (term ==0)
		cf_prints("cf$$ ");
	sig_flag = 0;
	while (getline(&(myshell.linept), &buf_len, stdin) != -1)
	{
		sig_flag = 1;
		myshell.count++;
		myshell.commands = cf_tokenize(myshell.linept, ";");
		for (i = 0; myshell.commands &&  myshell.commands[i] != NULL; i++)
		{
			myshell.av = cf_tokenize(myshell.commands[i], "\n \t\r");
			if (myshell.av && myshell.av[0])
				if (cf_builtins(&myshell) == NULL)
					cf_check_4path(&myshell);
			free(myshell.av);
		}
		free(myshell.linept);
		free(myshell.commands);
		sig_flag = 0;
		if (term == 0)
			cf_prints("cf$$ ");
		myshell.linept = NULL;
	}
	if (term == 0)
		cf_prints("\n");
	free_envir(myshell._environ);
	free(myshell.linept);
	exit(myshell.status);

}

