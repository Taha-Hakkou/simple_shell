#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

extern char **environ;

/**
 * main - simple_shell
 * @argc: arguments count
 * @argv: arguments vector
 * @envp: environment pointer
 * Return: Always 0
 */
int main()
{
	char *cmd[100];
	size_t cmd_size;
	pid_t pid;
	int status;
	struct stat st;
	ssize_t size;

	if (isatty(STDIN_FILENO))
	{
		while(1)
		{
			printf("#cisfun$ ");
			size = getline(cmd, &cmd_size, stdin);
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			cmd[0] = strtok(cmd[0], "\n");
			cmd[1] = NULL;
			
			if (stat(cmd[0], &st) == 0)
			{
				pid = fork();
				if (pid == -1)
					perror("Error");
				else if(pid == 0)
					execve(cmd[0], cmd, environ);
				else
					wait(&status);
			}
			else
				perror("Error");
	
			cmd[0] = NULL;
		}
	}
	else
	{
		/* is not a tty */
	}
	return (0);
}
