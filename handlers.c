#include "shell.h"

/************************ builtin_handler ************************/

/**
 * builtin_handler - handles built-in commands
 * @builtin: built-in command
 * Return: the built-in associated function
 *			that takes 'int' & 'char **' args & returns 'int'
 */
int (*builtin_handler(const char *builtin))(int, char **)
{
	builtin_t builtins[] = {
		{"exit", __exit},
		{"env", env},
		{"setenv", __setenv},
		{"unsetenv", __unsetenv},
		{"cd", cd},
		{"alias", alias},
		{NULL, NULL}
	};
	int i;

	for (i = 0; builtins[i].builtin; i++)
		if (!strcmp(builtin, builtins[i].builtin))
			return (builtins[i].bf);
	return (NULL);
}
/********************* variable_handler ****************************/

/**
 * variable_handler - handles the shell variables
 * @cmdlv: commad_line variable
 * Return: Nothing
 */
void variable_handler(__attribute__((unused)) char *cmdlv)
{
/*
 *	char *value;
 *
 *	if (*cmdlv == '$')
 *	{
 *		if (!strcmp(cmdlv, "$?"))
 *			something
 *		else if (!strcmp(cmdlv, "$$"))
 *			something
 *		else
 *		{
 *			value = getenv(cmdlv + 1);
 *			cmdlv = value;
 *		}
 *	}
 */
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

	path = getenv("PATH");
	paths = malloc(strlen(path) + 1); /* need to be freed */
	strcpy(paths, path);
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
