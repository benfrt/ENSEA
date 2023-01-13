#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>


#define MSG_WELCOME  "Bienvenue dans le shell ENSEA.\nPour quitter tapez 'exit'.\n"
#define MSG_PROMPT "enseah %"
#define EXIT_FAILURE_MSG "YOU HAVE A BAD LUCK ! TRY AGAIN...\n"


#define EXIT_MSG "Good bye, have a great time.\n"

#define MSG_NEXT_PROMPT_SIGN "enseash [ sign : %d| %d ms ]%%"
#define MSG_NEXT_PROMPT_EXIT "enseash [ exit : %d| %d ms ]%%"

#define CMD_SIZE 128

#define PATH   "/home"
#define test "main.c"
