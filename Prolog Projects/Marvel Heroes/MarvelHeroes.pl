% Title:  Marvel Heroes
% Desc:   In this program, I am creating a Marvel-themed expert system.
% Author: Bryce Verberne
% Date:   03/27/2023



avengers_assemble :-
  intro,
  write( 'Answer all questions \'y\' for yes or \'n\' for no.'),nl,
  clear_stored_answers,
  try_all_possibilities.

try_all_possibilities :-  % backtrack through all
  may_be(D),		  % possibilities
  explain(D),
  fail.

try_all_possibilities.	  % then succeed with no further action.

% case knowledge base - user responses
:- dynamic(stored_answer/2).

% procedure to get rid of previous responses
% without abolishing the dynamic declaration
clear_stored_answers :- retract(stored_answer(_,_)),fail.
clear_stored_answers.

% procedure to ask the user a question and recieve an
%  answer, or retrieve the result if already asked

user_says(Q,A) :- stored_answer(Q,A).

user_says(Q,A) :-
  \+ stored_answer(Q,_),
  nl,nl,
  ask_question(Q),
  get_yes_or_no(Response),
  asserta(stored_answer(Q,Response)),
  Response = A.

% Prompt that obtains a yes or no answer
get_yes_or_no( Result ) :-
  get(Char),	% read a single character
  get0(_),      % consume the return after it
  interpret(Char,Result),
  !.            % cut - only one result.

get_yes_or_no( Result ) :-
  nl,
  write('Type y or n'),
  get_yes_or_no( Result ).

interpret(89,yes).	% ASCII 89 = 'Y'
interpret(121,yes).	% ASCII 121 = 'y'
interpret(78,no).	% ASCII 78 = 'N'
interpret(110,no).	% ASCII 110 = 'n'

% Simple Marvel Heroes expert system
intro :-
  write('This program identifies the primary characters in'),nl,
  write('the Marvel Cinematic Universe.'), nl.

% Possibilities
may_be(iron_man) :-
  user_says(male, yes).

may_be(captain_america) :-
  user_says(male, yes).

may_be(thor) :-
  user_says(male, yes).

may_be(hulk) :-
  user_says(male, yes).

may_be(black_widow) :-
  user_says(male, no).

may_be(hawkeye) :-
  user_says(male, yes).

may_be(spider_man) :-
  user_says(male, yes).

may_be(doctor_strange) :-
  user_says(male, yes).

may_be(captain_marvel) :-
  user_says(male, no).

may_be(black_panther) :-
  user_says(male, yes).

% Text of Questions
ask_question(male) :-
  write('Is the character a male?'), nl.

% Explanations for the various diagnoses
explain(iron_man) :- nl,
  write('The character your looking for is Iron Man/Tony Stark.'), nl.

explain(captain_america) :- nl,
  write('The character your looking for is Captain America/Steve Rogers.'), nl.

explain(thor) :- nl,
  write('The character your looking for is Thor/Odinson.'), nl.

explain(hulk) :- nl,
  write('The character your looking for is Hulk/Bruce Banner.'), nl.

explain(black_widow) :- nl,
  write('The character your looking for is Black Widow/Natasha Romanoff.'), nl.

explain(hawkeye) :- nl,
  write('The character your looking for is Hawkeye/Clint Barton.'), nl.

explain(spider_man) :- nl,
  write('The character your looking for is Spider-Man/Peter Parker.'), nl.

explain(doctor_strange) :- nl,
  write('The character your looking for is Doctor Strange/Stephen Strange.'), nl.

explain(captain_marvel) :- nl,
  write('The character your looking for is Captain Marvel/Carol Danvers.'), nl.

explain(black_panther) :- nl,
  write('The character your looking for is Black Panther/T\'Challa.'), nl.