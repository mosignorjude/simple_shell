#include "shell.h"
/**
 * free_handler - handle memory freeing
 * @ptr: points to a pointer to be freed
 * @n: number of times to free
 * Return: void
 */
void free_handler(char **ptr)
{
	size_t i;
	size_t n = cmd_counter(ptr);

	if (ptr != NULL)
	{
		for (i = 0; i < n; i++)
		{
			if (ptr[i] != NULL)
			{
				free(ptr[i]);
				ptr[i] = NULL;
			}
		}
		free(ptr);
	}
}

