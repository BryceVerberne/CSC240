; Title:  Scheme Functions w/ Decisions
; Desc:   In this program, I simulate the logic of a full adder.
; Author: Bryce Verberne
; Date:   03/22/2023



#lang racket

;-----------------------
; Write the Logic Gate Functions Here
;-----------------------


;-----------------------
; Write the FullAdder Function Here
;-----------------------


;-----------------------
; Write the n-bitAdder Function Here
;-----------------------


;-----------------------
; Below are your test cases.  
;-----------------------


(newline)
(writeln "Testing Logic Gate Methods")
(newline)

(andgate 0 0)
(andgate 0 1)
(andgate 1 0)
(andgate 1 1)

(orgate 0 0)
(orgate 0 1)
(orgate 1 0)
(orgate 1 1)

(notgate 0)

(andgate 1)

(xorgate 0 0)
(xorgate 0 1)
(xorgate 1 0)
(xorgate 1 1)


(writeln "Testing Fulladder Methods")
(newline)

(fulladder 0 0 0)
(fulladder 0 0 1)
(fulladder 0 1 0)
(fulladder 0 1 1)
(fulladder 1 0 0)
(fulladder 1 0 1)
(fulladder 1 1 0)
(fulladder 1 1 1)


(writeln "Testing n bit adder Methods")
(newline)

(n-bit-addr '(0 1 0) '(0 1 1) 1)
(n-bit-addr '(1 1 1) '(0 0 0) 1)
(n-bit-addr '(1 1 0 0 1 0 1 0 1) '(1 0 1 1 0 0 0 1 1) 0)