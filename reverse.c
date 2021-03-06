
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file_utils.h"

/***************************************************************
*This program reverses the contents of a file and stores it
*in an other. (Both file names passed by user).
***************************************************************/
int main(int argc, char** argv){

	//create a char pointer to hold contents of file
	char* buffer;

	//create an int to hold the size of file
	int size;	

	//read the file passed from user and store its size
	size = read_file(argv[1], &buffer);

	//allocate memory enough to reverse the file
	char* ptr = malloc(size);

	if(ptr == NULL){
        	//This error handling was discussed with Isfar Baset
        	//if ran out of memory
        	//throw an error message and terminate
        	fprintf(stderr, "\n\nFile too big\nRan out of memory\n\n");
                exit(EXIT_FAILURE);
		}

	//store the file contents reversed
	for(int i = 0; i < size; ++i){
		
		ptr[i] = buffer[size-(i+1)];
	}

	//write the reversed contents in the 2nd file
	//passed by user
	write_file(argv[2], ptr, size);

	return 0;}
