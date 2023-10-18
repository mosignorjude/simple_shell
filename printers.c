#include "shell.h"
/**
 * print_prompt - print shell prompt
 *
 * Return: number of characters
 */
int print_prompt(void)
{
	char *shellPrompt = "JH~$ ";

	return (write(1, shellPrompt, str_len(shellPrompt)));
}
/**
 * put_char - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int put_char(char c)
{
	return (write(1, &c, 1));
}
/**
* print_str- prints a strings
* @str: the string to be printed
* Return: void
*/
void print_str(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		put_char(str[i]);
	}
	put_char('\n');
}

/**
 * print_error - print error
 * @progName: name of shell
 * @loopcount: loop count
 * @cmd: command
 * @error_msg: error message
 * Return: void
 */
void print_error(char *progName, size_t loopcount, char *cmd, char *error_msg)
{
	char error_buffer[READ_SIZE];
	char countToStr[32];
	int i = 0;
	ssize_t bytes_written;

	while (loopcount > 0)
	{
		countToStr[i++] = (loopcount % 10) + '0';
		loopcount = loopcount / 10;
	}
	countToStr[i] = '\0';

	str_cpy(error_buffer, progName);
	str_cat(error_buffer, ": ");
	str_cat(error_buffer, countToStr);
	str_cat(error_buffer, ": ");
	str_cat(error_buffer, cmd);
	str_cat(error_buffer, ": ");
	str_cat(error_buffer, error_msg);
	str_cat(error_buffer, "\n");

	bytes_written =  write(STDERR_FILENO, error_buffer, str_len(error_buffer));
	if (bytes_written == -1)
		perror("Error: write failed");
}

