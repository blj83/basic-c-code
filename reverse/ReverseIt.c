#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int f1, f2 , i, size;	

	if (argc<3) {
		printf("Usage: cp file_source file_target\n");
		exit(-1);
	}
 
 	f1=open(argv[1], O_RDONLY);
 	f2=open(argv[2], O_WRONLY | O_CREAT, 0777);

 	if ((f1<0) || (f2<0)) {
		printf("error open/create files\n");
		exit(-2);
	}
	

	size = lseek(f1, 0 , SEEK_END);
	char buffer[size];
	lseek(f1, 0, SEEK_SET);
	i = read(f1, buffer, size);
	
	if (i < 0){
		printf("ERROR: reading\n");
		close(f1);
		close(f2);
		return -3;
	}
	
	char *start = buffer, *end = (buffer + size-1);
        char temp;

        for (; start < end; ++start, --end){
                temp = *start;
                *start = *end;
                *end = temp;
        }


	write(f2, buffer, size);
	if (f2 < 0){
        	printf("ERROR writing.\n");
                close(f1);
                close(f2);
                return -4;
        }

	close(f1);
	close(f2);
	return 0;

}
