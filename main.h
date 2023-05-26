#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

int cf_strlen(char *strings);
char *cf_strcat(char *first_str, char *second_str);
int cf_strcmp(char *first_str, const char *second_str);
int cf_strtok_cmpr(char c, const char *strings);
char *cf_strtok(char *strings, const char *delim);
#endif /*MAIN_H*/
