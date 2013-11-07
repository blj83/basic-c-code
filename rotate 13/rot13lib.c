/*
        Filename: rot13lib.c
        Description: rot13 implementation
*/

#include "rot13lib.h"

// rot13 cipher
void rot13(char * _input)
{
	// your implementation goes here
	int i;

	for (i=0 ; _input[i] != '\0' ; i++)
	{

		if (_input[i] >= 65 && _input[i] <= 90)
		{

			if (_input[i] > 77)
			{
				_input[i] = _input[i] - 13;
			}
			else 
			{
				_input[i] = _input[i] + 13;
			}

		}
		
		else if (_input[i] >= 97 && _input[i] <= 122)
		{

			if (_input[i] > 109)
			{
				_input[i] = _input[i] - 13;
			}
			else 
			{
				_input[i] = _input[i] + 13;
			}
		}
		
	}
}


