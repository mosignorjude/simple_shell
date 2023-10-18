#ifndef SHELL_H
#define SHELL_H
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>
#include <stdbool.h>
#include <errno.h>
#define READ_SIZE 1024
extern char **environ;
/*string utilities*/
size_t str_len(const char *str);
int str_cmp(const char *s1, const char *s2);
char *str_cpy(char *dest, const char *src);
char *str_dup(char *str);
char *str_cat(char *dest, const char *src);
int str_ncmp(const char *s1, const char *s2, size_t n);
int str_to_int(char *str, int *result);
/*printing utilities*/
int put_char(char c);
void print_str(char *str);
int print_prompt(void);
void print_error(char *progName, size_t count, char *cmd, char *error_msg);
/*alpha-digits utilities*/
int isdigit_(int c);
int isalpha_(int c);
int tolower_(int c);
int atoi_(char *s);
/*getline function*/
int custom_fgetc(FILE *stream);
int get_char(void);
char *resize_buffer(char *buffer, size_t *size);
size_t readline(char **lineptr, size_t *n, FILE *stream);
char *cmdline_dup(char *lineptr, ssize_t chars_read);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
/*tokenizers*/
int token_counter(char *str, const char *delim);
char **split_str(char *str, const char *delim);
/*command functions*/
void execute_cmd(char **cmd_list, char *progName, size_t loopcount);
int cmd_counter(char **cmd);
char *get_path(char *cmd, char *progName, size_t loopcount);
void exit_shell(char **cmdList, char *lineptr, char *progName, int loopcount,
		char **new_environ);
void exec_builtins(char **cmd_list, char *lineptr, char *progName, int count,
		char ***new_environ);
int is_builtin(char *command);
/*handle environments*/
char *_getenv(const char *name);
char **_setenv(const char *name, const char *value, char **);
char **add_env(const char *name, const char *value);
char **ex_setenv(char **cmdList, char *progName, size_t count, char **);
void printenv(char **cmd_list, char *progName, int loopcount, char **environ);
/*miscellenous*/
void free_handler(char **ptr);

#endif /*SHELL_H*/
