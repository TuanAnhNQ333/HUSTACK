#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 
int main(int argc, char *argv[]){
    if (argc != 4){
		printf("Syntax error");
		return 1;
	}
 
	FILE* f1 = fopen(argv[1],"r");
	FILE* f2 = fopen(argv[3],"w");
 
	if (f1 == NULL) {
		printf("Cannot open %s.\n", argv[1]);
		exit(1);
	}
 
	if (f2 == NULL) {
		printf("Cannot open %s.\n", argv[3]);
		exit(1);
	}
 
	int c;
    int n;
    n = atoi(argv[2]);
 
	while ((c = fgetc(f1)) != EOF) {
            if(isalpha(c)) fputc(c+n, f2);
            else fputc(c, f2);
   }
 
   fclose(f1);
   fclose(f2);
 
   return 0;
}