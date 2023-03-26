% Title:  Genealogy
% Author: Bryce Verberne
% Desc:   In this program, I am creating a genealogical knowledge base on Amarna Family Tree.
% Date:   03/23/2023


% Knowledge base for a family - Example
/*
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
*/


% Amarna Family Tree - My knowledge base
% The 'male(<name>)' defines that the specified person is male
male(thutmosis_IV).
male(yuya).
male(amenhotep_III).
male(anen).
male(thutmose).
male(akhenaten).
male(horemheb).
male(setepenre).
male(tutakhamun).
male(ay).

% The 'female(<name>)' defines that the specified person is female
female(iset).
female(thuya).
female(mutemwiya).
female(tiye).
female(sitamun).
female(nebetah).
female(mutnodjmet).
female(meritaten).
female(meketaten).
female(neferneferuaten).
female(neferneferure).
female(ankhesenamun).
female(nefertiti).


% The 'parentOf(<parent>, <child>)' predicate defines that the first argument is the parent of the second 
parentOf(thutmosis_IV, amenhotep_III).
parentOf(yuya, tiye).
parentOf(yuya, anen).
parentOf(ay, nefertiti).
parentOf(ay, mutnodjmet).
parentOf(amenhotep_III, thutmose).
parentOf(amenhotep_III, iset).
parentOf(amenhotep_III, sitamun).
parentOf(amenhotep_III, nebetah).
parentOf(amenhotep_III, akhenaten).
parentOf(akhenaten, meritaten).
parentOf(akhenaten, meketaten).
parentOf(akhenaten, neferneferuaten).
parentOf(akhenaten, neferneferure).
parentOf(akhenaten, setepenre).
parentOf(akhenaten, tutakhamun).
parentOf(akhenaten, ankhesenamun).
parentOf(mutemwiya, amenhotep_III).
parentOf(thuya, tiye).
parentOf(thuya, anen).
parentOf(tiye, thutmose).
parentOf(tiye, sitamun).
parentOf(tiye, nebetah).
parentOf(tiye, akhenaten).
parentOf(tiye, iset).
parentOf(nefertiti, meritaten).
parentOf(nefertiti, meketaten).
parentOf(nefertiti, neferneferuaten).
parentOf(nefertiti, neferneferure).
parentOf(nefertiti, setepenre).
parentOf(nefertiti, tutakhamun).
parentOf(nefertiti, ankhesenamun).


% The 'lifepsan(<person>, <birth>, <death>)' predicate defines the birth & death year of the specified person
lifespan(mutemwiya, '14th century BC.', '1386 BC to 1353 BC.').
lifespan(thuya, '1391 BC.', '1353 BC.').
lifespan(tiye, '1398 BC.', '1338 BC.').
lifespan(nefertiti, '1353 BC.', '1336 BC.').
lifespan(thutmosis_IV, '1401 BC.', '1391 BC.').
lifespan(yuya, '18th dynasty', '18th dynasty').
lifespan(ay, 'late 14th century BC.', '1330-1335 BC.').
lifespan(amenhotep_III, '1388 BC.', '1353 BC.').
lifespan(akhenaten, '1353 BC.', '1336 BC.').
lifespan(anen, '1350 BC.', '1325 BC.').
lifespan(thutmose, '14th century BC.', '14th century BC.').
lifespan(horemheb, '1320 BC.', '1292 BC.').
lifespan(setepenre, '1279 BC.', '1213 BC.').
lifespan(tutakhamun, '1341 BC.', '1323 BC.').
lifespan(iset, '~1350 BC.', 'early 13th century BC.').
lifespan(sitamun, '~1350 BC.', 'mid-14th, early 13th century BC.').
lifespan(nebetah, '~1350 BC.', 'mid-14th, early 13th century BC.').
lifespan(mutnodjmet, '~1350 BC.', '1290-1280 BC.').
lifespan(meritaten, '~1351 BC', '1336-1337 BC.').
lifespan(meketaten, '~1349 BC', '1335-1334 BC').
lifespan(neferneferuaten, 'mid-14th century BC.', 'mid-1330s BC.').
lifespan(neferneferure, '~1350 BC.', 'early 13th century BC.').
lifespan(ankhesenamun, '~1348 BC.', '~1320 BC.').


% The following rules are created based off of the predefined facts above.
fatherOf(Dad, Child) :-
  parentOf(Dad, Child),
  male(Dad).

motherOf(Mom, Child) :- 
  parentOf(Mom, Child),
  female(Mom).

sonOf(Child, Parent) :-
  parentOf(Parent, Child),
  male(Child).

daughterOf(Child, Parent) :-
  parentOf(Parent, Child),
  female(Child).

siblingOf(C1, C2) :-
  parentOf(Parent, C1),
  parentOf(Parent, C2),
  C1 \= C2.

brotherOf(Brother, Sibling) :-
  siblingOf(Brother, Sibling),
  male(Brother).

sisterOf(Sister, Sibling) :-
  siblingOf(Sister, Sibling),
  female(Sister).

grandparentOf(Grandparent, Child) :- 
  parentOf(Parent, Child),
  parentOf(Grandparent, Parent).
  
auntOf(Aunt, Child) :-
  parentOf(Parent, Child),
  sisterOf(Aunt, Parent).

uncleOf(Uncle, Child) :-
  parentOf(Parent, Child),
  brotherOf(Uncle, Parent).

% I define ancestor as the immediate last person you descended from & onwards in this rule 
ancestorOf(Ancestor, Person) :-
  parentOf(Ancestor, Person).
ancestorOf(Ancestor, Person) :-
  parentOf(Parent, Person),
  ancestorOf(Ancestor, Parent),
  Ancestor \= Person.