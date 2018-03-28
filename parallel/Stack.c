#include "Hw2.h"



struct node *head = NULL;  

//Method to Push data into node
void Push(int number)
{	

	struct node *temp;
	temp = (struct node *) malloc (sizeof(struct node));
	
	temp->data = number;
	temp->next = NULL;
	
	pthread_mutex_lock(&Stack_mutex); // lock the mutex so only one thread can enter into crtical section
	
	if ( head == NULL )
	{
			head = temp;
 		
	}
	else {
		
		temp->next = head;  
		head = temp;
	}
	pthread_mutex_unlock(&Stack_mutex);	// unlock the mutex so other threads can have access of crtical section
}

//Method to pop data from node
int Pop()
{	
	
	int number;
	struct node *temp;

	
	pthread_mutex_lock(&Stack_mutex); // lock the mutex so only one thread can enter into crtical section

	temp = head;
		
	if(temp == NULL)
	{
		printf("Linked list is underfull");
		return;
	}
		
	head = head->next;
	
	pthread_mutex_unlock(&Stack_mutex);	// unlock the mutex so other threads can have access of crtical section
		
	number = temp->data;
	free(temp);
			
	return number;
}

// print number of elements of the node
long long GetStackCount() 
{

	long long i = 0;
	struct node *temp;
	
	pthread_mutex_lock(&Stack_mutex); // lock the mutex so only one thread can enter into crtical section
	temp = head;
	
	while(temp != NULL)
	{
		i ++;
		temp = temp->next;
	}
	
	pthread_mutex_unlock(&Stack_mutex);	// unlock the mutex so other threads can have access of crtical section
	return i;
}


// display all the elements of the node
void PrintAll()
{	
	
	int number;
	struct node *temp;
	temp = head;
    
	if (temp == NULL)
    {
        printf ("Linked list is empty\n");
        return;
    }
	
	printf ("\n\nLIST :- \n");
    
	while (temp != NULL)
	{	
        number = temp->data;
		temp = temp->next;
		printf("%d\n", number);
    }
	
}

// clear the node
void clear_stack(){
	
	struct node *temp;
	
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	
}
