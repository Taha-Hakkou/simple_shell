#include "shell.h"

/**
 * exit - 
 * Return: 
 */
int __exit(char **command_line)
{
	int status;
	
	if (command_line[1])
	{
		status = atoi(command_line[1]);
		exit(status);
	}
	exit(EXIT_SUCCESS);
}

/**
 * env - 
 * Return: nothing
 */
int env(char **__attribute((unused)) command_line)
{
	int i;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
	return (EXIT_SUCCESS);
}

/**
 * setenv - 
 *
 * Return:
 */
int _setenv(char **command_line)
{
	char *name, *value;
	size_t n, v;
	char *env;
	int i;

	name = command_line[1];
	value = command_line[2];
	if (strchr(name, '='))
	{
		printf("variable name shouldn't contain an '=' character.\n");
		return (EXIT_FAILURE);
	}
	n = strlen(name);
	v = strlen(value);
	env = malloc(n + v + 2);
	strcat(env, name);
	strcat(env, "=");
	strcat(env, value);
	for (i = 0; environ[i]; i++)
	{
		if (!memcmp(environ[i], name, n) && environ[i][n] == '=')
		{
			environ[i] = env;
			return (EXIT_SUCCESS);
		}
	}
	/*if (overwrite)
	{*/
		environ[i] = env;
		environ[i + 1] = NULL;
	/* }*/
	return (EXIT_SUCCESS);
}

/**
 * unsetenv -
 *
 * Return:
 */
int _unsetenv(char **command_line)
{
	char *name;
	int i, j;
	size_t n;

	name = command_line[1];
	n = strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (!memcmp(environ[i], name, n) && environ[i][n] == '=')
		{
			for (j = i; environ[j]; j++)
				environ[j] = environ[j + 1];
			break;
		}
	}
	return (EXIT_SUCCESS);
}

/**
 * cd - 
 *
 * Return:
 */
/*int cd(char **command_line)
{
	char *dir;

	dir = command_line[1];
	if (!dir)*/
		/* 1.use variable $HOME ? */
		/*chdir(getenv("HOME"));*//* 2.or use getenv */
		/* in both cases you're gonna use HOME from environ */
	/*else if (dir == "-")*/
		/* cd - == cd $OLDPWD  : previous working dir */
		/* if you never changed directory, OLDPWD is not defined */
		/* id so, the bash error:      bash: cd: OLDPWD not set */
	/*	chdir(getenv("OLDPWD"));  or can use variable : $OLDPWD 
	else
		chdir(dir);
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", getcwd(), 1);
	return (EXIT_SUCCESS);
}*/

/**
 * alias - 
 *
 * Return:
 */
/*int alias(char **command_line)
{
	char *name;
	int i;

	name = command_line[1];
	if (!name)*/
		/* prints list of all aliases : name='value' */
	/*else
		for (i = 0; name; i++)
		{
			if (!strchr(name, '='))
				 prints aliases of name 1 per line : name='value' 
			else
				 defines an alias, if defined replaces its value 
			name = command_line[i + 1]
		}
	return (EXIT_SUCCESS);
}*/
