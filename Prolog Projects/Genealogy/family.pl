% Title:  Genealogy
% Author: Bryce Verberne
% Desc:   In this program, I am creating a genealogical knowledge base on the Amarna Family Tree.
% Date:   03/14/2023


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

% Add male() & female() facts
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


% Add parentOf() facts
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


% Add lifespan() facts
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


% Add rulerOf() facts
rulerOf(thutmosis_IV, 'Egypt', '1401 BC.', '1391 BC.').
rulerOf(amenhotep_III, 'Egypt', '1391 BC.', '1353 BC.').
rulerOf(akhenaten, 'Egypt', '1353 BC.', '1336 BC.').
rulerOf(horemheb, 'Egypt', '1319 BC.', '1292 BC.').
rulerOf(setepenre, 'Egypt', '~14th century', '~14th century').
rulerOf(tutankhamun, 'Egypt', '1332 BC.', '1323 BC.').
rulerOf(ay, 'Egypt', '1323 BC.', '1319 BC.').
rulerOf(neferneferuaten, 'Egypt', '1353 BC.', '1336 BC').