#include "Hw2.h"



struct node *head = NULL; 

// Method to push data into stack
void Push(int number)
{	

	struct node *new_node;
	new_node = (struct node *) malloc (sizeof(struct node));
	new_node->next = NULL;
	new_node->data = number;
	
	if ( head == NULL )
	{
		head = new_node;
	}
	else {
		new_node->next = head;  
		head = new_node;
	}
}

// Method to extract data from stack
int Pop()
{
	int number;
	
	struct node *temp;

	temp = head;
	
	if(temp == NULL)
	{
		printf("Linked list is underfull");
		return;
	}
				
		number = temp->data;
		free(temp);
		head = head->next;	
	
	return number;
}

// Method to print number of data into the stack at a time
long long GetStackCount() 
{
	long long count = 0;
	struct node *temp;
	temp = head;
	
	while(temp != NULL)
	{
		count ++;
		temp = temp->next;
	}
	return count;
}


// Method to display all the data from the stack
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

// Method to clear stack
void clear_stack(){
	
	struct node *temp;
	
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	
}
