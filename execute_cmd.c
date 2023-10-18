#include "shell.h"
/**
 * execute_cmd - execute command
 * @cmd_list: command to be execute_cmd
 * @progName: name of progName
 * @loopcount: loop count
 * Return: void
 */
void execute_cmd(char **cmd_list, char *progName, size_t loopcount)
{
	char *cmd;
	pid_t child_pid;
	int status;

	if (cmd_list == NULL || cmd_list[0] == NULL)
		return;

	cmd = get_path(cmd_list[0], progName, loopcount);
	if (cmd == NULL)
		return;
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error: Fork failed");
		return;
	}
	else if (child_pid == 0)
	{
		if (execve(cmd, cmd_list, NULL) == -1)
		{
			perror("Error: execve failed");
			free(cmd);
			exit(1);
		}
	}
	else
	{
		wait(&status);
		free(cmd);
	}
}

