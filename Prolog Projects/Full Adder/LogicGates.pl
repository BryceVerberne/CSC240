% Title:  Full Adder
% Desc:   This program simulates the logic of a full adder.
% Author: Bryce Verberne
% Date:   03/29/2023



% -----------------------
% Logic Gate Predicates
% -----------------------

% This predicate represents the logical AND gate.
% It returns true if both input arguments add up to 2.
andGate(A, B) :-
  A + B =:= 2.

% This predicate represents the logical OR gate.
% It returns true if both input arguments do not add up to 0.
orGate(A, B) :-
  A + B =\= 0.

% This predicate represents the logical NOT gate.
% It returns true if the argument is 0 & false if 1.
notGate(A) :-
  A =:= 0.

% This predicate represents the logical XOR gate.
% It returns true if the two input arguments are not equal to each other.
xorGate(A, B) :-
  A =\= B.
  

% -----------------------
% FullAdder Predicate
% -----------------------


% -----------------------
% nBitAdder Predicate
% -----------------------


% -----------------------
% Test Cases  
% -----------------------

% Testing Logic Gate Methods
% andGate(0 0).
% andGate(0 1).
% andGate(1, 0).
% andGate(1, 1).

% orGate(0, 0).
% orGate(0, 1).
% orGate(1, 0).
% orGate(1, 1).

% notGate(0).
% notGate(1).

% xorGate(0, 0).
% xorGate(0, 1).
% xorGate(1, 0).
% xorGate(1, 1).


% Testing Fulladder Methods
% fullAdder(0, 0, 0).
% fullAdder(0, 0, 1).
% fullAdder(0, 1, 0).
% fullAdder(0, 1, 1).
% fullAdder(1, 0, 0).
% fullAdder(1, 0, 1).
% fullAdder(1, 1, 0).
% fullAdder(1, 1, 1).


% Testing n bit adder Methods
% nBitAdder([0,1,0], [0,1,1], 1).
% nBitAdder([1,1,1], [0,0,0], 1).
% nBitAdder([1,1,0,0,1,0,1,0,1], [1,0,1,1,0,0,0,1,1], 0).