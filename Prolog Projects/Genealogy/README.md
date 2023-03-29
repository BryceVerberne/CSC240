# Genealogy: Amarna Family Tree

This program defines the Amarna Family Tree, including their gender, lifespan, and familial relationships. The program uses Prolog to define the facts and relationships between the family members.

## Facts
The program defines the following facts about the family members:

- male(<name>): defines that the specified person is male
- female(<name>): defines that the specified person is female
- parentOf(<parent>, <child>): defines that the first argument is the parent of the second
- lifespan(<person>, <birth>, <death>): defines the birth and death year of the specified person
- successorOf(<next ruler>, <ruler>): defines the next pharaoh based on the current

## Usage
The program includes several rules that can be used to query information about the family members, including:

- fatherOf(<father>, <child>): returns the father of the specified child
- motherOf(<mother>, <child>): returns the mother of the specified child

To use the program, open Prolog and load the program file. Then, you can use the fatherOf and motherOf rules to query information about the family.

## Example Queries
Here are some example queries you can run with the program:

- fatherOf(X, tutakhamun).: returns the father of Tutankhamun
- motherOf(X, nefertiti).: returns the mother of Nefertiti

Additional queries can be found in the FamilyQueries.txt file in this directory.

## Disclaimer
Be wary that some of the facts and dates in the program are still subject to debate and interpretation.
