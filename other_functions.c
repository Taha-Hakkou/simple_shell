#include "shell.h"

/**
 * __exit - exits the shell program
 * @ac: args count
 * @cmdla: command_line array
 * Return: exit status
 */
int __exit(int ac, char **cmdla)
{
	int status;

	if (ac > 2)
	{
		printf("Usage: exit [status]\n");
		return (EXIT_FAILURE);
	}
	status = atoi(cmdla[1]); /* handle non int */
	exit(status);
	/* Return? */
}

/**
 * cd - changes current directory
 * @ac: args count
 * @cmdla: command_line array
 * Return: exit status
 */
int cd(int ac, char **cmdla)
{
	char *dir;

	if (ac > 2)
	{
		printf("Usage: cd [directory]\n");
		return (EXIT_FAILURE);
	} else if (ac == 2)
	{
		dir = cmdla[1];
		if (!strcmp(dir, "-"))
			dir = "$OLDPWD";
	} else
		dir = "$HOME";

	variable_handler(dir); /* handle error: 'bash: cd: OLDPWD is not set' */
	chdir(dir);
	_setenv("OLDPWD", getenv("PWD"), 1);
	/*_setenv("PWD", getcwd(), 1); do it after because 'getcwd' needs args */
	return (EXIT_SUCCESS);
}

/**
 * alias - prints or creates aliases
 * @ac: args count
 * @cmdla: command_line array
 * Return: exit status
 */
int alias(int ac, char **cmdla)
{

	char *alias;
	int i;

	if (ac == 1)
		printf("aliases\n");/* prints all aliases, one per line (name='value') */
	else
	{
		i = 0;
		alias = cmdla[i];
		while (alias)
		{
			if (strchr(alias, '='))
				printf("enter an alias\n"); /*defines an alias, if defined replaces value*/
			else
				printf("alias\n"); /* prints alias with name 'alias' */
			alias = cmdla[++i];
		}
	}
	return (EXIT_SUCCESS);
}
