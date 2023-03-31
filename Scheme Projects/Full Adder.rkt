; Title:  Full Adder
; Desc:   This program simulates the logic of a full adder.
; Author: Bryce Verberne
; Date:   03/22/2023



#lang racket

;-----------------------
; Logic Gate Functions
;-----------------------

; The 'andGate' function takes two inputs, 'a' and 'b',
; and returns the output value for their logical AND operation.
(define (andGate a b)
  (if (eq? (+ a b) 2)
    1
    0
  )
)

; The 'orGate' function takes two inputs, 'a' and 'b',
; and returns the output value for their logical OR operation.
(define (orGate a b)
  (if (eq? (+ a b) 0)
    0
    1
  )
)

; The 'notGate' function takes one input parameter, 'a',
; and returns the logical NOT operation on the input.
(define (notGate a)
  (if (eq? a 0)
      1
      0
  )
)

; The 'xorGate' function takes two inputs, 'a' and 'b',
; and returns the output value for their logical XOR operation.
(define (xorGate a b)
  (if (eq? a b)
      0
      1
  )
)


;-----------------------
; FullAdder Function
;-----------------------

; The fullAdder function displays the sum and carry output values
; of a full-adder circuit, given three input values, a, b, and x, to the console.
(define (fullAdder a b x)
  ; Sum & Carry Logic: 
  ;   Sum = (a ⊕ b) ⊕ x
  ;   Carry = ((a + b) • x) + (a • b)
  (cons (xorGate (xorGate a b) x) (orGate (andGate (orGate a b) x) (andGate a b)))
)


;-----------------------
; nBitAdder Function
;-----------------------

; The 'nBitAdder' function adds two binary numbers represented as lists, and
; returns the result with the carry bit as a pair.
(define (nBitAdder val1 val2 c)
  (let ((rVal1 (reverse val1))
        (rVal2 (reverse val2)))
    (define (adder lst1 lst2 carry)
      (if (or (null? lst1) (null? lst2))
          (cons carry '())
          (let ((sum (fullAdder (car lst1) (car lst2) carry)))
                (cons (car sum) (adder (cdr lst1) (cdr lst2) (cdr sum)))
          )
      )
    )
    (let ((result (adder rVal1 rVal2 c)))
      (cons (cdr (reverse result)) (car (reverse result)))
    )
  )
)


;-----------------------
; Test Cases
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
(newline)
(displayln "Testing Fulladder Methods")
(fullAdder 0 0 0)
(fullAdder 0 0 1)
(fullAdder 0 1 0)
(fullAdder 0 1 1)
(fullAdder 1 0 0)
(fullAdder 1 0 1)
(fullAdder 1 1 0)
(fullAdder 1 1 1)


(newline)
(newline)
(displayln "Testing n bit adder Methods")

(nBitAdder '(0 1 0) '(0 1 1) 1)
(nBitAdder '(1 1 1) '(0 0 0) 1)
(nBitAdder '(1 1 0 0 1 0 1 0 1) '(1 0 1 1 0 0 0 1 1) 0)