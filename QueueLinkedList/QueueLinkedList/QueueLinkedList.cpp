// QueueLinkedList.cpp : Defines the entry point for the console application.
//
#include<stdafx.h>
#include<iostream>
#include<process.h>  
#include<malloc.h>  
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

//   Creating a NODE Structure
struct node
{
	int data;
	struct node *next;
};

// Creating a class QUEUE
class queue
{
	struct node *frnt, *rear;
public:
	queue() // constructure
	{
		frnt = rear = NULL;
	}
	void insert(); // to insert an element
	void del();  // to delete an element
	void show(); // to show the stack
};
// Insertion
void queue::insert()
{
	int value;
	struct node *ptr;
	std::cout << "\nInsertion\n";
	std::cout << "Enter a number to insert: ";
	std::cin >> value;
	ptr = new node;
	ptr->data = value;
	ptr->next = NULL;
	if (frnt == NULL)
		frnt = ptr;
	else
		rear->next = ptr;
	rear = ptr;
	std::cout << "\nNew item is inserted to the Queue!!!";
	getch();
}

// Deletion
void queue::del()
{
	if (frnt == NULL)
	{
		std::cout << "\nQueue is empty!!";
		getch();
		return;
	}
	struct node *temp;
	temp = frnt;
	frnt = frnt->next;
	std::cout << "\nDeletion Operation........\nDeleted value is " << temp->data;
	delete temp;
	getch();
}

// Show Queue
void queue::show()
{
	struct node *ptr1 = frnt;
	if (frnt == NULL)
	{
		std::cout << "The Queue is empty!!";
		getch();
		return;
	}
	std::cout << "\nThe Queue is\n";
	while (ptr1 != NULL)
	{
		std::cout << ptr1->data << " ->";
		ptr1 = ptr1->next;
	}
	std::cout << "END";
	getch();
}

// Main function
int main()
{
	//clrsrc();
	queue q;
	int choice;
	while (1)
	{
		std::cout << "\n-----------------------------------------------------------";
		std::cout << "\n\t\tQUEUE USING LINKED LIST\n\n";
		std::cout << "1:INSERTION\n2:DELETION\n3:DISPLAY QUEUE\n4:EXIT";
		std::cout << "\nEnter your choice(1-4): ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			q.insert();
			break;
		case 2:
			q.del();
			break;
		case 3:
			q.show();
			break;
		case 4:
			exit(0);
			break;
		default:
			std::cout << "Please enter correct choice(1-4)!!"<<std::endl;
			getch();
			break;
		}
	}
	return 0;
}

