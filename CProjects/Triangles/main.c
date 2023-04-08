/*
*  Title:  Triangles
*  Desc:   This program demonstrates how to read from a file & operate on its contents.
*  Author: Bryce Verberne
*  Date:   04/07/2023
*/



#include <stdio.h>

int main(int argc, char *argv[]) {

    // Declare & initialize FILE pointer
    FILE *f = NULL;

    // Declare triangle dimension variables
    int val1;
    int val2;
    int val3;

    // Determine if the user provided the file name
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the file in read mode
    f = fopen(argv[1], "r");

    // Determine if the file has been opened successfully
    if (f == NULL) {
        printf("File %s cannot be opened.\n", argv[1]);
        return 1;
    }

    // Output acceptable triangle dimensions
    //  - Criteria:
    //     1. a + b > c
    //     2. a + c > b
    //     3. b + c > a
    while (fscanf(f, "%d, %d, %d\n", &val1, &val2, &val3) == 3) {
        if ((val1 + val2) > val3) {          // a + b > c
            if ((val1 + val3) > val2) {      // a + c > b
                if ((val2 + val3) > val1) {  // b + c > a
                    // Print the triangle dimensions
                    printf("%d, %d, %d\n", val1, val2, val3);
                }
            }
        }
    }

    // Close the file
    fclose(f);

    return 0;
}