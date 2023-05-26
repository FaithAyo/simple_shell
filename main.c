/**
 * main - main function to the shell project
 * @argc: number of arguments passed to the main function
 * @argv: array of arguments passed to main
 * @environment: environment variables
 *
 * Return: 0 or exit status
 */
int main(int argc, char **argv, char **environment)
{
	(void)argc;
	cf_data myshell;
	signal(SIGINT, cf_cntrlc);
	cf_builtin list[];

}

