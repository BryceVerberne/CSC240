/*
*  Title:  Savings Account
*  Desc:   This program manages a bank account with user input through a SavingsAccount class.
*  Author: Bryce Verberne
*  Date:   04/13/2023
*/



#include <iostream>
#include "Account.h"
using namespace std;

int main() {

    Account client1;  // Create client1 Account object
    Account client2;  // Create client2 Account object

    // Prompt user to enter initial dollar & cent amounts for client1
    cout << "Enter client1's initial deposit" << endl;
    client1.setInitialBalance();

    // Prompt client1 if they want to make a deposit or withdrawal
    client1.depositPrompt();
    client1.withdrawalPrompt();

    // Print the final balance of client2
    client1.printBalance();

    // Prompt user to enter initial dollar & cent amounts
    cout << "\nEnter client2's initial deposit" << endl;
    client2.setInitialBalance();

    // Prompt client2 if they want to make a deposit or withdrawal
    client2.depositPrompt();
    client2.withdrawalPrompt();

    // Print the final balance of client2
    client2.printBalance();

    return 0;
}