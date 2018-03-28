#include "Hw2.h"


void* ThreadFunction(void *arg)
{
  long tid = (long)arg;
  long long randNum;
  int i, j;
  srand(time(NULL));
  
  
  
  for(j=0;j<ITERATIONS;j++){
  

	for(i=0;i<numSize;i++)
    {
	  
      Push(numbers[i]);
	
    }
	
	
    randNum = rand() % (numSize);
	for(i=0;i<randNum;i++)
    {	
	  
        int popped = Pop();
        printf("%d Popped\n", popped);
    	
	}
	
  }

  
  printf("Thread %ld exiting \ncurrent stack count %lld\n",tid, GetStackCount());
  
  pthread_exit(NULL);
}