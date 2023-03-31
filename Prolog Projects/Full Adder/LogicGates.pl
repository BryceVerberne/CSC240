% Title:  Full Adder
% Desc:   This program simulates the logic of a full adder.
% Author: Bryce Verberne
% Date:   03/29/2023



% -----------------------
% Logic Gate Predicates
% -----------------------

% The 'andGate(<A>, <B>, <Y>)' predicate represents the logical AND gate for two binary bits.
andGate(0, 0, 0).
andGate(0, 1, 0).
andGate(1, 0, 0).
andGate(1, 1, 1).

% The 'orGate(<A>, <B>, <Y>)' predicate represents the logical OR gate for two binary bits.
orGate(0, 0, 0).
orGate(0, 1, 1).
orGate(1, 0, 1).
orGate(1, 1, 1).

% The 'notGate(<A>, <Y>)' predicate represents the logical NOT gate for one binary bit.
notGate(0, 1).
notGate(1, 0).

% The 'xorGate(<A>, <B>, <Y>)' predicate represents the logical XOR gate for two binary bits.
xorGate(0, 0, 0).
xorGate(0, 1, 1).
xorGate(1, 0, 1).
xorGate(1, 1, 0).


% -----------------------
% FullAdder Predicate
% -----------------------

% This function simulates a full adder. It takes two binary digits & a carry-in bit as input, 
% & produces the corresponding sum & carry-out bits.
fullAdder(A, B, Cin, Sum, Cout) :-
  % Sum = (A ⊕ B) ⊕ Cin
  xorGate(A, B, C),
  xorGate(C, Cin, Sum),

  % Cout = ((A + B) • Cin) + (A • B)
  orGate(A, B, D),
  andGate(D, Cin, E),
  andGate(A, B, F),
  orGate(E, F, Cout).


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