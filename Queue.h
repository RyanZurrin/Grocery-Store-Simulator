#pragma once
#pragma once

#include <iomanip>
#include <iostream>
#include "QueueInterface.h"

inline Queue::Queue()
{
	back = NULL;
	front = NULL;
	qty = 0;
	max = 20;
}

inline Queue::Queue(int maxSize)
{
	back = NULL;
	front = NULL;
	qty = 0;
	max = maxSize;
}

inline Queue::~Queue()
{
	makeEmpty();
}

inline bool Queue::enQueue(int num)
{
	Node* temp;
	if (isFull())
	{
		return false;
	}
	temp = new Node;
	temp->val = num;
	temp->next = NULL;

	if (back == NULL) {
		back = temp;
		back->next = NULL;
		back->val = num;
		front = back;
		qty++;
		return true;
	}
	else {
		back->next = temp;
		back = temp;
		qty++;
		return true;
	}

}

inline bool Queue::deQueue(int& num)
{
	Node* temp;
	if (back == front)
	{
		back = front = NULL;
		qty--;
		return true;
	}
	else
	{
		temp = front;
		num = temp->val;
		front = front->next;
		delete temp;
		qty--;
		return true;
	}

}


inline Node* Queue::getFront()const
{
	return this->front;
}

inline Node* Queue::getBack() const
{
	return this->back;
}

inline bool Queue::peek(int& num)const
{
	if (isEmpty())
	{
		num = 0;
		return false;
	}
	if (this->front != NULL)
	{
		num = front->val;
		return true;
	}
	num = 0;
	return false;

}

inline bool Queue::isEmpty()const
{

	if (qty==0)
	{
		return true;
	}
	return false;

}

inline bool Queue::isFull()const
{

	if (qty >= max)
	{
		return true;
	}
	return false;

}

inline bool Queue::makeEmpty()
{
	Node* temp;
	if (isEmpty())
	{
		std::cout << " Queue is empty" << std::endl;
		return false;
	}
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
	back = NULL;
	return true;
}

inline int Queue::getQty()
{
	return qty;
}

inline void Queue::displayQueue()const
{
	Node* temp;

		temp = front;
		while (temp != NULL)
		{
			std::cout << std::setw(6)<< temp->val;
			temp = temp->next;
		}
		std::cout << std::endl;

}