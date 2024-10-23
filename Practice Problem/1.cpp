#include <iostream>
#include <ctime>
using namespace std;
float price_beverage = 0; // for price_Beverage
float price_meal = 0;     // for price_meal
float bill, total_bill, tax;
float discount = 0;
int main()
{   // for current time
    time_t time_now = time(0);
    tm *ltm = localtime(&time_now);
    int hours = ltm->tm_hour;

    string option; // option for starting input
    cout << "\n\t**** WELCOME TO MY FAST-FOOD SHOP ****\n\n";
    cout << "\tPlease let us know how we can help you\n";
    cout << "\tWhat whould you like to take\n";
    cout << "\tPlease type:\n\n";
start:
    cout << "\tm/M   for Meals\n\tb/B   for Beverages\n";
    cin >> option;
    // for meal
    if (option == "M" || option == "m")
    {
        float option_meal;   // for options in meal menu
        float quantity_meal; // for meal quantity
    startmeal:
        cout << "\tHere is the Meal's price-list\n";
        cout << "\tEnter your choice (1, 2, or 3):\n\n";
        cout << "1.\tBurger\t\tRs.350\n";
        cout << "2.\tRoll Paratha\tRs.190\n";
        cout << "3.\tSpaghetti\tRs.225\n";
        cin >> option_meal;
        if (option_meal == 1)
        {
            price_meal = 350;
        }
        else if (option_meal == 2)
        {
            price_meal = 190;
        }
        else if (option_meal == 3)
        {
            price_meal = 225;
        }
        else
        {
            cout << "\tInvalid choice\n\tPlease type correct option\n\n";
            goto startmeal;
        }
        cout << "\thow much quantity/piece you want\t";
        cin >> quantity_meal;
        price_meal = (price_meal * quantity_meal);
    }
    else if (option == "B" || option == "b")
    {
        float option_beverage;   // for options in Beverages menu
        float quantity_beverage; // for Beverage quantity
    startbeverages:
        cout << "\tHere is the Beverage's price-list\n";
        cout << "\tEnter your choice (1, 2, or 3):\n\n";
        cout << "1.\tCoffee     \tRs.150/cup\n";
        cout << "2.\tFresh Juice\tRs.340/glass\n";
        cout << "3.\tGreen Tea  \tRs.75/cup\n";
        cin >> option_beverage;
        if (option_beverage == 1)
        {
            price_beverage = 150;
        }
        else if (option_beverage == 2)
        {
            price_beverage = 340;
        }
        else if (option_beverage == 3)
        {
            price_beverage = 75;
        }
        else
        {
            cout << "\tinvalid choice\n\tPlease type correct option\n\n";
            goto startbeverages;
        }
        cout << "\thow much quantity/piece you want\t";
        cin >> quantity_beverage;
        price_beverage = (price_beverage * quantity_beverage);
    }

    else
    {
        cout << "\tinvalid choice\n\tPlease type correct option\n\n";
        goto start;
    }
    bill = (price_beverage + price_meal);
    tax = (bill * 0.035);
    if (hours >= 16 && hours < 18)
    {
        discount = (0.25 * bill);
    }
    else if (hours < 8)
    {
        discount = (0.5 * bill);
    }
    total_bill = (bill + tax - discount);

    cout << "\n\n\t _______________________________________\n";
    cout << "\t|\t\tTotal Bill\t\t|\n";
    cout << "\t|_______________________________________|\n";
    cout << "\t|\t\t\t\t\t|\n";
    cout << "\t| Bill Amount:\t\t\t" << bill << "\t|\n";
    cout << "\t| 3.5% tax\t\t\t" << tax << "\t|\n";
    cout << "\t| Available Discount\t\t" << discount << "\t|\n";
    cout << "\t|\t\t\t\t\t|\n";
    cout << "\t| Total bill:\t\t\t" << total_bill << "\t|\n";
    cout << "\t|_______________________________________|\n";

    cout << "\n\n\t  ****  Thankyou for Shopping  ****\n";
    cout << "\t  **** [ABRARALI\t55843] ****\n\n";

    return 0;
}