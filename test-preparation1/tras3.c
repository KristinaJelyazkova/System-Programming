#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

main(int argc, char *argv[]){
	int fdi, fdo, k, broi, i = 0, status;
	char buff[40], c;
	fdi = open("fileA", O_RDWR);
	fdo = open(argv[1], O_CREAT | O_TRUNC | O_RDWR, 0666);
	if(fork() == 0){
		k = dup(1);
		close(1);
		dup(fdi);
		broi = read(fdi, buff, 40);
		c = buff[i++];
		if(c <= '0'){
			while(buff[i++] != '\n' && i < broi){
				write(1, "*", 1);
			}
			write(1, "\n", 1);
			close(1);
			dup(k);
			write(1, "*\n", 2);
		}
		write(fdo, "*\n", 2);
		close(fdi);
		close(fdo);
	}
	else{
		wait(&status);
		close(1);
		dup(fdo);
		execlp("wc", "wc", "-c", argv[1], NULL);
	}
}
