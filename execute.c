#include "shell.h"

/**
 * execute - executes
 * @cmdl: command line
 * Return:
 */
int execute(char *cmdl)
{
	pid_t pid;
	int status;
	char *path;

	char *cmdla[32]; /* commad_line array : try not to fix size */
	int i;

	/* 6. handle comments(#) + newline character(\n) */
	strtok(cmdl, "#\n");

	/* 7. handle the commands separator(;) */
	/*strtok(cmdl, ";");
	while (cmdl)
	{
		printf("%s\n", cmdl);*/ /* how to remove extra whitespace */
	/*	cmdl = strtok(NULL, ";");
	}*/

	/* 8. handle (&&) and (||) shell logical ops */

	/* 9. handle command args */
	cmdla[0] = strtok(cmdl, " ");
	for (i = 1; cmdla[i - 1]; i++)
		cmdla[i] = strtok(NULL, " ");

	/* 10. handle built-ins */
	int (*f)(char **) = builtin_handler(cmdla[0]);
	if (f)
		f(cmdla);
	else
	{
		/* 11.search for executable + handle PATH */
		if (access(cmdla[0], F_OK | X_OK)) /* or : !stat(cmdla[0], &st) */
		{
			path = path_handler(cmdla[0]);
			if (path)
			{
				/*printf("%s\n", path);*/
				cmdla[0] = path; /* but only works first time, in the second prompt : path return NULL !? */
			}
			else
			{
				perror(cmdla[0]);
				return(EXIT_FAILURE);
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
