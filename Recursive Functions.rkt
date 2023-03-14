; Title:  Recursive Functions
; Desc:   In this program, I am solving recursive functions.
; Author: Bryce Verberne
; Date:   03/14/2023



#lang racket

; Dot Product Function
;-----------------------
; A. Given two lists of numbers, return the dot-product.
(define (dotProduct lst1 lst2)
  (if (null? lst1)
      0
      (+ (* (car lst1) (car lst2)) (dotProduct (cdr lst1) (cdr lst2)))))
;-----------------------


; Duplicates Function
;-----------------------
; B. Given a list of numbers, return whether or not the list contains any duplicate entries.
; Method: 
;         if (the first element in the list exists in the second list)
;            return true
;         else
;            recursive call to search the rest of the list.

(define (duplicates base)
  (define (helper lst)
    (if (null? lst)
        (duplicates (cdr base))
        (if (equal? (car base) (car lst))
                                   #t
                                   (helper (cdr lst)))))
  (if (null? base)
      #f
      (helper (cdr base))))  
;-----------------------


;-----------------------
; Write the MaxDistance Function Here
;-----------------------

; // This will probably take two functions.
; // Function 1 sets dist to the abs of the first element in each list.
; // Then calls Function 2 with dist and "the rest of the list."

; // Function 2
; // if the length of the lists are zero, return dist
; // else if the distance between the first elements > dist
; //    recursive call to Function 2 passing the new dist and the rest of the list
; // else
; //    A recursive call to Function 2 passing the current dist and the rest of the list.

;-----------------------
; Below are your test cases.  
;-----------------------

(writeln "Dot Product of two empty lists '() '()")
(dotProduct '() '())

(writeln "Dot Product of single lists '(1) '(4)")
(dotProduct '(1) '(4))

(writeln "Dot Product of longer lists '(8 -2 4 6) '(2 -12 -4 7)")
(dotProduct '(8 -2 4 6) '(2 -12 -4 7))


(newline)
(writeln "Testing Duplicates Methods")
(newline)

(writeln "Duplicates of an empty lists? '()")
(duplicates '())

(writeln "Duplicates of a single list '(2)?")
(duplicates '(2))

(writeln "Duplicates of the list '(82 62 42 92 32)?")
(duplicates '(82 62 42 92 32))

(writeln "Duplicates of the list '(82 62 42 82 32)?")
(duplicates '(82 62 42 82 32))

(writeln "Duplicates of the list '(82 62 42 32 32)?")
(duplicates '(82 62 42 32 32))

(writeln "Duplicates of the list '(32 62 42 32 12)?")
(duplicates '(32 62 42 32 32))


(newline)
(writeln "Testing Max Distance Methods")
(newline)

(writeln "Max Distance of two empty lists '() '()")
; (maxDistance '() '())

(writeln "Max Distance of two single lists '(2) '(8)")
; (maxDistance '(2) '(8))

(writeln "Max Distance of two single lists '(-4) '(-12)")
; (maxDistance '(-4) '(-12))

(writeln "Max Distance of two longer lists")
(writeln "'(3  8 12 4 2 22 -4 18) '(6 -4 20 6 0 22  7  3)")
; (maxDistance '(3  8 12 4 2 22 -4 18) '(6 -4 20 6 0 22  7  3))
