#include "DynamicStack.h"
#include "DynamicQueue.h"
#include "Pancake.h"
#include "CustomExceptions.h"

#include <iostream>
#include <cstdlib>


// Const variables :D
constexpr int MAX_PANCAKES = 5;
constexpr int MAX_CUSTOMERS = 30;

// Prototypes
void CookPancakes(DynamicStack<Pancake>& pancakes);
void AddCustomers(DynamicQueue<Customer>& customers);
int GetRandomInt();

int main()
{
	// rand() initializer
	srand(time(nullptr));

	// Variables!
	DynamicQueue<Customer> customers;
	DynamicStack<Pancake> pancakes;
	int numOfPancakes;
	int customerCount = 1;

	// Cooking pancakes and adding customers to the queue!
	CookPancakes(pancakes);
	AddCustomers(customers);


	// Ssssshowtime!
	while (!customers.IsEmpty())
	{
		system("CLS");
		std::cout << "Looks like there is a new customer! Welcome to Pancake Paradise!\n\n";
		std::cout << "You are customer " << customerCount << " of " << MAX_CUSTOMERS << "!\n\n";
		bool isValid = false;
		do
		{
			std::cout << "How many pancakes for you? (max 3): ";
			std::cin.clear(); // Clearing input buffer
			std::cin >> numOfPancakes;
			if (numOfPancakes == 0 || numOfPancakes == 1 || numOfPancakes == 2 || numOfPancakes == 3)
			{
				isValid = true;
			} else
			{
				std::cout << "\nInvalid input. Please type number between 0-3!\n";
			}
		} while (!isValid);

		if (numOfPancakes == 0) // Make a funky little message!
		{
			std::cout << "\nYou.... Came to a pancake shop... And did not order any pancakes? Death to you.\n";
		} else
		{
			std::cout << "\nAlright! " << numOfPancakes << " of pancakes coming right up!\n";
		}

		for (int i = 0; i < numOfPancakes; i++)
		{
			try
			{
				if (pancakes.IsEmpty())
				{
					throw OutOfPancake{};
				}
			} catch (OutOfPancake& error)
			{
				std::cout << error.what() << std::endl;

				CookPancakes(pancakes);
			}

			pancakes.Pop().OutputPancake();
		}

		customerCount++;
		customers.Dequeue().ExitCustomer();
		system("pause");
	}

	std::cout << "\n\n All closed! Thank you for visiting Pancake Paradise! :D\n";
	return 0;
}

// Cooks pancakes based on the max pancakes constant. Will randomly have butter or/and syrup on them.
void CookPancakes(DynamicStack<Pancake> &pancakes)
{
		// Cook will cook some pancakes for us!
		for (int i = 0; i < MAX_PANCAKES; i++)
		{
			pancakes.Push(Pancake(static_cast<bool>(GetRandomInt()), static_cast<bool>(GetRandomInt())));
		}
}

void AddCustomers(DynamicQueue<Customer>& customers)
{
	// Add all the customers in the queue!
	for (int i = 0; i < MAX_CUSTOMERS; i++)
	{
		customers.Enqueue(Customer());
	}
}

int GetRandomInt()
{
	return rand() % 2;
}