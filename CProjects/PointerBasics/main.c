/*
*  Title:  Pointer Basics
*  Desc:   This program teaches the basics of using pointers in C.
*  Author: Bryce Verberne
*  Date:   04/05/2023
*/



#include <stdio.h>

int main() {

    // -------------------
    // Pointer Assignments
    // -------------------
    printf("-------------------");
    printf("\nPointer Assignments");
    printf("\n-------------------\n");

    int a = 10;
    int *p = &a;  // This is our pointer. Notice how there is a '*' before the variable name.
                  // By typing '&' before 'a', this stores the address of 'a' in 'p'.
                  // After writing int *p;, p = &a; would effectively land us in the same position
                  // You can also say int* p = &a;

    // Print p (the address of 'a')
    printf("Address of 'p' is: %d\n", p);

    // Print *p (the value that 'a' holds)
    printf("Value at 'p' is: %d\n", *p);

    // Print &a (the address of 'a'). Notice how the output is the same as 'p'.
    printf("Address of 'a' is: %d\n", &a);


    // Modify the value in 'a' with our pointer, 'p'.
    printf("\nOriginal value of 'a' is: %d\n", a);

    *p = 12; // Now, 'a' should have a value of 12. This concept is called de-referencing.

    printf("Modified value of 'a' is: %d\n", a);


    // Give *p a new variable
    int b = 20;
    *p = b;  // This doesn't change the address that 'p' holds, but assigns 'a' to the value of 'b'.
    p = &b;  // This effectively gives 'p' a new address (the address of 'b').

    // Print p (the address of 'b').
    printf("\nNew address of 'p' is: %d\n", p);

    // Print *p (the value that 'b' holds).
    printf("New value at 'p' is: %d\n", *p);


    // -------------------
    // Pointer Arithmetic
    // -------------------
    printf("\n\n-------------------");
    printf("\nPointer Arithmetic");
    printf("\n-------------------");

    // Reset our 'p' value
    a = 10;
    p = &a;

    printf("\nAddress of 'p' is: %d\n", p);

    // Print the size of an integer datatype
    printf("Size of an integer is %d bytes.\n", sizeof(int));

    // Add one to 'p'.
    // The address increments by 4 bytes, since this is the size of one word (four bytes or one integer variable).
    printf("\nAdding 1 to 'p' gives us %d\n", (p+1));

    // Increment 'p' by 2
    // The address will increment by 8 bytes.
    printf("Adding 2 to 'p' gives us %d\n", (p+2));

    // Let's find the value at address p+1 (use a * before our pointer)
    // We get a random value since we have no value allocated to this memory address.
    printf("\nIncremented '*p' gives us %d\n", *(p+1));


    // -------------------
    // Pointer Types
    // -------------------

    // Info:
    //  - Pointer variables are strongly typed. You need a pointer variable of a particular type to store a particular
    //    type of variable. Example: int* -> int & char* -> char.
    //  - Pointer variables don't only store addresses, but they are used to dereference these addresses to access
    //    and modify the values in these addresses.

    printf("\n\n-------------------");
    printf("\nPointer Types");
    printf("\n-------------------");

    a = 1025;
    p = &a;

    // Here is list of the different sizes of data types
    printf("\nData Type Sizes:\n");
    printf("int - %d bytes\n", sizeof(int));
    printf("char - %d bytes\n", sizeof(char));
    printf("float - %d bytes\n", sizeof(float));
    printf("double - %d bytes\n", sizeof(double));

    // Our pointer currently holds the address of 'a' and points to its value.
    printf("\nVariable 'p':\n");
    printf("Address = %d\n", p);
    printf("Value = %d\n", *p);

    // Increment '*p' by one. Hint: Since nothing is allocated to that position in memory, we'll get a random number.
    printf("\nIncrement 'p':\n");
    printf("Address = %d\n", (p+1));
    printf("Value = %d\n", *(p+1));

    // Create a char pointer
    char *p0;
    // p0 = p; ('p0' holds the address of our first pointer, 'p'.)
    // This doesn't work since 'p' is an integer pointer and 'p0' is a character pointer.

    // We can type cast 'p' to character pointer in order for us to assign 'p0' to 'p'.
    p0 = (char*)p;

    // Notice how the address is the same as 'p'. However, why do we get 1 as our value?
    // Since a char is one byte, we only take into consideration the first of four bytes of our 'a' integer variable.
    // For 1025, for example, it is written as 1025 = 00000000 00000000 00000100 00000001.
    // Here, we only consider 0000001, which is 1.
    printf("\nVariable 'p0':\n");
    printf("Address = %d\n", p0);
    printf("Value = %d\n", *p0);

    // Given that we received 00000001 for '*p0', incrementing by 1 in a char pointer should shift us to the next byte.
    // Therefore, we should receive 00000100 or 4.
    printf("\nIncrement '*p0':\n");
    printf("Address = %d\n", (p0+1));
    printf("Value = %d\n", *(p0+1));

    return 0;
}
