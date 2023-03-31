% Title:  Full Adder
% Desc:   This program simulates the logic of a full adder.
% Author: Bryce Verberne
% Date:   03/29/2023



% -----------------------
% Logic Gate Functions
% -----------------------

% 'andGate(<A>, <B>, <Y>)' 
% This function represents the logical AND gate for two binary bits.
andGate(0, 0, 0).
andGate(0, 1, 0).
andGate(1, 0, 0).
andGate(1, 1, 1).

% 'orGate(<A>, <B>, <Y>)' 
% This function represents the logical OR gate for two binary bits.
orGate(0, 0, 0).
orGate(0, 1, 1).
orGate(1, 0, 1).
orGate(1, 1, 1).

% 'notGate(<A>, <Y>)' 
% This function represents the logical NOT gate for one binary bit.
notGate(0, 1).
notGate(1, 0).

% 'xorGate(<A>, <B>, <Y>)' 
% This function represents the logical XOR gate for two binary bits.
xorGate(0, 0, 0).
xorGate(0, 1, 1).
xorGate(1, 0, 1).
xorGate(1, 1, 0).


% -----------------------
% FullAdder Function
% -----------------------

% This function simulates a full adder. It takes two binary digits & a 
% carry-in bit as input, & produces the corresponding sum & carry-out bits.
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
% nBitAdder Function
% -----------------------

% The 'nBitAdder' function adds two binary numbers represented as lists.
rmvLast(List, NewList) :-
  reverse(List, [_|T]),
  reverse(T, NewList).

nBitAdder(A, B, Cin, Sum, Cout) :-
  length(A, Length),
  Length = 0.

nBitAdder(A, B, Cin, Sum, Cout) :-
  length(A, LengthA),

  nth1(LengthA, A, ValA),
  nth1(LengthA, B, ValB),

  fullAdder(ValA, ValB, Cin, S, C),

  write(A), nl,
  write(B), nl,

  rmvLast(A, NewA), 
  rmvLast(B, NewB),

  write(NewA),
  write(ValA), nl,
  write(NewB),
  write(ValB), nl,

  write('This is the sum: '),
  write(S), nl,

  nBitAdder(NewA, NewB, C, S, Cout).
  

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