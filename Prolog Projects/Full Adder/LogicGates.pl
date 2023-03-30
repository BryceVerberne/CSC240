% Title:  Full Adder
% Desc:   This program simulates the logic of a full adder.
% Author: Bryce Verberne
% Date:   03/29/2023



%;-----------------------
%; Logic Gate Functions
%;-----------------------


%;-----------------------
%; FullAdder Function
%;-----------------------


%;-----------------------
%; nBitAdder Function
%;-----------------------


%;-----------------------
%; Test Cases  
%;-----------------------

%(newline)
%(writeln "Testing Logic Gate Methods")
%(newline)
%(andgate 0 0)
%(andgate 0 1)
%(andgate 1 0)
%(andgate 1 1)
%(orgate 0 0)
%(orgate 0 1)
%(orgate 1 0)
%(orgate 1 1)
%(notgate 0)
%(andgate 1)
%(xorgate 0 0)
%(xorgate 0 1)
%(xorgate 1 0)
%(xorgate 1 1)


%(writeln "Testing Fulladder Methods")
%(newline)
%(fulladder 0 0 0)
%(fulladder 0 0 1)
%(fulladder 0 1 0)
%(fulladder 0 1 1)
%(fulladder 1 0 0)
%(fulladder 1 0 1)
%(fulladder 1 1 0)
%(fulladder 1 1 1)

(writeln "Testing n bit adder Methods")
(newline)
(n-bit-addr '(0 1 0) '(0 1 1) 1)
(n-bit-addr '(1 1 1) '(0 0 0) 1)
(n-bit-addr '(1 1 0 0 1 0 1 0 1) '(1 0 1 1 0 0 0 1 1) 0)