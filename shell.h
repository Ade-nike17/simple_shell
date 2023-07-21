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
size_t strlen(const char *str);

#endif /* SHELL_H */
