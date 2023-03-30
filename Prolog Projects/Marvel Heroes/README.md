# Marvel Heroes

This program is a Marvel-themed expert system that helps users identify primary characters in the Marvel Cinematic Universe based on their answers to a series of questions.

## Characters

The program can identify the following Marvel characters:

- Iron Man/Tony Stark
- Captain America/Steve Rogers
- Thor/Odinson
- Hulk/Bruce Banner
- Black Widow/Natasha Romanoff
- Hawkeye/Clint Barton
- Spider-Man/Peter Parker
- Doctor Strange/Stephen Strange
- Captain Marvel/Carol Danvers
- Black Panther/T'Challa

## How to Run

1. Ensure you have a compatible Prolog interpreter installed on your system (e.g., SWI-Prolog).
2. Load the Marvel Heroes program into the interpreter.
3. Run the `avengers_assemble.` predicate to start the program.
4. Follow the on-screen prompts to answer the questions.

## Program Structure

The program consists of several parts:

- `avengers_assemble`: The main predicate that runs the program.
- `try_all_possibilities`: Tries all possibilities to identify the character.
- `user_says`, `get_yes_or_no`, `interpret`: Predicates to handle user input and store answers.
- `intro`: Displays an introduction message.
- `may_be`: A set of predicates that describe different Marvel characters.
- `ask_question`: Displays the question for the user.
- `explain`: Displays the final result based on user input.
