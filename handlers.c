#include "shell.h"

/************************ builtin_handler ************************/

/**
 * handle_builtins - 
 * @builtin: 
 * Return: 
 */
int (*builtin_handler(const char *builtin))(char **)
{
	builtin_t builtins[] = {
		{"exit", __exit},
		{"env", env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		/*{"cd", cd},
		{"alias", alias},*/
		{NULL, NULL}
	};
	int i;

	for (i = 0; builtins[i].builtin; i++)
		if (!strcmp(builtin, builtins[i].builtin))
			return (builtins[i].bf);
	return (NULL);
}

/*********************** path_handler ******************************/

/**
 * path_handler - Checks if the command executable exists in specified paths
 * @cmde: The command executable to check for
 * Return: The full path to the command executable if found, otherwise NULL
 */
char *path_handler(char *cmde)
{
	char *fpath; /* full path */
	char *paths, *path;
	int i;

	paths = getenv("PATH");
	if (!paths)
		return (NULL);

	path = strtok(paths, ":");
	for (i = 0; path; i++)
	{
		fpath = malloc(strlen(path) + strlen(cmde) + 2);
		if (!fpath)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		strcpy(fpath, path);
		strcat(fpath, "/");
		strcat(fpath, cmde);

		if (!access(fpath, F_OK | X_OK))
			return (fpath); /* use strdup to avoid memory leaks */
		free(fpath);
		path = strtok(NULL, ":");
	}
	return (NULL);
}
