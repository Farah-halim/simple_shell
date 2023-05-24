#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int execute_command(char **args);
char **take_input(char *buffer, size_t bufsize);
extern char **environ;
void _env(char **environ);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *get_command_path(const char *command);
ssize_t read_buffer(char *buffer, size_t *buffer_index,
		ssize_t *chars_read, FILE *stream);

#endif
