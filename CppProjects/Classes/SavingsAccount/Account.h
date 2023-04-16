/*
*  Title:  Account
*  Desc:   This program contains the declarations of the Account class.
*  Author: Bryce Verberne
*  Date:   04/13/2023
*/



// Account class declaration
class Account {
public:

    // Default Constructor: Initializes an empty Account object with dollars & cents set to 0
    Account();

    // Parameterized Constructor: Initializes an Account object with specified dollars & cents
    Account(int initDollars, int initCents);

    // Destructor: Cleans up resources when the Account object is destroyed
    ~Account() = default;

    // setDollars: Sets the dollar amount in the Account object
    void setDollars(int initDollars);

    // setCents: Sets the cents amount in the Account object
    void setCents(int initCents);

    // depositPrompt: Prompts the user to deposit money into the account & updates the account balance
    void depositPrompt();

    // withdrawalPrompt: Prompts the user to withdraw money from the account & updates the account balance
    void withdrawalPrompt();

    // printBalance: Prints the current balance in the Account object
    void printBalance() const;

private:
    int dollars; // Holds the dollar amount in the account
    int cents;   // Holds the cents amount in the account
};