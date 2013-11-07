#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

double total = 0, count = 0;
int debug = 0 , boolean = 0;

void printTotal(int sig){
	if ((debug % 2) == 0){
		printf("Total: %f\n" , total);
	}
}

void alarmTotal(int sig){
	printf("Total: %f\n" , total);
	boolean = 0;
}

void setAlarm(int sig){
	debug++;
}

void terminate(int sig){
	printf("Total: %f\n" , total);
	exit(0);
}

int main(int argc, char *argv[]){

	int one, two, three;

	one = atoi(argv[1]);
	two = atoi(argv[2]);
	three = atoi(argv[3]);
		
	if (argc != 4){
		printf("Please enter 3 parameters\n");
		exit(-1);
	}

	signal(SIGUSR1, printTotal);
	signal(SIGUSR2, setAlarm);
	signal(SIGINT, terminate);
	signal(SIGALRM, alarmTotal);

	while (count < two){
		count = count + .001;
		total = total + (count * one);
		if ((debug % 2) == 1 && boolean == 0){
                	alarm(three);
			boolean = 1;
        	}	
	}
	exit(0);
}
