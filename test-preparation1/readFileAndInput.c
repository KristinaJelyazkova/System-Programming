#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	int fdr = open(argv[1], O_RDONLY);
	int fdw = open(argv[2], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if(fdr == -1 || fdw == -1){
		write(1, "Error", 5);
		exit(1);
	}
	char buffer[1];
	int bytes = 0;
	while( (bytes = read(fdr, buffer, 1)) > 0){
		if(buffer[0] == '0' || buffer[0] == '1' || buffer[0] == '2'
		|| buffer[0] == '3' || buffer[0] == '4' || buffer[0] == '5'
		|| buffer[0] == '6' || buffer[0] == '7' || buffer[0] == '8'
		|| buffer[0] == '9'){	
		}
		else{
			write(fdw, buffer, bytes);
		}
			bytes = read(0, buffer, 1);
			if(bytes == 0){
				break;
			}
			else{
				if(buffer[0] == '0' || buffer[0] == '1' || buffer[0] == '2'
					|| buffer[0] == '3' || buffer[0] == '4' || buffer[0] == '5'
					|| buffer[0] == '6' || buffer[0] == '7' || buffer[0] == '8'
					|| buffer[0] == '9'){	
				}
				else{
					write(fdw, buffer, 1);
				}
			}
		}
	}
