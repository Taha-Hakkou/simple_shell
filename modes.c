#include "shell.h"

/**
 * interactive_mode - displays prompt, reads input & execute command repeatedly
 * Return: Nothing
 */
void interactive_mode(void)
{
	char *cmdl;
	size_t n = 32;
	/* ssize_t size; */

	while (1) /* 4. Loop until an 'exit' or EOF(ctrl+D) */
	{
		cmdl = malloc(n * sizeof(char));
		printf("#cisfun$ "); /* 1.Prompt */
		getline(&cmdl, &n, stdin); /* 2.Get user input + return size ! */
		/* EOF (end-of-file) handler */
		if (feof(stdin))
		{
			printf("\n");
			break;
		}
		execute(cmdl);
		free(cmdl);
	}
}

/**
 * simple_mode - non-interactive mode (command provided through a pipe)
 * Return: Nothing
 */
void simple_mode(void)
{
	char *cmdl;
	size_t n;
	/* ssize_t size; */

	n = 32;
	cmdl = malloc(n * sizeof(char));
	getline(&cmdl, &n, stdin); /* return size ! */
	while (!feof(stdin))
	{
		execute(cmdl);
		getline(&cmdl, &n, stdin); /* return size ! */
	}
	free(cmdl);
}

/**
 * file_mode - reads line by line from a file & executes commands
 * @pathname: path of file to execute
 * Return: Nothing
 */
void file_mode(char *pathname)
{
	int fd;
	FILE *stream;
	char *cmdl;
	size_t n;
	/* ssize_t size; */

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
	{
		perror(pathname);
		return;/*exit(EXIT_FAILURE);*/
	}
	stream = fdopen(fd, "r");
	n = 32;
	cmdl = malloc(n * sizeof(char));
	getline(&cmdl, &n, stream); /* return size ! */
	while (!feof(stream))
	{
		execute(cmdl);
		getline(&cmdl, &n, stream); /* return size ! */
	}
	free(cmdl);
	close(fd);
}
