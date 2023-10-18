#include "shell.h"
/**
 * str_len - finds length of a string
 * @s: string
 * Return: length of string
*/
size_t str_len(const char *s)
{
	size_t strlen = 0;

	if (s == NULL)
		return (-1);

	while (s[strlen] != '\0')
	{
		strlen++;
	}
	return (strlen);
}


/**
 * str_to_int - integer-string to integer
 * @str: string to conver
 * @result: pointer to the converted number
 * Return: converted integer
 */
int str_to_int(char *str, int *result)
{
	char ch;
	int i;

	if (str == NULL || result == NULL)
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		ch = str[i];
		if (!isdigit_(ch))
			return (0);
	}
	*result = atoi_(str);
	return (1);
}

/**
 * str_ncmp - compare string values
 * @s1: input value
 * @s2: input value
 * @n: number of bytes to compare
 * Return: s1[i] - s2[i]
 */
int str_ncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0' && i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);

}
