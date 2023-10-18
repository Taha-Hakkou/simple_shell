#include "shell.h"

/**
 * _unsetenv - deteles an environment variable
 * @name: variable name
 * Return: EXIT_SUCCESS on success, otherwise (-1) & errno indicates the error:
 *			EINVAL name is NULL, or points to a string of length 0.
 */
int _unsetenv(const char *name)
{
	int i, j;
	size_t nsize;

	if (!name || !(*name))
	{
		errno = EINVAL;
		return (-1);
	}
	nsize = strlen(name);
	for (i = 0; environ[i]; i++)
		if (!memcmp(environ[i], name, nsize) && environ[i][nsize] == '=')
			for (j = i; environ[j]; j++)
				environ[j] = environ[j + 1];
	return (EXIT_SUCCESS);
}
