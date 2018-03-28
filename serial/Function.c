#include "Hw2.h"


void Function(long arg)
{
  long iteration = arg;
  long long randNum;
  int i, j;
  srand(time(NULL));
  
  for(j=0;j<ITERATIONS;j++)
  {
    for(i=0;i<numSize;i++)
    {
	        Push(numbers[i]);
    }
     randNum = rand() % (numSize);
	 printf("\n");
     for(i=0;i<randNum;i++)
     {
       int popped = Pop();
       printf("%d popped\n", popped);
     } 
  }
  
  printf("\nCalled the function %ld time current stack count %lld\n",iteration, GetStackCount());
}
