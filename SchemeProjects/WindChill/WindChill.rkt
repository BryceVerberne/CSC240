; Title:  Wind Chill
; Desc:   In this program, I am writing the classic Wind Chill formula.
; Author: Bryce Verberne
; Date:   03/05/2023



#lang racket

; Write the classic WindChill Formula...
; Write a function that implments
;      Term1  (  Term2 )(        Term3      )    Term4
; WC = 91.4 - (91.4 - T)(.478 + .301(V)^(1/2) - .02V)
; WC = WindChill
; T = Temperature
; V = Velocity

(define (Term2 T)
  (- 91.4 T)

)
(define (Term3 V)
  (+ .478 (* .301 (sqrt V)))

)
(define (wc T V)
  (- 91.4 (* (Term2 T) (- (Term3 V) (* .02 V))))

)

(define (wc2 T V)
  (let (
         (Term2 (- 91.4 T))
         (Term3 (+ .478 (* .301 (sqrt V))))
       )
    (- 91.4 (* Term2 (- Term3 (* .02 V))))
  )
)

(wc 35 15)
(wc2 45 10)