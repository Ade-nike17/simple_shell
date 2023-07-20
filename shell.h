#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;


/* prototype functions */
char **split_input_line(char *lineptr, const char *delim);

#endif /* SHELL_H */
