#include "shell.h"
/**
 * cmdline_dup - makes a copy of line pointer
 * @lineptr: variable to copy
 * @chars_read: size of lineptr
 * Return: Line pointer copy
 */
char *cmdline_dup(char *lineptr, ssize_t chars_read)
{
	char *cmdLine_cpy = NULL;

	cmdLine_cpy = malloc(sizeof(char) * chars_read);
	if (cmdLine_cpy == NULL)
	{
		perror("error: memory allocation failed");
		return (NULL);
	}
	str_cpy(cmdLine_cpy, lineptr);
	return (cmdLine_cpy);
}
