#ifndef UNISH_H
#define UNISH_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
void execute(char **argv, char **args);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
void _free(char *l, char *c, char **args, int i);
char *_location(char *command);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int word_len(char *str);
int count_words(char *str);
char **strtow(char *str);
#endif
