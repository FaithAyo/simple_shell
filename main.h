#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>

extern char **environ;


/**
 * struct variables - variables
 * @av: command line arguments
 * @linept: buffer of command
 * @env: environment variables
 * @count: count of commands entered
 * @argv: arguments at opening of shell
 * @status: exit status
 * @commands: double pointer to commands
 */
typedef struct data
{
	char **av;
	char *linept;
	size_t count;
	char **argv;
	int status;
	char **commands;
	char **_environ;
} cf_data;



/**
 * struct builtin - structure for all my builtin functions
 * @name: name of builtin
 * @f: function for the builtin
 */

typedef struct builtin
{
	char *name;
	int (*f)(cf_data *);
} cf_builtin;


void set_data(cf_data *myshell, char **av);
void free_envir(cf_data * myshell);

int cf_strlen(char *strings);
char *cf_strdup(char *strings);
int cf_strcmp(char *first_str, char *second_str);
char *cf_strcat(char *first_str, char *second_str);

void print_error(cf_data *myshell, char *cmd);
void cf_prompt(void);
void cf_cntrlc(int sig);
int cf_prints(char *strings);
void print_error(cf_data *myshell, char *cmd);


char *int_str(unsigned int num);
void _puts(char *str);
int str_int(char *str);


/* builtin functions*/
void (*builtins(cf_data *myshell))(cf_data *myshell);
void __exit(cf_data *myshell);
void _env(cf_data *myshell);
void _setenv(cf_data *myshell);
void _unsetenv(cf_data *myshell);
void create_env(cf_data *myshell);
char *create_env_str(char *first_val, char *second_val);
char **search_env(char **env, char *val);


#endif /*MAIN_H*/
