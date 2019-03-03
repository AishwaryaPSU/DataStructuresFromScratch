#include <iostream>
#include <string>
#include <cctype>
using namespace std;
#define SIZE_OF_STRING 5
#define MAX 26

string randomName();

string city[10] = {"Commerce,TX", "San Jose,CA", "Seatlle,WA", "Plano,TX",
                   "Portland,OR", "Pheonix,AZ", "Stika,AL", "Philadelphia,PA", "New York,NY", "Baltimore,MA"};

string randomName()
{
    string resultString = "";
    char alphabetsAvailable[MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                                    'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                    'o', 'p', 'q', 'r', 's', 't', 'u',
                                    'v', 'w', 'x', 'y', 'z'};
    for (int i = 0; i < SIZE_OF_STRING; i++)
    {
        resultString = resultString + alphabetsAvailable[rand() % MAX];
    }
    resultString[0] = toupper(resultString[0]);
    return resultString;
}

int main()
{
    string name;
    cout << "Hi There!!!" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i << "th random string generated is " << randomName() << " having ID " << rand() % 9000 + 1000;
        cout << " located in " << city[i % 10] << endl;
    }
}
