#include "shell.h"

/**
 * _env - a fun to get the env
 * @environ: a macro
 */
void _env(char **environ)
{
	int x = 0;
	char **env = environ;
	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
