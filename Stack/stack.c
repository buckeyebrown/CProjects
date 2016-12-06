#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Stack* initializeStack(){
	//Create an empty stack and return it
	Stack* stack = malloc(sizeof(Stack));
	stack->top = NULL;
	stack->size = 0;
	return stack;
}


void push(char* word, Stack* stack){
	Node* node = (Node*) malloc(sizeof(Node));
	//Allocate the necessary memory for the node
	if (node == NULL){
		//If there is no memory left to allocate, free memory
		freeStack(stack);
		printf("\nNo memory left to allocate. Closing program.\n");
		exit(0);
	}
	else{	
		//Otherwise, push the word onto the top of the stack
		node->word = copyWord(word, stack);
		node->next = stack->top;
		stack->top = node;
		//Increment stack size
		stack->size++;
	}

}


char* copyWord(char* word, Stack* stack){
	char* val = malloc(strlen(word) + 1);
	if (val == NULL){
		//If there is no memory left to allocate, free memory
		freeStack(stack);
		printf("\nNo memory left to allocate. Closing program.\n");
		exit(0);
	}
	else{
		//Copy the word and return it
		strcpy(val, word);
	}
	return val;
}

void pop(Stack* stack){
	if (stack->top != NULL){
		//If there is a value on the stack
		Node* temp = stack->top;
		//Make a temp node for the word to be popped
		stack->top = stack->top->next;
		//The top of the stack is the next node in line
		stack->size--;
		//Decrement stack size
		printf("\nElement popped: %s\n", temp->word);
		free(temp->word);
		free(temp);
	}
}

void print(Stack* stack){
	while(stack->size > 0){
	//Pop all the values on the stack
		pop(stack);
	}
}

void freeStack(Stack* stack){
	if (stack->top != NULL){
	//If the top of the stack is null, there is no stack left to free.
		freeNode(stack->top);
	}
}

void freeNode(Node* node){
	//Free each node in the stack, recursively
   if(node->next == NULL){
   	free(node->word);
	free(node);
   }
   else{
   	free(node->word);
	free(node);
	freeNode(node->next);
   }
}
