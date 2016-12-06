#include <stdio.h>

/**
* Dylan Brown
*
* The purpose of this lab is to conduct a Depth First Search given an
* inputted number of vertices and an adjacency matrix.
*
*/


int getNumberOfVerticesFromUser();
int promptUserForAdjMatrix(int numVertices, int matrix[12][12]);
int initializedMarkedArray(int numVertices, int *marked);
int depthFirstSearch(int *marked, int matrix[12][12], int i, int numVertices);
int beginDFS(int *marked, int matrix[12][12], int numVertices);

int main(){
	int matrix[12][12];
	int numVertices = getNumberOfVerticesFromUser();
	int marked[numVertices];
	promptUserForAdjMatrix(numVertices, matrix);
	initializedMarkedArray(numVertices, marked);
	beginDFS(marked, matrix, numVertices);

return 0;
}

int beginDFS(int *marked, int matrix[12][12], int numVertices){
	int numComponents = 0;
	int x = 0;

	while (x < numVertices){
		if (marked[x] == 0){
			numComponents++;
			printf("\nComponent:");
			depthFirstSearch(marked, matrix, x, numVertices);
		}
		x++;
	}
	printf("\nTotal number of components: %i \n", numComponents);

	return 0;
}

int depthFirstSearch(int *marked, int matrix[12][12], int i, int numVertices){
	int j=0;
	int num = i + 1;
	printf(" %i", num);
	marked[i]=1;
	while (j < numVertices){
	if (matrix[i][j] == 1 && !marked[j]){
		depthFirstSearch(marked, matrix, j, numVertices);
		}
	j++;
	}
	return 0;
}

int getNumberOfVerticesFromUser(){
  printf("Please enter the number of vertices in this graph.\n");
  
  int numVertices; 
  scanf("%i", &numVertices);

  return numVertices;
}

int initializedMarkedArray(int numVertices, int *marked){
 int a=0;
 while (a < numVertices){
	marked[a] = 0;
	a++;
 }
 return 0;
}

int promptUserForAdjMatrix(int numVertices, int matrix[12][12]){
	int i = 0;
	int val;
  	printf("\nPlease enter the Adjacency Matrix below.\n");
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
