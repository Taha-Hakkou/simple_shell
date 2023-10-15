#include "shell.h"

/**
 * main - simple_shell
 * @argc: arguments count
 * @argv: arguments vector
 * Return: Always 0
 */
int main(int argc, char *argv[]/*, char *envp[]*/)
{
	char *program;
	char *filename;

	program = argv[0];
	/* 0. Input file handler */
	if (argc > 2)
	{
		errno = E2BIG;
		perror(program);
		return (EXIT_FAILURE); /* return or exit */
	} else if (argc == 2)
	{
		filename = argv[1];
		file_mode(filename);
	} else
	{
		if (isatty(STDIN_FILENO))
			interactive_mode();
		else
			simple_mode();
	}
	return (EXIT_SUCCESS);
}
