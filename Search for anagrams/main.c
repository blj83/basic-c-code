#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "mobydick.h"

/*
	Filename: main.c
	Note: DO NOT MODIFY
*/

int main(int argc, char **argv)
{
	/* Buffers to hold solved anagrams */
	char solved_anagram1[64] = {0};
	char solved_anagram2[64] = {0};
	char solved_anagram3[64] = {0};
	char solved_anagram4[64] = {0};
	
	/* Line numbers which each anagram is found on */
	int anagram1_line_number;
	int anagram2_line_number;
	int anagram3_line_number;
	int anagram4_line_number;
	
	/* The target anagrams to find */
	char anagram1[] = "heedlessly"; // Testcase 1
	char anagram2[] = "sedhlsleye"; // Testcase 2
	char anagram3[] = "taffomeatscenicicalinati"; // Testcase 3
	char anagram4[] = "loyntnnenoenoymtasrsietbiarjrmnfaaud"; // Testcase 4
	
	
	/* Load stdin */
	load_input();
	
	/* Find anagrams */
	find_anagram(anagram1, &anagram1_line_number, solved_anagram1);
	find_anagram(anagram2, &anagram2_line_number, solved_anagram2);
	find_anagram(anagram3, &anagram3_line_number, solved_anagram3);
	find_anagram(anagram4, &anagram4_line_number, solved_anagram4);
	
	/* Required output */
	printf("Anagram 1 is: %s\n", solved_anagram1);
	printf("Anagram 1 was found on line: %d\n", anagram1_line_number);
	printf("Anagram 2 is: %s\n", solved_anagram2);
	printf("Anagram 2 was found on line: %d\n", anagram2_line_number);
	printf("Anagram 3 is: %s\n", solved_anagram3);
	printf("Anagram 3 was found on line: %d\n", anagram3_line_number);
	printf("Anagram 4 is: %s\n", solved_anagram4);
	printf("Anagram 4 was found on line: %d\n", anagram4_line_number);
	
	/*
		Notes from TA (jiva):
		-Start early, compile often, test your logic often.
		-The four test cases consists of finding four anagrams.
		-Read the makefile for info on how to compile/run.
	*/
	
	return 0;
}

