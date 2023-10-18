#include "shell.h"
/**
 * printenv - prints the current environment
 * @cmd_list: command array.
 * @progName: shell name.
 * @loopcount: shell loop count.
 * @environ: environment variable
 * Return: void
 */
void printenv(char **cmd_list, char *progName, int loopcount, char **environ)
{
	unsigned int i = 0;
	int n;
	(void)progName;
	(void)loopcount;

	n = cmd_counter(cmd_list);
	if (n < 2)
	{
		while (environ[i] != NULL)
		{
			print_str(environ[i]);
			i++;
		}
	}
	/*execute_cmd(cmd_list, progName, loopcount);*/
	free_handler(cmd_list);
}


