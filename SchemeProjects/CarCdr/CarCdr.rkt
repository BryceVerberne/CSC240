; Title:  Car & Cdr
; Desc:   In this program, I am writing expressions to extract items in a list.
; Author: Bryce Verberne
; Date:   02/27/2023



#lang racket

; Write Scheme expressions to extract each item out of the following list
; Run the Output Test when finished

(define lst '((a b) c (d (e f)) ((g (h) i))))

; First one is done for you
(car (car lst))                                       ; Find 'a
(car (cdr (car lst)))                                 ; Find 'b
(car (cdr lst))                                       ; Find 'c
(car (car (cdr (cdr lst))))                           ; Find 'd
(car (car (cdr (car (cdr (cdr lst))))))               ; Find 'e
(car (cdr (car (cdr (car (cdr (cdr lst)))))))         ; Find 'f
(car (car (car (cdr (cdr (cdr lst))))))               ; Find 'g
(car (car (cdr (car (car (cdr (cdr (cdr lst))))))))   ; Find 'h
(car (cdr (cdr (car (car (cdr (cdr (cdr lst))))))))   ; Find 'i