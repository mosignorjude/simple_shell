#include "shell.h"
/**
 * get_path - get the path of command
 * @cmd: command
 * @progName: name of progName;
 * @loopcount: loop count
 * Return: path of the command
 */
char *get_path(char *cmd, char *progName, size_t loopcount)
{
	char *cmdPath, *cmdPath_cpy, *cmdPath_token;
	int pathToken_len;
	char *cmdFile_path;
	struct stat buffer;

	cmdPath = getenv("PATH");
	if (cmdPath)
	{
		cmdPath_cpy = str_dup(cmdPath);
		cmdPath_token = strtok(cmdPath_cpy, ":");

		while (cmdPath_token != NULL)
		{
			pathToken_len = str_len(cmdPath_token);
			cmdFile_path = malloc(pathToken_len + str_len(cmd) + 2);
			if (cmdFile_path == NULL)
			{
				free(cmdPath_cpy);
				return (NULL);
			}
			str_cpy(cmdFile_path, cmdPath_token);
			str_cat(cmdFile_path, "/");
			str_cat(cmdFile_path, cmd);

			if (stat(cmdFile_path, &buffer) == 0)
			{
				free(cmdPath_cpy);
				return (cmdFile_path);
			}
			free(cmdFile_path);
			cmdPath_token = strtok(NULL, ":");
		}
		free(cmdPath_cpy);

		if (stat(cmd, &buffer) == 0)
			return (str_dup(cmd));
	}
	print_error(progName, loopcount, cmd, "not found");
	return (NULL);
}
