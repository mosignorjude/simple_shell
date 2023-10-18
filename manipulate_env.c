#include "shell.h"
#include <stdio.h>
/**
 * _getenv - get environment
 * @name: name of the environment variable
 * Return: pointer to the environment value or NULL
 */
char *_getenv(const char *name)
{
	char **env;
	char *current_env, *value;
	size_t i = 0;

	if (name == NULL)
		return (NULL);

	env = environ;
	while (env[i] != NULL)
	{
		current_env = env[i];
		if (str_ncmp(current_env, name, str_len(name)) == 0)
		{
			if (current_env[str_len(name)] == '=')
			{
				/*moves the position after '='*/
				value = current_env + str_len(name) + 1;
				return (value);
			}
		}
		i++;
	}
	return (NULL);
}


/**
 * ex_setenv - handel the execution of setenv
 * @cmdList: command array
 * @progName: shell name
 * @count: loop count
 * @new_env: track environment
 * Return: void
 */
char **ex_setenv(char **cmdList, char *progName, size_t count, char **new_env)
{
	int n;
	char *name;
	char *value;
	char **result = NULL;

	if (cmdList == NULL)
		return (NULL);
	if (cmdList[1] == NULL || cmdList[2] == NULL)
	{
		free_handler(cmdList);
		return (NULL);
	}
	name = cmdList[1];
	value = cmdList[2];
	n = cmd_counter(cmdList);
	if (n == 3)
	{
		result =  _setenv(name, value, new_env);
		if (result != 0)
			print_error(progName, count, cmdList[0], "failed");
	}
	else
		return (NULL);
	free_handler(cmdList);
	return (result);
}
