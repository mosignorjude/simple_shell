#include "shell.h"
/**
 * token_counter -  count tokens
 * @str: string
 * @delim: delimiter
 * Return: number of tokens
 */
int token_counter(char *str, const char *delim)
{
	int toks_count = 0;
	char *toks;

	toks = strtok(str, delim);
	while (toks != NULL)
	{
		toks_count++;
		toks = strtok(NULL, delim);
	}
	return (toks_count);
}

/**
 * split_str - splits strings into tokens
 * @str: strings
 * @delim: delimiter
 * Return: array of each word
 */
char **split_str(char *str, const char *delim)
{
	char *str_copy;
	char **tokens = NULL;
	char *toks;
	int count = 0, i, j;

	if (str == NULL || str[0] == '\0' || str[0] == '\n')
		return (NULL);
	str_copy = str_dup(str);
	if (str_copy == NULL)
		return (NULL);
	toks = strtok(str_copy, delim);
	while (toks != NULL)
	{
		count++;
		toks = strtok(NULL, delim);
	}
	tokens = malloc((count + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		free(str_copy);
		return (NULL);
	}
	str_cpy(str_copy, str);
	toks = strtok(str_copy, delim);
	for (i = 0; toks != NULL; i++)
	{
		tokens[i] = str_dup(toks);
		if (tokens[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(tokens[j]);
			free(tokens);
			free(str_copy);
			return (NULL);
		}
		toks = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	free(str_copy);
	return (tokens);
}
/**
 * cmd_counter - count commands
 * @cmd: commands
 * Return: number of commands
 */
int cmd_counter(char **cmd)
{
	int i, count = 0;

	for (i = 0; cmd[i] != NULL; i++)
	{
		count++;
	}
	return (count);
}

