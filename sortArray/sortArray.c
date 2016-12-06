/*
* Dylan Brown
* The purpose of this code is to deliver a sorted array to the user.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int promptUserForInputOfArraySize();
int promptUserForArrayElements(int arraySize, float *arrayPointer);
int sort(float *array, int arraySize);
int printSortedArray(float *array, int arraySize);

int main(){
  int arraySize;
  float *array;

  arraySize = promptUserForInputOfArraySize();
  if (arraySize > 0){
  array = (float*)malloc (sizeof(float) * arraySize);
  promptUserForArrayElements(arraySize, array);
  }
  free(array);

  return 0;
}

int promptUserForInputOfArraySize(){
  int input; 
  printf("Please enter the desired array size.\n\n");
  int validInput = scanf("%i", &input); //Obtains the user's input for their array size
  if (input < 1 || validInput ==0){
   printf("Sorry, you did not input a correct element. Ending the program.\n\n");
   return 0;
  }  
  return input;
}


int promptUserForArrayElements(int arraySize, float *array){
  float arrayElement;
  int isCorrectElement;
  printf("Please enter the array elements.\n");
  for (int i = 0; i < arraySize; i++){
	if (i > 0){
	  printf("Please enter the next element.\n");
	}
  	isCorrectElement = scanf("%f", &arrayElement); //Obtains the user's input for their floating element
  	if (isCorrectElement == 0){
  		printf("Sorry, you did not input a correct element. Ending the program.\n\n");
		return 0;
  	}
	array[i] = arrayElement;
  }
  printf("\n");
  sort(array, arraySize);
	
  return 0;
}

int sort(float *array, int arraySize){
 int a,b;
	
  for(a=0; a<arraySize; a++){
    for(b=a+1; b<arraySize; b++){
	if(array[a] > array[b]){
	 float var = array[a];
	 array[a] = array[b];
	 array[b] = var;
	}
    }
  }

  printSortedArray(array, arraySize);	

 return 0;
}

int printSortedArray(float *array, int arraySize){
	printf("Sorted Array with increasing value:\n");
	for(int a=0; a<arraySize; a++){
	 printf("%f ",array[a]);
	}
  	printf("\n");
	return 0;
}
