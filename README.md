# SIMPLE_SHELL :

Simple UNIX command interpreter

## Project functionalities :

* Display a prompt
* Wait for the user to type a command (A command line always ends with a new line)
* The prompt is displayed again each time a command has been executed.
* The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.

* If an executable cannot be found, print an error message and display the prompt again.
* Handle errors.
* You have to handle the “end of file” condition (Ctrl+D)

* Handle command lines with arguments

* Handle the PATH
* fork must not be called if the command doesn’t exist

*** Implement built-ins ***
	* exit (exits the shell)
		** Usage: exit status (status is an integer used to exit the shell)     => verify status with 'echo $?'
	* env (prints the current environment)
		** Usage: env
	* setenv (Initialize a new environment variable, or modify an existing one)
		** Usage: setenv VARIABLE VALUE
		** Should print something on stderr on failure
	* unsetenv (Remove an environment variable)
		** Usage: unsetenv VARIABLE
		** Should print something on stderr on failure
	* cd (Changes the current directory of the process)
		** Usage: cd [DIRECTORY]
		** If no argument is given to cd the command must be interpreted like cd $HOME
		** You have to handle the command cd -
		** You have to update the environment variable PWD when you change directory
	* alias
		** Usage: alias [name[='value'] ...]
			*** alias: Prints a list of all aliases, one per line, in the form name='value'
			*** alias name [name2 ...]: Prints the aliases name, name2, etc 1 per line, in the form name='value'
			*** alias name='value' [...]: Defines an alias for each name whose value is given. If name is already an alias, replaces its value with value

*** Use our own functions ***
	* getline
		** Use a buffer to read many chars at once and call the least possible the read system call
		** You will need to use static variables
	* strtok
	* setenv
	* unsetenv

* Handle the commands separator ';' (see example 11)

* Handle the && and || shell logical operators  (see example 12)

* Handle variables replacement  (see example 14)
	** Handle the $? variable
	** Handle the $$ variable

* Handle comments (#)   (see example 15)

* File as input
	** Usage: simple_shell [filename]
	** Your shell can take a file as a command line argument
	** The file contains all the commands that your shell should run before exiting
	** The file should contain one command per line
	** In this mode, the shell should not print a prompt and should not read from stdin

## Project architecture :

. simple_shell/
	* README.md: readme file
	* AUTHORS:
	* compile.sh:
	* hsh: 
	* Project files:
		** shell.c: main program
		** shell.h:

## Requirements :

* Betty Style
* No memory leaks
* No more than 5 functions per file
* Header files should be include garded
* Use syscalls just in need !

## Compilation command :

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


