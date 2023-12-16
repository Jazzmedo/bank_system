#include <iostream>
using namespace std;
struct holder
{
    string ID;
    string name;
    string adress;
    int balance;
    holder *next;
};
struct branch
{
    string ID;
    string name;
    string manager;
    branch *next;
};
branch *head = NULL;
holder *head2 = NULL;
void InsertB(string id, string name, string manger) // Insert in the Beginning
{
    branch *temp = new branch;
    temp->ID = id;
    temp->name = name;
    temp->manager = manger;
    temp->next = head;
    head = temp;
}
void display()
{
    if (head == NULL)
        cout << "List is Empty\n";
    else
    {

        branch *temp = head;
        while (temp != NULL)
        {
            cout << temp->ID << " " << temp->name << " " << temp->manager << "\n";
            temp = temp->next;
        }
    }
}
bool search(string id)
{
    if (head == NULL)
        cout << "List is Empty\n";
    else
    {
        {
            branch *temp = head;
            while (temp != NULL)
            {
                if (temp->ID == id)
                {
                    cout << temp->ID << " " << temp->name << " " << temp->manager << " \n";
                    return true;
                }
                temp = temp->next;
            }
        }
        cout << "Handler ID not found\n";
        return false;
    }
    return false;
}
void insertBh(string idd, string namee, string adresss, int balancee = 0.0)
{
    holder *temp = new holder;
    temp->ID = idd;
    temp->name = namee;
    temp->adress = adresss;
    temp->balance = balancee;
    temp->next = head2;
    head2 = temp;
}
void displayh()
{
    if (head2 == NULL)
        cout << "List is Empty\n";
    else
    {
        holder *temp = head2;
        while (temp != NULL)
        {
            cout << temp->ID << " " << temp->name << " " << temp->adress << " " << temp->balance << "\n";
            temp = temp->next;
        }
    }
}
bool searchhN(string namee)
{
    if (head2 == NULL)
        cout << "List is Empty\n";
    else
    {
        holder *temp = head2;
        while (temp != NULL)
        {
            if (temp->name == namee)
            {
                cout << temp->ID << " " << temp->name << " " << temp->adress << " " << temp->balance << "\n";
                return true;
            }
            temp = temp->next;
        }
        cout << "Handler Name not found\n";
        return false;
    }
    return false;
}
bool searchhI(string idd)
{
    if (head2 == NULL)
        cout << "List is Empty\n";
    else
    {
        holder *temp = head2;
        while (temp != NULL)
        {
            if (temp->ID == idd)
                return true;
            temp = temp->next;
        }
        cout << "Handler ID not found\n";
        return false;
    }
    return false;
}
void updateh(string idd, string namee, string adresss, int balancee)
{
    if (head2 == NULL)
        cout << "List is Empty\n";
    else if (searchhI(idd) == false)
        return;
    else
    {
        holder *temp = head2;
        while (temp != NULL)
        {
            if (temp->ID == idd)
            {
                temp->name = namee;
                temp->adress = adresss;
                temp->balance = balancee;
                return;
            }
            temp = temp->next;
        }
    }
    return;
}
void deleteitemh(string idd)
{
    if (head2 == NULL)
        cout << "List is Empty\n";
    else if (searchhI(idd) == false)
        return;
    else
    {
        holder *temp1 = head2;
        holder *temp2 = NULL;
        if (head2->ID == idd)
        {
            head2 = head2->next;
            delete temp1;
        }
        else
        {
            while (temp1->ID != idd && temp1 != NULL)
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            temp2->next = temp1->next;
            delete (temp1);
            cout << "Item Deleted\n";
        }
    }
}
void ln()
{
    cout << "###############################################\n";
}
void rr()
{
    cout << "###############################################"
         << "\n";
    cout << "#                                             #"
         << "\n";
    cout << "#        Modern Academy CS Department         #"
         << "\n";
    cout << "#                                             #"
         << "\n";
    cout << "###############################################"
         << "\n";
    cout << "#  #####     ######     #########     ######  #"
         << "\n";
    cout << "# #     #   #      #   #         #   #      # #"
         << "\n";
    cout << "##  Joe  # # Hanafi # # AbduAllah # #  Ziad  ##"
         << "\n";
    cout << "# #     #   #      #   #         #   #      # #"
         << "\n";
    cout << "#  #####     ######     #########     ######  #"
         << "\n";
}
void abdo()
{
    ln();
    cout << "Enter '1' to Add new branch.\n";
    cout << "Enter '2' to Display Branch.\n";
    cout << "Enter '3' to Search for Branch by ID.\n";
    cout << "Enter '4' to Add new Holder.\n";
    cout << "Enter '5' to Remove a Holder.\n";
    cout << "Enter '6' to Display Holder data.\n";
    cout << "Enter '7' to Search for Holder by Name.\n";
    cout << "Enter '8' to Update Holder Information.\n";
    cout << "Enter 'x' to Exit.\n";
    ln();
}
int main()
{
    rr();
    string id, manager, name, address;
    int balance = 0;
    while (true)
    {
        abdo();
        char x;
        cout << "Enter the number of the process : ";
        cin >> x;
        switch (x)
        {
        case '1'://Add new branch
            cout << "Enter Branch's ID : ";
            cin >> id;
            cout << "Enter Branch's Name : ";
            cin >> name;
            cout << "Enter Branch's Manager : ";
            cin >> manager;
            InsertB(id, name, manager);
            break;
        case '2': //Display Branch
            display();
            break;
        case '3'://Search for Branch by ID
            cout << "Enter Branch's ID : ";
            cin >> id;
            search(id);
            break;
        case '4'://Add new Holder
            cout << "Enter Holder's ID : ";
            cin >> id;
            cout << "Enter Holder's Name : ";
            cin >> name;
            cout << "Enter Holder's Address : ";
            cin >> address;
            cout << "Enter Holder's Balance : ";
            cin >> balance;
            insertBh(id, name, address, balance);
            break;
        case '5'://Remove a Holder
            cout << "Enter Holder's ID : ";
            cin >> id;
            deleteitemh(id);
            break;
        case '6'://Display Holder data
            displayh();
            break;
        case '7'://Search for Holder by Name
            cout << "Enter Holder's Name : ";
            cin >> name;
            searchhN(name);
            break;
        case '8'://Update Holder Information
            cout << "Enter Holder's ID : ";
            cin >> id;
            cout << "Enter Holder's Name : ";
            cin >> name;
            cout << "Enter Holder's Address : ";
            cin >> address;
            cout << "Enter Holder's Balance : ";
            cin >> balance;
            updateh(id, name, address, balance);
            break;
        case 'x'://exit
            return 0;
            break;
        default:
            cout << "Error! Try Again : ";
            break;
        }
    }
    return 0;
}