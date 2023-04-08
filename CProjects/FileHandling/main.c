/*
*  Title:  File Handling
*  Desc:   This program demonstrates how to work with files in C.
*  Author: Bryce Verberne
*  Date:   04/07/2023
*/



#include <stdio.h>

int main() {

    // --------------
    // Opening a File
    // --------------
    printf("--------------\n");
    printf("Opening a File\n");
    printf("--------------\n");

    // We use the file pointer 'FILE*' to work with files.
    FILE* fptr;  // 'fptr' is the name of the file pointer.

    // We can use the 'fopen("<filename.txt>", "<mode>")' function to open a file.
    // The modes tell C if we want to read ('r') to or write ('w') from the file.
    fptr = fopen("TutorialFile.txt", "r");

    // Tip: If the file is not available in the specified location, it will return NULL.
    // We can use an if...else statement to determine if the file is actually open.
    if (fptr != NULL) {
        printf("File Open Successful\n");
    }
    else {
        printf("File Open Unsuccessful\n");
    }

    // When we are done reading a file, it is good practice to close it.
    // We use the 'fclose(<filePointer>);
    fclose(fptr);


    // --------------
    // Reading a File
    // --------------
    printf("\n--------------\n");
    printf("Reading a File\n");
    printf("--------------\n");

    // Start by opening the file
    fptr = fopen("TutorialFile.txt", "r");

    // Check to ensure that the file was successfully opened
    if (fptr != NULL) {
        printf("File Open Successful\n");
    }
    else {
        printf("File Open Unsuccessful\n");
    }

    // When reading a file in C, we generally read the content to a character array
    char content[1000];

    // We use the 'fgets(<arrayName>, <arraySize>, <filePointer>);' to move the contents into our content array.
    fgets(content, 1000, fptr);

    printf("\nFile Contents:\n");

    // 'fgets()' can only read one line at a time, so we should only expect the first three numbers
    // Now, print the contents
    printf("%s", content);

    // Using a loop can help us get the rest of the file
    // While there is still content, 'fgets()' will return true & the loop will continue. Otherwise, it will exit.
    while(fgets(content, 1000, fptr)) {
        printf("%s", content);
    }

    // Close the file
    fclose(fptr);


    // -----------------
    // Writing to a File
    // -----------------
    // IMPORTANT: Whenever we open a file that already exists in write mode, all of its current contents will be erased.

    printf("\n\n-----------------\n");
    printf("Writing to a File\n");
    printf("-----------------\n");

    // We use the 'fopen("<filename.txt>", "<mode>")' function to open a file.
    // The modes tell C if we want to read ('r') to or write ('w') from the file.
    // Tip: When using this to write to a file, if the file name specified has not been created,
    //      one will be created for you with the name that you specify.
    fptr = fopen("NewFile.txt", "w");

    // Check to ensure that the file was successfully opened
    if (fptr != NULL) {
        printf("File Open Successful\n");
    }
    else {
        printf("File Open Unsuccessful\n");
    }

    // We can write to a file with the 'fputs("<message>", <filePointer>);' function.
    fputs("This is my new file!\n", fptr);
    fputs("I don't know what to put here.\n", fptr);

    // Close the file
    fclose(fptr);


    // Let's now read from the file we created
    // Start by opening the file
    fptr = fopen("NewFile.txt", "r");

    // Get it's contents
    printf("\nFile Contents:\n");

    // Print the file's contents using a while loop
    while(fgets(content, 1000, fptr)) {
        printf("%s", content);
    }

    // Close the file
    fclose(fptr);


    return 0;
}
