// queuewithArray.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


const int maxQueue = 7;

struct queueType
{
	string op[maxQueue];
	int front;
	int back;
};

void createQueue(queueType &queue);
bool fullQueue(queueType queue);
bool emptyQueue(queueType queue);
void inQueue(queueType &queue, string &newElement);
void deQueue(queueType &queue, string &opOut);

int main()
{
	queueType operators;
	string newElement;
	string opOut;
	char question;

	createQueue(operators);

	cout << "Do you want to enter data (Y/N)? ";
	cin >> question;

	while ((question == 'y' || question == 'Y') && (!(fullQueue(operators))))
	{
		cout << "Enter a Char: ";
		cin >> newElement;

		inQueue(operators, newElement);

		if (!(fullQueue(operators)))
		{
			cout << "Do you want to enter data (Y/N)? ";
			cin >> question;
		}
	}


	while (!(emptyQueue(operators)))
	{
		deQueue(operators, opOut);
		cout << opOut << " ";
	}



	cin.get();
	cin.ignore();
	return 0;
}

void createQueue(queueType &queue)
{
	queue.front = maxQueue - 1;
	queue.back = maxQueue - 1;
}

void inQueue(queueType &queue, string &newElement)
{
	queue.back = (queue.back + 1) % maxQueue;
	queue.op[queue.back] = newElement;
}

void deQueue(queueType &queue, string &opOut)
{
	queue.front = (queue.front + 1) % maxQueue;
	opOut = queue.op[queue.front];
}

bool fullQueue(queueType queue)
{
	if (queue.front == (queue.back + 1) % maxQueue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool emptyQueue(queueType queue)
{
	if (queue.front == queue.back)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}