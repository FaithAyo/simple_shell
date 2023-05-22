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
 * @signal: control c signal from the keyboard
 * Return: void
 */
void cf_cntrlc(int signal)
{
	char *cntrlc = "\ncf$$ ";

	void(signal);

	write(1, cntrlc, strlen(cntrlc));
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

