#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]){
	if(fork()){
		int status;
		wait(&status);
		close(2);
		open("tee_errors", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		char buff[100];		
		sprintf(buff, "status = %d\n", WEXITSTATUS(status));
		write(2, buff, strlen(buff));
	}
	else{
		close(0);
		open(argv[1], O_RDONLY);
		close(2);
		open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		execlp("tee", "tee", NULL);
	}
}
