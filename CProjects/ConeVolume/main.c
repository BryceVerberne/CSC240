/*
*  Title:  Volume of N Cones
*  Desc:   This program computes the total volume of N cones, where N is a number entered by the user.
*  Author: Bryce Verberne
*  Date:   02/13/2023
*/



/**
*   Volume of N Cones
*/
#include <stdio.h>
#include <math.h>

#define PI M_PI  // Pi constant variable

// Prototypes
float computeVolume(float, float);

// Main method.
int main(void) {

    // Declare Variables
    float height;           // In inches
    float radius;           // In inches
    float totalVolume = 0;  // Total volume of all cones
    int numCones;           // Number of cones

    printf("Welcome to the Volume of Cones Program\n");

    // Get numCones
    printf("How many Cones do you wish to calculate? ");
    scanf("%d", &numCones);

    // Request positive input
    while (numCones < 0) {
        printf("Please enter a number > 0: ");
        scanf("%d", &numCones);
    }

    // Request information and calculate the volume of every cone
    for (int i = 0; i < numCones; ++i) {
        // Get radius
        printf("Enter the radius for cone %d: ", (i + 1));
        scanf("%f", &radius);

        // Request positive input
        while (radius < 0) {
            printf("Please enter a positive radius: ");
            scanf("%f", &radius);
        }

        // Get height
        printf("Enter the height for cone %d: ", (i + 1));
        scanf("%f", &height);

        // Request positive input
        while (height < 0) {
            printf("Please enter a positive height: ");
            scanf("%f", &height);
        }

        // Do Processing
        totalVolume += computeVolume(height, radius);
    }

    // Output Results
    printf("The total volume of %d cones is %.2f\n", numCones, totalVolume);
    printf("Goodbye\n");

    return 0;
}

/**
* computeVolume method
*/
// This method calculates and returns the volume
float computeVolume(float h, float r) {
    return (1.0 / 3.0) * PI * pow(r, 2) * h;
}