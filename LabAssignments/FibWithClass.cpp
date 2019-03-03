#include <iostream>

using namespace std;

#define SIZE 30

class Fibonacci
{
  public:
    Fibonacci();
    void push(int n);
    unsigned int pop();
    unsigned int fibonacciNumber(int n);

  private:
    unsigned int *fib;
    int top;
};

Fibonacci::Fibonacci()
{
    fib = new unsigned int[SIZE];
    top = -1;
}

void Fibonacci::push(int n)
{
    if (top != SIZE)
    {
        fib[++top] = n;
        return;
    }
    cout << "Stack is full" << endl;
}

unsigned int Fibonacci::pop()
{
    if (top != -1)
        return fib[top--];
    return -1;
}

unsigned int Fibonacci::fibonacciNumber(int n)
{
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;
    return fibonacciNumber(n - 1) + fibonacciNumber(n - 2);
}

int main()
{
    Fibonacci fibonacci;
    for (int i = 0; i < SIZE; i++)
    {
        fibonacci.push(fibonacci.fibonacciNumber(i));
    }
    for (int i = 0; i < SIZE; i++)
    {
        cout << "The number popped out is : " << fibonacci.pop() << endl;
    }
}
