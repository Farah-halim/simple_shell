#include "shell.h"
/**
 * main - entry point
 * Return: 0 if success
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t ip;
	int id, status;
	char *b = "$ ", **args;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, b, strlen(b));
		fflush(stdout);
		ip = _getline(&buffer, &bufsize, stdin);
		if (ip == -1)
		{
			if (ip == EOF)
				break;
			perror("getline");
			exit(1);
		}
		buffer[ip - 1] = '\0';
		args = take_input(buffer, bufsize);
		if (!strcmp(args[0], "exit"))
			break;
		if (!strcmp(args[0], "env"))
			_env(environ);
		status = execute_command(args);
		free(args);
	}free(buffer);
	return (0);
}
