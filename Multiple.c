#include <stdio.h>
#include <stdlib.h>

int main(int argc , char * argv[] )
{

int a , b;

if (argc < 3 || argc > 3 )
{
	printf("Sorry you did not enter the correct number of integers\n");
	exit(-1);
}

a = atoi(argv[1]);

if (a == 0){
	if (argv[1][0] != 0){
		printf("Wrong input\n");
		exit(-2);
	}
}

b = atoi(argv[2]);

if (b == 0){
	if (argv[2][0] != 0 ){
		printf("Wrong input\n");
		exit(-3);
	}
}
if (b % a ==  0 || argv[1][0] == 0 ){
	printf("%d is a multiple of %d\n", a, b );
	exit(1);
}

else
{
	printf("%d is not a multiple of %d\n", a , b  );
	exit(2);
} 

}
