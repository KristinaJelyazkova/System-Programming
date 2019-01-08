#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]){
	if(fork()){
		if(fork()){
			int status1, status2;
			wait(&status1);
			wait(&status2);
			char result[100];
			sprintf(result, "status 1 = %d, status 2 = %d\n",
				WEXITSTATUS(status1), WEXITSTATUS(status2));
			write(1, result, strlen(result));
		}
		else{
			execlp(argv[1], argv[1], NULL);
		}
	}
	else{
		execvp(argv[2], &argv[2]);
	}
}
