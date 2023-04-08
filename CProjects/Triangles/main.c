/*
*  Title:  Triangles
*  Desc:   This program demonstrates how to read from a file & operate on its information
*  Author: Bryce Verberne
*  Date:   04/07/2023
*/



#include <stdio.h>

int main(int argc, char *argv[]) {

    // To run the compiled program & provide the Triangle1.txt file, type the following:
    //  > gcc -o Triangles
    //  > ./Triangles Triangle1.txt

    // Create FILE pointer
    FILE *f = NULL;

    // Determine if the user provided the file name
    if (argc < 2) {
        printf("> ./%s <filename>\n", argv[0]);

        return 1;
    }

    // Open the file in read mode
    f = fopen(argv[1], "r");

    // Determine if the file has been opened successfully
    if (f != NULL) {
        printf("File Open Successful");
    }
    else {
        printf("File Open Unsuccessful");
    }

    // Close the file
    fclose(f);

    return 0;
}