#include<stdio.h>
#include<fcntl.h>
#include<stdbool.h>

void wc(char *file, bool c, bool w, bool l, int *ct, int *wt, int *lt){
	int fd = 0;
	if(file != NULL){
        	fd = open(file, O_RDONLY);
		printf("%s: ", file);
	}
        int x = 1;
        char buff[1];
        int size = 1;
        int symbols = 0, words = 0, lines = 0;
        while(x > 0){
                x = read(fd, buff, size);
                if(x == 0){
                        break;
                }
                if(c == true){
                        symbols++;
                }
                if(w == true && buff[0] == ' '){
                        words++;
                }
                if(buff[0] == '\n'){
			if(l == true){
                        	lines++;
			}
			if(w == true){
                        	words++;
			}
                }
        }
	if(c == true){
		printf("%dc ", symbols);
		*ct = *ct + symbols;
	}
	if(w == true){
		printf("%dw ", words);
		*wt = *wt + words;
	}
	if(l == true){
		printf("%dl ", lines);
		*lt = *lt + lines;
	}
	printf("\n");
}
                                         


int main(int argc, char *argv[]){
	if(strcmp(argv[1], "wc") != 0){
		printf("error");
		exit(1);
	}
        int i = 0, j = 3;
        bool c = false, w = false, l = false;
	int ct = 0, wt = 0, lt = 0;
	if(argv[2] == NULL){
		wc(NULL, c, w, l, &ct, &wt, &lt);
		exit(0);
	}
	if(argv[2][0] != '-'){
		c = w = l = true;
		j = 2;
	}
	else{
        	while(argv[2][i] != '\0'){
                	if(argv[2][i] == 'c'){
                        	c = true;
                	}	
            	    if(argv[2][i] == 'w'){
                	        w = true;
                	}
                	if(argv[2][i] == 'l'){
                        	l = true;
                	}
                	i++;
        	}
		if(argv[3] != NULL && argv[3][0] == '-'){
			switch(argv[3][1]){
				case 'c': c = true; break;
				case 'w': w = true; break;
				case 'l': l = true; break;
			}
			j = 4;
		}
		if(argv[4] != NULL && argv[4][0] == '-'){
			switch(argv[4][1]){
				case 'c': c = true; break;
				case 'w': w = true; break;
				case 'l': l = true; break;
			}
			j = 5;
		}
	}
	if(argv[j] == NULL){
		wc(NULL, c, w, l, &ct, &wt, &lt);
		exit(0);
	}
        while(argv[j] != NULL){
                wc(argv[j], c, w, l, &ct, &wt, &lt);
                j++;
        }
	printf("TOTAL: ");
	if(c == true){
		printf("%dc ", ct);
	}
	if(w == true){
		printf("%dw ", wt);
	}
	if(l == true){
		printf("%dl ", lt);
	}
	printf("\n");
}

