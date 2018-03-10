/******************************************************************
** Author: 	  		Artem Slivka
** Date: 	  		08/04/17
** Description:		Queue.hpp is the header file for class Queue.
**		  			It contains function declaration for the class.
******************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <stddef.h>		//For NULL definition
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Queue
{
	struct QueueNode
	{
		int value;
		QueueNode* next;					//pointer that points to the next QueueNode
		QueueNode* prev;					//pointer that points to the prev QueueNode
		//Constructor
		QueueNode(int fvalue, QueueNode* fnext = NULL, QueueNode* fprev = NULL)
		{
			value = fvalue;
			next = fnext;
			prev = fprev;
		}
	};
	QueueNode* front;
	QueueNode* back;

public:
	Queue();
	~Queue();
	void addBack(int value); 				//adds item at the end of the queue
	int getFront();							//returns the value at the front of the queue
	void removeFront();						//removes the front item in the structure
	void displayQueue(string direction);	//displays the queue in chosen direction
	bool isEmpty();							//checks if queue is empty
	void displayNode(QueueNode* input, string name);
};

#endif 
