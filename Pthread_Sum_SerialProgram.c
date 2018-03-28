
#include<stdio.h>				// include header

 
void SumUpto(int  number)			// SumUpto funtion
{
	int i;
	long result=0;
	
	for(i=1; i<=number; i++)
	{
		result = result + i;
	}
	
	printf("RESULT = %ld\n",result);	// print results
	
}

void main(int argc, char *argv[])		// main starts from here
{	

	int i;
	long NUMBERS, NUM_ITERATION;
	printf("ENTER NUMBERS :");
	scanf("%ld",&NUMBERS);

	printf("ENTER NO OF ITERATIONS :");
	scanf("%d",&NUM_ITERATION);
	
	start();
	for(i=0; i< NUM_ITERATION; i++)
	{
		SumUpto(NUMBERS);		// calling function into for loop
	}
	stop();
}

