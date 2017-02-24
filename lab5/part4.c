//Part 4: Using the pipe and fork commands, 
//create a program that uses the pipe command for: 
//ls -al|awk '{ print $3 }'|sort -u

#include <stdlib.h>
#include <unistd.h>

void exec1();
void exec2();
void exec3();

int pid;
int pipe1[2];
int pipe2[2];

void main(){
	//create pipe
	if(pipe(pipe1)==-1){
		perror("bad pipe1");
		exit(1);
	}

	if((pid))
}


void exec1(){
	dup2(pipe1[1], 1);

	close(pipe1[0]);
	close(pipe1[1]);
	execlp("ps","ps", "aux", NULL);

	perror("bad exec ps");
	_exit(1);
}

void exec2(){
	dup2(pipe1[0], 0);

	dup2(pipe2[1], 1);

	close(pipe1[0]);
	close(pipe1[1]);
	close(pipe2[0]);
	close(pipe2[1]);
	execlp("ps","ps", "{ print $1 }", NULL);

	perror("bad exec grep root");
	_exit(1);
}

void exec3(){
	dup2(pipe2[0], 0);

	close(pipe2[0]);
	close(pipe2[1]);

	execlp("sort","sort", "-u", NULL);

	perror("bad exec grep sbin");
	_exit(1);
}