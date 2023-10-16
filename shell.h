#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;
/*************************       modes       ****************************/

void file_mode(char *);
void interactive_mode(void);
void simple_mode(void);

int execute(char *);

/*************************     handlers      ****************************/

int (*builtin_handler(const char *))(char **);
char *path_handler(char *);

/************************* builtin_handler.c ****************************/

/**
 * struct builtin - Built-in structure
 * @builtin: The built-in
 * @bf: The associated function
 */
typedef struct builtin
{
	char *builtin;
	int (*bf)(char **);
} builtin_t;

int __exit(char **);
int env(char **);
int _setenv(char **);
int _unsetenv(char **);
int cd(char **);
int alias(char **);

/************************************************************************/

#endif /* SHELL_H */
