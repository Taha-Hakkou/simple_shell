#include "shell.h"

/**
 * execute - executes complex command_lines
 * @cmdl: command_line
 * Return: exit status
 */
int execute(char *cmdl)
{
	int status;

	/* 6. handle comments(#) + newline character(\n) */
	strtok(cmdl, "#\n");

	/* 7. handle the commands separator(;) */
	/*
	 * strtok(cmdl, ";");
	 * while (cmdl)
	 * {
	 * printf("%s\n", cmdl);*/ /* how to remove extra whitespace */
	/*
	 * cmdl = strtok(NULL, ";");
	*}
	*/

	/* 8. handle (&&) and (||) shell logical ops */


	status = micro_execute(cmdl);
	return (status);
}

/**
 * micro_execute - executes simple command_lines
 * @cmdl: command line
 * Return: exit status
 */
int micro_execute(char *cmdl)
{
	char *cmdla[32]; /* cmd array : try not to fix size */
	int i, length, status;
	int (*f)(int, char **);
	pid_t pid;
	char *path;

	/* 9. handle command args */
	cmdla[0] = strtok(cmdl, " ");
	length = 0;
	for (i = 1; cmdla[i - 1]; i++)
	{
		length++;
		cmdla[i] = strtok(NULL, " "); /* & use: variable_handler(cmdla[i]);*/
	}
	/* 10. handle built-ins */
	f = builtin_handler(cmdla[0]);
	if (f)
		f(length, cmdla);
	else /* 11.search for executable + handle PATH */
	{
		if (access(cmdla[0], F_OK | X_OK)) /* or : !stat(cmdla[0], &st) */
		{
			path = path_handler(cmdla[0]);
			if (path)
				cmdla[0] = path;
			else
			{
				perror(cmdla[0]);
				return (-1);
			}
		}
		pid = fork();
		if (pid == -1)
			perror("Error");
		else if (pid == 0)
			execve(cmdla[0], cmdla, environ);
		else
			wait(&status);
	}
	return (EXIT_SUCCESS);
}
