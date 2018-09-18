
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

	//store the file contents reversed
	for(int i = size - 1; i >= 0; i--){
		
		ptr[size-i] = buffer[i];
	}

	//write the reversed contents in the 2nd file
	//passed by user
	write_file(argv[2], ptr, size);

	return 0;

}
