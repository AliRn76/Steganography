#include <stdio.h>

#define MAX_FILE_SIZE (1024*1024*4)



int main( int argc, char *argv[] ) {

	char key[64];
	
	if( argc == 2 ) {		
		FILE *fptr;
		unsigned char data[MAX_FILE_SIZE];
		
		fptr = fopen(argv[1], "rb");
		unsigned char original_hex[] = "\x35\x51\x9D\x36\xE0\x80\x3F\x0A\xF4\x29\x6A\x8E\x69\xE8\xCA\xF3\x49\xBD\x76\x81\x81\x50\x18\xB0\x06\x2A\x7D\x87\x34\x87\x8A\xEC\x5A\x18\x32\x12\x9E\xB4\xCC\x0C\x75\xA7\xB9\x23"; 
		
		int i = 0;
		while (!feof(fptr)) {
			data[i++] = fgetc(fptr);
		}
		
		fclose(fptr);

		for(int i=880 ; i<924 ; i++)
			key[i-880] = (data[i] ^ (original_hex[i-880]));
			
		
	}
	else if( argc > 2 ) {
		printf("Too many arguments supplied.\n");
	}
	else {
		printf("One argument expected.\n");
	}
	
	
	printf("Key: ");

	for(int i=0 ; i<44 ; i++)
		printf("%c", key[i]);
	printf("\n");
	
	return 0;
}
