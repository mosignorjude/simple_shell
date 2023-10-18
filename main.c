#include "shell.h"
/**
 * main - entry point
 * @ac: argument counter
 * @av: argument vector array
 * Return: always zero
 */
int main(int ac, char **av)
{
	char *cmd_line = NULL;
	const char *delim = " \n";
	size_t n = 0, loopcount = 0;
	ssize_t bytes_read = 0;
	char *progName = av[0];
	char **new_environ = NULL;
	(void)ac;

	while (true)
	{
		if (isatty(STDIN_FILENO))
			print_prompt();
		loopcount++;
		bytes_read = _getline(&cmd_line, &n, stdin);
		if (bytes_read == -1)
			break;
		
		av = split_str(cmd_line, delim);
		if (av == NULL)
			continue;

		if (is_builtin(av[0]) == 0)
			exec_builtins(av, cmd_line, progName, loopcount, &new_environ);
		else
		{
			execute_cmd(av, progName, loopcount);
			free_handler(av);
		}
	}
	free(cmd_line);
	if (new_environ)
		free_handler(new_environ);
	return (0);
}
