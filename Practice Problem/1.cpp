#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include <cctype>
#include <algorithm>

using namespace std;

struct TransactionNode
{
    string transaction;
    TransactionNode *next;
};

class Account
{
private:
    string firstName;
    string lastName;
    string cnic;
    string phoneNumber;
    int age;
    string accountType;
    long int accountNumber;
    int pin;
    float balance;
    TransactionNode *transactionHead;

public:
    Account(string firstName, string lastName, string cnic, string phoneNumber, int age, string accountType, float balance);
    ~Account();
    void depositAmount(float amount);
    bool withdrawAmount(float amount);
    void displayAccountDetails() const;
    void showTransactionHistory() const;
    bool validatePin(int inputPin) const;
    float getBalance() const { return balance; }
    long int getAccountNumber() const { return accountNumber; }
};

bool isValidName(const string &name)
{
    return all_of(name.begin(), name.end(), ::isalpha);
}

bool isValidCnic(const string &cnic)
{
    return cnic.length() == 13 && all_of(cnic.begin(), cnic.end(), ::isdigit);
}

bool isValidPhoneNumber(const string &phone)
{
    return phone.length() == 10 && all_of(phone.begin(), phone.end(), ::isdigit);
}

Account::Account(string firstName, string lastName, string cnic, string phoneNumber, int age, string accountType, float balance)
    : firstName(firstName), lastName(lastName), cnic(cnic), phoneNumber(phoneNumber), age(age), accountType(accountType), balance(balance), transactionHead(nullptr)
{

    srand(time(0));
    accountNumber = 10000000 + rand() % 90000000;
    pin = 1000 + rand() % 9000;

    cout << "\nAccount created successfully!" << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "PIN: " << pin << endl;

    TransactionNode *newTransaction = new TransactionNode;
    newTransaction->transaction = "Account opened with balance: " + to_string(balance);
    newTransaction->next = nullptr;
    transactionHead = newTransaction;
}

Account::~Account()
{
    TransactionNode *current = transactionHead;
    while (current != nullptr)
    {
        TransactionNode *next = current->next;
        delete current;
        current = next;
    }
}

void Account::depositAmount(float amount)
{
    balance += amount;
    TransactionNode *newTransaction = new TransactionNode;
    newTransaction->transaction = "Deposited: " + to_string(amount) + ", New Balance: " + to_string(balance);
    newTransaction->next = transactionHead;
    transactionHead = newTransaction;
    cout << "Amount deposited successfully." << endl;
}

bool Account::withdrawAmount(float amount)
{
    if (amount <= balance)
    {
        balance -= amount;
        TransactionNode *newTransaction = new TransactionNode;
        newTransaction->transaction = "Withdrew: " + to_string(amount) + ", New Balance: " + to_string(balance);
        newTransaction->next = transactionHead;
        transactionHead = newTransaction;
        cout << "Amount withdrawn successfully." << endl;
        return true;
    }
    else
    {
        cout << "Insufficient balance for withdrawal." << endl;
        return false;
    }
}

void Account::displayAccountDetails() const
{
    cout << "\nAccount Details:" << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "CNIC: " << cnic << endl;
    cout << "Phone Number: +92" << phoneNumber << endl;
    cout << "Age: " << age << endl;
    cout << "Account Type: " << accountType << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Balance: " << balance << endl;
}

void Account::showTransactionHistory() const
{
    cout << "\nTransaction History for Account " << accountNumber << ":" << endl;
    TransactionNode *current = transactionHead;
    while (current != nullptr)
    {
        cout << "  " << current->transaction << endl;
        current = current->next;
    }
}

bool Account::validatePin(int inputPin) const
{
    return inputPin == pin;
}

class Bank
{
private:
    Account *accounts[100];
    int accountCount;

public:
    Bank() : accountCount(0) {}
    ~Bank();
    void createAccount();
    void deleteAccount(long int accountNumber, int pin);
    void showListOfAllAccounts() const;
    Account *searchAccount(long int accountNumber, int pin);
    void customerMenu();
    void atmMenu();
};

Bank::~Bank()
{
    for (int i = 0; i < accountCount; i++)
    {
        delete accounts[i];
    }
}

void Bank::createAccount()
{
    string firstName, lastName, cnic, phoneNumber, accountType;
    int age;
    float initialDeposit;

    // Input validation for first name and last name
    cout << "\nEnter your first name: ";
    cin >> firstName;
    while (!isValidName(firstName))
    {
        cout << "Invalid first name. Please use only alphabetic characters: ";
        cin >> firstName;
    }

    cout << "Enter your last name: ";
    cin >> lastName;
    while (!isValidName(lastName))
    {
        cout << "Invalid last name. Please use only alphabetic characters: ";
        cin >> lastName;
    }

    // Input validation for CNIC
    cout << "Enter your CNIC number (13 digits, without dashes): ";
    cin >> cnic;
    while (!isValidCnic(cnic))
    {
        cout << "Invalid CNIC. Please enter a 13-digit number: ";
        cin >> cnic;
    }

    // Input validation for phone number
    cout << "Enter your phone number (without +92): ";
    cin >> phoneNumber;
    while (!isValidPhoneNumber(phoneNumber))
    {
        cout << "Invalid phone number. Please enter a 10-digit number: ";
        cin >> phoneNumber;
    }

    // Input validation for age
    cout << "Enter your age: ";
    cin >> age;
    while (age < 18 || age > 100)
    {
        cout << "Invalid age. Please enter an age between 18 and 100: ";
        cin >> age;
    }

    // Input validation for account type
    cout << "Enter account type (saving/current): ";
    cin >> accountType;
    while (accountType != "saving" && accountType != "current")
    {
        cout << "Invalid account type. Enter 'saving' or 'current': ";
        cin >> accountType;
    }

    // Check minimum balance requirements for account type
    cout << "Enter initial deposit amount: ";
    cin >> initialDeposit;
    if ((accountType == "saving" && initialDeposit < 500) || (accountType == "current" && initialDeposit < 1000))
    {
        cout << "Insufficient deposit for account type. Saving requires a minimum of 500, current requires a minimum of 1000." << endl;
        return;
    }

    accounts[accountCount++] = new Account(firstName, lastName, cnic, phoneNumber, age, accountType, initialDeposit);
}

void Bank::deleteAccount(long int accountNumber, int pin)
{
    for (int i = 0; i < accountCount; i++)
    {
        if (accounts[i]->getAccountNumber() == accountNumber && accounts[i]->validatePin(pin))
        {
            delete accounts[i];
            accounts[i] = accounts[--accountCount];
            cout << "Account deleted successfully!" << endl;
            return;
        }
    }
    cout << "Account not found or incorrect PIN." << endl;
}

void Bank::showListOfAllAccounts() const
{
    cout << "\nList of All Accounts:\n";
    for (int i = 0; i < accountCount; i++)
    {
        accounts[i]->displayAccountDetails();
        cout << "------------------------" << endl;
    }
}

Account *Bank::searchAccount(long int accountNumber, int pin)
{
    for (int i = 0; i < accountCount; i++)
    {
        if (accounts[i]->getAccountNumber() == accountNumber && accounts[i]->validatePin(pin))
        {
            return accounts[i];
        }
    }
    cout << "Account not found or incorrect PIN." << endl;
    return nullptr;
}

void Bank::customerMenu()
{
    int choice;
    do
    {
        cout << "\nCustomer Menu:\n";
        cout << "1. Create Account\n";
        cout << "2. Delete Account\n";
        cout << "3. Deposit Amount\n";
        cout << "4. Withdraw Amount\n";
        cout << "5. Show Account Details\n";
        cout << "6. Show All Accounts\n";
        cout << "7. Show Transaction History\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        long int accountNumber;
        int pin;
        float amount;
        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            cout << "Enter account number to delete: ";
            cin >> accountNumber;
            cout << "Enter PIN: ";
            cin >> pin;
            deleteAccount(accountNumber, pin);
            break;
        case 3:
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter PIN: ";
            cin >> pin;
            if (Account *acc = searchAccount(accountNumber, pin))
            {
                cout << "Enter amount to deposit: ";
                cin >> amount;
                acc->depositAmount(amount);
            }
            break;
        case 4:
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter PIN: ";
            cin >> pin;
            if (Account *acc = searchAccount(accountNumber, pin))
            {
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                acc->withdrawAmount(amount);
            }
            break;
        case 5:
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter PIN: ";
            cin >> pin;
            if (Account *acc = searchAccount(accountNumber, pin))
            {
                acc->displayAccountDetails();
            }
            break;
        case 6:
            showListOfAllAccounts();
            break;
        case 7:
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter PIN: ";
            cin >> pin;
            if (Account *acc = searchAccount(accountNumber, pin))
            {
                acc->showTransactionHistory();
            }
            break;
        case 8:
            cout << "Exiting Customer Menu.\n";
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 8);
}

void Bank::atmMenu()
{
    long int accountNumber;
    int pin;

    cout << "\n--- ATM Access ---" << endl;
    cout << "Enter your account number: ";
    cin >> accountNumber;
    cout << "Enter PIN: ";
    cin >> pin;

    Account *acc = searchAccount(accountNumber, pin);
    if (!acc)
    {
        cout << "Invalid account details. Exiting ATM menu." << endl;
        return;
    }

    int choice;
    do
    {
        cout << "\nATM Menu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        float amount;

        switch (choice)
        {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            acc->depositAmount(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            acc->withdrawAmount(amount);
            break;
        case 3:
            cout << "Current Balance: " << acc->getBalance() << endl;
            break;
        case 4:
            cout << "Exiting ATM Menu.\n";
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);
}
void nameApp()
{
    system("cls");
    cout << "\n\t||||||      / \\     ||\\\\    || ||  //  ||||||  ||\\\\    ||  ||||||||      ||||||||  \\\\    //  |||||||| |||||||||| |||||||| ||\\\\    //|| ";
    Sleep(120);
    cout << "\n\t||  //     // \\\\    || \\\\   || || //     ||    || \\\\   ||  ||            ||         \\\\  //   ||           ||     ||       || \\\\  // || ";
    Sleep(120);
    cout << "\n\t|||||     //   \\\\   ||  \\\\  || ||//\\     ||    ||  \\\\  ||  ||  ||||      ||||||||    \\\\//    ||||||||     ||     |||||||| ||  \\\\//  || ";
    Sleep(120);
    cout << "\n\t||  \\\\   //|||||\\\\  ||   \\\\ || ||/ \\\\    ||    ||   \\\\ ||  ||    ||            ||     //           ||     ||     ||       ||        ||";
    Sleep(120);
    cout << "\n\t||||||  //       \\\\ ||    \\\\|| ||   \\\\ ||||||  ||    \\\\||  ||||||||      ||||||||    //      ||||||||     ||     |||||||| ||        || \n\n";
    Sleep(120);
}

int main()
{
    nameApp();
    Bank bank;
    int choice;
    do
    {
        cout << "\nMain Menu:\n";
        cout << "1. Customer Menu\n";
        cout << "2. ATM Menu\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.customerMenu();
            break;
        case 2:
            bank.atmMenu();
            break;
        case 3:
            cout << "Thank you for using our bank service!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 3);

    return 0;
}