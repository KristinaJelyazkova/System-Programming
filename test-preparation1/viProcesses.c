#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	if(fork()){
		int status;
		wait(&status);
		execlp("mv", "mv", argv[1], "testDir", NULL);
	}
	else{
		int pd[2];
		pipe(pd);
		if(fork()){
			close(1);
			open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			close(0);
			dup(pd[0]);
			close(pd[0]);
			close(pd[1]);
			execlp("grep", "grep", "-w", "vi", NULL);
		}
		else{
			close(1);
			dup(pd[1]);
			close(pd[1]);
			close(pd[0]);
			execlp("ps", "ps", "aux", NULL);
		}
	}
}
