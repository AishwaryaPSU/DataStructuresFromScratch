
#include <iostream>
using namespace std;
struct item
{
    string data;
    item *next;
    item(string x, item *t)
    {
        data = x;
        next = t;
    }
};

//Complete the following function to add an item to Linked Listed using only "first" pointer

bool Bag::add(string str)
{
    item AddItem = new item(str,NULL);			//  dynamically create a new struct/item
    //if ( AddItem == ??) return false; 		// not enought memory
    item *temp = NULL;
    temp=first;
    while(temp->next != null)
    {
        temp = temp->link;
    }
    temp = AddItem;
	size++;
    return true;	// added.
}
