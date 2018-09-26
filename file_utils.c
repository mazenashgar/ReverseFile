#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

/***********************************************************************
* This function opens a file, determines the size of it, 
* Allocate enough memory for it, then reads the file. If the file
* is not found, then it throws an error message. 
***********************************************************************/
int read_file(char* filename, char** buffer){

	//open the file 
	FILE* fp = fopen(filename, "r");
	
	//create an int to hold the size of the file
	int size = 0;

	//if the file was open successfully 
	if(fp){
	
		//determine the size of the file
		struct stat st;
		stat(filename, &st);
		size = st.st_size;

		//allocate enough memory for the file content
		*buffer = (char*) malloc(size*sizeof(char));
		
		if(buffer == NULL){
			//This error handling was discussed with Isfar Baset
			//if ran out of memory
			//throw an error message and terminate
			fprintf(stderr, "\n\nFile too big\nRan out of memory\n\n");
			exit(EXIT_FAILURE);
		}
		
		//read the file
		fread( *buffer, size, 1, fp);
	}else{
		//if the file opening was not successful,
		//throw an error message and terminate the program
		fprintf(stderr, "\n\nFILE NOT FOUND\n\n");
		exit(EXIT_FAILURE);
	}

	//close the file
	fclose(fp);

	//return the size of the file
	return size;	
}

/********************************************************************
*This function opens/creates a file,and write contents in it. 
********************************************************************/
int write_file(char* filename, char* buffer, int size){
	
	//open or create file	
	FILE* fp = fopen(filename, "w+");
	
	//write the contents of buffer in the file
	fwrite(buffer, size, 1, fp);
	
	//close the file
	fclose(fp);
	
	return 0;
}

