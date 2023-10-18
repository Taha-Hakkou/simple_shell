#include "shell.h"

/**
 * _setenv - change or add an environment variable
 * @name: variable name
 * @value: variable value
 * @overwrite: add the variable if non-zero
 * Return: EXIT_SUCCESS on success, otherwise (-1) & errno indicates the error:
 *			EINVAL name is NULL, points to an empty string, or contains an '='.
 *			ENOMEM Insufficient memory to add a new variable to the environment.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	size_t nsize, vsize, i;
	char *envar;

	if (!name || !(*name) || strchr(name, '='))
	{
		errno = EINVAL;
		return (-1);
	} else if (!value)
		_unsetenv(name);
	else
	{
		nsize = strlen(name);
		vsize = strlen(value);
		envar = malloc(nsize + vsize + 2);
		if (envar)
		{
			strcat(envar, name);
			strcat(envar, "=");
			strcat(envar, value);
			for (i = 0; environ[i]; i++)
			{
				if (!memcmp(environ[i], envar, nsize + 1))
				{
					if (overwrite)
						environ[i] = envar;
					break;
				}
			}
			if (!environ[i]/* && i < (sizeof(environ) / sizeof(environ[0])) - 1*/)
			{
				environ[i] = envar;
				environ[i + 1] = NULL; /* Could cause size problem */
			} /* else {errno = ENOMEM; return (-1);} */
		} else
		{
			errno = ENOMEM;
			return (-1);
		}
	}
	return (EXIT_SUCCESS);
}
