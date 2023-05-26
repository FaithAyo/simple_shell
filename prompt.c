#include "main.h"
/**
 * cf_prompt - print the command prompt
 * Return: void
 */
void cf_prompt(void)
{
	char *prompt = "cf$$ ";

	if (isatty(STDIN_FILENO))
		write(1, prompt, strlen(prompt));
}

/**
 * cf_cntrlc - interrupts the signal
 * @sig: control c signal from the keyboard
 * Return: void
 */
void cf_cntrlc(int sig)
{
	void(sig);
	char *cntrlc = "\ncf$$ ";
	cf_prints(cntrlc);
}

/**
 * cf_prints - fxn that prints to standard output
 * @strings: the string to be printed out
 * Return: the no of characters printed or -1 on failure
 */
int cf_prints(char *strings)
{
	int str_len;

	str_len = cf_strlen(strings);
	write(1, strings, str_len);
	if (write(1, strings, str_len) != str_len)
	{
		perror("Error");
		return (-1);
	}
	return (write(1, strings, str_len));
}

/**
 * print_error - prints error messages to standard error
 * @vars: pointer to struct of variables
 * @msg: message to print out
 *
 * Return: void
 */
void print_error(cf_data *myshell, char *cmd)
{
	char *len;


	_puts(myshell->argv[0]);
	_puts(": ");
	len = int_str(myshell->count);
	_puts(len);
	free(len);
	_puts(": ");
	_puts(myshell->av[0]);
	if (cmd)
	{
		_puts(cmd);
	}
	else
		perror("Error");
}