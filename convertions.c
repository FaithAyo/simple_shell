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
	unsigned int num1, len = 0;

	num1 = num;

	for (len = 0; num1 != 0; len++)
		num1 /=  10;
	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	buffer[len] = '\0';
	for (--len; num; --len)
	{
		buffer[len] = (num % 10) + '0';
		num /= 10;
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
/*	unsigned int count = 0, size = 0;
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
	return (a * b);*/
unsigned int i, digits;
	int num = 0, num_test;

	num_test = INT_MAX;
	for (digits = 0; num_test != 0; digits++)
		num_test /= 10;
	for (i = 0; str[i] != '\0' && i < digits; i++)
	{
		num *= 10;
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if ((i == digits - 1) && (str[i] - '0' > INT_MAX % 10))
			return (-1);
		num += str[i] - '0';
		if ((i == digits - 2) && (str[i + 1] != '\0') && (num > INT_MAX / 10))
			return (-1);
	}
	if (i > digits)
		return (-1);
	return (num);	
}
