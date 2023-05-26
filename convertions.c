#include "main.h"

/**
 * int_str - converts unsigned int to a string
 * @num: unsigned int to convert
 *
 * Return: pointer to the converted string
 */
char *int_str(unsigned int num)
{
	char *buffer;
	int num1, len = 0;

	num1 = num;

	for (len = 0; num1 != 0; len++)
		num1 = num1 / 10;
	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == NULL)
	{
		return (NULL);
	}
	buffer[len] = '\0';
	for (--len; num; --len)
	{
		buffer[len] = (num % 10) + '0';
		num = num / 10;
	}
	return (buffer);
}

/**
 * _puts - prints a string to standard error
 * @str: string to print
 *
 * Return: void
 */
void _puts(char *str)
{
	ssize_t num;

	num = cf_strlen(str);
	write(STDERR_FILENO, str, num);
	if ((write(STDERR_FILENO, str, num)) != num)
	{
		perror("Fatal Error");
		exit(1);
	}

}

/**
 * str_int - converts a string to an integer
 * @str: string to convert
 *
 * Return: the integer value
 */
int str_int(char *str)
{
	unsigned int count = 0, size = 0;
	unsigned int a= 0, b = 1, c = 1, i;

	while (*(str + count) != '\0')
	{
		if (size > 0 && (*(str + count) < '0' || *(str + count) > '9'))
			break;
		if (*(str + count) == '-')
			b *= -1;
		if ((*(str + count) >= '0') && (*(str + count) <= '9'))
		{
			if (size > 0)
				c *= 10;
			size++;
		}
		count++;
	}
	for (i = count-size; i < count; i++)
	{
		a = a + ((*(str + i) - 48)*c);
		c /= 10;
	}
	return (a * b);	
}