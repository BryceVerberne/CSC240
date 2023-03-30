# Genealogy: Amarna Family Tree

This program is a genealogical knowledge base on the Amarna Family Tree, which consists of ancient Egyptian royalty.

## Description

The Amarna Family Tree Genealogy program uses Prolog to define relationships and properties of the family members. It includes information about the gender, parentage, and lifespan of each individual. Additionally, the program features rules to determine more complex relationships, such as siblings, aunts, uncles, and ancestors.

## Usage

1. Install a Prolog interpreter, such as SWI-Prolog.
2. Load the genealogy program into the Prolog interpreter.
3. Query the knowledge base to explore relationships and properties of the Amarna Family Tree members.

## Facts

The Amarna Family Tree Genealogy program is based on historical facts and estimates about the ancient Egyptian royalty. The program includes:

- Gender information for each individual.
- Parent-child relationships.
- Estimated birth and death dates (in BCE).

## Example Queries

```plaintext
?- fatherOf(amenhotep_III, akhenaten).
true.

?- motherOf(X, akhenaten).
X = tiye.

?- siblingOf(akhenaten, sitamun).
true.

?- grandparentOf(thutmosis_IV, akhenaten).
true.

?- ancestorOf(tiye, tutakhamun).
true.

?- descendentOf(tutakhamun, thutmosis_IV).
true.

?- contemporaryOf(ay, akhenaten).
true.
```

## Disclaimer
Please note that this genealogical knowledge base may not contain the most recent or comprehensive information, as new discoveries and research can change our understanding of ancient Egyptian history. Some relationships and dates in the program may be subject to debate or further research.

Feel free to modify the program to incorporate new information or to adjust relationships and dates according to alternative theories.

## License

This project is open source and available for anyone to use or modify.
