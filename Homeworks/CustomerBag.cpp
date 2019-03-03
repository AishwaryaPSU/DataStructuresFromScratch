#include <iostream>
#include <string>
#include <cctype>

#define SIZE_OF_STRING 5 //this is for restricting the name of customers to one word of length 5 alphabets
#define MAX 26 //used in generating customer names
#define DATE 28//used in generating customer DOB (28 days of the months)
#define MTH 12 //used in generating the months in DOB
using namespace std;


//there are 10 city options
string city[10] = {"Commerce,TX", "San Jose,CA", "Seatlle,WA", "Plano,TX",
                   "Portland,OR", "Pheonix,AZ", "Stika,AL", "Philadelphia,PA", "New York,NY", "Baltimore,MA"};
string month[MTH] = {"Jan ", "Feb ", "Mar ", "Apr ", "May ", "Jun ",
                     "Jul ", "Aug ", "Sep ", "Oct ", "Nov ", "Dec "};//array used for the months
//array used for selecting the dates in DOB
string date[DATE] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28"};

//the following functions and data structures and variables are used in generating the unique random id's
string randomName(); 
int uniqueId[2000]={};
int idx=0;
bool isUniqueID(int id); 

//structure of the customer
struct customer
{
    string name;
    int ID;
    string DOB;
    string address;
    customer *next;
    customer(string inputName, int inputID, string inputDOB, string inputAddress)
    {
        name = inputName;
        ID = inputID;
        DOB = inputDOB;
        address = inputAddress;
    }
};
typedef struct customer *link;

class CustomerBag
{
  public:
    CustomerBag();
    bool addCustomer(int i);
    bool searchCustomerByID(int id);
    void listCustomerByAddress(string addr);
    bool removeCustomerById(int id);
    bool removeLastInsertedCustomer();
    void removeAllCustomers();
    int customerCount();
    void display();

  private:
    int numberOfCustomers;
    link first; //keeps track of the first customer node in the bag link list
    link last; //keeps track of the last customer node in the bag link list
};

void CustomerBag::removeAllCustomers()
{
    if (first == NULL)
    {
        cout << "Nothing to remove.Bag is empty" << endl;
        return;
    }
    int i = 0; //used to check and make sure all the 1000 customers in the bag are deleted
    while (first != NULL)
    {
        link temp = first;
        first = first->next;
        delete temp;
        i++;
        numberOfCustomers--;
    }
    cout << "Number of customers deleted = " << i << endl;
}

void CustomerBag::display() //display all the 1000 customers
{
    if (first == NULL)
        cout << "Bag is empty" << endl;
    link temp = first;
    int i = 1;  //used as index of all the 1000 customers in the bag link list
    while (temp != NULL)
    {
        cout << i << " Name: " << temp->name << " ID : " << temp->ID << endl;
        temp = temp->next;
        i++;
    }
}
bool CustomerBag::removeLastInsertedCustomer()
{
    if (first == NULL)
    {
        cout << "Nothing to delete.Bag is empty" << endl;
        return false;
    }
    link temp = first;
    link behindTemp = first;
    while (temp->next != NULL)
    {
        behindTemp = temp;
        temp = temp->next;
    }
    last = behindTemp;
    last->next = NULL;
    cout << temp->ID << " " << temp->name << " ->entry deleted" << endl;
    delete temp;
    numberOfCustomers--;
    return true;
}

bool CustomerBag::removeCustomerById(int id)
{
    if (first == NULL)
    {
        cout << "Bag is empty.Nothing to delete." << endl;
        return false;
    }
    if (first->ID == id)
    {
        link temp = first;
        first = first->next;
        delete temp;
        numberOfCustomers--;
        return true;
    }
    link current = first;
    link back = first;
    while (current != NULL)
    {
        if (current->ID == id)
        {
            back->next = current->next;
            delete current;
            numberOfCustomers--;
            return true;
        }
        back = current;
        current = current->next;
    }
    return false;
}

int CustomerBag::customerCount()
{
    return numberOfCustomers;
}

void CustomerBag::listCustomerByAddress(string addr)
{
    link temp = first;
    int count = 0;
    cout << "List of customers with the address " << addr << endl;
    while (temp != NULL)
    {
        if (temp->address == addr)
        {
            cout <<"Customer Name:" << temp->name << "\tCustomer Id:" << temp->ID<<endl;
            count++;
        }
        temp = temp->next;
    }
    cout << "Number of customers located in " << addr << " are " << count << endl;
}

bool CustomerBag::searchCustomerByID(int id)
{
    link temp = first;
    while (temp != NULL)
    {
        if (temp->ID == id){
            cout<<"Customer with ID "<<temp->ID<<" exits"<<endl;
            cout<<"Customer Name: "<<temp->name<<"\nCustomer DOB: "<<temp->DOB<<"\nCustomer address: "<<temp->address<<endl;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool CustomerBag::addCustomer(int i)
{
    //check to ensure at any point in time there are only 1000 customers in the bag
    if (numberOfCustomers >= 1000)
    {
        cout << "Customer count reached 1000." << endl;
        return false;
    }
    //generating the attributes of each customer randomnly
    string name = randomName();
    int custID = rand() % 9000 + 1000; //1000 is added in order to go about the random number generated between 1 and 1000 which are not 4 digits
    
    while(!isUniqueID(custID)){
        custID = rand() % 9000 + 1000;
    }
    string addr = city[i % 10];
    string dob = month[i % MTH] + date[i % DATE] + ", " + to_string(2001 + (rand() % 18));
    link newCustomer = new customer(name, custID, dob, addr);

    if (first == NULL)
    {
        first = last = newCustomer;
        numberOfCustomers=numberOfCustomers+1;
        cout<<"Number of Customer in Bag:" <<numberOfCustomers<<endl;
        return true;
    }
    last->next = newCustomer;
    last = newCustomer;
    numberOfCustomers=numberOfCustomers+1;
    cout<<"Number of Customer in Bag:" <<numberOfCustomers<<endl;
    return true;
}

CustomerBag::CustomerBag()
{
    cout<<"Customer Bag initiated. "<<endl;
    numberOfCustomers = 0;
    first = last = NULL;
}

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
    resultString[0] = toupper(resultString[0]); //converting the first letter to upper case
    return resultString;
}
//this function is used to make sure that the random number generated is not a duplicate
bool isUniqueID(int id){
    for(int i=0;i<idx;i++){
        if(uniqueId[i]==id)
            return false;
    }
    uniqueId[idx++]=id;
    return true;
}

int main()
{
    CustomerBag customerBag;
    int tempI=0;//variable used in adding customers into bag when the number is <1000
    //the following loop populates the customer bag with 1000 entries at run time.
    for (int i = 1; i <= 1000; i++)
    {
        customerBag.addCustomer(i);    
    }
    int selection;
    while (selection != 9)
    {
        cout << "(1):Add new customer "<<endl;
        cout << "(2):Search a customer with ID" << endl;
        cout << "(3):List names and IDS of the customers who are specified by an address" << endl;
        cout << "(4):Remove a customer with ID" << endl;
        cout << "(5):Remove the last inserted customer" << endl;
        cout << "(6):Remove all customers" << endl;
        cout << "(7):Number of customers in the bag" << endl;
        cout << "(8):Display Bag Contents" << endl;
        cout << "(9):Exit" << endl;
        cin >> selection;
        switch (selection)
        {
        case 1://this case helps us add customers into the bag if the count is below 1000 which may have happened due to deleting
            customerBag.addCustomer(tempI);
            tempI++;
            break;
        case 2:
            int custID;
            cout << "Enter ID of the customer to be searched : ";
            cin >> custID;
            cout << (customerBag.searchCustomerByID(custID) == 0 ? "No such Customer exists." : "") << endl;
            break;

        case 3:
            cout << "Specify the address of the customer" << endl;
            unsigned int addressIdx;
            cout << "1.Commerce,TX\n2.San Jose,CA\n3.Seatlle,WA\n4.Plano,TX\n5.Portland,OR\n6.Pheonix,AZ\n7.Stika,AL\n8.hiladelphia,PA\n9.New York,NY\n10.Baltimore,MA" << endl;
            cout << "Enter the location index: ";
            cin >> addressIdx;
            switch (addressIdx)
            {
            case 1:
                customerBag.listCustomerByAddress(city[0]);
                break;
            case 2:
                customerBag.listCustomerByAddress(city[1]);
                break;
            case 3:
                customerBag.listCustomerByAddress(city[2]);
                break;
            case 4:
                customerBag.listCustomerByAddress(city[3]);
                break;
            case 5:
                customerBag.listCustomerByAddress(city[4]);
                break;
            case 6:
                customerBag.listCustomerByAddress(city[5]);
                break;
            case 7:
                customerBag.listCustomerByAddress(city[6]);
                break;
            case 8:
                customerBag.listCustomerByAddress(city[7]);
                break;
            case 9:
                customerBag.listCustomerByAddress(city[8]);
                break;
            case 10:
                customerBag.listCustomerByAddress(city[9]);
                break;
            default:
                cout << "Wrong selection. Try again." << endl;
                break;
            }
            break;
        case 4:
            cout<<"Enter the id of the customer that you want to remove: ";
            cin >> custID;
            cout<<(customerBag.removeCustomerById(custID)==1?"Customer Successfully Removed":"No such Customer exits")<<endl;
            break;
        case 5:
            customerBag.removeLastInsertedCustomer();
            break;
        case 6:customerBag.removeAllCustomers();
            break;
        case 7:
            cout << "Number of customers in Bag = " << customerBag.customerCount() << endl;
            break;
        case 8:
            customerBag.display();
            break;
        default:
            break;
        }
    }
}