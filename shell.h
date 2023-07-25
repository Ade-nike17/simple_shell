#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;


/* prototype functions */
char **split_input_line(char *lineptr, const char *delim);
char **get_input_tokens();
void execmd(char **tokens);
char *find_path(char *cmd);
void exit_shell(void);
void print_env(char **env);
void print_str_list(char **list);
char **dup_env();
void free_env(char **environ);
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *str1, const char *str2);
int _puts(const char *str);
int _putchar(char c);
char *_strdup(const char *str);


#endif /* SHELL_H */
