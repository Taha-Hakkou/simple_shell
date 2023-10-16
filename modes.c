#include "shell.h"

/**
 * file_mode - reads line by line from a file & executes commands
 * @pathname: path of file to execute
 * Return: Nothing
 */
void file_mode(char *pathname)
{
	int fd;
	char *cmdl;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
	{
		perror(pathname);
		return;/*exit(EXIT_FAILURE);*/
	}
	/*while ()
	{
		cmdl = ;read(fd, buf, count);*//* read & execution of each line */
	/*	execute(cmdl);
	}*/
	close(fd);
}

/**
 * interactive_mode - displays prompt, reads input & execute command repeatedly
 * Return: Nothing
 */
void interactive_mode(void)
{
	char *cmdl;
	size_t n = 32;
	ssize_t size;

	while (1) /* 4. Loop until an 'exit' or EOF(ctrl+D) */
	{
		cmdl = malloc(n * sizeof(char));
		printf("#cisfun$ "); /* 1.Prompt */
		size = getline(&cmdl, &n, stdin); /* 2.Get user input */
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
	size_t n = 32;
	ssize_t size;

	cmdl = malloc(n * sizeof(char));
	size = getline(&cmdl, &n, stdin);
	execute(cmdl);
	free(cmdl);
}
