#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <conio.h>
#include <regex>
using namespace std;

// Error Handling Class
class Validation // class for input validations
{
public:
    // Name validation function
    bool nameValidation(const string &str)
    {
        if (str.empty())
        {
            return false;
        }

        return !regex_match(str, regex(".\\d.")); // Ensure no digits in name
    }

    // Menu choice validation (to ensure input is numeric)
    bool menuChoice(const string &choice)
    {
        if (choice.empty() || choice.find(' ') != string::npos)
        {
            return false;
        }

        for (char ch : choice)
        {
            if (!isdigit(ch))
            {
                return false;
            }
        }
        return true;
    }
    bool isValidEmail(const string &email) const
    {
        regex emailPattern(R"((\w+)(\.?)(\w*)@gmail\.com)");
        return regex_match(email, emailPattern);
    }

    // String validation to check if not empty and not only spaces
    bool stringValidation(const string &str)
    {
        if (str.empty())
        {
            return false;
        }

        for (char ch : str)
        {
            if (!isspace(ch))
            {
                return true;
            }
        }

        return false;
    }

    // Phone validation to ensure correct format (example for 11-digit phone numbers)
    bool phoneValidation(const string &input)
    {
        if (input.length() != 11)
        {
            return false;
        }

        for (char ch : input)
        {
            if (!isdigit(ch))
            {
                return false;
            }
        }
        return true;
    }

    // Function for password logic with masking and reveal option
    void passLogic(string &password, const string &promptText)
    {
        char pass[32] = {0};
        char ch;
        bool enter = false;
        int i = 0;
        bool show = false;

        cout << promptText;

        while (!enter)
        {
            ch = _getch();

            if (isalnum(ch))
            {
                pass[i] = ch;
                if (show)
                {
                    cout << ch;
                }
                else
                {
                    cout << "*";
                }
                i++;
            }

            if (ch == '\b' && i >= 1) // Handle backspace
            {
                cout << "\b \b";
                i--;
            }

            if (ch == '\r') // Enter key
            {
                enter = true;
            }

            if (ch == '\t') // Toggle show/hide password
            {
                show = !show;
                cout << "\r" << promptText;
                for (int j = 0; j < i; j++)
                {
                    cout << (show ? pass[j] : '*');
                }
            }
        }

        pass[i] = '\0';
        password = pass;
    }
};
// Class for contact details
class Contact
{
public:
    string name, number, email, type;
    bool isFavorite;

    Contact(string name = "", string number = "", string email = "", string type = "", bool favorite = false)
        : name(name), number(number), email(email), type(type), isFavorite(favorite) {}

    void markAsFavorite(bool favorite) { isFavorite = favorite; }
    friend ostream &operator<<(ostream &os, const Contact &contact)
    {
        os << "Name: " << contact.name << "\nNumber: " << contact.number << "\nEmail: " << contact.email
           << "\nType: " << contact.type << "\nFavorite: " << (contact.isFavorite ? "Yes" : "No") << endl;
        return os;
    }
};

class BST : public Validation
{
private:
    struct Node
    {
        Contact contact;
        Node *left, *right;
        Node(Contact c) : contact(c), left(nullptr), right(nullptr) {}
    };

public:
    Node *root;
    BST() : root(nullptr) {}

public:

    void insert(Contact contact)
    {
        root = insert(root, contact); // Call private insert with root
    }
    // void saveToFile(const string &filename) const
    // {
    //     ofstream file(filename);
    //     if (file.is_open())
    //     {
    //         inOrder(root, file);
    //         file.close();
    //         cout << "\nContacts saved successfully to " << filename << "\n";
    //     }
    //     else
    //     {
    //         cout << "\nFailed to open file for saving.\n";
    //     }
    // }
    Node *insert(Node *node, Contact contact)
    {
        if (node == nullptr)
        {
            return new Node(contact);
        }

        if (contact.name < node->contact.name)
        {
            node->left = insert(node->left, contact);
        }
        else if (contact.name > node->contact.name)
        {
            node->right = insert(node->right, contact);
        }
        else
        {
            if (contact.number != node->contact.number || contact.email != node->contact.email)
            {
                node->right = insert(node->right, contact); // Insert with the same name but different info
            }
            else
            {
                cout << "\nContact already exists with the same name, number, and email.\n";
            }
        }
        return node;
    }

    Node *minValueNode(Node *node) const
    {
        Node *current = node;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    void displayFavorites(Node *node) const
    {
        if (node == nullptr)
            return;
        displayFavorites(node->left);
        if (node->contact.isFavorite)
        {
            cout << node->contact;
        }
        displayFavorites(node->right);
    }

    void inOrder(Node *node, ostream &os) const
    {
        if (!node)
            return;

        inOrder(node->left, os);

        os << node->contact.name << " "
           << node->contact.number << " "
           << node->contact.email << " "
           << node->contact.type << " "
           << (node->contact.isFavorite ? "Yes" : "No") << "\n";

        inOrder(node->right, os);
    }

    Node *deleteNode(Node *node, const string &name)
    {
        if (node == nullptr)
            return node;

        if (name < node->contact.name)
        {
            node->left = deleteNode(node->left, name);
        }
        else if (name > node->contact.name)
        {
            node->right = deleteNode(node->right, name);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = minValueNode(node->right);
            node->contact = temp->contact;
            node->right = deleteNode(node->right, temp->contact.name);
        }
        return node;
    }

    void deleteMultipleContacts(const vector<string> &names)
    {
        for (const auto &name : names)
        {
            root = deleteNode(root, name);
        }
        cout << "\nSpecified contacts have been deleted.\n";
    }

    void deleteAllContacts()
    {
        delete root;
        root = nullptr;
        cout << "\nAll contacts have been deleted.\n";
    }

    void editContact(const string &name)
    {
        Node *contactNode = searchContact(name);
        if (contactNode)
        {
            cout << "\nEditing contact details for " << name << ":\n";
            cout << "Enter new number (or press enter to keep current): ";
            string newNumber;
            getline(cin, newNumber);
            if (!newNumber.empty())
                contactNode->contact.number = newNumber;

            cout << "Enter new email (or press enter to keep current): ";
            string newEmail;
            getline(cin, newEmail);
            if (!newEmail.empty() && Validation::isValidEmail(newEmail))
                contactNode->contact.email = newEmail;

            cout << "Enter new type (or press enter to keep current): ";
            string newType;
            getline(cin, newType);
            if (!newType.empty())
                contactNode->contact.type = newType;

            cout << "\nContact updated successfully!\n";
        }
        else
        {
            cout << "\nContact not found.\n";
        }
    }

    void markAsFavorite(const string &name)
    {
        Node *contactNode = searchContact(name);
        if (contactNode)
        {
            contactNode->contact.isFavorite = true;
            cout << "\n"
                 << name << " has been added to favorites.\n";
        }
        else
        {
            cout << "\nContact not found.\n";
        }
    }







    Node *search(Node *node, const string &name) const
    {
        if (node == nullptr || node->contact.name == name)
        {
            return node;
        }
        if (name < node->contact.name)
        {
            return search(node->left, name);
        }
        return search(node->right, name);
    }

    Node *searchContact(const string &name) // Declares function with parameter
    {
        Node *result = search(root, name); // Calls recursive search function correctly
        if (result)
        {
            cout << "\nContact found:\n"
                 << result->contact;
        }
        else
        {
            cout << "\nNo contact found with the name " << name << endl;
        }
        return result;
    }

    void loadNmaes(Node *node, string name[], int &i)
    {
        if (node == nullptr)
            return;
        name[i] = node->contact.name;
        i++;
        loadNmaes(node->right, name, i);
        loadNmaes(node->left, name, i);
        return;
    }
    void loadNunbers(Node *node, string number[], int &j)
    {
        if (node == nullptr)
            return;
        number[j] = node->contact.number;
        j++;
        loadNunbers(node->right, number, j);
        loadNunbers(node->left, number, j);
        return;
    }

    void searchContacts(Node *node)
    {
        int size=1000;
        string name[size];
        string numbers[size];

        int i = 0;
        loadNmaes(node, name, i);


        int j = 0;
        loadNunbers(node, numbers, j);

        string matchedNames[i];
        string matchedNumbers[j];

        string currentInput = "";

        while (true)
        {
            system("cls");
            cout << " ---------------------------------------\n";
            cout << "| Enter a key to search: " << currentInput << "\t\t|";
            cout << "\n ---------------------------------------\n";

            int matchCountnames = 0;
            int matchCountnumbers = 0;

            if (!currentInput.empty())
            {
                cout << "\n\n";
                string lowerInput = currentInput;
                transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

                for (int i = 0; i < size; i++)
                {
                    string lowerName = name[i];
                    transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

                    if (lowerName.find(lowerInput) != string::npos)
                    {
                        matchedNames[matchCountnames++] = name[i]; // Add matched name to matchedNames
                    }
                }
                for (int i = 0; i < size; i++)
                {

                    if (numbers[i].find(lowerInput) != string::npos)
                    {
                        matchedNumbers[matchCountnumbers++] = numbers[i]; // Add matched name to matchedNames
                    }
                }
                if (matchCountnames > 0 || matchCountnumbers > 0)
                {
                    for (int i = 0; i < matchCountnames; i++)
                    {
                        cout << matchedNames[i] << "\n";
                    }
                    for (int i = 0; i < matchCountnumbers; i++)
                    {
                        cout << matchedNumbers[i] << "\n";
                    }
                }
  
                else
                {
                    cout << "No Contact found.\n";
                }
            }
            char ch = getch();

            if (ch == 13)
            {
                if (matchCountnames <= 0 && matchCountnumbers <= 0)
                {
                    break;
                }
                system("cls");
                string lowerInput = currentInput;
                transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

                bool found = false;
                displayFullDetails(node, lowerInput, found);
                break;

            }
            else if (ch == 27)
            { // Escape key
                cout << "\nSearch discarded. Returning to main menu.\n";
                break;
            }

            // Handle backspace
            else if (ch == 8)
            {
                if (!currentInput.empty())
                {
                    currentInput.pop_back();
                }
            }
            else
            {
                currentInput += ch;
            }
        }
    }

    void displayFullDetails(Node *node, const string &currentInput, bool &found) const
    {

        if (!node)
            return;

        displayFullDetails(node->left, currentInput, found);
        string lowerName = node->contact.name;
        transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);

        if (lowerName.find(currentInput) != string::npos || node->contact.number.find(currentInput) != string::npos)
        {
            cout << "\n---------------------------";
            cout << "\nName: " << node->contact.name
                 << "\nNumber: " << node->contact.number
                 << "\nEmail: " << node->contact.email
                 << "\nType: " << node->contact.type
                 << "\nFavorite: " << (node->contact.isFavorite ? "Yes" : "No");
            cout << "\n---------------------------";
            found = true; // Set found to true if a match is found
        }

        displayFullDetails(node->right, currentInput, found);
    }







    void removeFromFavorite(const string &name)
    {
        Node *contactNode = searchContact(name);
        if (contactNode && contactNode->contact.isFavorite)
        {
            contactNode->contact.isFavorite = false;
            cout << "\n"
                 << name << " has been removed from favorites.\n";
        }
        else
        {
            cout << "\nContact not found or is not a favorite.\n";
        }
    }

    void displayInOrder(Node *node) const
    {
        if (!node)
            return;

        displayInOrder(node->left);

        cout << "\n---------------------------";
        cout << "\nName: " << node->contact.name
             << "\nNumber: " << node->contact.number
             << "\nEmail: " << node->contact.email
             << "\nType: " << node->contact.type
             << "\nFavorite: " << (node->contact.isFavorite ? "Yes" : "No");
        cout << "\n---------------------------";

        displayInOrder(node->right);
    }

    void displayFavoriteContacts() const
    {
        if (root == nullptr)
        {
            cout << "\nNo contacts available.\n";
        }
        else
        {
            cout << "\nDisplaying favorite contacts:\n";
            displayFavorites(root);
        }
    }
};
class FileManager : public BST
{
public:
    void loadFromFile(const string &filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "\nFailed to open file for loading.\n";
            return;
        }

        delete root;
        root = nullptr;

        string line, name, number, email, type, favorite;
        int contactCount = 0; 
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, name, ' ');
            getline(ss, number, ' ');
            getline(ss, email, ' ');
            getline(ss, type, ' ');
            getline(ss, favorite, ' ');

            if (!name.empty() && !number.empty() && !email.empty() && !type.empty())
            {
                Contact contact(name, number, email, type);
                contact.isFavorite = (favorite == "Yes");

                insert(contact); // Insert the contact into BST
            }
        }
        file.close();
    }

    void saveToFile(const string &filename) const
    {
        ofstream file(filename);
        if (file.is_open())
        {
            inOrder(root, file);
            file.close();
            cout << "\nContacts saved successfully to " << filename << "\n";
        }
        else
        {
            cout << "\nFailed to open file for saving.\n";
        }
    }
    void backupContacts() const
    {
        ifstream src("contacts.txt", ios::binary);
        ofstream dest("contacts_backup.txt", ios::binary);

        if (src.is_open() && dest.is_open())
        {
            dest << src.rdbuf();
            cout << "\nBackup created successfully as 'contacts_backup.txt'\n";
        }
        else
        {
            cout << "\nFailed to create backup.\n";
        }
    }
};
class Authentication : protected Validation
{

public:
    string password;
    string securityAnswer;
    void changePassword()
    {
        while (true)
        {
            cout << "\nEnter new password: ";
            getline(cin, password);
            if (stringValidation(password)) // Validate the username
            {
                break; // Exit loop if username is valid
            }
            else
            {
                cout << "\n\t Invalid Password Patteren" << endl;
            }
        }
        cout << "\nPassword changed successfully!\n";
    }

    void restorePassword()
    {
        string answer;
        cout << "\nTo restore your password, answer the security question.";
        while (true)
        {
            cout << "\nWhat is your favorite color? ";
            getline(cin, answer);
            if (stringValidation(answer)) // Validate the username
            {
                break; // Exit loop if username is valid
            }
            else
            {
                cout << "\nInvalid Answer. please try again\n";
            }
        }
        if (answer == securityAnswer)
        {
            cout << "\nYour password is: " << password << endl;
        }
        else
        {
            cout << "\nIncorrect answer. Cannot restore password.\n";
        }
    }

    bool authenticate()
    {
        int attempts = 0;
        string inputPassword;
        while (attempts < 3)
        {
            // cout << "\nEnter password: ";
            passLogic(inputPassword, "Enter password: ");
            // getline(cin, inputPassword);
            if (inputPassword == password)
            {
                return true;
            }
            else
            {
                cout << "\nIncorrect password. Try again.\n";
                attempts++;
            }
        }
        cout << "\nToo many failed attempts. Exiting settings.\n";
        return false;
    }
};
// Application class that manages user interaction
class PhoneBookApp : public Authentication, public FileManager
{
private:
    BST bst;
    FileManager fileManager;
    Validation validator;
    Authentication auth;
    string password;
    string securityAnswer;

public:
    PhoneBookApp() : password("123"), securityAnswer("blue") {}

    // Main settings menu
    void settingsMenu()
    {
        if (!authenticate())
            return; // Exit if authentication fails
        string choice;
        do
        {
            cout << "\n--- Settings Menu ---";
            cout << "\n1. Change Password";
            cout << "\n2. Backup Contacts";
            cout << "\n3. Restore Password";
            cout << "\n0. Return to Main Menu";
            cout << "\nSelect an option: ";
            while (true)
            {
                cout << "\nSelect an option: ";
                getline(cin, choice);
                if (validator.menuChoice(choice))
                {
                    break;
                }
                cout << "\n\tInvalid option! Please try again.\n\n";
            }

            if (choice == "1")
            {
                system("cls");
                changePassword();
            }
            else if (choice == "2")
            {
                system("cls");
                backupContacts(); // Uncomment if backupContacts function is implemented
            }
            else if (choice == "3")
            {
                system("cls");
                restorePassword();
            }
        } while (choice != "0");
    }

    void startApp()
    {
        //     if (!authenticate())
        //     {
        //         return; // Exit if authentication fails
        //     }
        // Load contacts immediately when the app starts
        loadFromFile("contacts.txt");

        string choice;
        do
        {
            displayMenu();
            while (true)
            {
                cout << "\nSelect an option: ";
                getline(cin, choice);
                if (validator.menuChoice(choice))
                {
                    break;
                }
                cout << "\n\tInvalid option! Please try again.\n\n";
            }
            if (choice == "1")
            {
                system("cls");
                addContact();
            }
            else if (choice == "2")
            {
                system("cls");
                editContact();
            }
            else if (choice == "3")
            {
                system("cls");
                bst.searchContacts(root);
            }
            else if (choice == "4")
            {
                system("cls");
                batchDelete();
            }
            else if (choice == "5")
            {
                system("cls");
                manageFavorites();
            }
            else if (choice == "6")
            {
                system("cls");
                displayAllContacts();
            }
            else if (choice == "7")
            {
                system("cls");
                settingsMenu();
            }
        } while (choice != "0");
    }
    void addContact()
    {
        string name, number, email, type;

        while (true)
        {
            cout << "\nEnter the Name ";
            getline(cin, name);
            if (validator.nameValidation(name)) // Validate the username
            {
                break; // Exit loop if username is valid
            }
            else
            {
                cout << "\n\n\tInvalid Name. Please try again.\n";
            }
        }

        while (true)
        {
            cout << "Enter number: ";
            getline(cin, number);
            if (validator.phoneValidation(number))
            {
                break;
            }
            else
            {
                cout << "\n\n\tInvalid Number. Please try again.\n";
            }
        }
        while (true)
        {
            cout << "Enter email (must end with '@gmail.com'): ";
            getline(cin, email);
            if (validator.isValidEmail(email))
            {
                break;
            }
            else
            {
                cout << "\nInvalid email. Please ensure the email ends with '@gmail.com'.\n";
            }
        }

        while (true)
        {
            cout << "Enter type (PTCL, Local, Emergency): ";
            getline(cin, type);
            if (validator.nameValidation(type)) // Validate the username
            {
                break; // Exit loop if username is valid
            }
            else
            {
                cout << "\n\n\tInvalid Type. Please try again.\n";
            }
        }

        Contact newContact(name, number, email, type);
        insert(newContact);
        saveToFile("contacts.txt"); // Save after adding contact
        cout << "\nContact added successfully!\n";
    }

    void displayAllContacts() const
    {
        if (root == nullptr)
        {
            cout << "\nNo contacts available.\n";
        }
        else
        {
            cout << "\nDisplaying all contacts:\n";
            bst.displayInOrder(root);
        }
    }
    void markAsFavorite()
    {
        string name;
        while (true)
        {
            cout << "\nEnter the name of the contact to mark as favorite: ";
            getline(cin, name);
            if (validator.nameValidation(name)) // Validate the username
            {
                break; // Exit loop if username is valid
            }
            else
            {
                cout << "\n\n\tInvalid Name. Please try again.\n";
            }
        }
        bst.markAsFavorite(name);
        saveToFile("contacts.txt"); // Save after marking as favorite
    }

    void removeFromFavorite()
    {
        string name;
        while (true)
        {
            cout << "\nEnter the name of the contact to remove from favorites: ";
            getline(cin, name);
            if (validator.nameValidation(name)) // Validate the username
            {
                break; // Exit loop if username is valid
            }
            else
            {
                cout << "\n\n\tInvalid Name. Please try again.\n";
            }
        }
        bst.removeFromFavorite(name);
        saveToFile("contacts.txt"); // Save after removing from favorite
    }

    void editContact()
    {
        string name;
        while (true)
        {
            cout << "\nEnter the name of the contact to edit: ";
            getline(cin, name);
            if (validator.nameValidation(name)) // Validate the username
            {
                break; // Exit loop if username is valid
            }
            else
            {
                cout << "\n\n\tInvalid Name. Please try again.\n";
            }
        }
        bst.editContact(name);
        saveToFile("contacts.txt"); // Save after editing contact
    }

    void batchDelete()
    {
        cout << "\n--- Batch Delete Menu ---";
        cout << "\n1. Delete multiple contacts by name";
        cout << "\n2. Delete all contacts";
        string choice;
        while (true)
        {
            cout << "\nSelect an option: ";
            getline(cin, choice);
            if (validator.menuChoice(choice))
            {
                break;
            }
            cout << "\n\tInvalid option! Please try again.\n\n";
        }

        if (choice == "1")
        {
            vector<string> names;
            string name;
            cout << "\nEnter names to delete (type 'done' to finish):\n";
            while (true)
            {
                getline(std::cin, name);
                if (name == "done")
                    break;
                names.push_back(name);
            }
            bst.deleteMultipleContacts(names);
            saveToFile("contacts.txt"); // Save after batch delete
        }
        else if (choice == "2")
        {
            bst.deleteAllContacts();
            saveToFile("contacts.txt"); // Save after deleting all
        }
        else
        {
            cout << "\nInvalid choice. Returning to main menu.\n";
        }
    }

    void manageFavorites()
    {
        string choice;
        do
        {
            favoriteMenu();
            while (true)
            {
                cout << "\nSelect an option: ";
                getline(cin, choice);
                if (validator.menuChoice(choice))
                {
                    break;
                }
                cout << "\n\tInvalid option! Please try again.\n\n";
            }
            if (choice == "1")
            {
                system("cls");
                markAsFavorite();
            }
            else if (choice == "2")
            {
                system("cls");
                removeFromFavorite();
            }
            else if (choice == "3")
            {
                system("cls");
                bst.displayFavoriteContacts();
            }
        } while (choice != "0");
    }

    void favoriteMenu()
    {
        cout << "\n--- Favorite Contacts Menu ---";
        cout << "\n1. Add to Favorite";
        cout << "\n2. Remove from Favorite";
        cout << "\n3. Display Favorite Contacts";
        cout << "\n0. Exit";
    }

    void displayMenu()
    {
        cout << "\n--- Phone Book Management System ---";
        cout << "\n1. Add Contact";
        cout << "\n2. Edit Contact";
        cout << "\n3. Search Contact";
        cout << "\n4. Delete Contact";
        cout << "\n5. Manage Favorite Contacts";
        cout << "\n6. Display All Contacts";
        cout << "\n7. Settings";
        cout << "\n0. Exit";
    }
};

int main()
{
    PhoneBookApp app;
    app.startApp();
    return 0;
}