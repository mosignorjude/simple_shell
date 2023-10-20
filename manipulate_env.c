#include "shell.h"
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
	char *name = NULL;
	char *value = NULL;
	char **result = NULL;

	if (cmdList == NULL)
		return (NULL);
	n = cmd_counter(cmdList);

	if (n != 3)
	{
		perror("invalid number of arguments");
		free_handler(cmdList);
		return (NULL);
	}
	name = cmdList[1];
	value = cmdList[2];
	result =  _setenv(name, value, new_env);
	if (result == NULL)
		print_error(progName, count, cmdList[0], "failed", NULL);
	free_handler(cmdList);
	return (result);
}

/**
 * ex_unsetenv - handel the execution of unsetenv
 * @cmdList: command array
 * @progName: shell name
 * @count: loop count
 * @new_env: track environment
 * Return: void
 */
char **ex_unsetenv(char **cmdList, char *progName, size_t count,
		char **new_env)
{
	int n;
	char *name = NULL;
	char **result = NULL;
	(void)new_env;

	if (cmdList == NULL)
		return (NULL);
	n = cmd_counter(cmdList);

	if (n != 2)
	{
		perror("invalid number of arguments");
		free_handler(cmdList);
		return (NULL);
	}
	name = cmdList[1];
	result =  _unsetenv(name, new_env);
	if (result == NULL)
		print_error(progName, count, cmdList[0], "failed", NULL);
	free_handler(cmdList);
	return (result);
}
