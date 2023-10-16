#include "shell.h"

/**
 * _strtok - extract tokens from strings
 * @str: parsed string in first call, & NULL in each subsequent call
 * @delim: delimiter (set  of bytes that delimit the tokens)
 * Return: a pointer to the start of the found token,
 *	   & NULL if str is empty or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *text;
	static int not_first_call;
	char *token;
	int i, j;

	if (!str && !text)
	{
		if (not_first_call)
			return (text);
		else
		{
			printf("No previous text\n"); /* seg fault actually */
			exit(EXIT_FAILURE);
		}
	}
	else if (!delim)
	{
		printf("no delim provided\n");
		exit(EXIT_FAILURE);
	}
	else if (str)
		text = str;

	printf("%s\n", text); /* preview */

	token = text;
	for (i = 0; text[i]; i++)
	{
		for (j = 0; delim[j]; j++)
			if (delim[j] == text[i])
				break;
		if (delim[j] == text[i]) /* to exit nested for loop */
			break;
	}
	if (text[i] = '\0')
		text = NULL;
	else
	{
		text = &text[i + 1];
		token[i] = '\0';
	}

	printf("%s\n", token); /* preview */
	if (text)
		printf("%s\n", text);
	else
		printf("nil\n");

	return (token);
}

/**
 * main - '_strtok' tester
 *
 * Return:
 */
int main(int ac, char *av[])
{
	char text[] = "this is a text to tokenize !";
	int i;

	for (i = 0; i < 1; i++)
		printf("%d\n", i);
	printf("%d\n", i);

	return (0);
}
