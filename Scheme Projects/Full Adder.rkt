; Title:  Scheme Functions w/ Decisions
; Desc:   In this program, I simulate the logic of a full adder.
; Author: Bryce Verberne
; Date:   03/22/2023



#lang racket

;-----------------------
; Write the Logic Gate Functions Here
;-----------------------

; The 'andGate' function is a logical function that takes two input parameters, 'a' and 'b', and
; returns an ouput value that represents the logical AND operation between the two inputs.
(define (andGate a b)
  (if (eq? (+ a b) 2)
    1
    0
  )
)

; The 'orGate' function is a logical function that takes two input parameters, 'a' and 'b', and
; returns an ouput value that represents the logical OR operation between the two inputs.
(define (orGate a b)
  (if (eq? (+ a b) 0)
    0
    1
  )
)

; The notGate function is a logical function that takes one input parameter, 'a', and returns an
; output value that represents the logical NOT operation on the input.
(define (notGate a)
  (if (eq? a 0)
      1
      0
  )
)

; The 'xorGate' function takes two input values 'a' and 'b', and returns an output value that
; represents the logical XOR (exclusive OR) operation between the two inputs.
(define (xorGate a b)
  (if (eq? a b)
      0
      1
  )
)

;-----------------------
; Write the FullAdder Function Here
;-----------------------


;-----------------------
; Write the n-bitAdder Function Here
;-----------------------


;-----------------------
; Below are your test cases.  
;-----------------------


(displayln "Testing Logic Gate Methods")

(displayln "AND Gate:")
(andGate 0 0)
(andGate 0 1)
(andGate 1 0)
(andGate 1 1)

(newline)
(displayln "OR Gate:")
(orGate 0 0)
(orGate 0 1)
(orGate 1 0)
(orGate 1 1)

(newline)
(displayln "NOT Gate:")
(notGate 0)
(notGate 1)

(newline)
(displayln "XOR Gate:")
(xorGate 0 0)
(xorGate 0 1)
(xorGate 1 0)
(xorGate 1 1)

(newline)
(writeln "Testing Fulladder Methods")
(newline)

;(fulladder 0 0 0)
;(fulladder 0 0 1)
;(fulladder 0 1 0)
;(fulladder 0 1 1)
;(fulladder 1 0 0)
;(fulladder 1 0 1)
;(fulladder 1 1 0)
;(fulladder 1 1 1)


(writeln "Testing n bit adder Methods")
(newline)

;(n-bit-addr '(0 1 0) '(0 1 1) 1)
;(n-bit-addr '(1 1 1) '(0 0 0) 1)
;(n-bit-addr '(1 1 0 0 1 0 1 0 1) '(1 0 1 1 0 0 0 1 1) 0)