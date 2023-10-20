#include "shell.h"
/**
 * _unsetenv - update an environment variable
 * @name: variable name
 * @new_env: environment
 * Return: void
 */
char **_unsetenv(const char *name, char **new_env)
{
	char **new_environ;
	size_t size = 0;
	size_t i = 0;

	if (name == NULL)
		return (NULL);

	while (environ[size] != NULL)
		size++;
	new_environ = malloc(sizeof(char *) * (size + 2));
	if (new_environ == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (str_ncmp(environ[i], name, str_len(name)) == 0)
			continue;
		new_environ[i] = str_dup(environ[i]);
	}
	new_environ[i] = NULL;
	if (new_env)
		free_handler(new_env);
	environ = new_environ;
	print_str("env removed");
	return (new_environ);
}
