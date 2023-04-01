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
% carry-in bit as input, & then produces the corresponding sum & carry-out bits.
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

% The nBitAdder function builds upon the FullAdder by allowing the user to add two
% binary numbers of n length. 
last(X, [X]).

last(X, [ _ | Tail]) :- 
  last(X, Tail).

rmvLast(List, NewList) :-
  append(NewList, [_], List).

adder([], [], Cin, [], Cin).

adder(A, B, Cin, Sum, Cout) :-

  last(ValA, A),
  last(ValB, B),

  fullAdder(ValA, ValB, Cin, S, C),

  rmvLast(A, NewA),
  rmvLast(B, NewB),

  adder(NewA, NewB, C, NewSum, Cout),
  Sum = [S | NewSum].

nBitAdder(A, B, Cin, ReversedSum, Cout) :-
  adder(A, B, Cin, Sum, Cout),
  reverse(Sum, ReversedSum).


% -----------------------
% Test Cases  
% -----------------------

% Testing Logic Gate Methods
andGateTest :-
  write('A  B  Y'), nl,
  andOut(0,0),
  andOut(0,1),
  andOut(1,0),
  andOut(1,1).

orGateTest :-
  write('A  B  Y'), nl,
  orOut(0,0),
  orOut(0,1),
  orOut(1,0),
  orOut(1,1).

notGateTest :-
  write('A  Y'), nl,
  notOut(0),
  notOut(1).

xorGateTest :-
  write('A  B  Y'), nl,
  xorOut(0, 0),
  xorOut(0, 1),
  xorOut(1, 0),
  xorOut(1, 1).


% Testing Fulladder Methods  
fullAdderTest :-
  write('A  B  Cin  Cout  Sum'), nl,
  fullAdderOut(0,0,0),
  fullAdderOut(0,0,1),
  fullAdderOut(0,1,0),
  fullAdderOut(0,1,1),
  fullAdderOut(1,0,0),
  fullAdderOut(1,0,1),
  fullAdderOut(1,1,0),
  fullAdderOut(1,1,1).


% Testing n bit adder Methods
nBitAdderTest :-
  nBitAdderOut([0,1,0], [0,1,1], 1), nl,
  nBitAdderOut([1,1,1], [0,0,0], 1), nl,
  nBitAdderOut([1,1,0,0,1,0,1,0,1], [1,0,1,1,0,0,0,1,1], 0).


% Below are my functions that print to console.
andOut(A, B) :-
  andGate(A, B, Y),
  format('~w  ~w  ~w~n', [A, B, Y]).

orOut(A, B) :-
  orGate(A, B, Y),
  format('~w  ~w  ~w~n', [A, B, Y]).

notOut(A) :-
  notGate(A, Y),
  format('~w  ~w~n', [A, Y]).

xorOut(A, B) :-
  xorGate(A, B, Y),
  format('~w  ~w  ~w~n', [A, B, Y]).

fullAdderOut(A, B, C) :-
  fullAdder(A, B, C, Sum, Carry),
  format('~w  ~w   ~w    ~w     ~w~n', [A, B, C, Carry, Sum]).

nBitAdderOut(A, B, C) :-
  nBitAdder(A, B, C, Sum, Carry),
  format('A:   ~w  Cout: ~w~nB:   ~w  Sum:  ~w~nCin: ~w~n', [A,Carry,B,Sum,C]).