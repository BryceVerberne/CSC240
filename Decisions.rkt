; Title: Scheme Functions w/ Decisions
; Desc: In this program, I am writing Scheme functions with conditional statements. 
; Author: Bryce Verberne
; Date: 03/11/2023



#lang racket

; Write a function called WaterWeight that accepts
;   Diameter, Length and either #t or #f

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Given: w = PI * (D/24) * L * K
;        w  - water weight (pounds)
;        D  - pipe diameter (inches)
;        L  - pipe length (feet)
;        K  - water density (pounds per cubic foot; 62.4 for pure water or 64.08 for sea water)
;        PI - pi(3.14159)
; Returns: Weight of water (w)

(define (WaterWeight D L Val)
  (let ((K (if Val
               62.4
               64.08)))
  (displayln (* 3.14159 (/ D 24) L K))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(display "Water Weight ")
(newline)

(display "PW Pipe Diameter 20, Pipe Length 24 ")
(WaterWeight 20 24 #t)

(display "SW Pipe Diameter 20, Pipe Length 24 ")
(WaterWeight 20 24 #f)


; Write a function called RadioFrequency that accepts
;  a frequency
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Given: A frequency in MHz
;        Inputs - Frequency in MHz(1 MHz = 1000 KHz)
; Returns: A string with the abbreviation for the Frequency Band.

(define (RadioFrequency val)
  (if (and (>= val .01) (<= val .03))
      "VLF"
      (if (and (> val .03) (<= val .3))
          "LF"
          (if (and (> val .3) (<= val 3))
              "MF"
              (if (and (> val 3) (<= val 30))
                  "HF"
                  (if (and (> val 30) (<= val 328.6))
                      "VHF"
                      (if (and (> val 328.6) ( <= val 2009))
                          "UHF"
                          "Invalid Value")))))))
                  
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(newline)
(display "Radio Frequencies")
(newline)

(displayln "20 KHz")
; (displayln (exact->inexact(/ 20 1000)))
(displayln (RadioFrequency .02))

(displayln "50 KHz")
; (displayln (exact->inexact(/ 50 1000)))
(displayln (RadioFrequency .05))

(displayln "350 KHz")
; (displayln (exact->inexact(/ 350 1000)))
(displayln (RadioFrequency .350))

(displayln "3500 KHz")
; (displayln (exact->inexact(/ 3500 1000)))
(displayln (RadioFrequency 3.500))

(displayln   "328599 KHz")
; (displayln (exact->inexact (/ 328599 1000)))
(displayln (RadioFrequency 32.8599))

(displayln   "2000000 KHz")
; (displayln (/ 2000000 1000))
(displayln (RadioFrequency 2000.000))

(displayln   "4000000 KHz")
; (displayln (/ 4000000 1000))
(displayln (RadioFrequency 4000.000))


; Write a function called PayCheck that accepts hourly rate, 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Given:
;        (a) Employees are either hourly or paid by commission
;        (b) Hourly employees get their hourly rate times the number of hours,
;            plus time and a half for overtime (more than 40 hours).
;        (c) Comissioned employees get a percentage of their sales.
;        (d) Every employee has the option to contribute to the boss's birthday
;            fund, and the amount of the donation is subtracted from weekly pay.

(define (PayCheck type work pay kissup)
  (if type
      (let ((hours (if (> work 40)
                       (+ (* 1.5 (- work 40)) 40)
                       work)))
       (displayln (- (* hours pay) kissup)))
      (let ((tax (if (< work 1000)
                          0.01
                          (if (and (>= work 1000) (< work 10000))
                              0.025
                              0.06))))
        (displayln (- (* work tax) kissup)))))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(newline)
(display "Sales")
(newline)

(display "Pay 35 hours, $10 hr, no kissup $")
(PayCheck #t 35 10 0)

(display "Pay 45 hours, $10 hr, no kissup $")
(PayCheck #t 45 10 0)

(display "Pay 35 hours, $10 hr, $20 kissup $")
(PayCheck #t 35 10 20)

(display "Pay 45 hours, $10 hr, $20 kissup $")
(PayCheck #t 45 10 20)

(display "Pay $500 sales, $0 hr, no kissup $")
(PayCheck #f 500 0 0)

(display "Pay $5000 sales, $0 hr, no kissup $")
(PayCheck #f 5000 0 0)

(display "Pay $15000 sales, $0 hr, no kissup $")
(PayCheck #f 15000 0 0)

(display "Pay $500 sales, $0 hr, $20 kissup $")
(PayCheck #f 500 0 20)

(display "Pay $5000 sales, $0 hr, $20 kissup $")
(PayCheck #f 5000 0 20)

(display "Pay $15000 sales, $0 hr, $20 kissup $")
(PayCheck #f 15000 0 20)