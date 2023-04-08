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
        printf("File Open Successful");
    }
    else {
        printf("File Open Unsuccessful");
    }

    return 0;
}
