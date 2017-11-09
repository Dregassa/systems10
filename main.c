#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

static void sighandler (int signo){
	if (signo == SIGINT){
		int fd = open("log.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
		char errmsg [40];
	       	sprintf(errmsg, "Exited due to SIGINT (PID = %d)\n", getpid() );
		write(fd, errmsg, strlen(errmsg) );
		close(fd);
		exit(1);	
	}
	if (signo == SIGUSR1){
		printf("Parent PID: %d\n", getppid());
	}
}

int main(){
	signal(SIGINT, sighandler);
	signal(SIGUSR1, sighandler);
	
	//printf("%d\n",SIGUSR1);
	
	while(1){
		printf("PID: %d\n", getpid());
		sleep(1);
	}
}
