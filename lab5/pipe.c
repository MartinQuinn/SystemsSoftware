#include <stdio.h>
#include <unistd.h>
#inlcude <sys/types/h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int fd[2], nbytes;
	pid_t pid;
	char string[] = "Well howya.\n";
	char readbuffer[100];

	// Create pipe
	pipe(fd);

	// Create child process
	pid = fork();

	if(pid == 0)// This is the child
	{
		//Take no input and close fd[0]
		close(fd[0]);

		//Send output to parent via write
		write(fd[1], string, (strlen(string)+1));
		exit(0);
	}
	else // This is the parent
	{
		// Send no output, close fd[1]
		close(fd[1]);

		//Get input from the pipe via read
		nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
		printf("Message from Child: %s\n", readbuffer );
	}
}