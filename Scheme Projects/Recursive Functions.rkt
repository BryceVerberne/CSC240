; Title:  Recursive Functions
; Desc:   In this program, I am solving recursive functions.
; Author: Bryce Verberne
; Date:   03/14/2023



#lang racket

; Dot Product Function
;-----------------------
; A. Given two lists of numbers, return the dot-product.
;
; Strategy:
;           Create function that multiplies a corresponding element and adds the result to
;           the recursive call of the next element of both lists.
(define (dotProduct lst1 lst2)
  (if (or (null? lst1) (null? lst2))
      0
      (+ (* (car lst1) (car lst2)) (dotProduct (cdr lst1) (cdr lst2)))))
;-----------------------


; Duplicates Function
;-----------------------
; B. Given a list of numbers, return whether or not the list contains any duplicate entries.
;
; Strategy: 
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


; Max Distance Function
;-----------------------
; C. Given two lists of numbers (same length) and return the largest difference between
;    corresponding pairs of numbers.
;
; Strategy:
;    Function 1: Takes two lists and finds the absolute value of the difference between
;                each element.
;    Function 2: Finds the max value of a list by comparing each element to the list
;                head node and is replaced if the element is bigger.
;    Function 3: Given two lists, passes them to function 1, then passes the result of
;                fuction 1 to function 2. 

(define (lstMaker lst1 lst2)
  (if (or (null? lst1) (null? lst2))
      '()
      (cons (abs (- (car lst1) (car lst2))) (lstMaker (cdr lst1) (cdr lst2)))))

(define (maxVal lst)
  (if (null? (cdr lst))
      (car lst)
      (if (< (car lst) (maxVal (cdr lst)))
          (maxVal (cdr lst))
          (car lst))))

(define (maxDistance lst1 lst2)
  (if (or (null? lst1) (null? lst2))
      0
      (let ((diff (lstMaker lst1 lst2)))
        (maxVal diff))))
;-----------------------


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
(maxDistance '() '())

(writeln "Max Distance of two single lists '(2) '(8)")
(maxDistance '(2) '(8))

(writeln "Max Distance of two single lists '(-4) '(-12)")
(maxDistance '(-4) '(-12))

(writeln "Max Distance of two longer lists")
(writeln "'(3  8 12 4 2 22 -4 18) '(6 -4 20 6 0 22  7  3)")
(maxDistance '(3  8 12 4 2 22 -4 18) '(6 -4 20 6 0 22  7  3))
