/*
        Filename: main.c
        Description: Test cases for your rot13 implementation
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "rot13lib.h"

#define MAX_LEN 4096

int main(int argc, char ** argv)
{
	int i, j, bytes_read = 0;
	char c;
	FILE * plaintext_file, * rot13_file;
	
	/* Buffers */
	char plaintext_buf[MAX_LEN];
	char rot13_buf[MAX_LEN];
	
	/* Check args */
	if(argc != 3)
	{
		printf("usage: %s <plaintext_file> <rot13_file>\n", argv[0]);
		exit(-1);
	}
	
	/* Open files */
	plaintext_file = fopen(argv[1], "r");
	rot13_file = fopen(argv[2], "r");
	if(plaintext_file == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	if(rot13_file == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	
	/* Read bytes from plaintext_file */
	for(i = 0, j = 0; i < MAX_LEN && (c = getc(plaintext_file)) != EOF; i++, j++)
	{
		plaintext_buf[j] = c;
		bytes_read++;
	}

	/* Read bytes from rot13_file */
	for(i = 0, j = 0; i < MAX_LEN && (c = getc(rot13_file)) != EOF; i++, j++)
	{
		rot13_buf[j] = c;
	}
	
	/* Perform rot13 operation on plaintext file */
	rot13(plaintext_buf);
	
	/* Check if passed or failed */
	for(i = 0; i < bytes_read; i++)
	{
		if(plaintext_buf[i] != rot13_buf[i])
		{
			printf("Failed\n");
			exit(0);
		}
	}
	
	printf("Passed\n");
	exit(0);
}
