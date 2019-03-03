#include <iostream>

using namespace std;

struct student
{
    string name;
    int id;
    string phone;
};

int main()
{
    student A;
    A.name = "Amy";
    A.id = 1;
    A.phone = "1-2-3";

    student *ptr = NULL;
    ptr = &A;

    cout << "Name of A is " << (*ptr).name << endl;
    cout << "Id of A is " << (*ptr).id << endl;
    cout << "Phone number of A is " << (*ptr).phone << endl;

    cout << "Name of A is " << ptr->name << endl;
    cout << "Id of A is " << ptr->id << endl;
    cout << "Phone number of A is " << ptr->phone << endl;

    cout << "Pointers with Arrays " << endl;
    int B[5] = {7, 2, 3, 9, 1};

    cout << "B[0] is = " << B[0] << endl;
    int *C = NULL;
    C = B;
    cout << "C[0] is = " << C[0] << endl;

    for (int cnt = 0; cnt < 5; cnt++)
    {
        cout << B[cnt] << " , ";
    }

    int row = 4;
    int col = 3;
    int **D = new int *[row];

    // for (int j = 0; j < row; j++)
    // {

    //     D[j] = new int[col];
    // }
    for (int j = 0; j < row; j++)
    {
        for (int k = 0; j < col; k++)
        {
            D[j][k] = rand() % 100;
            cout << D[j][k] << ", ";
        }
        cout << endl;
    }
}