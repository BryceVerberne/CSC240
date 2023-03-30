# Marvel Heroes

This Marvel-themed expert system identifies major characters from the Marvel Cinematic Universe based on user input.

## Description

This expert system is designed to identify primary characters from the Marvel Cinematic Universe by asking the user a series of yes/no questions related to the character's traits and abilities. The user is prompted to answer 'y' for yes or 'n' for no. Based on the user's response, the program deduces and presents the chracter that best fits the user's description. 

## Possible Characters

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

## Example

```plaintext
?- avengers_assemble.
This program identifies the primary characters in
the Marvel Cinematic Universe.

Answer all questions 'y' for yes or 'n' for no.

Is your character male?
y

Can he fly?
n

Do they turn green when they're angry?
n

Does your character wield a shield?
y

The character your looking for is Captain America/Steve Rogers.
false.
```

## How to Run

1. Ensure you have a compatible Prolog interpreter installed on your system (e.g., [SWI-Prolog](https://www.swi-prolog.org/Download.html)).
2. Load the `marvel_heroes.pl` file into the interpreter.
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

## License

This project is licensed under the same terms as the overall repository. See the [LICENSE](../LICENSE) file in the root directory for details.
