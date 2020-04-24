#include <stdio.h>
#include <string.h>

#define MAX_FILE_SIZE (1024*1024*4)

int main( int argc, char *argv[] ) {

	int z = 0;
	int y = 0;
	unsigned char argv_int[44];
	char final_name[100] = "secured_";

	//printf("sizeof(a) / sizeof(a[0]): %li\n", (sizeof(argv[2]) / sizeof(argv[2][0])));
	//for(int i=0 ; i<44 ; i++){
	//	argv_int[i] = argv[2][i];
       	//	printf("%c", argv_int[i]);	
	//}
	while(argv[2][y]){
		argv_int[y] = argv[2][y++];
	}
	
	printf("\n");
	
	//for (int i=0 ; i<44 ; i++){
		//printf("%i: %c    ",i, argv_int[i]);
	//}
	//printf("\n");
	while(argv[2][z])
		printf("argv[2][%i] = %c\n", z, argv[2][z++]);

	if( argc == 3 ) {
		//printf("The arguments supplied are %s and %s\n", argv[1], argv[2]);
		
		FILE *fptr;
		char data[MAX_FILE_SIZE];
		
		fptr = fopen(argv[1], "rb");
		
		int i = 0;
		while (!feof(fptr)) {
			data[i++] = fgetc(fptr);
		}
		
		fclose(fptr);
		
		fptr = fopen(strcat(final_name, argv[1]), "wb");
		
		for(int j = 0;j < i-1;j++){
			if(j>=880 && j<924){
				//if(argv_int[j-880]){
					fputc((data[j] ^ argv_int[j-880]), fptr);
					//printf("%c ^ %c = %c \n", data[j], argv_int[j-880], (data[j] ^ argv_int[j-880]));
				//}
				//fputc(data[j], fptr);
				//printf("%c ", argv_int[j-880]);
			}else
				fputc((data[j]),fptr);
		}
		fclose(fptr);
		printf("Key Secured Successfully\n");	
	}
	else if( argc > 3 ) {
		printf("Too many arguments supplied.\n");
	}
	else {
		printf("Two argument expected.\n");
	}
	
	return 0;
}
