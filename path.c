#include "shell.h"

/**
 * get_command_path- a fun to read buffer
 * @command: command
 * Return: chars
 */
char *get_command_path(const char *command)
{
	char *path_env, *path, *dir;
	char *command_path;

	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
			return (strdup(command));
		else
			return (NULL);
	}
	path_env = getenv("PATH");
	if (path_env == NULL)
		return (NULL);
	path = strdup(path_env);
	if (path == NULL)
		return (NULL);
	dir = strtok(path, ":");
	while (dir != NULL)
	{
		command_path = (char *)malloc(strlen(dir)
				+ strlen(command) + 2);
		if (command_path == NULL)
		{
			free(path);
			return (NULL);
		}
		command_path[0] = '\0';
		sprintf(command_path, "%s/%s", dir, command);
		if (access(command_path, X_OK) == 0)
		{
			free(path);
			return (command_path);
		}
		free(command_path);
		dir = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
