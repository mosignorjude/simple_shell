#include "shell.h"
/**
 * is_builtin - checks if a command is builtin
 * @command: command
 * Return: 0 if test is true
 */
int is_builtin(char *command)
{
	char *builtins[64] = {"exit", "env", "setenv", "unsetenv"};
	int i;

	if (command == NULL)
		return (-1);

	for (i = 0; builtins[i] != NULL; i++)
	{
		if (str_cmp(command, builtins[i]) == 0)
			return (0);
	}
	return (-1);
}
/**
 * exec_builtins - execute builtin command
 * @cmd_list: array of command
 * @lineptr: lineptr
 * @progName: shell program name.
 * @count: shell loop count
 * @new_environ: track environ ptr allocated
 * Return: void
 */
void exec_builtins(char **cmd_list, char *lineptr, char *progName, int count,
		char ***new_environ)
{
	char *cmd = cmd_list[0];
	char **tmp_env;

	if (!cmd_list || !lineptr || cmd_list == NULL)
		return;
	if (str_cmp(cmd, "exit") == 0)
		exit_shell(cmd_list, lineptr, progName, count, *new_environ);
	else if (str_cmp(cmd, "env") == 0)
		printenv(cmd_list, progName, count, environ);
	else if (str_cmp(cmd, "setenv") == 0)
	{
		tmp_env = ex_setenv(cmd_list, progName, count, *new_environ);
		if (!tmp_env && (*new_environ))
			free_handler(*new_environ);
		*new_environ = tmp_env;
	}
	else if (str_cmp(cmd, "unsetenv") == 0)
	{
		tmp_env = ex_unsetenv(cmd_list, progName, count, *new_environ);
		if (!tmp_env && (*new_environ))
			free_handler(*new_environ);
		*new_environ = tmp_env;
	}


}


