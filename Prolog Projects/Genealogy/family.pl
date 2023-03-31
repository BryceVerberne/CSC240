% Title:  Genealogy
% Author: Bryce Verberne
% Desc:   In this program, I am creating a genealogical knowledge base on Amarna Family Tree.
% Date:   03/23/2023



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
male(smenkhkare).

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
% Be wary that some of these facts are still subject to debate
parentOf(thutmosis_IV, amenhotep_III).
parentOf(yuya, tiye).
parentOf(yuya, anen).
parentOf(nefertiti, ay).
parentOf(mutnodjmet, ay).
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
parentOf(akhenaten, smenkhkare).
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
parentOf(nefertiti, smenkhkare).

% The 'lifepsan(<person>, <birth>, <death>)' predicate defines the birth & death year of the specified person
% These dates are negative since they took place during BCE
% Be wary that some of these dates are estimates and/or subject to debate
lifespan(mutemwiya, -1400, -1350).
lifespan(thuya, -1400, -1350).
lifespan(tiye, -1398, -1338).
lifespan(nefertiti, -1370, -1330).
lifespan(thutmosis_IV, -1412, -1390).
lifespan(yuya, -1380, -1340).
lifespan(ay, -1390, -1320). 
lifespan(amenhotep_III, -1386, -1353).
lifespan(akhenaten, -1372, -1335).
lifespan(anen, -1340, -1320).
lifespan(thutmose, -1390, -1352).
lifespan(horemheb, -1319, -1292).
lifespan(setepenre, -1350, -1330).
lifespan(tutakhamun, -1341, -1323).
lifespan(iset, -1370, -1330).
lifespan(sitamun, -1370, -1350).
lifespan(nebetah, -1400, -1350).
lifespan(mutnodjmet, -1390, -1330).
lifespan(meritaten, -1351, -1338).
lifespan(meketaten, -1352, -1340).
lifespan(neferneferuaten, -1350, -1335).
lifespan(neferneferure, -1345, -1330).
lifespan(ankhesenamun, -1348, -1322).

% The 'successorOf(<next ruler>, <ruler>)' predicate defines the next pharaoh based on the current. 
successorOf(amenhotep_III, thutmosis_IV).
successorOf(akhenaten, amenhotep_III).
successorOf(smenkhkare, akhenaten).
successorOf(tutakhamun, smenkhkare).
successorOf(ay, tutakhamun).
successorOf(horemheb, ay).


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

% I define ancestor as the immediate last person you descended from & onwards
ancestorOf(Ancestor, Person) :-
  parentOf(Ancestor, Person).
ancestorOf(Ancestor, Person) :-
  parentOf(Parent, Person),
  ancestorOf(Ancestor, Parent),
  Ancestor \= Person.

% I define descendent as the immediate succeeding person & onwards
descendentOf(Descendent, Person) :-
  parentOf(Person, Descendent).
descendentOf(Descendent, Person) :-
  parentOf(Person, Child),
  descendentOf(Descendent, Child),
  Descendent \= Person.

% I define contemporary as someone who is alive at the same time
contemporaryOf(Contemporary, Person) :-
  lifespan(Person, B1, D1),
  lifespan(Contemporary, B2, D2),
  B2 < D1,
  B1 < D2,
  Contemporary \= Person.