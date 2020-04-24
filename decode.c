#include <stdio.h>

#define MAX_FILE_SIZE (1024*1024*4)



void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


int togglebit(int n) 
{ 
    if (n == 0) 
        return 1; 
  
    int i = n; 
    n |= n >> 1; 
    n |= n >> 2; 
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
  
    return i ^ n; 
} 

int XNOR(int num1, int num2)
{
    if (num1 < num2)
        swap(&num1, &num2);
    num1 = togglebit(num1);

    return num1 ^ num2;
}

int main( int argc, char *argv[] ) {

	char key[1024];
	
	if( argc == 2 ) {
		//printf("The arguments supplied are %s\n", argv[1]);
		
		FILE *fptr;
		unsigned char data[MAX_FILE_SIZE];
		
		fptr = fopen(argv[1], "rb");
		unsigned char orginal_hex[] = "\x35\x51\x9D\x36\xE0\x80\x3F\x0A\xF4\x29\x6A\x8E\x69\xE8\xCA\xF3\x49\xBD\x76\x81\x81\x50\x18\xB0\x06\x2A\x7D\x87\x34\x87\x8A\xEC\x5A\x18\x32\x12\x9E\xB4\xCC\x0C\x75\xA7\xB9\x23"; 
		int i = 0;
		while (!feof(fptr)) {
			data[i++] = fgetc(fptr);
		}
		
		fclose(fptr);
		for(int i=880 ; i<924 ; i++){
			//printf("DATA: %X ", data[i]);
			//printf("Orginal_HEX: %X ", orginal_hex[i-880]);
			//key[i-880] = XNOR((data[i]), orginal_hex[i-880]);
			key[i-880] = (data[i] ^ (orginal_hex[i-880]));
			//printf("  KEY: %c\n", key[i-880]);
		}
		
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
