#include "main.h"
#include "fonct.c"

char cmd[128];


int main(){
    
	pid_t pid = 0;
	int status;
	
	welcomeMSG();
	displayPrompt();
	
	clockid_t clk_id = CLOCK_REALTIME;
	struct timespec tp1;
	tp1.tv_sec = 0;
	tp1.tv_nsec = 0;
	clock_gettime(clk_id, &tp1);
	
	while(1){
		
		readCmd(cmd);
		clock_settime(clk_id,&tp1);
		pid = fork();
		
		if(pid == 0){
			
			cmd_exe(cmd);
		}else{
			
			wait(&status);
			clock_gettime(clk_id,&tp1);
			displayNextPrompt(status,tp1.tv_nsec/ 1000000);
		}
	}
}
