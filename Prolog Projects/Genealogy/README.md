# Genealogy: Amarna Family Tree

This program is a genealogical knowledge base on the Amarna Family Tree, which consists of ancient Egyptian royalty.

## Description

The Amarna Family Tree Genealogy program uses Prolog to define relationships and properties of the family members. It includes information about the gender, parentage, and lifespan of each individual. Additionally, the program features rules to determine more complex relationships, such as siblings, aunts, uncles, and ancestors.

## Program Overview

The program includes the following predicates:

<details>
  <summary><b>Click to expand: Predicates</b></summary>

  - `male(<name>)`
  - `female(<name>)`
  - `parentOf(<parent>, <child>)`
  - `lifespan(<person>, <birth>, <death>)`
  - `successorOf(<next ruler>, <ruler>)`
  - `fatherOf(<father>, <child>)`
  - `motherOf(<mother>, <child>)`

</details>

Additional rules are provided to determine family relationships, ancestors, descendants, and contemporaries:

<details>
  <summary><b>Click to expand: Rules</b></summary>

- `fatherOf(Dad, Child)`
- `motherOf(Mom, Child)`
- `sonOf(Child, Parent)`
- `daughterOf(Child, Parent)`
- `siblingOf(C1, C2)`
- `brotherOf(Brother, Sibling)`
- `sisterOf(Sister, Sibling)`
- `grandparentOf(Grandparent, Child)`
- `auntOf(Aunt, Child)`
- `uncleOf(Uncle, Child)`
- `ancestorOf(Ancestor, Person)`
- `descendentOf(Descendent, Person)`.
- `contemporaryOf(Contemporary, Person)`

</details>

## Usage

1. Ensure you have a compatible Prolog interpreter installed on your system (e.g. [SWI-Prolog](https://www.swi-prolog.org/Download.html)).
2. Load the `family.pl` program into the Prolog interpreter.
3. Query the knowledge base to explore relationships and properties of the Amarna Family Tree members.

## Example

This example demonstrates various queries using the given family relationship rules and predicates in the "Genealogy" program.

```plaintext
?- fatherOf(amenhotep_III, akhenaten).
true.

?- motherOf(X, akhenaten).
X = tiye.

?- motherOf(tiye, X).
X = thutmose ;
X = sitamun ;
X = nebetah ;
X = akhenaten ;
X = iset.

?- ancestorOf(X, tutakhamun).
X = akhenaten ;
X = nefertiti ;
X = amenhotep_III ;
X = tiye ;
X = thutmosis_IV ;
X = mutemwiya ;
X = yuya ;
X = thuya.

?- ancestorOf(tiye, tutakhamun).
true.

?- descendentOf(tutakhamun, thutmosis_IV).
true.

?- contemporaryOf(ay, akhenaten).
true.
```

## Disclaimer

The relationships and historical facts provided in this program are based on existing knowledge and should not be considered as definitive or accurate. Some of the facts may be estimates or subject to debate.
