#include <iostream>
#include <conio.h>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class NameSearchBST
{
private:
    struct TreeNode
    {
        string name;
        TreeNode *left;
        TreeNode *right;

        TreeNode(string n) : name(n), left(nullptr), right(nullptr) {}
    };

    TreeNode *root;

    // Insert a name into the BST
    TreeNode *insert(TreeNode *node, string name)
    {
        if (!node)
            return new TreeNode(name);
        if (name < node->name)
        {
            node->left = insert(node->left, name);
        }
        else
        {
            node->right = insert(node->right, name);
        }
        return node;
    }

    // Display matching names recursively
    void displayMatches(TreeNode *node, const string &input, bool &found) const
    {
        if (!node)
            return;

        string lowerName = node->name;
        transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower);
        string lowerInput = input;
        transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

        if (lowerName.find(lowerInput) != string::npos)
        {
            cout << node->name << "\n";
            found = true;
        }

        displayMatches(node->left, input, found);
        displayMatches(node->right, input, found);
    }

    // Clear the tree
    void clearTree(TreeNode *node)
    {
        if (node)
        {
            clearTree(node->left);
            clearTree(node->right);
            delete node;
        }
    }

public:
    NameSearchBST() : root(nullptr) {}

    ~NameSearchBST()
    {
        clearTree(root);
    }

    // Insert all names into the BST
    void insertNames(const string names[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            root = insert(root, names[i]);
        }
    }

    // Display results based on the current input
    void displayResults(const string &currentInput) const
    {
        system("cls");
        cout << " ---------------------------------------\n";
        cout << "| Matching contacts for: " << currentInput << "\t|\n";
        cout << " ---------------------------------------\n\n";

        bool found = false;
        displayMatches(root, currentInput, found);

        if (!found)
        {
            cout << "No contacts found.\n";
        }
    }

    // Search for names based on user input
    void searchNames() const
    {
        string currentInput = "";

        while (true)
        {
            system("cls");
            cout << " ---------------------------------------\n";
            cout << "| Enter name to search: " << currentInput << "\t\t|\n";
            cout << " ---------------------------------------\n\n";

            if (!currentInput.empty())
            {
                displayResults(currentInput);
            }

            char ch = getch();

            if (ch == 13)
            { // Enter key
                cout << "\nReturning to main menu.\n";
                break;
            }
            else if (ch == 27)
            { // Escape key
                cout << "\nSearch discarded. Returning to main menu.\n";
                break;
            }
            else if (ch == 8)
            { // Backspace key
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
};

int main()
{
    NameSearchBST nameSearch;

    string names[50] = {
        "Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hannah",
        "Ian", "Jack", "Kathy", "Liam", "Mona", "Nate", "Olivia", "Paul",
        "Quincy", "Rachel", "Sam", "Tina", "Uma", "Victor", "Wendy", "Xander",
        "Yara", "Zane", "Aiden", "Bella", "Carter", "Daisy", "Ethan", "Fiona",
        "George", "Hazel", "Isla", "Jonah", "Kylie", "Leo", "Mason", "Nora",
        "Owen", "Penny", "Quinn", "Ryan", "Sophia", "Tyler", "Ursula", "Vera"};

    nameSearch.insertNames(names, 50);
    nameSearch.searchNames();

    return 0;
}
