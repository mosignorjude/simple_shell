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
	int i = 0;

	if (name == NULL || value == NULL)
		return (NULL);
	while (environ[i] != NULL)
	{
		if (str_ncmp(environ[i], name, str_len(name)) == 0)
		{
			tmp_env = update_env(name, value);
			if (new_env)
				free_handler(new_env);
			return (tmp_env);
		}
		i++;
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
	print_str("env added");
	return (new_environ);
}

/**
 * update_env - update an environment variable
 * @name: variable name
 * @value: variable value
 * Return: void
 */
char **update_env(const char *name, const char *value)
{
	char **new_environ;
	size_t size = 0;
	char *buffer;
	size_t i = 0;

	if (name == NULL || value == NULL)
		return (NULL);

	while (environ[size] != NULL)
		size++;
	new_environ = malloc(sizeof(char *) * (size + 1));
	if (new_environ == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (str_ncmp(environ[i], name, str_len(name)) != 0)
		{
			new_environ[i] = str_dup(environ[i]);
		}
		else
		{
			buffer = malloc(str_len(name) + str_len(value) + 2);
			if (buffer == NULL)
				return (NULL);
			str_cpy(buffer, name);
			str_cat(buffer, "=");
			str_cat(buffer, value);
			new_environ[i] = buffer;
		}
	}
	new_environ[i] = NULL;
	environ = new_environ;
	print_str("env updated");
	return (new_environ);
}
