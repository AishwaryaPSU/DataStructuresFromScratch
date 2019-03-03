#include <iostream>
using namespace std;
#define SIZE 30

void push(int n);
unsigned int pop();

unsigned int *fib = new unsigned int[SIZE];
int top = -1;

void push(int n)
{
    if (top != SIZE)
    {
        fib[++top] = n;
    }
}
int fibonacciNum(int n)
{

    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    return fibonacciNum(n - 1) + fibonacciNum(n - 2);
}

unsigned int pop()
{
    if (top != -1)
    {
        return fib[top--];
    }
    return -1;
}

int main()
{
    for (int i = 0; i < SIZE; i++)
    {
        push(fibonacciNum(i));
    }
    for (int i = 0; i < SIZE; i++)
    {
        cout << "value poped out of stack is : " << pop() << endl;
    }
}