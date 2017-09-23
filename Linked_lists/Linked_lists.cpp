// Linked_lists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <stdio.h>
#include <iostream>

typedef struct Node
{
	int data;
	Node* next;
}Node;

Node* head;

void printList()
{
	Node* temp = head;
	while (temp != NULL)
	{
		std::cout << " " << temp->data;
		temp = temp->next;
	}
	std::cout << std::endl;
	//free(temp);
}

void insertAtStart(int x)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = x;
	temp->next = head;
	head = temp;
	//free(temp);
}

void insertAtEnd(int x)
{
	if (head == NULL)
	{
		insertAtStart(x);
		return;
	}
	else
	{
		Node* temp_1 = head;
		while (temp_1->next != NULL)
		{
			temp_1 = temp_1->next;
		}
		Node* temp_2 = (Node*)malloc(sizeof(Node));
		temp_2->data = x;
		temp_2->next = NULL;
		temp_1->next = temp_2;
	}
}

void insertAtPosition(int x, int p, int n)
{
	if (p == 1)
	{
		insertAtStart(x);
	}
	else if (p == n)
	{
		insertAtEnd(x);
	}
	else
	{
		Node* temp_1 = head;
		for (int i = 0; i < p - 2; i++)
		{
			temp_1 = temp_1->next;
		}
		Node* temp_2 = (Node*)malloc(sizeof(Node));
		temp_2->data = x;
		temp_2->next = temp_1->next;
		temp_1->next = temp_2;
	}
}

int genericInsertFunction(int key)
{
	int n, x;
	std::cout << "Number of elements in list: ";
	std::cin >> n;
	std::cout << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::cout << "Enter the number: " << std::endl;
		std::cin >> x;
		std::cout << std::endl;
		if (key == 1)
		{
			insertAtStart(x);
		}
		else if (key == 2)
		{
			insertAtEnd(x);
		}
		else
		{
			std::cout << "Key error" << std::endl;
			return 0;
		}
		printList();
	}
	return n;
}

int main(int argc, char** argv)
{
	head = NULL;
	int key, n, x;

	std::cout << "1. Insert at the start of list" << std::endl;
	std::cout << "2. Insert at the end of list" << std::endl;
	std::cout << "3. Insert at a given position" << std::endl;
	std::cout << "4. Delete from a given position" << std::endl;
	std::cout << "Enter the linked list operation key: ";
	std::cin >> key;

	switch (key)
	{
	case 1:
		genericInsertFunction(key);
		break;
	case 2:
		genericInsertFunction(key);
		break;
	case 3:
		n = genericInsertFunction(1);
		int p;
		std::cout << "Enter the number to insert: " << std::endl;
		std::cin >> x;
		std::cout << std::endl;

		std::cout << "Enter the position to insert: ";
		std::cin >> p;
		std::cout << std::endl;

		insertAtPosition(x, p, n);
		printList();
		break;
	case 4:
		break;
	default:
		break;
	}
	
    return 0;
}

