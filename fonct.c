void welcomeMSG(){
	write(0,MSG_WELCOME,strlen(MSG_WELCOME));
}

void displayPrompt(){
	
	write(0,MSG_PROMPT,strlen(MSG_PROMPT));
}

void displayNextPrompt(int status,unsigned long time){
	
	char buff[CMD_SIZE];
	memset(buff,'\0',CMD_SIZE);
	
	if( WIFEXITED(status)){

		sprintf(buff,MSG_NEXT_PROMPT_EXIT,status,(int)time);
	}else{
		sprintf(buff,MSG_NEXT_PROMPT_SIGN,status,(int)time);
	}
	write(0,buff,sizeof(buff));
	
}

void cmd_exe(char CMD[]){
	execlp(CMD,CMD,NULL);

	write(0,EXIT_FAILURE_MSG,sizeof(EXIT_FAILURE_MSG));
	exit(getpid());
		
}

void readCmd(char cmd[CMD_SIZE]){
	int sizeRead;
	
	sizeRead = read(STDIN_FILENO,cmd,128);
	char buff[sizeRead];
	strxfrm(buff,cmd,sizeRead-1); // réduit la taille de la chaine de caractere
		 
	if( strcmp("exit\0", buff) == 0 ){
		write(0,EXIT_MSG,sizeof(EXIT_MSG));
		exit(getpid());
	}


	cmd[sizeRead-1] = '\0';
}
