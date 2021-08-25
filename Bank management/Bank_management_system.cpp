#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

typedef struct Account
{
    int Accountnum;
    string name;
    int dd, mm, yyyy;
    int openingbal;
    int pin;
    struct Account *next;
    bool atm_active;
} account;

account *head = NULL;

void Add_account()
{
    account *temp;
    if (head == NULL)
    {
        head = new account;
        cout << "---------------Account Application form---------------------" << endl;
        cout << "Account No. (10 digits): ";
        cin >> head->Accountnum;
        cout << "Account Holder : ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, head->name, '\n');
        cout << "Date of Birth(dd/mm/yyyy) : ";
        cin >> head->dd >> head->mm >> head->yyyy;
        // cout<<"Phone No. : ";
        // cin>>head->phonenum;
        cout << "Opening Balance : ";
        cin >> head->openingbal;
        cout << "Pin (4 digits): ";
        cin >> head->pin;
        head->atm_active = false;
        head->next = NULL;
        temp = head;
        temp->next = NULL;
    }
    else
    {
        account *node1 = new account;
        cout << "---------------Account Application form---------------------" << endl;
        cout << "Account No. (10 digits): ";
        cin >> node1->Accountnum;
        cout << "Account Holder : ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, node1->name, '\n');
        cout << "Date of Birth(dd/mm/yyyy) : ";
        cin >> node1->dd >> node1->mm >> node1->yyyy;
        cout << "Opening Balance : ";
        cin >> node1->openingbal;
        cout << "Pin (4 digits): ";
        cin >> node1->pin;
        node1->atm_active = false;
        node1->next = NULL;
        temp->next = node1;
        temp = node1;
    }
}

void Delete_account()
{
    account *p = head;
    account *q = head->next;
    int pin, acc_num;
    cout << "Enter account number : ";
    cin >> acc_num;
    cout << "Enter pin : ";
    cin >> pin;
    while ((acc_num != p->Accountnum) && (p != NULL))
    {
        p = p->next;
        q = q->next;
        if (p == NULL)
        {
            cout << "Invalid Credentials!!!\n";
        }
    }
    if (pin == p->pin)
    {
        p->next = q->next;
        q->next = NULL;
        free(q);
        cout << "Account deleted Successfully!!!\n";
    }
    system("pause");
}

void display_acc()
{
    int acc_num;
    cout << "Enter account number : ";
    cin >> acc_num;
    account *ptr = head;
    while ((ptr->Accountnum != acc_num) && (ptr != NULL))
    {
        ptr = ptr->next;
        if (ptr == NULL)
        {
            cout << "Account Does not exist!!!\n";
        }
    }
    if (acc_num == ptr->Accountnum)
    {
        cout << "---------------Account Information---------------------" << endl;
        cout << "Account No. : " << ptr->Accountnum << endl;
        cout << "Account Holder : " << ptr->name << endl;
        cout << "Date of Birth(dd/mm/yyyy) : " << ptr->dd << "/" << ptr->mm << "/" << ptr->yyyy << endl;
        cout << "Balance : " << ptr->openingbal << endl
             << endl;
    }

    system("pause");
}

void deposit()
{
    account *ptr = head;
    int acc_num;
    cout << "Enter account number : ";
    cin >> acc_num;
    while ((ptr->Accountnum != acc_num) && ptr != NULL)
    {
        ptr = ptr->next;
    }
    int pin;
    cout << "Enter pin : ";
    cin >> pin;
    if (pin == ptr->pin)
    {
        int amt;
        cout << "Enter amount : ";
        cin >> amt;
        ptr->openingbal += amt;
    }
    else
    {
        cout << "Invalid Pin" << endl;
        system("pause");
    }
}

void withdraw()
{
    account *ptr = head;
    int acc_num;
    cout << "Enter account number : ";
    cin >> acc_num;
    while ((ptr->Accountnum != acc_num) && ptr != NULL)
    {
        ptr = ptr->next;
    }
    int pin;
    int val = ptr->openingbal;
    cout << "Enter pin : ";
    cin >> pin;
    if (pin == ptr->pin)
    {

        int amt;
        cout << "Enter amount : ";
        cin >> amt;
        if (amt > val)
        {
            cout << "Not Sufficient Balance!!!" << endl;
            system("pause");
        }
        else
        {
            ptr->openingbal -= amt;
        }
    }
    else
    {
        cout << "Invalid Pin!!!";
        system("pause");
    }
}

void search()
{
    account *ptr = head;
    int acc_num;
    cout << "Enter account number : ";
    cin >> acc_num;
    while ((ptr->Accountnum != acc_num) && ptr != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->Accountnum != acc_num)
    {
        cout << "Account Does not Exist!!!" << endl;
        system("pause");
    }
    else
    {
        cout << "---------------Account Information---------------------" << endl;
        cout << "Account No. : " << ptr->Accountnum << endl;
        cout << "Account Holder : " << ptr->name << endl;
        cout << "Date of Birth(dd/mm/yyyy) : " << ptr->dd << "/" << ptr->mm << "/" << ptr->yyyy << endl;
        cout << "Balance : " << ptr->openingbal << endl;
        system("pause");
    }
}

void activate_atm()
{
    account *ptr = head;
    int acc_num;
    cout << "Enter account number : ";
    cin >> acc_num;
    while ((ptr->Accountnum != acc_num) && ptr != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->atm_active == 1)
        cout << "Current Status : Active" << endl;
    else
        cout << "Current Status : Inactive" << endl;

    cout << "Enter 1 : For Activating\n      2 : For Deactivating\n";
    cin >> ptr->atm_active;
}

void transfer()
{
    account *acc1 = head;
    account *acc2 = head;
    int sender, receiver, pin;
    cout << " Account number (Sender) : ";
    cin >> sender;
    cout << " Account number (Reciever) : ";
    cin >> receiver;
    while ((acc1->Accountnum != sender) && (acc1 != NULL))
    {
        acc1 = acc1->next;
    }
    while ((acc2->Accountnum != receiver) && (acc2 != NULL))
    {
        acc2 = acc2->next;
    }
    cout << "Enter pin (sender) : ";
    cin >> pin;
    if (pin == acc1->pin)
    {
        int amt;
        cout << "Enter amount : ";
        cin >> amt;
        acc1->openingbal -= amt;
        acc2->openingbal += amt;
    }
    else
        cout << "Invalid Pin!!!\n";

    system("pause");
}

void pin_change()
{
    account *ptr = head;
    int acc_num;
    cout << "Enter account number : ";
    cin >> acc_num;
    while ((ptr->Accountnum != acc_num) && ptr != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->atm_active == 1)
    {

        cout << "Enter current pin : ";
        int pin;
        cin >> pin;
        if (pin == ptr->pin)
        {
            cout << "Enter new pin : ";
            cin >> ptr->pin;
        }
        else
        {
            cout << "Invalid Pin\n";
        }
    }
    else
        cout << "ATM Service Not Activated!!!\n";

    system("pause");
}

void display_balance()
{
    account *ptr = head;
    int acc_num;
    cout << "Enter account number : ";
    cin >> acc_num;
    while ((ptr->Accountnum != acc_num) && ptr != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->atm_active == 1)
        cout << "Balance : " << ptr->openingbal << " Rs " << endl;
    else
        cout << "ATM Service Not Activated!!!\n";

    system("pause");
}

void update_info()
{
    account *ptr = head;
    int acc_num;
    cout << "Enter account number : ";
    cin >> acc_num;
    while ((acc_num != ptr->Accountnum) && (ptr != NULL))
    {
        ptr = ptr->next;
    }
    int ch;
    cout << "What do you want to update?  ";
    cout << "1. Name                                 2.DOB\n";
    cout << "Enter choice : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        cout << "Enter new name : ";
        cin >> ptr->name;
        break;

    case 2:
        cout << "Enter DOB(dd/mm/yyyy) : ";
        cin >> ptr->dd >> ptr->mm >> ptr->yyyy;
        break;

    default:
        break;
    }
}

class Bank
{
public:
    void bank_menu()
    {
        system("cls");
        system("color B0");
        cout << "\n\n###############################################################" << endl;
        cout << "#            Welcome To National Bank of India                #" << endl;
        cout << "###############################################################\n"
             << endl;
        cout << "1.CREATE ACCOUNT                     2.CLOSE ACCOUNT" << endl
             << endl;
        cout << "3.DEPOSIT                            4.WITHDRAW" << endl
             << endl;
        cout << "5.SEARCH                             6.TRANSFER" << endl
             << endl;
        cout << "7.DISPLAY                            8.UPDATE INFO" << endl
             << endl;
        cout << "9.ACTIVATE ATM SERVICE               10.EXIT" << endl
             << endl;

        int choice;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Add_account();
            break;

        case 2:
            Delete_account();
            break;

        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            search();
            break;
        case 6:
            transfer();
            break;
        case 7:
            if (head != NULL)
                display_acc();
            else
            {
                cout << "No accounts available" << endl;
                system("pause");
                bank_menu();
            }

        case 8:
            update_info();
            break;
        case 9:
            activate_atm();
            break;
        case 10:
            display_main_menu();
            break;

        default:
            bank_menu();
        }
    }

    void atm_menu()
    {
        system("cls");
        system("color 9F");
        cout << "\n\n###############################################################" << endl;
        cout << "#            Welcome To National Bank of India                #" << endl;
        cout << "###############################################################\n"
             << endl;
        cout << "1.CASH DEPOSIT                       2.CASH WITHDRAW" << endl
             << endl;
        cout << "3.FUNDS TRANSFER                     4.PIN CHANGE" << endl
             << endl;
        cout << "5.BALANCE ENQUIRY                    6.EXIT" << endl
             << endl;

        int choice;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            deposit();
            break;
        case 2:
            withdraw();
            break;
        case 3:
            transfer();
            break;
        case 4:
            pin_change();
            break;
        case 5:
            display_balance();
            break;
        case 6:
            display_main_menu();
            break;

        default:
            break;
        }
    }

    void display_main_menu()
    {
        system("cls");
        system("color F0");
        cout << "\n\n###############################################################" << endl;
        cout << "#            Welcome To National Bank of India                #" << endl;
        cout << "###############################################################\n"
             << endl;
        cout << "1.Bank Service                             2.ATM Service      \n\n";
        int choice;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            bank_menu();
            break;
        case 2:
            atm_menu();
            break;

        default:
            break;
        }
    }
};

int main(void)
{
    Bank b;
    while (1)
    {
        b.display_main_menu();
    }

    return 0;
}