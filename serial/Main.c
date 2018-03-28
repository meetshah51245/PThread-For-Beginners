#include "Header.h"


int main(int argc, char *argv[])
{
	
  start();	
  if(argc < 2)
  {
    printf("\nInvalid num of command line args. Usage: prog <inputFile>\n");
	exit(-1);
  }
  
  GetNumbers(argv[1]);
 
 /************************************************************************************/
    
  int i;
  for(i=0;i<NUM_THREADS;i++)
  {
    Function(i);
  }
   
  
  
/******************************************************************************************/
  
 // PrintAll();
  
  if(numbers != NULL)
  {
    free(numbers);
  }
  
  printf("At the end stack count %lld \n", GetStackCount());
  
  stop();
  
  clear_stack();
 
  printf("\nMain program completed. Exiting.\n \n");

}
