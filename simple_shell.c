#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Entry point for the simple_shell prompt program
 *
 * This program displays a prompt, reads a line of input from the user
 * The program forks a child process to execute a command and wait for the child process to finish
 * the program handle error and continue to display prompt until the user exit
 *
 * Return - Return 0 on sucess
 */

int main(void)
{
	char *text = NULL;
	size_t lent = 0;
	ssize_t lineread;
	pid_t pid;
	int position;

	while (1)
	{
		printf("simpleshell$ ");
		lineread = getline(&text, &lent, stdin);

		if (lineread == -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("getline");
				continue;
			}
		}
		text[strcspn(text, "\n")] = '\0';
		if (strlen(text) == 0)
		{
			continue;
		}

		pid = fork();
		if (pid == -1)
		{
			perror("error");
			continue;
		}
		else if (pid == 0)
		{
			char *argv [] = {text, NULL};
			if (execve(text, argv, NULL) == -1)
			{
				perror("error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
		wait(&position);
		}
	}
	free(text);
	return (0);
}
