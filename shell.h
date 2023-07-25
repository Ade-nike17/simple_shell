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
void execmd(char **tokens, char **env);
char *find_path(char *cmd);
void exit_shell(void);
void print_env(char **env);
void print_str_list(char **list);
char **dup_env();
void free_env(char **environ);
size_t strlen(const char *str);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);
int strcmp(const char *str1, const char *str2);



#endif /* SHELL_H */
