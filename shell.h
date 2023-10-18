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
int micro_execute(char *);

/*************************     handlers      ****************************/

int (*builtin_handler(const char *))(int, char **);
void variable_handler(char *cmdlv);
char *path_handler(char *);

/*************************  builtin_handler  ****************************/

/**
 * struct builtin - Built-in structure
 * @builtin: The built-in
 * @bf: The associated function
 */
typedef struct builtin
{
	char *builtin;
	int (*bf)(int, char **);
} builtin_t;

int __exit(int, char **);
int env(int, char **);
int __setenv(int, char **);
int __unsetenv(int, char **);
int cd(int, char **);
int alias(int, char **);

/************************  crafted functions  ****************************/

ssize_t _getline(char **, size_t *, FILE *);
char *_strtok(char *, const char *);
int _setenv(const char *, const char *, int);
int _unsetenv(const char *);

#endif /* SHELL_H */
