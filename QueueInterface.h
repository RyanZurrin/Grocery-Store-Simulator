#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue
{
public:

	/// <summary>
	/// Initializes a new instance of the <see cref="Queue"/> class.
	/// </summary>
	Queue();

	/// <summary>
	/// Initializes a new instance of the Queue class.
	/// </summary>
	/// <param name="maxSize">The max number of elements queue can hold</param>
	Queue(int);

	/// <summary>
	/// Finalizes an instance of the Queue class.
	/// </summary>
	~Queue();

	/// <summary>
	/// Enqueues the specified number.
	/// </summary>
	/// <param name="num">The number.</param>
	/// <returns>true if successfully enqueues: false if else</returns>
	bool enQueue(int num);

	/// <summary>
	/// Des the queue.
	/// </summary>
	/// <param name="num">The .</param>
	/// <returns></returns>
	bool deQueue(int& num);

	/// <summary>
	/// Gets the front.
	/// </summary>
	/// <returns></returns>
	Node* getFront()const;

	/// <summary>
	/// Gets the back.
	/// </summary>
	/// <returns></returns>
	Node* getBack()const;

	/// <summary>
	/// Peeks the specified .
	/// </summary>
	/// <param name="">The .</param>
	/// <returns>num</returns>
	bool peek(int& num)const;//save next element to a int

	/// <summary>
	/// Determines whether this instance is empty.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is empty; otherwise, <c>false</c>.
	/// </returns>
	bool isEmpty()const;//return true if empty:false if else

	/// <summary>
	/// Determines whether this instance is full.
	/// </summary>
	/// <returns>
	///   <c>true</c> if this instance is full; otherwise, <c>false</c>.
	/// </returns>
	bool isFull()const;//return true if full: false if else

	/// <summary>
	/// Makes the empty.
	/// </summary>
	/// <returns></returns>
	bool makeEmpty();//empties the queue

	/// <summary>
	/// Gets the qty.
	/// </summary>
	/// <returns>qty of stack</returns>
	int getQty();//return the qty of items in the queue

	/// <summary>
	/// Displays the queue.
	/// </summary>
	void displayQueue()const;
	//::Queue& operator=(Queue* queue);

private:
	Node* back;//pointer to rear of list
	Node* front;;//pointer to start of list
	int qty;//variable to hold number of elements
	int max;//max size of queue
};

#endif