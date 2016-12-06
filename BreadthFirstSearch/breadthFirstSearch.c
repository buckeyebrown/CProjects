#include <stdio.h>
#include <stdlib.h>

/**
* Dylan Brown
* The purpose of this lab is to conduct a Breadth First Search given an
* inputted number of vertices and an adjacency matrix.
* Email: brown.4414@osu.edu
* To compile: gcc -o lab2 lab2.c
* To run: ./lab2 < test1
*
*/

typedef struct node{
	int data;
	int marked;
	struct node *next;
} Node;

typedef struct queue{
	Node* start;
	int length;
} Queue;

int getNumberOfVerticesFromUser();
int promptUserForAdjMatrix(int numVertices, int matrix[12][12]);
Queue* initializeQueue();
void initializedMarkedArray(int numVertices, int *marked);
Node* createNode(int nodeVal);
void enqueue(int data, Queue* queue);
Node* dequeue(Queue* queue);
int beginBFS(int *marked, int matrix[12][12], int numVertices);
void breadthFirstSearch(int *marked, int matrix[12][12], int i, int numVertices);

int main(int argc, char *argv[]){
  int matrix[12][12];
  int numVertices = getNumberOfVerticesFromUser();
  int marked[numVertices];
  promptUserForAdjMatrix(numVertices, matrix);
  initializedMarkedArray(numVertices, marked);
  beginBFS(marked, matrix, numVertices);
  return 0;
}

int getNumberOfVerticesFromUser(){  
  int numVertices; 
  scanf("%i", &numVertices);

  return numVertices;
}

int promptUserForAdjMatrix(int numVertices, int matrix[12][12]){
	int i = 0;
	int val;
	while (i < numVertices){
		int j = 0;
		while (j < numVertices){
			scanf("%i", &val);
			matrix[i][j] = val;
			j++;
		}
		i++;
	}
	return 0;
}

Queue* initializeQueue(){
	Queue* queue = malloc(sizeof(Queue));
	queue->start = NULL;
	queue->length = 0;
	return queue;
}

void initializedMarkedArray(int numVertices, int *marked){
 int a=0;
 while (a < numVertices){
	marked[a] = 0;
	a++;
 }
}

Node* createNode(int nodeVal){
//Create a node structure from a value and return it
  Node* createdNode = malloc(sizeof(Node));
  createdNode->data = nodeVal;
  createdNode->marked = 0;
  createdNode->next = NULL;
  return createdNode;
}

void enqueue(int data, Queue* queue){
	Node* node = createNode(data);
	if(queue->start == NULL){
		queue->start = node;
		queue->length++;
	}
	else {
	Node* priorNode = queue->start;
		while(priorNode->next != NULL){
			priorNode = priorNode->next;
		}
	priorNode->next = node;
	queue->length++;
	}
}

Node* dequeue(Queue* queue){
	Node* head = queue->start;
	queue->start = head->next;
	queue->length--;
	return head;
}

int beginBFS(int *marked, int matrix[12][12], int numVertices){
	int numComponents = 0;

	int i = 0;
	while (i < numVertices){
		if (marked[i] == 0){
			numComponents++;
			printf("\nComponent:");
			printf("\nVertices & Distances:\n");
			breadthFirstSearch(marked, matrix, i, numVertices);
		}
		i++;
	}
	printf("\nTotal number of components: %i \n", numComponents);

	return 0;
}

void breadthFirstSearch(int *marked, int matrix[12][12], int i, int numVertices){
	Queue* queue = initializeQueue();
	marked[i]=1;
	int pathLength = 0;
	enqueue(i, queue);

	while(queue->length > 0){
		Node* current = dequeue(queue);
		i = current->data;
		int num = i + 1;
		printf("%i %i\n", num, pathLength);
		int j = 0;
		int pathLengthUpdated = 0;
		while (j < numVertices){
			if(matrix[i][j] == 1 && !marked[j]){
				enqueue(j, queue);
				marked[j] = 1;
				if (pathLengthUpdated == 0){
					pathLength++;
					pathLengthUpdated = 1;
				}
			}
			j++;
		}
	}
}
