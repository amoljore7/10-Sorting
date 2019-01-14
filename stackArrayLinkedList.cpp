//////////////////////////////////////////////////////////////////////////////////////////
//
//			Implementation of Stack using Linked List
//
//////////////////////////////////////////////////////////////////////////////////////////

/*
Stacks is abstract data types (ADT)

We can implement stack in two ways
	1.Arrays
	2.Linked lists

We can perform following operations on stack
	push( ) Insert element at top of stack
	pop( ) Delete and return the top of stack
	IsStackEmpty( ) Return true if stack is empty
	IsStackFull( ) Return true if stack is Full

Applications of Stacks :

	Web browsers store the addresses of recently visited sites on a stack
	Each time the visits a new site ==> pushed on the stack.
	Browsers allow to “pop” back to previously visited site.

	The undo-mechanism in an editor
	The changes are kept in a stack.
	When the user presses “undo” the stack of changes is popped.

	The function-call mechanism
	The active (called but not completed) functions are kept on a stack
	Each time a function is called, a new frame describing its context is pushed onto the stack
	The context of a method: its parameters, local variables, what needs to be returned, and where 
	to return (the instruction to be executed upon return)
	When the function returns, its frame is popped, the context is reset to the previous method 
	(now on top of the stack) and the program continues by executing the previously suspended method

-----------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<malloc.h>
# define MAX 10

struct stack
{
	int data;
	struct stack *next;
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//
//	Description:
//		This function acounts number of elements in stack.
//
///////////////////////////////////////////////////////////////////////////////////////////
int Count(struct stack *head)
{
	int no = 0;
	while(head != NULL)
	{
		++no;
		head = head -> next;
	}
	return no;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	IsStackEmpty
//
//	Description:
//		This function checks whether stack is empty or not.
//
///////////////////////////////////////////////////////////////////////////////////////////
int IsStackEmpty(struct stack *head)
{
	if(head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	IsStackFull
//
//	Description:
//		This function checks whether stack is full or not.
//
///////////////////////////////////////////////////////////////////////////////////////////
int IsStackFull(struct stack *head)
{
	if(Count(head) == MAX)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//
//	Description:
//		This function displays contents of stack.
//
///////////////////////////////////////////////////////////////////////////////////////////
void Display( struct stack *head )
{
	if(head == NULL)
	{
		return;
	}
	while(head)
	{
		printf(" |%d| \n", head->data);
		head = head -> next;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	pop
//
//	Description:
//		This function remove element from stack.
//
///////////////////////////////////////////////////////////////////////////////////////////
int pop(struct stack **head)
{
	int no = 0;
	struct stack *temp1,*temp2;
	temp1 = temp2 = ( *head );

	if(IsStackEmpty(*head))
	{
		return -1;
	}
	else
	{
		while(temp1 -> next != NULL)
		{
			temp2 = temp2 -> next;
			temp1 = temp2 -> next;
		}
		temp2 -> next = NULL;
		no = temp1 -> data;
		free(temp1);
		return no;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	push
//
//	Description:
//		This function add element in stack.
//
///////////////////////////////////////////////////////////////////////////////////////////
void push(struct stack **head, int no)
{
	struct stack *temp;
	struct stack *newn = (struct stack*)malloc(sizeof(struct stack));
	newn -> data = no;
	temp = (*head);

	if(IsStackFull(*head))
	{
		free(newn);
		return;
	}

	if(*head == NULL)
	{
		newn -> next = NULL;
		(*head) = newn;
	}
	else
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newn;
		newn -> next = NULL;
	}
}

int main(int argc, char *argv[])
{
	struct stack * first = NULL;

	push(&first,10);
	push(&first,20);
	push(&first,30);
	push(&first,40);

	printf("Elements in stack are\n");
	Display(first);

	printf("Poped element : %d\n",pop(&first));
	printf("Poped element : %d\n",pop(&first));

	printf("Elements in stack are\n");
	Display(first);
	return 0;
}
