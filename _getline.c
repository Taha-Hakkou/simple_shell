#include "shell.h"

/**
 * _getline - reads  an  entire line from stream
 * @lineptr: pointer to buffer address
 * @n: pointer to allocated size
 * @stream: stream to read from
 * Return: number of chars read, including 'newline' char and not 'null byte' (on success)
 *		   (-1) on failure reading aline (including 'eof' condition) & errno is set to indicate error :
 *			EINVAL Bad arguments (n or lineptr is NULL, or stream is not valid).
 *			ENOMEM Allocation or reallocation of the line buffer failed.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char **_lineptr;
	size_t *_n;
	ssize_t length; /* can be used to handle embedded null bytes in the line read */

	if (!lineptr || !n || /*non-valid stream*/)
	{
		errno = EINVAL;
		return (-1);
	}
	/* The buffer is null-terminated and includes the newline character, if one was found */
	/* Alternatively,  before  calling  getline(),  *lineptr  can contain a pointer to a malloc(3)-allocated buffer *n bytes in
       size.  If the buffer is not large enough to hold the line, getline() resizes it with realloc(3), updating  *lineptr  and
       *n as necessary. */

	/* If *lineptr is set to NULL before the call, then getline() will allocate a buffer for storing  the  line.   This  buffer
       should be freed by the user program even if getline() failed */
	if (!(*lineptr))
		*lineptr = malloc();

	read(STDIN_FILENO, *lineptr, );

	/* on a successful call, *lineptr and *n will be updated */
	*lineptr = ;
	*n = ;

	return (length);
}


int main()
{
	return (0);
}
