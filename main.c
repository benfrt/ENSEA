#include "main.h"

int exit_rq = 0;


char cmd[128];

void welcomeMSG(){
	write(0,MSG_WELCOME,strlen(MSG_WELCOME));
}

void displayPrompt(){
	write(0,MSG_PROMPT,strlen(MSG_PROMPT));
}

void cmd_exe(char CMD[]){
	execlp(CMD,CMD,NULL);
	exit(getpid());
		
}


void readCmd(){
	int sizeRead;
	
	sizeRead = read(STDIN_FILENO,cmd,128);
	char buff[sizeRead];
	strxfrm(buff,cmd,sizeRead-1);
	write(0,buff,strlen(buff));
	 if ("exit" == buff)exit(getpid());
	cmd[sizeRead-1] = '\0';
}

int main(){
        
	pid_t pid;
	int status;
	welcomeMSG();
	displayPrompt();

	while(1){
		
		readCmd(cmd);
		
		pid = fork();
		

		if(pid == 0){
		cmd_exe(cmd);
		}else{
		wait();
		displayPrompt();
		}


		}
		
		

	
	
}
