#include<stdio.h>
#include<fcntl.h>

void cp(char *file1, char *file2){
	int fd1 = open(file1, O_RDONLY);
	int fd2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0755);
	int bytes = 0, size = 512;
	char buff[512];
	while( (bytes = read(fd1, buff, size)) > 0){
		write(fd2, buff, bytes);
	}	
}

int main(int argc, char *argv[]){
	char buff[5];
	int size = 5;
	int bytes = 0;
	int fd = 1;
	if(argv[1] != NULL){
		fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0755);
	}
	while( (bytes = read(0, buff, size)) > 0){
		write(fd, buff, bytes);
	}
	if(argv[1] == NULL){
		exit(0);
	}
	int i = 2;
	while(argv[i] != NULL){
		cp(argv[1], argv[i]);
		i++;
	}	
}
