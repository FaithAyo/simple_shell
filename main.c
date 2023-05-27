#include "main.h"

/*global variable for contrl c*/
unsigned int sig_flag;


/**
 * cf_cntrlc - interrupts the signal
 * @cc: control c signal from the keyboard
 * Return: void
 */
static void sig_handler(int cc)
{
        (void) cc;

        if (signal_flag == 0)
                cf_prints("\ncf$$ ");
        else
                cf_prints("\n");
}
/**
 * main - main function to the shell project
 * @ac: number of arguments count passed to the main function
 * @argv: array of arguments vector passed to main
 * @environ: environment variables
 *
 * Return: 0 or exit status
 */
int main(int ac, char **argv, char **environ)
{
	size_t buf_len;
	unsigned int term, i;
	cf_data myshell;
	void (ac);

	buf_len = 0;
	term = 0;
	myshell[] = {NULL, NULL, 0, NULL, 0, NULL, NULL};
	myshell.argv = argv;
	myshell._environ = set_env(environ);
	signal(SIGINT, sig_handler);
	if (!isatty(STDIN_FILENO))
		term = 1;
	if (term ==0)
		cf_prints("cf$$ ");
	signal_flag = 0;
	while (getline(&(cf_data.linept), &buf_len, stdin) != -1)
	{
		signal_flag = 1;
		myshell.count++;
		myshell.commands = cf_tokenize(myshell.linept, ";");
		for (i = 0; myshell.commands &&  myshell.commands[i] != NULL; i++)
		{
			myshell.av = cf_tokenize(myshell.commands[i], "\n \t\r");
			if (myshell.av && myshell.av[0])
				if (builtins(&myshell) == NULL)
					cf_check_4path(&myshell);
			free(myshell.av)
		}
		free(myshell.linept);
		free(myshell.commands);
		signal_flag = 0;
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

