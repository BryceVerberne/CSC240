/*
*  Title:  Pointer Variables
*  Desc:   This program demonstrates the use of pointer variables.
*  Author: Bryce Verberne
*  Date:   04/05/2023
*/



// Program Description:
//  - This program demonstrates the use of pointer variables.
//  - It finds the area of a rectangle given length and width.
//  - It prints the length and width in ascending order.

#include <iostream>
using namespace std;

int main()
{

    int length;	// holds length
    int width;	// holds width
    int area;	// holds area

    int *lengthPtr = nullptr;	// int pointer which will be set to point to length
    int *widthPtr = nullptr;	// int pointer which will be set to point to width

    cout << "Please input the length of the rectangle" << endl;
    cin >> length;

    cout << "Please input the width of the rectangle" << endl;
    cin >> width;

    // Assign 'lengthPtr' to 'length' (hold its address)
    lengthPtr = &length;

    // Assign 'widthPtr' to 'width' (hold its address)
    widthPtr = &width;

    // Get area using our pointers & print to console
    area = *lengthPtr * *widthPtr;
    cout << "The area is " << area << endl;

    // Use pointers to check if length is greater than, less than, or the same as width.
    if (*lengthPtr > *widthPtr) {
        cout << "The length is greater than the width" << endl;
    }
    else if (*lengthPtr < *widthPtr) {
        cout << "The width is greater than the length" << endl;
    }
    else {
        cout << "The width and length are the same" << endl;
    }

    return 0;
}