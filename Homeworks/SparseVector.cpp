#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <unistd.h> // From http://cs.dvc.edu/HowTo_CSleep.html

using namespace std;

const int SIZE = 1000;
// A struct to keep items
struct item
{
    unsigned int index;
    int data;
    item *next;
};
// Maintains index,data association for the vector. Indexes are kept ordered.
class Vector
{
public:
    Vector();                                   // Construction
    bool add(unsigned int index, int data);		// Adds a new item to vector
    void ListAll();                             // List all items of vector, starting with the first ITEM
	unsigned short getSize();						// returns the size of the vector
	void setSize(unsigned int size);
    Vector operator * (Vector&);
	item *getFirst(); 		// returns the pointer, "first"

private:
    item *first;					// A pointer to show the first node
    item *last;                     // A pointer to show the last node
    unsigned short size;			// how many items vector has
    unsigned short compSize;		// non-zero items vector has
};

// Initialize the class
Vector::Vector()
{
    first = last = NULL;
    size = 0 ;
}

unsigned short Vector::getSize()
{
		return size;
}

item * Vector::getFirst()
{
	return first;
}

void Vector::ListAll()                             // List all items of vector, starting with the first ITEM
{
    item *it = first;
    int  cnt = 0;

    while (it != NULL ) {

        while (cnt < it->index)
        {
            cout << cnt << ":0 \t" ;
            cnt++;
        }
        cout << it->index << ":";
        cout << it->data << "\t";
        it = it->next;
        cnt++;
    }
    cout << endl;
}

Vector Vector::operator* (Vector &param) {
  Vector productVector;
  if (size != param.size) cout << " Something is wrong ..." << endl;
  cout << " Same size vectors found, getting product vector now..." << endl;
  item *itA = first;
  item *itB = param.getFirst();

while (itA != NULL || itB != NULL )
  {
      if (itA != NULL && itB != NULL )
      {
		  if (itA->index < itB->index)
		  {
             // cout <<" A index < B index =>"<< itA->data << " " <<itB->data<<" "<<endl ;
              //cout <<"A index: "<<itA->index<<" B index:"<<itB->index<<endl;
              productVector.add(itA->index, 0);
			  itA = itA->next;
		  }
		  else if (itA->index > itB->index)
		  {
              //cout <<" A index > B index =>"<< itA->data << " " <<itB->data<<" "<<endl ;
              //cout <<"A index: "<<itA->index<<" B index:"<<itB->index<<endl;
			  productVector.add(itB->index, 0 );
			  itB = itB->next;
		  }
		  else
		  {	  
              //cout <<" A index = B index =>"<< itA->data << " " <<itB->data<<" "<<endl ;
              //cout <<"A index: "<<itA->index<<" B index:"<<itB->index<<endl;
			  productVector.add(itA->index, itB->data * itA->data  );
			  itA = itA->next;
			  itB = itB->next;
		  }
      }
      else  if (itA != NULL )
      {
			  productVector.add(itA->index, 0 );
			  itA = itA->next;
      }
      else if  (itB != NULL )
      {
       
			  productVector.add(itB->index, 0 );
			  itB = itB->next;
      }
  }
  productVector.setSize(size);

  return productVector;
}

void Vector::setSize(unsigned int size)
{
	this->size = size;
}

bool Vector::add(unsigned int index, int data)		// Adds a new item to Vector, to the end
{
    item *NewItemPtr = new item;			//  dynamically create a new struct/item
    if ( NewItemPtr == NULL) return false;  // not enought memory

    NewItemPtr->index = index;  				// we append, add to end of list
    NewItemPtr->data = data;
    NewItemPtr->next = NULL;
    compSize++;
	//size=index+1;

    if ( last == NULL) 					// first item to be added
    {
        first = last = NewItemPtr;
    }
    else
    {
        last->next = NewItemPtr;
        last = NewItemPtr;
    }
    return true;	// added.
}

int main(int argc, const char * argv[])
{
    Vector A,B, ProductVector;
    int locA = 0, locB = 0 ;
    int data = 0;
    for (int i=0; i< 5; i++) // adds 20 items.
        {
            locA = locA + rand() % 3 + 1;
            data = rand() % 50 + 30;
            A.add(locA, data);

			locB = locB + rand() % 3 + 1;
            data = rand() % 50 + 30;
            B.add(locB, data);
        }

	//A.add(locA+1, 0);
	//B.add(locA+1, 0);
	A.setSize(10);
	B.setSize(10);
    A.ListAll(); cout << A.getSize() << " items found..." << endl;
	B.ListAll(); cout << B.getSize() << " items found..." << endl;
    cout<<"=========================="<<endl;
    ProductVector = A * B;
    ProductVector.ListAll(); cout << ProductVector.getSize() << " items found..." << endl;
}
