#include <iostream>
#include <conio.h>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    // Array of names to search from
    string names[100] = {
        "Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hannah",
        "Ian", "Jack", "Kathy", "Liam", "Mona", "Nate", "Olivia", "Paul",
        "Quincy", "Rachel", "Sam", "Tina", "Uma", "Victor", "Wendy", "Xander",
        "Yara", "Zane", "Aiden", "Bella", "Carter", "Daisy", "Ethan", "Fiona",
        "George", "Hazel", "Isla", "Jonah", "Kylie", "Leo", "Mason", "Nora",
        "Owen", "Penny", "Quinn", "Ryan", "Sophia", "Tyler", "Ursula", "Vera",
        "Will", "Ximena", "Yasmin", "Zack", "Abby", "Brandon", "Chloe", "Derek",
        "Elena", "Felix", "Gina", "Harry", "Ivy", "Jason", "Kelly", "Logan",
        "Maria", "Nathan", "Oscar", "Patricia", "Quinn", "Robert", "Sara",
        "Tom", "Umar", "Vanessa", "Wesley", "Xavier", "Yasmine", "Zara",
        "Alfred", "Bryan", "Cynthia", "Dylan", "Elliot", "Freya", "Gavin",
        "Heather", "Isaac", "Jake", "Kim", "Lily", "Miles", "Nina", "Omar"};

    string currentInput = ""; // Stores the user’s current input
    string matchedNames[100]; // Array to store matched names

    while (true)
    {
        system("cls"); // Clear screen for real-time updates
        cout << " ---------------------------------------\n";
        cout << "| Enter name to search: " << currentInput << "\t\t|";
        cout << "\n ---------------------------------------\n";

        // If the input is not empty, perform the search
        if (!currentInput.empty())
        {
            cout << "\n\n";
            string lowerInput = currentInput;
            transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower); // Convert input to lowercase

            int matchCount = 0; // Counter for matches
            for (int i = 0; i < 100; i++)
            {
                string lowerName = names[i];
                transform(lowerName.begin(), lowerName.end(), lowerName.begin(), ::tolower); // Convert names to lowercase

                // Check if name contains the input as substring
                if (lowerName.find(lowerInput) != string::npos)
                {
                    matchedNames[matchCount++] = names[i]; // Add matched name to matchedNames
                }
            }

            // Display matched names
            if (matchCount > 0)
            {
                for (int i = 0; i < matchCount; i++)
                {
                    cout << matchedNames[i] << "\n";
                }
            }
            else
            {
                cout << "No matches found.\n";
            }
        }

        // Get the next character input without Enter
        char ch = getch();

        // Exit search if Enter is pressed
        if (ch == 13)
        {
            cout << "\nExiting search.\n";
            break;
        }

        // Handle backspace
        if (ch == 8)
        {
            if (!currentInput.empty())
            {
                currentInput.pop_back();
            }
        }
        else if (ch != 27) // Ignore ESC key
        {
            currentInput += ch; // Append character to input
        }
    }

    return 0;
}
