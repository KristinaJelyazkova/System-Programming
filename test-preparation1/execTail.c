#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]){
	if(fork()){
		int status;
		wait(&status);
		char string[30];
		sprintf(string, "status = %d\n", WEXITSTATUS(status));
		write(1, string, strlen(string));
	}
	else{
		close(1);
		open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		close(2);
		open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		execlp("tail", "tail", "-2l", argv[1], NULL);
	}
}
