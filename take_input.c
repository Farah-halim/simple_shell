#include "shell.h"
/**
 * take_input - a fun to take input
 * @buffer: buffer
 * @bufsize: size
 * Return: arguments
 */
char **take_input(char *buffer, size_t bufsize)
{
	char **args, *tok;
	int i = 0;

	args = (char **)malloc(sizeof(char *) * bufsize);
	if (!args)
	{
		perror("malloc");
		exit(1);
	}
	tok = strtok(buffer, " ");
	while (tok)
	{
		args[i++] = tok;
		tok = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}
