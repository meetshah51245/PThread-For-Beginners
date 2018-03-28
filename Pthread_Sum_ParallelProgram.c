#include<stdio.h>										// header included
#include<stdlib.h>										// header included	
//#define NUM_THREADS 10										// define number of threads
//#define NUMBERS 1000000										// define NUMBER for iteration

void *SumUpto(void *args)									// thread function
{
	long i, number;
	long result = 0;
	

	number = (long)args;									// assigning datatype to args using type-casting

	for( i = 1; i <= number ;i++)
	{
		result = result + i;
	}

	printf("RESULT = %ld\n",result);

pthread_exit(NULL);										// thread exits here and returns null value
}

void main(int argc, char *argv[])								// main thread starts here
{	
	
	int NUM_THREADS;
	printf("ENTER NUMBER OF THREADS YOU WANT TO CREATE :");
	scanf("%d",&NUM_THREADS);

	pthread_t threads[NUM_THREADS];								// declaring array of threads

	int rc; 
	long i,NUMBERS;

	printf("ENTER NUMBERS :");
	scanf("%ld",&NUMBERS);
	
	start();
	for(i = 0; i < NUM_THREADS; i++)
	{
		rc = pthread_create(&threads[i], NULL, SumUpto, (void *)NUMBERS);		// creating threads

		if(rc)
		{
			printf("ERROR: return code from pthread_create() is %d\n",rc);     	// throw an error code if error occurs in system
			printf("code  %d =  %s\n", rc, strerror(rc));				// print string of error code
			exit(-1);
		}

	}


	stop();
	pthread_exit(NULL); 	
								// main thread should exit at the end. if you don't call it, 													it won't wait for othrer threads to complete their executi												     on and kills all the child threads.
}


