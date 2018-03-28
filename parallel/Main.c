#include "Header.h"

pthread_mutex_t Stack_mutex; // mutex declared 

int main(int argc, char *argv[])
{
	
   pthread_t threads[NUM_THREADS];
   pthread_attr_t attr;
   int rc;
   long i;
   void *status;
 
   pthread_attr_init(&attr);												// Thread attributes initialize
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);		// Allow threads to join
	
   pthread_mutex_init(&Stack_mutex, NULL);								// Mutex initialized	
	
	
	
  //TIMING START
  start();
  
  if(argc < 2)
  {
    printf("\nInvalid num of command line args. Usage: prog <inputFile>\n");
	exit(-1);
  }
  GetNumbers(argv[1]);
 /************************************************************************************/
 
	//Your program/calls/etc goes here
 	
	for(i = 0; i < NUM_THREADS; i++)
	{
		rc = pthread_create(&threads[i], &attr, ThreadFunction, (void *)i);	// Thread created
		if(rc)
		{
			printf("\n ERROR OCCURED");
			exit(-1);
		}
	}
	
	for(i = 0; i < NUM_THREADS; i++)
	{
		rc = pthread_join(threads[i], &status);			 // it'll join all the threads
		if(rc)
		{
			printf("\n ERROR OCCURED");
			exit(-1);
		}
	}
	
 //Pass a long id to the thread function (thread id)
 
 /***********************************************/
 
 
 /// DO NOT CHANGE ANYTHING IN THIS BLOCK
 
 // PrintAll(); // print all the data from the stack
  if(numbers != NULL)
  {
    free(numbers);
  }
  
  printf("\nAt the end stack i %lld\n", GetStackCount()); // print the counter of the stack

  printf("Main program completed. Exiting.\n");
  /// DO NOT CHANGE ANYTHING IN THIS BLOCK

	pthread_mutex_destroy(&Stack_mutex);		// we have to distroy mutex before exiting main function. Othrerwise it might be momeory leak problem.
	
	stop(); // time stops
	
	pthread_exit(NULL); // main exits 
	
}
