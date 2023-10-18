#include "shell.h"

/**
 * env - prints the environment variables list
 * @ac: args count
 * @cmdla: command_line array
 * Return: exit status
 */
int env(int ac, __attribute__((unused)) char **cmdla)
{
	int i;

	if (ac != 1)
	{
		printf("Usage: env\n");
		return (EXIT_FAILURE);
	}
	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
	return (EXIT_SUCCESS);
}

/**
 * __setenv - create or change an environment variable
 * @ac: args count
 * @cmdla: command_line array
 * Return: exit status
 */
int __setenv(int ac, char **cmdla)
{
	char *name;
	char *value;

	if (ac != 3)
	{
		printf("Usage: setenv <name> <value>\n");
		return (EXIT_FAILURE);
	}
	name = cmdla[1];
	value = cmdla[2];
	_setenv(name, value, 1);
	return (EXIT_SUCCESS);
}

/**
 * __unsetenv - deletes an environment variable
 * @ac: args count
 * @cmdla: command_line array
 * Return: exit status
 */
int __unsetenv(int ac, char **cmdla)
{
	char *name;

	if (ac != 2)
	{
		printf("Usage: unsetenv <name>\n");
		return (EXIT_FAILURE);
	}
	name = cmdla[1];
	_unsetenv(name);
	return (EXIT_SUCCESS);
}
