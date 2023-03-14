# A knowledge base for a family
male(bob).
male(mike).

female(jane).
female(elaine).
mother_of(jane, elaine).
mother_of(jane, mike).
mother_of(elaine, bob).

father_of(david, elaine).
father_of(david, mike).

sibling_of(X, Y) :- mother_of(P, X), mother_of(P, Y).
sibling_of(X, Y) :- father_of(P, X), father_of(P, Y).

grandmother_of(X, Z) :- mother_of(X, Y), mother_of(Y, Z).
grandmother_of(X, Z) :- mother_of(X, Y), father_of(Y, Z).