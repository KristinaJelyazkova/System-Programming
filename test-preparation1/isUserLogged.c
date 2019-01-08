#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	if(fork()){
		wait(NULL);
		int fd = open("f1", O_RDONLY);
		char buffer[20];
		if(read(fd, buffer, 20) == 0){
			write(1, "No\n", 3);
		}
		else{
			write(1, "Yes\n", 4);
		}
	}
	else{
		int pd[2];
		pipe(pd);

		if(fork()){
			close(0);
			dup(pd[0]);
			close(pd[0]);
			close(pd[1]);
		
			close(1);
			open("f1", O_WRONLY | O_CREAT | O_TRUNC, 0644);
			execlp("grep", "grep", "-w", argv[1], NULL);
		}
		else{
			close(1);
			dup(pd[1]);
			close(pd[1]);
			close(pd[0]);
			execlp("who", "who", NULL);
		}
	}
}
