/*
* Dylan Brown
* The purpose of this code is to create and model a stack in order to
* keep track of words, defined as a set of strings, in a sentence.
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


void promptUserToEnterACommand(Stack* stack);
void checkCommand(char* command, Stack* stack);
void beginPush(Stack* stack);
void freeStackAndExitProgram(Stack* stack);
void programExit();

int main(){
	Stack* stack = initializeStack();
	//Creates the stack initially
	promptUserToEnterACommand(stack);
	return 0;
}

void promptUserToEnterACommand(Stack* stack){
	//Allocate memory for a command. It shouldn't be more than 10 characters
	char* input = malloc(sizeof(char) * 10);
	printf("Please enter a command:\n");
	if(fgets(input, sizeof(input), stdin)){
		char* command = malloc(sizeof(char) * 10);
		if(sscanf(input, "%s", command)){
			free(input);
			checkCommand(command, stack);
			//Check the command and decide what to do with it
		}
	}

}

void checkCommand(char* command, Stack* stack){
	int checkForPush = strcmp(command, "push");
	int checkForPop = strcmp(command, "pop");
	int checkForPrint = strcmp(command, "print");
	int checkForExit = strcmp(command, "exit");

	free(command);


	if (checkForPush == 0){
		//Push if the user typed push
		beginPush(stack);
		promptUserToEnterACommand(stack);
	}
	else if (checkForPop == 0){
		//Pop if the user typed pop
		pop(stack);
		promptUserToEnterACommand(stack);
	}
	else if(checkForPrint == 0){
		//Print if the user typed print
		print(stack);
		promptUserToEnterACommand(stack);
	}
	else if(checkForExit == 0){
		//Exit if the user typed exit
		freeStackAndExitProgram(stack);
	}
	else{
		//Otherwise, check for the next command
		promptUserToEnterACommand(stack);
	}

}

void beginPush(Stack* stack){
	char* input = malloc(sizeof(char) * 64);
	printf("\nEnter a string to push onto the stack: ");
	if(fgets(input, (sizeof(char) * 64), stdin)){
		char* word = malloc(sizeof(char) * 64);
		//Allocate memory for the word, it can be up to 64 characters
		if(sscanf(input, "%s", word)){
			push(word, stack);
			//Push the word then free the memory
			free(word);
		}
	}
}

void freeStackAndExitProgram(Stack* stack){
	//Free allocated memory then exit program
	freeStack(stack);
	programExit();
}

void programExit(){
	printf("\nProgram exiting.\n");
	exit(0);
}
