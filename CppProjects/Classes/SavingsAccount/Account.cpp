/*
*  Title:  Savings Account
*  Desc:   This program implements the Account class
*  Author: Bryce Verberne
*  Date:   04/13/2023
*/



#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

// Default Constructor
// -------------------
// Desc: Initializes an empty Account object with dollars & cents set to 0
Account::Account() {
    dollars = 0;
    cents = 0;
}

// Parameterized Constructor
// -------------------------
// Desc:   Initializes an Account object with specified dollars & cents
// Input:  int values for dollars & cents
// Output: None
Account::Account(int initDollars, int initCents) {
    dollars = initDollars;
    setCents(initCents);
}

// setDollars
// ----------
// Desc:   Sets the dollar amount in the Account object
// Input:  int value representing the dollar amount
// Output: None
void Account::setDollars(int initDollars) {
    dollars = initDollars;
}

// setCents
// --------
// Desc:   Sets the cents amount in the Account object
// Input:  int value representing the cents amount
// Output: None
void Account::setCents(int initCents) {
    dollars += initCents / 100;
    cents = initCents % 100;
}

void Account::setInitialBalance() {
    int dollars;
    int cents;

    cout << "Input Dollars: ";
    cin >> dollars;
    cout << "Input Cents: ";
    cin >> cents;

    cout << endl;

    setDollars(dollars);
    setCents(cents);

    printOptions();
}

// depositPrompt
// -------------
// Desc:   Prompts the user to deposit money into the account.
//         Adds the deposited amount to the private data members dollars & cents.
// Input:  None.
// Output: None.
void Account::depositPrompt() {
    string input;         // Input string for user's choice (y/n)
    int dollarAmount;     // Dollar amount to be deposited
    int centAmount;       // Cent amount to be deposited

    // Prompt user to enter if they want to make a deposit
    cout << "Would you like to make a deposit? [y/n]" << endl;
    cin >> input;

    // Continue the loop until the user inputs 'n' or 'N'
    while (input != "n" && input != "N") {

        // If user inputs 'y' or 'Y', proceed with deposit
        if (input == "y" || input == "Y") {
            // Prompt user to input the dollar amount to be deposited
            cout << "Input the dollars to be deposited: ";
            cin >> dollarAmount;

            // Check to see if dollarAmount is positive, & if not, ask the user to reenter a value
            while (dollarAmount < 0) {
                cout << "Please enter a positive dollar value: ";
                cin >> dollarAmount;
            }

            // Prompt user to input the cent amount to be deposited
            cout << "Input the cents to be deposited: ";
            cin >> centAmount;

            // Check to see if centAmount is positive, & if not, ask the user to reenter a value
            while (centAmount < 0) {
                cout << "Please enter a positive cent value: ";
                cin >> centAmount;
            }

            // Add the deposited dollar amount to the account
            // Also, add the deposited cent amount divided by 100 to the account (to handle cent overflow)
            dollars += dollarAmount + ((cents + centAmount) / 100);

            // Update the cent amount by adding the deposited cent amount and taking the remainder when divided by 100
            cents = (cents + centAmount) % 100;
        }
        else {
            // Display a message if the user input is not valid
            cout << "That is not a valid entry. Please try again.";
        }

        cout << endl;
        printBalance();

        // Prompt user to enter if they want to make another deposit
        cout << endl << "Would you like to make a deposit? [y/n]" << endl;
        cin >> input;
    }

    cout << endl;
}


// withdrawalPrompt
// ----------------
// Desc:   Prompts the user to withdraw money from the account.
//         Deducts the withdrawn amount from the private data members dollars & cents.
// Input:  None.
// Output: None.
void Account::withdrawalPrompt() {
    string input;         // Input string for user's choice (y/n)
    int dollarAmount;     // Dollar amount to be withdrawn
    int centAmount;       // Cent amount to be withdrawn
    int numDollars = 0;   // Used for handling cases when cents amount is larger than current cents

    // Prompt user to enter if they want to make a withdrawal
    cout << "Would you like to make a withdrawal? [y/n]" << endl;
    cin >> input;

    // Continue the loop until the user inputs 'n' or 'N'
    while (input != "n" && input != "N") {

        // If user inputs 'y' or 'Y', proceed with withdrawal
        if (input == "y" || input == "Y") {
            // Prompt user to input the dollar amount to be withdrawn
            cout << "Input the dollars to be withdrawn: ";
            cin >> dollarAmount;

            // Check to see if dollarAmount is positive, & if not, ask the user to reenter a value
            while (dollarAmount < 0) {
                cout << "Please enter a positive dollar value: ";
                cin >> dollarAmount;
            }

            // Prompt user to input the cent amount to be withdrawn
            cout << "Input the cents to be withdrawn: ";
            cin >> centAmount;

            // Check to see if centAmount is positive, & if not, ask the user to reenter a value
            while (centAmount < 0) {
                cout << "Please enter a positive cent value: ";
                cin >> centAmount;
            }

            // Combine dollar and cent amounts, handling cents overflow
            dollarAmount += centAmount / 100;
            centAmount %= 100;

            // Check if the account has sufficient funds for withdrawal
            if ((dollars - dollarAmount) >= 0) {
                // Check if the account has enough cents to complete the transaction
                if (((cents + ((dollars - dollarAmount) * 100)) - centAmount) >= 0) {
                    // Deduct the withdrawn dollar amount from the account
                    dollars -= dollarAmount;

                    // Check if the current cent amount is smaller than the cent amount to be withdrawn
                    if (cents < centAmount) {
                        // Calculate the number of dollars to be converted to cents
                        while ((numDollars * 100) < (centAmount - cents)) {
                            ++numDollars;
                        }

                        // Deduct the converted dollars from the account
                        dollars -= numDollars;
                        // Update the cent amount after the conversion
                        cents = (numDollars * 100) - (centAmount - cents);
                    }
                    else {
                        // Deduct the withdrawn cent amount from the account
                        cents -= centAmount;
                    }
                }
            }
            else {
                // Display a message if the account has insufficient funds
                cout << "Declined Transaction: Insufficient funds" << endl;
            }
        }
        else {
            // Display a message if the user input is not valid
            cout << "That is not a valid entry. Please try again.";
        }

        cout << endl;
        printBalance();

        // Prompt user to enter if they want to make another withdrawal
        cout << endl << "Would you like to make a withdrawal? [y/n]" << endl;
        cin >> input;
    }
    cout << endl;
}

// printBalance
// ------------
// Desc:   Prints the current balance in the Account object.
// Input:  None.
// Output: Displays the balance in dollars & cents on the console.
void Account::printBalance() const {
    cout << "Current Balance" << endl;
    cout << "--------------------------" << endl;
    cout << "Dollars = $" << dollars << " Cents = ¢" << cents << endl;
}

void Account::printOptions() const {
    cout << "OPTIONS" << endl;
    cout << "b - See Balance" << endl;
    cout << "d - Deposit Money" << endl;
    cout << "w - Withdraw Money" << endl << endl;
}