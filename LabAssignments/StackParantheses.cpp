#include <iostream>
#include<string>
#define MAX_STACK_SIZE 50

using namespace std;
bool isOpposite(char a, char b);
struct node
{
    char data;
    struct node *next;
    node(char a, node *b)
    {
        data = a;
        next = b;
    }
};
typedef node *link;

class StackParantheses
{
  public:
    StackParantheses();
    bool push(char data);
    void pop();
    char getTop();
    bool isEmpty();

  private:
    link top;
    link head;
    int sizeOfStack;
};

StackParantheses::StackParantheses()
{
    head = top = NULL;
    sizeOfStack = 0;
}
char StackParantheses::getTop()
{
    if(top == NULL)
        return '\0';
    return top->data;
}

bool StackParantheses::push(char data)
{
    if (sizeOfStack >= MAX_STACK_SIZE)
    {
        cout << "Maximum Capacity reached. Cannot add more element\n";
        return false;
    }
    link newNode = new node(data, NULL);
    if (newNode == NULL)
        return false;

    if (top == NULL)
    {
        head = top = newNode;
        sizeOfStack++;
        return true;
    }
    top->next = newNode;
    top = newNode;
    sizeOfStack++;
    return true;
}

void StackParantheses::pop()
{
    if (top == NULL)
    {
        cout << "Stack is empty.\n";
        return;
    }
    if(head == top){
        head = top = NULL;
        sizeOfStack--;
        return;
    }
    link temp = head;
    while (temp->next != top)
    {
        temp = temp->next;
    }
    top = temp;
    //temp = temp->next;
    //delete temp;
    top->next = NULL;
    sizeOfStack--;
}
bool StackParantheses::isEmpty(){
    return (sizeOfStack == 0);
}

int main()
{
    StackParantheses sp;
    string inputString;
    cout << "Enter the string of parantheses\n";
    cout << "Options to choose from are:\n";
    cout << "[,],{,},(,),<, and >\n";
    //using the inbuilt function get line
    getline(cin,inputString);
    cout<<"The string you entered is: "<<inputString<<endl;
    string substring = " ";
    if (inputString.find(substring) != std::string::npos) {
        std::cout << "Empty space is not allowed in the string. Please try again\n";
        return -1;
    }
    for (int i = 0; i < inputString.length(); i++)
    {
        char topOfStack = sp.getTop();
        //cout<<"Top of Stack: "<<topOfStack<<"\tInput String["<<i<<"]: "<<inputString[i]<<endl;
        if (isOpposite(topOfStack, inputString[i]))
            sp.pop();
        else
            sp.push(inputString[i]);
    }
    cout<<((sp.isEmpty()==0)?"False":"True")<<endl;
}

bool isOpposite(char a, char b)
{
    if (a == '[' && b == ']')
        return true;
    if (a == '(' && b == ')')
        return true;
    if (a == '{' && b == '}')
        return true;
    if (a == '<' && b == '>')
        return true;
    return false;
}
