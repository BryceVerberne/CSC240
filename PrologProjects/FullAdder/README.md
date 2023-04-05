# Full Adder

A Prolog program that simulates a full adder using basic logic gates and allows adding binary numbers of arbitrary length.

## Description

This Prolog program simulates the logic of a full adder. It provides functions for basic logic gates (AND, OR, NOT, and XOR) and a full adder implementation, which can be used to add two binary numbers of arbitrary length. Additionally, this program includes test cases for each of these components.

## Program Structure

The program consists of several parts:

### Logic Gate Functions

The program includes implementations of the following logic gates:

- AND gate: `andGate/3`
- OR gate: `orGate/3`
- NOT gate: `notGate/2`
- XOR gate: `xorGate/3`

Each gate function takes binary input values as arguments and outputs the resulting binary value.

### Full Adder Function

The `fullAdder/5` function simulates a full adder, taking two binary digits and a carry-in bit as input, and then produces the corresponding sum and carry-out bits.

### n-Bit Adder Function

The `nBitAdder/5` function builds upon the Full Adder by allowing the user to add two binary numbers of n length. It takes two lists of binary digits and a carry-in bit as input, and then produces the resulting sum and carry-out bits.

### Test Cases

The program includes test cases for each of the implemented functions:

- Logic gate tests:
  - `andGateTest/0`
  - `orGateTest/0`
  - `notGateTest/0`
  - `xorGateTest/0`
- Full adder test: `fullAdderTest/0`
- n-Bit adder test: `nBitAdderTest/0`

To run the tests, simply call the respective test predicates.

## Usage

1. Ensure you have a compatible Prolog interpreter installed on your system (e.g. [SWI-Prolog](https://www.swi-prolog.org/Download.html)).
2. Load the `LogicGates.pl` file into the Prolog interpreter.
3. Call the desired functions with appropriate input values.
4. For testing, run the corresponding test predicates (e.g., `andGateTest`, `fullAdderTest`, `nBitAdderTest`).

## Example

The examples below demonstrate how to use the `fullAdder` and `nBitAdder` functions and execute a test case for the `fullAdderTest`.

```plaintext
?- fullAdder(1, 0, 1, Sum, Cout).
Sum = 0,
Cout = 1 .

?- nBitAdder([1, 0, 1], [1, 1, 0], 0, Sum, Cout).
Sum = [0, 1, 1],
Cout = 1 .

?- fullAdderTest.
A  B  Cin  Cout  Sum
0  0   0    0     0
0  0   1    0     1
0  1   0    0     1
0  1   1    1     0
1  0   0    0     1
1  0   1    1     0
1  1   0    1     0
1  1   1    1     1
true .
```
