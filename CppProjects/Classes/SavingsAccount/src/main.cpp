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

// Prototypes
int arraySize();
void fillList(Account *client, int size);
void clientSummary(Account *client, int size);

int main() {
    // Print an introduction for the user
    cout << "Welcome to your interactive savings account!" << endl;

    // Get the number of clients
    int numClients = arraySize();

    // Create an array of Account objects to store client account information
    Account clientList[numClients];

    // Call fillList function to get information from the user about each client
    fillList(clientList, numClients);

    // Print a summary of all client accounts
    clientSummary(clientList, numClients);

    // Exit the program
    return 0;
}


// arraySize
// ---------
// Desc:   Gets the number of clients from the user
// Input:  None
// Output: int value representing the number of clients
int arraySize() {
    int size; // The number of clients for the interactive savings account program

    // Prompt the user for the number of clients
    cout << "To begin, enter the number of clients: ";

    // Check to see if the entered number is positive, & if not, ask the user to reenter the value
    while (!(cin >> size) || (size <= 0)) {
        // Tutorial: https://www.youtube.com/watch?v=m2P5A4nR51g&ab_channel=JesusHilarioHernandez

        cout << "Please enter a positive number of clients: ";

        // Clear the error state of the input stream
        cin.clear();

        // Ignore any remaining characters in the input buffer
        cin.ignore(123, '\n');
    }
    cout << endl;

    // Return the number of clients
    return size;
}

// fillList
// --------
// Desc:   Interacts with the user & performs actions on each client's account
// Input:  Pointer to an array of Account objects, int value representing the number of clients
// Output: None
void fillList(Account *client, int size) {
    string input; // The input string to store user selections
    bool exit = false; // Flag to determine whether to exit the program or not

    // Loop through each client's account & execute user-selected actions
    for (int i = 0; (i < size) && (!exit); ++i) {
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
}

// clientSummary
// -------------
// Desc:   Prints a summary of all client accounts
// Input:  Pointer to an array of Account objects, int value representing the number of clients
// Output: None
void clientSummary(Account *client, int size) {
    cout << "Client Summary" << endl;
    for(int i = 0; i < size; ++i) {
        client[i].printSummary(i); // Print the account summary for the current client
    }
}