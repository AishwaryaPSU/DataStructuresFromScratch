#include <iostream>
#define N 6
using namespace std;

double GT = 0;
double GQS[4] = {0};

struct SP
{
    string name;
    double QS[4];
    double total;
};

SP MyCom[N];

int main()
{
    double sum = 0;
    // srand(123); // srand(time());
    cout << "You have " << N << "salespeople with: " << endl;
    cout << "ID \t Name \t QS1 \t QS2 \t QS3 \t QS4 \t Total " << endl;
    for (int count = 0; count < N; count++)
    {
        MyCom[count].name = "Amy";
        cout << 101 + count << "\t" << MyCom[count].name << "\t";

        for (int k = 0; k < 4; k++)
        {
            MyCom[count].QS[k] = rand() % 1000;
            sum += MyCom[count].QS[k];
            cout << MyCom[count].QS[k] << "\t";
        }
        MyCom[count].total = sum;
        GT = GT + MyCom[count].total;
        cout << MyCom[count].total << endl;
    }

    for (int k = 0; k < 4; k++)
    {
        sum = 0;
        for (int cnt = 0; cnt < N; cnt++)
        {
            sum += MyCom[cnt].QS[k];
        }

        GQS[k] = sum;
    }
    cout << "Total \t \t" << GQS[0] << "\t" << GQS[1] << " \t" << GQS[2] << "\t " << GQS[3] << " \t" << endl;
}