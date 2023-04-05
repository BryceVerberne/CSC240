# Volume of N Cones

A C program to calculate the total volume of N cones, based on user input for the number of cones and their dimensions.

## Description

This program computes the total volume of N cones, where N is a number entered by the user. The program prompts the user to input the number of cones, and for each cone, the user inputs the radius and height. The program then calculates the volume of each cone and outputs the total volume of all the cones.

## Features
- Supports calculation of multiple cone volumes at once.
- Validates user input and ensures that only positive numbers are used for the number of cones, radius, and height.
- Uses a separate function to calculate the volume of each cone.

## Usage

1. Ensure you have a compatible C compiler installed on your system (e.g. [GCC](https://gcc.gnu.org/)).
2. Compile the `main.c` file using a C compiler (e.g. gcc volume_of_cones.c -o volume_of_cones).
3. Run the compiled program (e.g. ./volume_of_cones).
4. Follow the prompts to enter the number of cones and the radius and height of each cone.
5. The program will output the total volume of all cones.

## Example

```plaintext
Welcome to the Volume of Cones Program
How many Cones do you wish to calculate? 2
Enter the radius for cone 1: 5
Enter the height for cone 1: 7
Enter the radius for cone 2: 3
Enter the height for cone 2: 4
The total volume of 2 cones is 220.48
```
