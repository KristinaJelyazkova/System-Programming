#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	int fdr = open(argv[1], O_RDONLY);
	int fdw = open(argv[1], O_WRONLY | O_APPEND);
	if(fdr == -1 || fdw == -1){
		write(1, "Error", 5);
		exit(1);
	}
	char buffer[1];
	int bytes = 0;
	close(0);
	dup(fdr);
	int copyOut = dup(1);
	close(1);
	dup(fdw);
	while( (bytes = read(0, buffer, 1)) > 0){
		if(buffer[0] == '0' || buffer[0] == '1' || buffer[0] == '2'
		|| buffer[0] == '3' || buffer[0] == '4' || buffer[0] == '5'
		|| buffer[0] == '6' || buffer[0] == '7' || buffer[0] == '8'
		|| buffer[0] == '9'){
			close(1);
			dup(copyOut);
			while( (bytes = read(0, buffer, 1)) > 0){
				write(1, buffer, bytes);
			}
			break;		
		}
		else{
			write(1, buffer, bytes);
		}
	}
}
