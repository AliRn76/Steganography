#include <stdio.h>
#include <string.h>

#define MAX_FILE_SIZE (1024*1024*4)

int main( int argc, char *argv[] ) {

	unsigned char argv_int[44];
	char final_name[100] = "secured_";
	
	if( argc == 3 ) {
		FILE *fptr;
		unsigned char* data = (char*)malloc(MAX_FILE_SIZE);
		
		int y = 0;
		while(argv[2][y]){
			if(y == 44)
				break;
			argv_int[y] = argv[2][y++];
		}
	
		fptr = fopen(argv[1], "rb");
		
		int i = 0;
		while (!feof(fptr)) {
			data[i++] = fgetc(fptr);
		}
		
		fclose(fptr);
		
		fptr = fopen(strcat(final_name, argv[1]), "wb");
		
		int j;
		for(j=0 ; j<i-1 ; j++){
			if(j>=880 && j<924){
				if(j == 880)
					fputc((data[j] ^ argv_int[j-779]), fptr);
				else if (argv_int[j-880])
					fputc((data[j] ^ argv_int[j-880]), fptr);
				else
					fputc((data[j]),fptr);
			}
			else
				fputc((data[j]),fptr);
		}

		fclose(fptr);

		printf("Key Secured Successfully\n\n");	
		printf("Your Message:     ");
		int z = 1;
		while(argv_int[z])
			printf("%c", argv_int[z++]);
		printf("\nNew Image Name:   %s\n", final_name);	
	}

	else if( argc > 3 )
		printf("Too many arguments supplied.\n");

	else
		printf("Two argument expected.\n");

	
	return 0;
}
