#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

/**
 * errorGetline - Entry  point for the errorGetlinem
 * @lineread: To read variables
 * This program displays a prompt, reads a line of input from the user
 * The program forks a child process to execute a command and
 * wait for child process to execute
 * the program handle error and continue to display prompt until the user exit
 *
 * Return: Always Return 0 on sucess
 */
int errorGetline(ssize_t lineread)
{
	if (lineread == -1)
	{
		if (feof(stdin))
			{
				printf("\n");
				return (1);
			}
		else
			{
				perror("getline");
				return (0);
			}
	}
	return (0);
}
/**
 * is_empty - Checks if a string is empty or contains only whitespace
 * @str: The string to check
 *
 * Return: 1 if the string is empty or white space, 0 otherwise
 */
int is_empty(const char *str)
{
	while (*str)
	{
		if (!isspace((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}


/**
 * main - Entry  point for the prompt
 * This program displays a prompt, reads a line of input from the user
 * The program forks a child process to execute a command and
 * wait for child process to execute
 * the program handle error and continue to display prompt until the user exit
 * Return: Return 0 on sucess
 */
int main(void)
{
	char *text = NULL;
	size_t lent = 0;
	ssize_t lineread;
	pid_t pid;
	int position;

	while (1)
	{	if(isatty(STDIN_FILENO))
			printf("simpleshell$ ");
		lineread = getline(&text, &lent, stdin);
		if (lineread == -1)
		{
			if (errorGetline(lineread))
				break;
			continue;
		}
		text[strcspn(text, "\n")] = '\0';
		if (is_empty(text))
			continue;
		 if (strlen(text) > 255)
			continue;
		if(strcmp(text, "exit") == 0)
			break;
		pid = fork();
		if (pid == -1)
		{
			perror("error");
			continue;
		}
		else if (pid == 0)
		{
			char *argv[2];

			argv[0] = text, argv[1] = NULL;
			if (execve(text, argv, NULL) == -1)
				perror("error"), exit(EXIT_FAILURE);
		}
		else
			wait(&position);
	}
	free(text);
	return (0);
}
