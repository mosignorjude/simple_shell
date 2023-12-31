#include "shell.h"
#include <unistd.h>
/**
 * exit_shell - exits the shell
 * @cmdList: command array
 * @lineptr: line pointer
 * @progName: shell program name.
 * @loopcount: shell loop count.
 * @new_environ: track env
 * Return: void
 */
void exit_shell(char **cmdList, char *lineptr, char *progName, int loopcount,
		char **new_environ)
{
	int status = 0;
	char *command = cmdList[0];
	int n, exit_arg = 0;
	size_t i = 0;

	n = cmd_counter(cmdList);
	if (n > 1)
	{
		if (str_to_int(cmdList[1], &exit_arg))
			status = exit_arg;
		else
		{
			status = 2;
			print_error(progName, loopcount, command, "Illegal number", cmdList[1]);
			if (!(isatty(STDIN_FILENO)))
				exit(2);
			free_handler(cmdList);
			return;
		}
	}
	free_handler(cmdList);
	free(lineptr);

	if (new_environ)
	{
		while (new_environ[i])
			free(new_environ[i++]);
		free(new_environ);
	}
	exit(status);
}


