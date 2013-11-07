#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<signal.h>

int boolean = 0;

void parse(char *line, char **argv){
	while (*line != '\0'){
		while (*line == ' ' || *line == '\t' || *line == '\n'){
			*line++ = '\0';
		}
		if (*line == '&'){
			boolean = 1;
			*line = '\0';
		}
		else{	
			*argv++ = line;
		}
		while (*line != '\0' && *line != ' ' && *line != '\t'){
			line++;
		}
	}
	*argv = '\0';
}

void execute(char **argv){
	pid_t i;
	int status;
	
	if ((i = fork()) < 0){
		perror("fork");
		exit(-1);
	}
	else if (i == 0){
		if (execvp(*argv, argv) < 0) {
			perror("execvp");
			exit(-1);
		}
	}
	else {
		if (boolean == 0){
			wait(&status);
		}
	}
}

void prompt(int sig){
	printf("\n> ");
}

int main(){
	char line[1024];
	char *argv[64];
	
	printf("$ dummyshell\n");
	while(1){
		printf("> ");
		signal(SIGINT, prompt);
		gets(line);
		if (*line == '\n')
			continue;
		parse(line, argv);
		if (strcmp(argv[0], "exit") == 0){
			exit(0);
		}
		execute(argv);
		printf("\n");
	}
}

