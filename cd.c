#include "shell.h"

/**
 * _cd - a built-in cd
 * @path: the path
 */
void _cd(char *path)
{
	char cwd[1024];
	const char *home_dir;
	const char *old_dir;

	if (path == NULL)
	{
		home_dir = getenv("HOME");
		if (home_dir == NULL)
		{
			fprintf(stderr, "cd: no $HOME environment variable\n");
			return;
		}
		path = (char *)home_dir;
	}
	else if (strcmp(path, "-") == 0)
	{
		old_dir = getenv("OLDPWD");
		if (old_dir == NULL)
		{
			fprintf(stderr, "cd: no previous directory available\n");
			return;
		}
		path = (char *)old_dir;
	}

	if (chdir(path) != 0)
	{
		perror("chdir failed");
		return;
	}

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd failed");
		return;
	}
}
