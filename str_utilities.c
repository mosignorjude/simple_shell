#include "shell.h"

/**
 * str_cmp - compare string values
 * @s1: input value
 * @s2: input value
 *
 * Return: s1[i] - s2[i]
 */
int str_cmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);

}

/**
 *str_cpy - copies string to a variable
 * @src: source variable
 * @dest: destination variable
 * Return: void
 */
char *str_cpy(char *dest, const char *src)
{
	int i;

	/*Copy characters from src to dest*/
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	/*Add the null terminator to the destination string*/
	dest[i++] = '\0';
	return (dest);
}

/**
 * str_dup - Function Duplicates a string
 * @str: The string to duplicate
 *
 * Return: A pointer to the newly allocated duplicate string, or NULL
 */
char *str_dup(char *str)
{
	char *dup_str;
	size_t len = 0;

	if (str == NULL)
		return (NULL);

	len = str_len(str);
	dup_str = malloc(len + 1);

	if (dup_str == NULL)
	{
		perror("Error: Memory allocation failed");
		return (NULL);
	}

	str_cpy(dup_str, str);

	return (dup_str);
}


/**
 * str_cat - concatenate two string
 * @src: source string
 * @dest: destination variable
 * Return: pointer dest
 */
char *str_cat(char *dest, const char *src)
{
	int i;
	int dest_length = 0;
	/*get the dest string length*/
	while (dest[dest_length] != '\0')
		dest_length++;

	/*appends characters from src to dest*/
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_length + i] = src[i];

	}
	/*Add the null terminator to the destination string*/
	dest[dest_length + i] = '\0';

	return (dest);
}
