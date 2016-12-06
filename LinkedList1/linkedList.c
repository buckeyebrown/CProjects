/*
* Dylan Brown
* 
* The purpose of this code is to model a singley linked list in C.
*
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
} Node;

typedef struct List{
	Node* start;
} List;

List* createLinkedListFromInput(int argc, char *argv[]);
void promptIfUserDidntProvideLinkedVals();
List* initializeList();
Node* createNode(int nodeVal);
void insertNode(Node* node, List* list);
void findWhereToInsertNextNode(Node* node, List* list);
void printList(List* list);
void printNodes(Node* node);
void searchForNodeAndDestroy(int value, Node* node, List* list);
void deleteNode(List* list, int value);
void deleteTheNextNode(Node* node);
void tellUserNodeWasDeleted(int value);
void tellUserTheListIsEmpty();
void freeList(List* list);
void freeNode(Node* node);
void promptUserForInputOfPositiveInt(List* list);
void programExit();

int main(int argc, char *argv[]){
  List* list = createLinkedListFromInput(argc, argv);
  promptUserForInputOfPositiveInt(list);
  
  return 0;
}

List* createLinkedListFromInput(int argc, char *argv[]){
	List* singlelyLinkedList = initializeList();
	if (argc == 1){
	  promptIfUserDidntProvideLinkedVals();
	}
	else{
	  int a = 1;
	  int nodeVal;
	  while (a < argc){
	//Create a node for each argument passed through the command line
		nodeVal = atoi(argv[a]); //Convert argument to int
		Node* newNode = createNode(nodeVal);
		insertNode(newNode, singlelyLinkedList);
		a++;  
	  }
	}
	printf("Linked List created.\n");
	return singlelyLinkedList;
}

void promptIfUserDidntProvideLinkedVals(){
	printf("Please pass through the values to create a Linked List from in the command line.\n");
	programExit();
}

List* initializeList(){
//Create an empty list structure and return it
  List* sllList = malloc(sizeof(List));
  sllList->start = NULL;
  return sllList;
}

Node* createNode(int nodeVal){
//Create a node structure from a value and return it
  Node* createdNode = malloc(sizeof(Node));
  createdNode->data = nodeVal;
  createdNode->next = NULL;
  return createdNode;
}


void insertNode(Node* node, List* list){
//If there isn't a head node for the list, insert node there
  if (list->start == NULL){
	list->start = node;
  }  
  else {
//Otherwise, find the best place to insert the node
	findWhereToInsertNextNode(node, list);
  }
}

void findWhereToInsertNextNode(Node* node, List* list){
//Iterate through the nodes, insert the node at the end of the list
  	Node* priorNode = list->start;
	while(priorNode->next != NULL){
	  priorNode = priorNode->next;
	}
	priorNode->next = node;
}

void printList(List* list){
  printf("\nCurrent List: ");
  printNodes(list->start);
}

void printNodes(Node* node){
 if(node->next == NULL){
//print the last node on the list
   printf("%i\n", node->data);
 }
 else{
//print each node on the list except the last one
   printf("%i, ", node->data);
   printNodes(node->next);
 }
}

void deleteNode(List* list, int value){
  searchForNodeAndDestroy(value, list->start, list);
}

void searchForNodeAndDestroy(int value, Node* node, List* list){
  Node* nextNode = node->next;
//The next node is assigned to a seperate variable

  if(node->data == value){
//If the start node for the list is the node we're looking for
    if(node->next == NULL){
//And the start node is the last node, tell user the list is empty
	freeList(list);
	tellUserTheListIsEmpty();
    }
    else{
//If there are more nodes, the start node is now the next node
	list->start = node->next;
	tellUserNodeWasDeleted(value);
    }
  }
  else if(nextNode == NULL){
//If the next node isn't the node we're looking for, and we didn't find it
//Then the value isn't in the list
     printf("\nNo node with value %i found.\n",value);
  }
  else if(nextNode->next == NULL){
//If the node after the next is null
    if(nextNode->data == value){
//Delete the next node if the next node is the value we're looking for
	deleteTheNextNode(node);
	tellUserNodeWasDeleted(value);
    }
    else{
//If it isn't, then the node isn't in the list
     printf("\nNo node with value %i found.\n",value);
    }
  }
  else if(nextNode->data == value){
//If the next node is the value we're looking for, delete it.
     deleteTheNextNode(node);
     tellUserNodeWasDeleted(value);
  }
  else{
//Recursive call, passing through the next node in the list
	searchForNodeAndDestroy(value, nextNode, list);
  }

}

void deleteTheNextNode(Node* node){
//Assign the node after next to this node's next, "deleting" the node.
  Node* nextNode = node->next;
  free(node->next);
  Node* temp = nextNode->next;
  node->next = temp;
}

void tellUserNodeWasDeleted(int value){
  printf("\nNode with value %i was deleted.\n", value);
}

void tellUserTheListIsEmpty(){
  printf("\nThe list is now empty.\n");
  programExit();
}

void freeList(List* list){
   freeNode(list->start);
}

void freeNode(Node* node){
   if(node->next == NULL){
	free(node);
   }
   else{
	free(node);
	freeNode(node->next);
   }
}

void promptUserForInputOfPositiveInt(List* list){

    int input;
    printf("\nEnter one of the following control integers:");
    printf("\n\t0 - exit program");
    printf("\n\t1 - Enter another integer to delete it from the list");
    printf("\n\t2 - Print all elements in the list");
    printf("\n\t3 - Insert an integer into the list\n");
    scanf("%i", &input);

    if(input == 0){
//Exit program if 0 is inputed.
	freeList(list);
	programExit();
    }
    else if (input == 1){
//Delete the inputted val if 1 is the control integer
	int val;
	scanf("%i", &val);
	deleteNode(list, val);
	promptUserForInputOfPositiveInt(list);
    }
    else if (input == 2){
//Print list if 2 is inputed
	printList(list);
	promptUserForInputOfPositiveInt(list);
    }
    else if (input == 3){
//Insert the inputted value if 3 is the control integer
	int val;
	scanf("%i", &val);
	Node* node = createNode(val);
	insertNode(node, list);
	promptUserForInputOfPositiveInt(list);
    }
    else{
//Close program for any number that isn't 0, 1, or 2
	printf("Wrong control integer inputted. Closing.\n");
	freeList(list);
	programExit();
    }
}

void programExit(){
	printf("\nProgram exiting.\n");
	exit(0);
}
