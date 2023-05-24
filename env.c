#include "shell.h"

/**
 * _env - a fun to get the env
 * @environ: a macro
 */
void _env(char **environ)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
