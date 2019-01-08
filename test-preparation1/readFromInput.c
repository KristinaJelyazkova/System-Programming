#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	int fd1 = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd1 == -1 || fd2 == -1){
		write(1, "Error", 5);
		exit(1);
	}
	char buffer[1];
	int bytes = 0;
	char previous[1] = "b";
	char preprevious[1] = "b";

	while( (bytes = read(0, buffer, 1)) > 0){
		write(fd1, buffer, bytes);
		if(buffer[0] == 'a' && previous[0] == 'a' && preprevious[0] == 'a'){
			lseek(fd2, -2, SEEK_CUR);
			write(fd2, ">", 1);
			previous[0] = '>';
			preprevious[0] = '>';
		}
		else{
			write(fd2, buffer, bytes);
			preprevious[0] = previous[0];
			previous[0] = buffer[0];
		}
	}
}
