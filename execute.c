#include "shell.h"
/**
 * execute_command - a fun to execute
 * @args: arguments
 * Return: status
 */
int execute_command(char **args)
{
	int status;
	int j;
	int id;

	id = fork();
	if (id == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (id == 0)
	{
		j = execvp(args[0], args);
		if (j == -1)
		{
			perror(args[0]);
			exit(1);
		}
	}
	else
		wait(&status);
	return (status);
}
