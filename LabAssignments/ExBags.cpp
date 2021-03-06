// Mutlu Mete
// Bag implementation using a dynamically allocated mem space (NOT LINKED LIST)

// To Be completed in the class

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <limits> //library which provides the minimum and maximum values of types
#define BAG_CAPACITY 20;
using namespace std;

class BagDyn
{
  public:
	BagDyn();					// construction
	bool Add(int n);			// Add, true if successfully added
	bool Remove(int n);			// Removes an item from the bag
	unsigned int getCapacity(); // return the capacity, the max number of items to be held
	unsigned int getSize();		// current number of items in the bag
	bool Search(int s);			// search for an item
	bool isEmtpy();				// Checks if the bag is empty
	void ListAll();				// displays all items of the bag
	int minOfItems();			// returns the minimum element in the bag
	int maxOfItems();			//returns the maximum element in the bag
	BagDyn copy(BagDyn bag);	//returns a copy of the provided bag

  private:
	int *data;
	unsigned int size;
	unsigned int capacity;
};

BagDyn::BagDyn() // construction
{
	data = NULL;
	capacity = BAG_CAPACITY;
	size = 0;
	data = new int[capacity];
	if (data == NULL)
	{
		cout << "An error occured, bag cannot be allocated" << endl;
	}
	else
	{
		//cout << data;
		cout << "A bag to keep " << capacity << " items is created and ready to use" << endl;
	}
}

int BagDyn::minOfItems()
{
	//int min = std::numeric_limits<int>::max();
	int min = data[0];
	for (int i = 1; i < size; i++)
	{
		if (data[i] < min)
		{
			min = data[i];
		}
	}
	return min;
}

int BagDyn::maxOfItems()
{
	int max = data[0];
	for (int i = 1; i < size; i++)
	{
		if (data[i] > max)
		{
			max = data[i];
		}
	}
	return max;
}
BagDyn BagDyn::copy(BagDyn bag)
{
	BagDyn newBag;
	newBag.data = bag.data;
	newBag.size = bag.size;
	newBag.capacity = bag.capacity;
	return newBag;
}

// returns the capacity, the max number of items to be held
unsigned int BagDyn::getCapacity()
{
	return capacity;
}

// number of items in the bag
unsigned int BagDyn::getSize()
{
	return size;
}

// search for an item
bool BagDyn::Search(int s)
{
	for (int i = 0; i < size; i++) // i < size   or i <= (size-1)
	{
		if (data[i] == s)
			return true;
	}
	return false;
}

// Checks if the bag is empty
bool BagDyn::isEmtpy()
{
	if (size == 0)
		return true;
	return false;
}

// Adds an items, true if successfully added
bool BagDyn::Add(int n)
{
	if (size == capacity)
		return false; // no more space, it is full

	for (int i = 0; i < size; i++) // i < size   or i <= (size-1) // check or duplicate entry
	{
		if (data[i] == n)
			return false;
	}
	// data[size] = n; size++;
	data[size++] = n;
	return true;
}

// displays all items of the bag
void BagDyn::ListAll()
{
	if (size == 0)
	{
		cout << "Bag is empty" << endl;
		return;
	}

	for (int i = 0; i < size; i++) // i < size   or i <= (size-1)
	{
		if (i == size - 1)
			cout << data[i];
		else
			cout << data[i] << ", ";
	}
	cout << endl;
}

// Removes an item from the bag
bool BagDyn::Remove(int n)
{
	if (isEmtpy() == true)
		return false;

	for (int i = 0; i < size; i++) //  search for the item
	{
		if (data[i] == n)
		{
			data[i] = data[--size];
			return true;
		}
	}
	return false;
}

// Demonstrate the usage of the bag
int main()
{
	BagDyn aBag;

	aBag.ListAll();
	aBag.Add(5);
	aBag.Add(7);
	aBag.Add(1);
	aBag.ListAll();
	aBag.Add(8);
	aBag.Add(17);
	aBag.Add(5);
	aBag.ListAll();
	// Write a loop to insert 10 integers in a loop.

	if (aBag.Search(8) == true)
		cout << "8 is in the bag" << endl;
	if (aBag.Search(17) == true)
		cout << "17 is in the bag" << endl;
	if (aBag.Search(3) == true)
		cout << "3 is in the bag" << endl;
	else
		cout << " 3 is not in the bag" << endl;

	aBag.Remove(17);
	aBag.ListAll();
	aBag.Remove(5);
	aBag.ListAll();
	cout << "Size of the bag is " << aBag.getSize() << endl;
	cout << "The minimum element in the bag is = " << aBag.minOfItems() << endl;
	cout << "The maximum element in the bag is = " << aBag.maxOfItems() << endl;
	BagDyn newBag = aBag.copy(aBag);
	cout << "Copy of the existing bag created!!" << endl;
	cout << "Contents of new Bag are :" << endl;
	newBag.ListAll();
	cout << "Size of new Bag is :" << newBag.getSize() << endl;
	cout << "Capacity of new Bag is :" << newBag.getCapacity() << endl;
	//system("pause");
}
