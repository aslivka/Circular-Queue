/******************************************************************
** Author: 			Artem Slivka
** Date: 			08/04/17
** Description:		Queue.cpp is the function implementation file
**					for class Queue. It stores the functions for
**					manipulating a circular doubly-linked queue/list.
******************************************************************/

#include "Queue.hpp"

/*********************************************************************
** Description:		This is the default constructor for class Queue.
**
*********************************************************************/
Queue::Queue()
{
	back = NULL;
	front = NULL;
}

/*********************************************************************
** Description:		This is the default destructor for class Queue.
**
*********************************************************************/
Queue::~Queue()
{
	//Removing front element one iteration at a time
	//until both front/back point to null, indicating empty list
	while (front != NULL && back != NULL)
	{
		removeFront();
	}
}

/*********************************************************************
** Description:		This function creates a new QueueNode and adds it
**					to the list. The back pointer should point to the 
**					newly created node at the back of the queue.
*********************************************************************/
void Queue::addBack(int value)
{
	//If the initial list is empty
	if (isEmpty() == true)
	{
		//Creating new temporary node
		QueueNode* newNode = new QueueNode(value);
		
		//First assigning the node's address to back/front
		back = newNode;
		front = back;
		
		//Setting prev/next pointers
		back->next = front;
		front->prev = back;

		newNode = NULL;
	}

	else if (isEmpty() == false)
	{
		//Creating 2 temporary pointers for swapping values
		QueueNode* newBack = new QueueNode(value);

		//Assigning back pointer to point forward to new
		//temp node 
		back->next = newBack;

		//Assigning new node to point back to old back node address
		//This will allow the doubly circular link
		newBack->prev = back;

		//Re-assigning old back node to point to new node
		//since we just increased the list size by 1
		back = newBack;

		//Connecting the end of new list to front of list in forward 
		//direction
		back->next = front;

		//Connecting the end of new list to front of list in reverse
		//direction
		front->prev = back;

		newBack = NULL;
	}
}

/*********************************************************************
** Description:		This function returns the current value at the front
**					of the queue, when the list isn't empty. Otherwise,
**					it prints a message.
*********************************************************************/
int Queue::getFront()
{
	//Wanted to add check for empty queue inside function
	//but compiler gave a warning about not returning value

	return front->value;
}

/*********************************************************************
** Description:		This function removes the node that front pointer
**					is pointing to. Then, the front pointer points
**					to the new first node in the front of the queue.
*********************************************************************/
void Queue::removeFront()
{
	//If list empty, do nothing
	if (isEmpty() == true)
	{
		cout << "The queue is empty." << endl;
	}
	
	//If list has 1 element, then free memory using one of the
	//pointers front/back. Both point to the same location.
	else if(isEmpty() == false && front == back)
	{
		delete front;
		front = NULL;
		back = NULL;
	}

	//If list has 2 or more elements
	else if (isEmpty() == false && front != back)
	{
		//Storing old location of front node 
		//for later deletion from heap
		QueueNode* tempNode = front;

		front = front->next;
		front->prev = back;
		back->next = front;
		
		//Deleting memory for old front node
		delete tempNode;
		tempNode = NULL;
	}
}

/*********************************************************************
** Description:		This function displays the current queue of values
**					depending on the direction chosen.
*********************************************************************/
void Queue::displayQueue(string direction)
{
	if (isEmpty() == true)
	{
		cout << "The queue is empty." << endl;
	}
	
	else 
	{
		if (direction == "forward")
		{
			QueueNode* tempNode = front;
			//cout << endl;
			cout << "Displaying queue contents (forward direction)" << endl;

			//Printing entire list
			do
			{
				cout << tempNode->value << " ";
				tempNode = tempNode->next;
			} while (tempNode != front);
	
			cout << endl;
		}
		if (direction == "reverse")
		{
			QueueNode* tempNode = back;
			//cout << endl;
			cout << "Displaying queue contents (backward direction)" << endl;

			//Printing entire list
			do
			{
				cout << tempNode->value << " ";
				tempNode = tempNode->prev;
			} while (tempNode != back);
			
			cout << endl;
		}
	}
}

/*********************************************************************
** Description:		This function checks if the queue is empty.
**					
*********************************************************************/
bool Queue::isEmpty()
{
	//If front and back nodes are
	//pointing to memory location(s), 
	//list isn't empty
	if (front != NULL && back != NULL)
	{
		return false;
	}
	
	//Otherwise, the front/back = NULL
	//since that's how they're initialized in Node constructor
	else 
	{
		return true;
	}
}

/*********************************************************************
** Description:		This function displays all of the node's parameters.
**					It was used primarily for debugging purposes.
*********************************************************************/
void Queue::displayNode(QueueNode* input, string name)
{
	if (isEmpty() == true)
	{
		cout << "The queue is empty." << endl;
	}

	else
	{
		cout << name << ":\t";
		cout << "address:" << input << "\t";
		cout << input->prev << " " << input->value << " " << input->next << endl;
	}
}