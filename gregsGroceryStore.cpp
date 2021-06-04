/**
 * @FileName gregsGroceryStore.cpp
 * @Details build a grocery store simulation using a queue ADT as the base
 * @Author Ryan Zurrin
 * @DateBuilt  3/2/2021
 * @DueDate 3/4/2021
 */
#include "Queue.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void displayGroceryLines(Queue* q[]);
int generateItems();
void delayTime();
void checkoutCustomers(Queue* q[]);
int findFullestCartAtRegister(Queue* q[]);

static int customersTotal = 0;
static int globaltimeKeeper = 0;
const int MIN_CHANCE = 1;
const int MAX_CHANCE = 10;
const int MIN_ITEMS = 1;
const int MAX_ITEMS = 100;

int main()
{
	unsigned long seed = time(0);
	srand(seed);
	int totalCustomers, items, lineNumber, shortestLine;
	Queue* lines[5];
	lines[0] = new Queue();
	lines[1] = new Queue();
	lines[2] = new Queue();
	lines[3] = new Queue();
	lines[4] = new Queue();

	for (; globaltimeKeeper <= 180; globaltimeKeeper++)
	{

		shortestLine = lines[0]->getQty();
		lineNumber = 0;
		if (globaltimeKeeper < 165)
		{
			totalCustomers = (rand() % (MAX_CHANCE - MIN_CHANCE + 1))
						   + MIN_CHANCE;
			if (totalCustomers >= 1 && totalCustomers <= 4) {}//generating 0 customers
			if (totalCustomers >= 5 && totalCustomers <= 8)//generating 1 customer
			{
				for (int i = 0; i <= 4; i++)
				{
					if (lines[i]->getQty() < shortestLine)
					{
						shortestLine = lines[i]->getQty();
						lineNumber = i;
					}
				}
				//findShortestLine(lines, lineNumber);
				items = generateItems();
				lines[lineNumber]->enQueue(items);
				displayGroceryLines(lines);
				delayTime();
			}
			if (totalCustomers >= 9)//generating 2 customers
			{
				for (int i = 0; i <= 4; i++)
				{
					if (lines[i]->getQty() < shortestLine)
					{
						shortestLine = lines[i]->getQty();
						lineNumber = i;
					}
				}
				//findShortestLine(lines, lineNumber);
				items = generateItems();
				lines[lineNumber]->enQueue(items);
				displayGroceryLines(lines);
				delayTime();

				shortestLine = lines[0]->getQty();
				lineNumber = 2;
				for (int i = 4; i > 0; i--)
				{
					if (lines[i]->getQty() < shortestLine)
					{
						shortestLine = lines[i]->getQty();
						lineNumber = i;
					}
				}
				//findShortestLine(lines, lineNumber);
				items = generateItems();
				lines[lineNumber]->enQueue(items);
				displayGroceryLines(lines);
				delayTime();
			}
			//displayGroceryLines(store);
			delayTime();
		}
		if ((globaltimeKeeper % 3 == 0 && globaltimeKeeper > 5 )||
				 globaltimeKeeper > 165)
		{
			checkoutCustomers(lines);
			//displayGroceryLines(store);
			delayTime();
		}
	}

	lines[0] = NULL;
	lines[1] = NULL;
	lines[2] = NULL;
	lines[3] = NULL;
	lines[4] = NULL;
	delete lines[0];
	delete lines[1];
	delete lines[2];
	delete lines[3];
	delete lines[4];

	return 0;
}

/// <summary>
/// Displays the grocery lines.
/// </summary>
/// <param name="lines">The lines array pointer.</param>
void displayGroceryLines(Queue* q[])
{
	system("CLS");
	for (int i = 0; i <= 4; i++)
	{
		cout << "CheckOut line " << i+1 << " ";
		q[i]->displayQueue();
	}
	if(globaltimeKeeper<180){
				std::cout << "\ntime: " << globaltimeKeeper<<", customers today: "
									<< customersTotal;
	}
	else
		std::cout << "\nCLOSED "<< endl<<"Customers today: "
									<< customersTotal << endl;

}//end function displayGroceryLines

int generateItems()
{
	return (rand() % (MAX_ITEMS - MIN_ITEMS + 1)) + MIN_ITEMS;
}//end function generateItems

/// <summary>
/// Delays the time.
/// </summary>
void delayTime()
{
	for (double  delay = 0; delay <= 200000000; delay++){}
}

/// <summary>
/// Finds the fullest cart at register.
/// </summary>
/// <param name="q">The q.</param>
/// <returns></returns>
int findFullestCartAtRegister(Queue* q[])
{
	int mostItems, temp;
	q[0]->peek(mostItems);
	int lineNumber = 0;
	for (int i = 0; i <= 4; i++)
	{
		q[i]->peek(temp);
		if (temp > mostItems)
		{
			mostItems = temp;;
			lineNumber = i;
		}
	}
	return lineNumber;
}

/// <summary>
/// Checkouts the customers.
/// </summary>
/// <param name="q">The q.</param>
void checkoutCustomers(Queue* q[])
{
	int totalItems, counted;
	counted = 0;
	int toCheckout = findFullestCartAtRegister(q);
	q[toCheckout]->deQueue(totalItems);
	displayGroceryLines(q);
	if(totalItems>0){customersTotal++;}
	delayTime();
	for (int i = totalItems*1000; i > 0; i--){}
	while ((totalItems<50 && counted < 3))
	{
		toCheckout = findFullestCartAtRegister(q);
		q[toCheckout]->deQueue(totalItems);
		if(totalItems>0){customersTotal++;}
		displayGroceryLines(q);
		//std::cout << "checking out line: "<< toCheckout;
		delayTime();
		counted++;
		for (int i = totalItems*100; i > 0; i--){}
	}
	if (globaltimeKeeper>160)
	{
		toCheckout = findFullestCartAtRegister(q);
		q[toCheckout]->deQueue(totalItems);
		if(totalItems>0){customersTotal++;}
		displayGroceryLines(q);
		for (int i = totalItems*1000; i > 0; i--){}
	}

}
