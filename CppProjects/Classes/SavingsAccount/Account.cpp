/*
*  Title:  Savings Account
*  Desc:   This program implements the Account class
*  Author: Bryce Verberne
*  Date:   04/13/2023
*/



#include <iostream>
#include <string>
#include <limits>
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
    dollars += initCents / 100; // Divide initCents by 100 to get the dollar amount
    cents = initCents % 100;    // Use modulo operator to get the remaining cents
}

// setInitialBalance
// -----------------
// Desc:   Prompts user to enter initial balance in dollars & cents for a specified client
// Input:  int value representing the client number
// Output: None
void Account::setInitialBalance(int clientNum) {
    int initDollars;
    int initCents;

    // Prompt user to enter initial dollar & cent amounts
    cout << "Enter Client " << (clientNum + 1) << "'s initial balance" << endl;

    cout << "Input Dollars: ";

    // Check to see if initDollars is positive, & if not, ask the user to reenter a value
    while (!(cin >> initDollars) || (initDollars < 0)) {
        // Clear the error state of the input stream
        cin.clear();

        // Ignore any remaining characters in the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Please enter a positive dollar value: ";
    }

    cout << "Input Cents: ";

    // Check to see if centAmount is positive, & if not, ask the user to reenter a value
    while (!(cin >> initCents) || (initCents < 0)) {
        // Clear the error state of the input stream
        cin.clear();

        // Ignore any remaining characters in the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Please enter a positive cent value: ";
    }

    // Set the entered dollar & cent amounts in the Account object
    setDollars(initDollars);
    setCents(initCents);
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

            // Check to see if dollarAmount is positive, & if not, ask the user to reenter a value
            while (!(cin >> dollarAmount) || (dollarAmount < 0)) {
                // Clear the error state of the input stream
                cin.clear();

                // Ignore any remaining characters in the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Please enter a positive dollar value: ";
            }

            // Prompt user to input the cent amount to be deposited
            cout << "Input the cents to be deposited: ";

            // Check to see if centAmount is positive, & if not, ask the user to reenter a value
            while (!(cin >> centAmount) || (centAmount < 0)) {
                // Clear the error state of the input stream
                cin.clear();

                // Ignore any remaining characters in the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Please enter a positive cent value: ";
            }

            // Add the deposited dollar amount to the account
            // Also, add the deposited cent amount divided by 100 to the account (to handle cent overflow)
            dollars += dollarAmount + ((cents + centAmount) / 100);

            // Update the cent amount by adding the deposited cent amount & taking the remainder when divided by 100
            cents = (cents + centAmount) % 100;

            // Prompt user to enter if they want to make another deposit
            cout << endl << "Would you like to make another deposit? [y/n]" << endl;
            cin >> input;
        }
        else {
            // Display a message if the user input is not valid
            cout << "That is not a valid entry. Please try again.";

            // Prompt user to reenter a valid character
            cout << endl << "Press 'y' (yes) or 'n' (no) to make a deposit." << endl;
            cin >> input;
        }

    }
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

            // Check to see if dollarAmount is positive, & if not, ask the user to reenter a value
            while (!(cin >> dollarAmount) || (dollarAmount < 0)) {
                // Clear the error state of the input stream
                cin.clear();

                // Ignore any remaining characters in the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Please enter a positive dollar value: ";
            }

            // Prompt user to input the cent amount to be withdrawn
            cout << "Input the cents to be withdrawn: ";

            // Check to see if centAmount is positive, & if not, ask the user to reenter a value
            while (!(cin >> centAmount) || (centAmount < 0)) {
                // Clear the error state of the input stream
                cin.clear();

                // Ignore any remaining characters in the input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Please enter a positive cent value: ";
            }

            // Combine dollar & cent amounts, handling cents overflow
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

            // Prompt user to enter if they want to make another deposit
            cout << endl << "Would you like to make another withdrawal? [y/n]" << endl;
            cin >> input;
        }
        else {
            // Display a message if the user input is not valid
            cout << "That is not a valid entry. Please try again.";

            // Prompt user to reenter a valid character
            cout << endl << "Press 'y' (yes) or 'n' (no) to make a withdrawal." << endl;
            cin >> input;
        }
    }
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

// printSummary
// ------------
// Desc:   Prints the summary of the Account object for a specified client.
// Input:  int value representing the client number
// Output: Displays the client number & their balance in dollars & cents on the console.
void Account::printSummary(int clientNum) const {
    cout << " - Client " << (clientNum + 1) << endl;
    cout << "    Dollars = $" << dollars << endl;
    cout << "    Cents =   ¢" << cents << endl;
}

// printOptions
// ------------
// Desc:   Prints the available options for interacting with the Account object.
// Input:  None.
// Output: Displays the list of options & their corresponding keys on the console.
void Account::printOptions() const {
    cout << endl << "OPTIONS" << endl;
    cout << "b - See Balance" << endl;
    cout << "d - Deposit Money" << endl;
    cout << "w - Withdraw Money" << endl;
    cout << "n - Next Client" << endl;
    cout << "q - Quit Program" << endl << endl;
    cout << "Choose an option: ";
}