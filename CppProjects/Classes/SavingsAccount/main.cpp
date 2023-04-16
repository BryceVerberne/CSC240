/*
*  Title:  Savings Account
*  Desc:   This program manages a bank account with user input through a SavingsAccount class.
*  Author: Bryce Verberne
*  Date:   04/13/2023
*/



#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

int main() {
    int numClients; // The number of clients for the interactive savings account program
    string input; // The input string to store user selections
    bool exit = false; // Flag to determine whether to exit the program or not

    cout << "Welcome to your interactive savings account!" << endl;
    cout << "To begin, enter the number of clients: ";
    cin >> numClients;

    // Check to see if numClients is positive, & if not, ask the user to reenter the value
    while(numClients <= 0) {
        cout << "Please enter a positive number of clients: ";
        cin >> numClients;
    }

    cout << endl;

    Account client[numClients]; // Array of Account objects to store client account information

    // Loop through each client's account and execute user-selected actions
    for (int i = 0; (i < numClients) && (!exit); ++i) {
        client[i].setInitialBalance(i); // Set the initial balance for the current client

        client[i].printOptions(); // Print the available options for the current client
        cin >> input; // Read the user's selected option
        cout << endl;

        // Continue looping until the user selects "n" (Next Client) or "q" (Quit Program)
        while(input != "n") {
            if(input == "b") {
                client[i].printBalance(); // Print the current client's balance
            }
            else if(input == "d") {
                client[i].depositPrompt(); // Prompt the user to deposit money into the current client's account
            }
            else if(input == "w"){
                client[i].withdrawalPrompt(); // Prompt the user to withdraw money from the current client's account
            }
            else if(input == "q") {
                exit = true; // Set the exit flag to true to end the program
                break; // Exit the inner loop
            }
            else {
                cout << "That is not an option. Please try again." << endl;
            }

            client[i].printOptions(); // Print the available options for the current client
            cin >> input; // Read the user's selected option
            cout << endl;
        }
    }

    // Print a summary of all client accounts
    cout << "Client Summary" << endl;
    for(int i = 0; i < numClients; ++i) {
        client[i].printSummary(i); // Print the account summary for the current client
    }

    return 0; // Exit the program
}
