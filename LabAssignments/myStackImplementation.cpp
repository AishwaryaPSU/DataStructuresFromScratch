#include <iostream>
using namespace std;

#define STACK_CAPACITY 10

struct node
{
    int data;
    node *link;
    node(int data, node *link)
    {
        data = data;
        link = link;
    }
};

typedef struct node *link;

class Stack
{
  public:
    Stack();
    bool push(int data);
    void pop();
    void show();

  private:
    link top;
    int size;
};

Stack::Stack()
{
    top = NULL;
    size = 0;
}

bool Stack::push(int data)
{
    if (size == STACK_CAPACITY)
    {
        cout << "Stack capacity reached. Cannot add more items" << endl;
        return false;
    }
    node *newNode = new node(data, NULL);
    newNode->link = top->link;
    top->link = newNode;
    size++;
    return true;
}
void Stack::show()
{
    link temp = top;
    cout << "Contents of the stack are: " << endl;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->link;
    }
}

int main()
{
    Stack stack;
    stack.push(1);
    stack.show();
}