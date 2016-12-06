/*
* Dylan Brown
*
* The purpose of this code is to accept a user's integer input, and output the
* prime numbers in the range and the number of twin prime sets there are.
*
*/

#include <stdio.h>
#include <math.h>

int checkForPrime(int val);
int promptUserForInteger();
int checkInputForCorrectValue(int input);
int findAllPrimes(int userValue);
int printOutIfItIsAPrime(int num);
int checkForTwinPrimes(int num, int lastPrime, int numberOfTwinPrimes);

int main(){
  
  int x = promptUserForInteger();
  
  checkInputForCorrectValue(x);

  printf("Primes from 2 to %d:\n",x);
  findAllPrimes(x);

  return 0;
}


int promptUserForInteger(){
  int input; 
  printf("Please enter a positive integer that is greater than 1 and less than 200.\n\n");
  scanf("%d", &input); //Obtains the user's input for their number.
  int correctValue = checkInputForCorrectValue(input); //Checks if the user's input is valid.
  if (correctValue == 0){
    input = promptUserForInteger(); //If the user's input is invalid, asks for their input again.
  }
  return input;
}

int checkInputForCorrectValue(int x){
  if (x > 1 && x < 200){ //If the integer is anywehre from 2 to 199, it is a correct input.
    return 1;
  }
  else if (x < 2){ //If the integer is less than 2, then it is not a prime number. Prompts the user to reenter an input.
    printf("Please enter an integer greater than 1.\n");
  }
  else if (x > 200){ //If the integer is greater than 200, then it is outside of the scope for the project.
    printf("Please enter an integer less than 200.\n");
  }
  return 0; //Return a 0 so the user has to reenter an input.
}

int findAllPrimes(int userValue){
  int num = 2; //This is the first prime number we will check.
  int numberOfTwinPrimes = 0; //Initially, there should be 0 twin primes. This counter will go up for each pair found.
  int lastPrime = 0; //This is where the last prime number will be stored.
  while (num <= userValue){
    //While our incremented number is less than the user's input, or equal to.
    if (printOutIfItIsAPrime(num) == 1){ // If it IS a prime number, then we will check for twin primes
      numberOfTwinPrimes = checkForTwinPrimes(num, lastPrime, numberOfTwinPrimes);
      //If there was a twin prime, the number of twin primes will be incremented.
      lastPrime = num;
      //The prime number will now be stored as the lastPrime.
    }
    num++;
    //Increment num to iterate through all primes.
  }
  printf("\nAmongst these there are %d twin primes.\n", numberOfTwinPrimes);
  //Print out the total number of twin primes that the code has found.
  return 0;
}

int checkForTwinPrimes(int num, int lastPrime, int numberOfTwinPrimes){
  if (lastPrime != 0 && (num - lastPrime) == 2){
    //If the last prime number is 0, then that was our initial case and we shouldn't check for twin primes yet.
    //If the current number minus the lastPrime number is equal to two, then we found a twin prime and should increment our counter.
    numberOfTwinPrimes++;
  }
  //return our newly incremented value.
  return numberOfTwinPrimes;
}

int printOutIfItIsAPrime(int num){
  if (checkForPrime(num) == 1){
    //If it is a prime number, then print out that prime number and return a 1.
    printf("%d ", num);
    return 1;
  }
  //If it is not a prime, return a 0.
  return 0;
}

int checkForPrime(int val){
  //Check to see if the number val is a prime number.

  int i = 2;
  //Start with the first prime, 2.
  
  while(i < val){
    if (i != val && val % i == 0){
      //If for any i, i is the same as the number val
      //Or if val modulus i is equal to 0, for any number less than i
      //Then the number is not a prime, and return 0 immediately.
      return 0;
    }
    //Increment i to check for more numbers less than the number val.
    i++;
  }
  //If there was no case found where the number val isn't a prime, then it is a prime. Return 1.
  return 1;
}
