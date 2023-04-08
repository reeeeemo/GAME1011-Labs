#include "DynamicStack.h"
#include "DynamicQueue.h"
#include "Pancake.h"

#include <iostream>

// Const variables :D
constexpr int MAX_PANCAKES = 5;

// Prototypes
void CookPancakes(DynamicStack<Pancake> &pancakes);


int main()
{
	DynamicStack<Pancake> pancakes;
	CookPancakes(pancakes);

	for (int i = 0; i < MAX_PANCAKES; i++)
	{
		pancakes.Pop().OutputPancake();
	}
	return 0;
}

// Cooks pancakes based on the max pancakes constant.
void CookPancakes(DynamicStack<Pancake> &pancakes)
{
		// Cook will cook some pancakes for us!
		for (int i = 0; i < MAX_PANCAKES; i++)
		{
			pancakes.Push(Pancake());
		}
}

