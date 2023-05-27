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
	void (*f)(cf_data *);
} cf_builtin;

char **set_env(char **env);
void free_envir(char **env);

int cf_strlen(char *strings);
char *cf_strdup(char *strings);
int cf_strcmp(char *first_str, char *second_str);
char *cf_strcat(char *first_str, char *second_str);

void print_error(cf_data *myshell, char *cmd);
int cf_prints(char *strings);
void print_error(cf_data *myshell, char *cmd);


char *int_str(unsigned int num);
void _puts(char *str);
int str_int(char *str);


/* builtin functions*/
void (*cf_builtins(cf_data *myshell))(cf_data *myshell);
void __exit(cf_data *myshell);
void _env(cf_data *myshell);
void _setenv(cf_data *myshell);
void _unsetenv(cf_data *myshell);
void create_env(cf_data *myshell);
char *create_env_str(char *first_val, char *second_val);
char **search_env(char **env, char *val);

/* path.c*/
void cf_check_4path(cf_data *buf);
char *cf_path_finder(char **environ);
int cf_execute_path(char *cmd, cf_data *buf);

/*strtok.c*/
char *cf_strtok(char *strings, const char *delim);
char **cf_tokenize(char *buf, char *delim);
int cf_strtok_cmpr(char ch, const char *strings);
char **cf_malloc(char **pt, size_t *num);

/* directory.c*/
int cf_execute_cwd(cf_data *buf);
int cf_check_4dir(char *strings);

#endif /*MAIN_H*/
