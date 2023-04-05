; Title:  Data Structure Manipulation
; Desc:   This program demonstrates how to manipulate pairs & lists
; Author: Bryce Verberne
; Date:   02/27/2023



#lang racket

; Let's create a pair

(cons 2 4)  ; Let's create an ordered pair of (2,4)

(cons 'rectangle (cons 10 20))

(define bList '(ascii 
                (characters (a b c) (a e i o))
                (numbers (1 3 8 2))
                (punctuation (@ % $))
                unicode
                (cherokee (#\x1382 #\x13C4 #\1306))
               )
)

(define pt1 (cons 2 4))
(define pt2 (cons 3 8))

pt1
pt2

; We used cons to create the ordered pair (x, y)
; No variable names.
; Let's figure out the change in x:

(- (car pt2) (car pt1))

(- (cdr pt2)(cdr pt1))

; Distance between pt1 and pt2? 

(define y (- (cdr pt2) (cdr pt1)))
(define x (- (car pt2) (car pt1)))

(sqrt (+ (expt x 2) (expt y 2)))

; (define hypot (pt1 pt2)
; ( let (
;        (y (- (cdr pt2) (cdr pt1)))
;        (x (- (car pt2) (car pt1)))
;      )
;    (sqrt (+ (expt x 2) (expt y 2)))
; )
;)

; (hypot pt1 pt2)

(cons 3 (cons 4 (cons 5 6)))

; (3 . (4 . (5 . 6)))

(cons (cons 4 5) (cons 6 7))

(define lst1 '(1 2 3 4) )

lst1

; Let's mess with lists

(cons 1 '(3 4))

(define lst2 (cons 1 '(3 4)))

(pair? lst2)
(list? lst2)

(pair? '())  ; An empty list cannot be a pair
(list? '())  ; An empty list is a list

; Can you use cons to join more than two elements.
; No... To join more than two, you use list.

(cons 1 2)
; (const 1 2 3)
(list 1 2 3)

(define grades (list 82 32 96 87 68 92))

grades

(car grades)

(cdr grades)

; Lists: The car gives the first element. The cdr gives the rest of the list

(car (cdr (cdr grades)))
; In CSC110, we're doing String functions, like substring and charAt

(caddr grades)

(define IQs '((bubba 12) (bertha 92) (beavis 142) (bertram)))

IQs

(car (car IQs))
(car (cdr (car IQs)))

(cdr (car IQs))

(define aList '(pt1 (2 4) pt2 (4 8) pt3 (6 12) linear))
(define qList '(pt1 (1 2) pt2 (2 4) pt3 (3 8) exponential))
(define vList '(pt1 (1 2) pt2 (2 2) constant))

; Challenge, can you print (6 12)
; Print linear or exponential

(define (printFunctionName flist)
  (car (cdr (cdr (cdr (cdr (cdr flist))))))
  (car (cdr (cdr (cdr (cdr (cdr (cdr flist)))))))
)

(printFunctionName aList)
(printFunctionName qList)

; Let's both use an if else and recursion.
(define (printFunctionVariable flist)
  (if (eq? (cdr flist) '())
      (car flist)
      (printFunctionVariable (cdr flist))
   )
)

; If else and condtion

(define (isNegative num)
  (if (< num 0)
      "Why so negative"
      "Such a positve outlook"

  )
)

(define (isNeutral num)
  (cond
    ((< num 0) "Why so negative")
    ((> num 0) "Such a positive outlook")
    (else "Non-Value Added, I see")
  )
)

(display "Enter a positive number ")

(isNeutral (read))

(define speeds '(55 25 32))

; We would use a for-loop to sum up a list

(define (sumup lst)
  (if (eq? lst '())
      0
      (+ (car lst) (sumup (cdr lst)))
  )
)

(sumup speeds)

(list-ref '(1 2 3 4 5 6) 4)

; Let's write our own Max Function.
(max 3 2 8 4 9 7)

(define (maximum2 max lst)
  (cond
    ((null? lst)
     max)
    ((> (car lst) max)
     (maximum2 (car lst) (cdr lst)))
    (else
     (maximum2 max (cdr lst)))
  )
)

; This handles the empty list correctly; otherwise, things blow up.
(define (maximum lst)
  (if (null? lst)   ; If it's null, then we don't want to do anything.
      0
      (maximum2 (car lst) (cdr lst))
  )
)