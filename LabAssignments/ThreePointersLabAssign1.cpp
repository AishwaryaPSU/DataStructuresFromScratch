#include <iostream>

using namespace std;

void testFunction(short x, short *A, short *B, short *C, short testCaseNumber);

int main()
{
    short x = 9;
    short *A = &x;
    short *B = &x;
    short *C = &x;

    testFunction(x, A, B, C, 1);
    x += 5;
    testFunction(x, A, B, C, 2);
}

void testFunction(short x, short *A, short *B, short *C, short testCaseNumber)
{
    short LHS = 3 * x;
    short RHS = (*A) + (*B) + (*C);
    if (LHS == RHS)
    {
        cout << "LHS value = " << LHS << endl;
        cout << "RHS value = " << RHS << endl;
        cout << "Test case " << testCaseNumber << " Passed!!!" << endl;
    }
    else
    {
        cout << "LHS value = " << LHS << endl;
        cout << "RHS value = " << RHS << endl;
        cout << "Test case " << testCaseNumber << " Failed!!!" << endl;
    }
}
