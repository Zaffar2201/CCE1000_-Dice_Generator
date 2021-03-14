/*Processor directives*/
#include <limits.h>
#include <stdlib.h>

// declaring functions with integer return type
int checkFace(int faces);                          	
int checkThrow(int throws);
int myRandom(int f);

int
main ()//starting point of the program
{
  
  // Declaring variables
  int NumberOfFaces, NumberOfThrows, count;	         
  int RandomNumber, display_count;
 
  		                      
  /* Promt user to input number of faces in the die
   Stores it into integer variable NumberOfFaces
   */
  printf("Please enter the number of faces(2 - 24) : ");  
  scanf("%d", &NumberOfFaces);

  // calling checkFace funtion to check range of number of faces
  NumberOfFaces = checkFace(NumberOfFaces);	  

  /* Promt user to input number of throws
   Stores it into integer variable NumberOfThrows
  */
  printf("Please enter the number of throws( 2 - 499) : ");
  scanf("%d", &NumberOfThrows);

  // calling checkThrow function to check range of throws
  NumberOfThrows = checkThrow (NumberOfThrows);
 
  // declaring integer array with range 0 to NumberOfFaces
  int dice[NumberOfFaces];                  

  // initialise all elements to 0 as all elements are initially null
  for(int i = 0;i<NumberOfFaces;i++){
      dice[i]=0;
  }       
  // seed the random number in order to get a truly random number
  srand(time(NULL));
  
  // loop till end of throws
  for(count = 1; count <= NumberOfThrows; count++)   
    {
        
      // Generating a random number usinng myRandom function
      RandomNumber = myRandom(NumberOfFaces);
      
      // display the RandomNumber
      printf("%d\n", RandomNumber);
      
      /*increment array[n-1] if random number = n
        for eg 
        array[0] is incremented each time random number = 1
        array[5] is incremented each time randum number = 4
      */
      dice[RandomNumber-1] += 1;
    }

  // loop to display occurence of each face
  for(display_count = 0; display_count < NumberOfFaces; display_count++)
    {
      // Occurence = (Number of times generated / total throws) * 100
      // convert number of times into float type in order to calculate in terms of percentage %
      // display their corresponding Occurence in 2 dp
      printf("\nOccurences of %d is %.2f%\n", display_count+1, (((float) dice[display_count]) / NumberOfThrows) * 100);

    }

  return 0;
}

int
checkFace(int faces)
{
  // while loop executes as long as codition is TRUE
  // if faces are within the range ; while(not(true)) ---> while(false), hence will not execute the loop
  // if faces are outside the range ; while(not(false)) ---> while(true), hence enter loop
  while(!(faces > 1 && faces < 25))
    {
      printf("Invalid range for Number of Faces. Please re-enter the number of faces : ");
      scanf("%d", &faces);
    }
  // return the correct range of faces to NumberOfFaces
  return faces;
}


int
checkThrow (int throws)
{
 loop: // subroutine like in assembly
 
  // checks if throws are outside range
  if(throws < 2 || throws > 499){
      printf("Invalid range for Number of Throws. Please re-enter the number of throws : ");
      scanf("%d", &throws);
  // jump to loop as long as if statement is true 
  goto loop;
  }
  return throws;
}

int
myRandom(int f){
    
    // Generating a num from 0 to (NumberOfFaces-1) by the %(MOD) sign
     // add 1 to the random number so that it is within 1 to NumberOfFaces
     // then return the random number
    return (rand()%f+1);
}