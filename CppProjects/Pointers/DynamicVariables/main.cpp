/*
*  Title:  Dynamic Variables
*  Desc:   This program demonstrates the use of dynamic variables.
*  Author: Bryce Verberne
*  Date:   04/05/2023
*/



#include <iostream>
using namespace std;

const int MAXNAME = 10;

int main()
{
    int pos;
    char *name = nullptr;
    int *one = nullptr;
    int *two = nullptr;
    int *three = nullptr;
    int result;

    //	Allocate the integer variable one
    one = new int;

    //	Allocate the integer variable two
    two = new int;

    //	Allocate the integer variable three
    three = new int;

    //	Allocate the character array pointed to by name
    name = new char[10];

    cout << "Enter your last name with exactly 10 characters." << endl;
    cout << "If your name has < 10 characters, repeat last letter. " << endl
         << "Blanks at the end do not count." << endl;

    for (pos = 0; pos < MAXNAME; pos++) {
        cin >> *(name + pos); // Read a character into the name array
    }

    cout << "Hi ";

    for (pos = 0; pos < MAXNAME; pos++) {
        cout << *(name + pos); // Print a character from the name array
    }

    cout << endl << "Enter three integer numbers separated by blanks" << endl;

    // Input three numbers and store them in the
    // dynamic variables pointed to by pointers one, two, and three.
    cout << "Input three integer values:" << endl;
    cin >> *one >> *two >> *three;

    // Echo print
    cout << "The three numbers are ";

    // Output those numbers
    cout << *one << ", " << *two << ", and " << *three << "." << endl;

    // Calculate the sum of the three numbers
    result = *one + *two + *three;

    cout << "The sum of the three values is " << result << endl;

    // Deallocate one, two, three and name
    delete one;
    delete two;
    delete three;
    delete [] name;

    return 0;
}