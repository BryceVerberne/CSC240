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
    printf("Pointer Assignments\n");

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

    *p = 12; // Now, 'a' should have a value of 12. This concept is called dereferencing.

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
    // Pointer Arithemtic
    // -------------------
    printf("\nPointer Arithmetic");

    // Reset our 'p' value
    a = 10;
    p = &a;

    printf("\nAddress of 'p' is: %d\n", p);

    // Print the size of an integer datatype
    printf("Size of an integer is %d bytes.\n", sizeof(int));

    // Add one to 'p'.
    // The address increments by 4 bytes, since this is the size of one word (four bytes or one integer variable).
    printf("Adding 1 to 'p' gives us %d\n", (p+1));

    // Increment 'p' by 2
    // The address will increment by 8 bytes.
    printf("Adding 2 to 'p' gives us %d\n", (p+2));

    // Let's find the value at address p+1 (use a * before our pointer)
    // We get a random value since we have no value allocated to this memory address.
    printf("Value at address 'p'+1 is %d\n", *(p+1));

    return 0;
}
