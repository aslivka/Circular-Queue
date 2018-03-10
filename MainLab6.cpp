/*********************************************************************
** Program name:	Lab6 
** Author:			Artem Slivka
** Date:			8/4/17
** Description:		This program creates a circular doubly-linked queue
**					structure. It can add/remove/display items in the
**					queue.
*********************************************************************/

#include <iostream>
#include <string>
#include "Queue.hpp"
#include "Menu.hpp"
#include "Utility.hpp"

int main()
{
	Queue queue1;
	Menu menu1;
	//Setting menu options
	menu1.addOption("Enter a value to be added to the queue");
	menu1.addOption("Display first node (front) value");
	menu1.addOption("Remove first node (front) value");
	menu1.addOption("Display the queue contents in forward order");
	menu1.addOption("Display the queue contents in reverse order");
	menu1.addOption("Exit");

	do
	{
		//Printing menu options
		menu1.printMenu();

		//Selecting menu option
		int menuChoice = getIntegerRange(1, 6);

		//Set/select a menu option
		menu1.setOption(menuChoice);

		switch (menu1.getOption())
		{
		case 1: {
					//prompting user for int value
					cout << "Enter an integer value (from -100000 to 100000)" << endl;
					int inputNum = getIntegerRange(-100000, 100000);
					queue1.addBack(inputNum);
					//cout << "Displaying updated list";
					queue1.displayQueue("forward");
					break;
				}
		case 2: {
				if (queue1.isEmpty() == true)
				{
					cout << "The queue is empty." << endl;
				}
				else
				{
					cout << "Displaying front node's value." << endl;
					cout << queue1.getFront() << endl;
				}
				break;
				}
		case 3: {			
				if (queue1.isEmpty() == true)
				{
					queue1.removeFront();
				}
				else
				{
					cout << "Removing front node from queue." << endl;
					queue1.removeFront();
					queue1.displayQueue("forward");
				}
				break;
				}
		case 4: {
					queue1.displayQueue("forward");
					break;
				}
		case 5: {
					queue1.displayQueue("reverse");
					break;
				}
		}
	} while (menu1.getOption() != 6);
	cout << "Quitting program..." << endl;
	
	cin.get();
	return 0;
}


