#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "mobydick.h"

/* Global variables */

char buffer[1250000];
int index_buffer, temp_ind , index_unsolved , index_solved , start_found , end_found , lines,  boolean, found , full;

/*
	One of two methods called by the main method. It loads in the 
	stdin and assigns it to a array variable called buffer.
*/

void load_input()
{
	int i = 0;

	while ((buffer[i] = getchar()) != EOF)
	{
		i++;
	}
	buffer[i] = 0;

}

/*
	Checks to see if the current char is a new line char. If it
	is then it moves on the next char and increments line.
*/

void check_line()
{

	if (buffer[index_buffer] == '\n')
	{
		lines++;
		index_buffer++;
	}
}

/*
	This method checks to see if the char at the current index in
	the buffer is a char and not a space or punctuation. If it is 
	it skips it and moves on to the next char.
*/

void is_char()
{
	while ((buffer[temp_ind] >= 32 && buffer[temp_ind] <= 64) || (buffer[temp_ind] >= 91 && buffer[temp_ind] <= 96) || (buffer[temp_ind] >= 123))
	{
		temp_ind++;
	}
}

/*
	This method takes two arrays and copies one to the other. It 
	essentially creates a temporary array that will be manipulated
	while the original remains untouched.
*/

void copy_anagram(char *uns , char *temp)
{
	int i = 0;
	while (uns[i] != '\0')
	{
		temp[i] = uns[i];
		i++;
	}
	temp[i] = '\0';
}

/*
	This metho takes an array as a parameter and it compares the char
	of the array to the char of the buffer. If they are not equal it will
	go to the next letter in the anagram. If it is found it will change
	the char at that index to 9 and change found to 1. 
*/

void check_found(char *temp)
{
	if (temp[index_unsolved] != (tolower(buffer[temp_ind])))
        {
		index_unsolved++;	
		boolean = 0;
	}
	else
	{
		if (start_found == 0)
		{
			start_found = temp_ind;
		}
		found = 1;
		temp[index_unsolved] = '9'; 
		boolean = 1;
	}
}

/*
	This method takes an array and copies the found anagram to it.
	It uses the variables statr and end found to do this.
*/
void transfer_found(char *sol)
{
	int i = 0;
	int size = end_found - start_found - 1;
	while(i < size)
	{
		sol[index_solved] = buffer[start_found];
		index_solved++;
		start_found++;
		i++;
	}
	sol[i] = '\0';
}

/*
	This method will take an array as a parameter and check to see 
	if it is full of the char 9. If it is it changes the value to 1
	if not to 0;
*/

void check_full(char *temp)
{
	int i =0;
	int slen = strlen(temp);
	while (temp[i] != '\0' && temp[i] == '9')
	{
		i++;
	}
	if (i == slen)
	{
		full = 1;
	}
	else 
	{
		full = 0;
	}
}

/*
	This method takes an array and determines if the anagram has been found.
	It does this by checking to see if the characters in that array are all
	equal to the number 9. If it is found then it sets an end index for the
	solved array.
*/

void check_anagram(char *temp)
{
	int i =0;
	int len = strlen(temp);

	while (temp[i] != '\0' && temp[i] == '9')
	{
		i++;
	}
	if (i == len)
	{
		end_found = temp_ind;
	}
	else 
	{
		start_found = 0;
	}
}


/*
	This is one of the two methods that is called by the main method of the
	program. The goal of this method is to search through the buffer and 
	check character by character to attempt to find the anagram. It then 
	returns the solved array and line number. It call the needed local 
	methods to complete this task.
*/

void find_anagram(char *_unsolved_anagram, int *_lineno, char *_solved_anagram)
{
	lines = 1;
	full = 0;
	end_found = 0;
	index_buffer = 0;
	char temp [64];

	while (buffer[index_buffer] != '\0' && end_found == 0)
	{	
		index_solved = 0;
		check_line();
		copy_anagram(_unsolved_anagram , temp);		
		boolean = 1;
		temp_ind = index_buffer;
		while (boolean == 1)
		{
			index_unsolved = 0;
			found = 0;
			is_char();
			while (temp[index_unsolved] != '\0' && found == 0)
			{
				check_found(temp);
			}
			if (full == 0)
			{
				temp_ind++;
			}
			check_full(temp);
		}
		check_anagram(temp);
		index_buffer++;
	}
	transfer_found(_solved_anagram);
	*_lineno = lines;
}

