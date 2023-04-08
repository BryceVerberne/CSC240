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
    // The modes tell C if we want to read ('r'), or write ('w') from the file.
    fptr = fopen("TutorialFile.txt", "r");

    // Tip: If the file is not available in the specified location, it will return NULL.
    // We can use an if...else statement to determine if the file is actually open.
    if (fptr != NULL) {
        printf("File Open Successful\n");
    }
    else {
        printf("File Open Unsuccessful\n");
    }


    // --------------
    // Reading a File
    // --------------
    printf("--------------\n");
    printf("Reading a File\n");
    printf("--------------\n");

    // When reading a file in C, we generally read the content to a character array
    char content[1000];

    // We use the 'fgets(<arrayName>, <arraySize>, <pointerName>);' to move the contents into our content array.
    fgets(content, 1000, fptr);

    printf("File Contents:\n");

    // 'fgets()' can only read one line at a time, so we should only expect the first three numbers
    // Now, print the contents
    printf("%s", content);

    // Using a loop can help us get the rest of the file
    // While there is still content, 'fgets()' will return true & the loop will continue. Otherwise, it will exit.
    while(fgets(content, 1000, fptr)) {
        printf("%s", content);
    }

    // When we are done reading a file, it is good practice to close it.
    // We use the 'fclose(<pointerName>);
    fclose(fptr);

    return 0;
}
