#include "shell.h"
/**
 * _setenv - adds a varaible with value to environment
 * @name: variable name
 * @value: variable value
 * @new_env: track allocated env
 * Return: 0 on success -1 on error
 */

char **_setenv(const char *name, const char *value, char **new_env)
{
	char **tmp_env;
	size_t size = 0;
	char *buffer;
	int i = 0;

	if (name == NULL || value == NULL)
		return (NULL);
	if (new_env != NULL)
	{
		while (new_env[size] != NULL)
			size++;

		while (new_env[i] != NULL)
		{
			char *current_env = new_env[i];

			if (str_ncmp(current_env, name, str_len(name)) == 0)
			{
				buffer = malloc(str_len(name) + str_len(value) + 2);
				if (buffer == NULL)
					return (NULL);
				str_cpy(buffer, name);
				str_cat(buffer, "=");
				str_cat(buffer, value);
				free(new_env[i]);
				new_env[i] = buffer;
				return (0);
			}
			i++;
		}
	}
	tmp_env = add_env(name, value);
	if (new_env)
		free_handler(new_env);
	return (tmp_env);
}
/**
 * add_env - add variable to environment
 * @name: variable name
 * @value: variable value
 * Return: 0 on success or -1 on error
 */
char **add_env(const char *name, const char *value)
{
	char *buffer;
	size_t size = 0, i;
	char **new_environ;

	while (environ[size] != NULL)
		size++;

	new_environ =  malloc(sizeof(char *) * (size + 2));
	if (new_environ == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		new_environ[i] = str_dup(environ[i]);

	buffer = malloc((str_len(name) + str_len(value) + 2));
	if (buffer == NULL)
	{
		for (i = 0; i < size; i++)
			free(new_environ[i]);
		free(new_environ);
		return (NULL);
	}
	str_cpy(buffer, name);
	str_cat(buffer, "=");
	str_cat(buffer, value);

	new_environ[size] = buffer;
	new_environ[size + 1] = NULL;
	environ = new_environ;
	return (new_environ);
}


