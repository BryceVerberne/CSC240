; Title: Scheme Financials Calculations
; Desc: In this program, I am writing Scheme functions to solve given problems. 
; Author: Bryce Verberne
; Date: 02/15/2023



#lang racket
; This is an assignment that allows us to practice creating functions
; Make sure you document all Functions as shown for distance and FutureValue.
; Refer to the pdf on Canvas for the exact formulas and the answers you should get

; Example. The distance function
; Given: r - Rate of Speed
;        t - Time of Travel
; Result: d = rt

(define (distance r t)
  (display (* r t)))

(distance 70 1)
(newline)


; Function 1. Future Value Function
; Given: P - payment
;        r - interest
;        t - num years
; Result: Future Value of your investement at end of t years


(define (FVNum r t)
  (- (expt (+ 1 r) t) 1))

(define (FutureValue p r t)
  (display "Future Value is: " )
  (display (* p (/ (FVNum r t) r) (+ 1 r))))

(define (FutureValue2 p r t) ; In class example (not included in calculation)
  (let (
        (fvnum (- (expt (+ 1 r) t) 1))
       )
      (display "Answer " )
      (display (* p (/ fvnum r) (+ 1 r)))
  )
)

(FutureValue 2000 .10 20)
(newline)


; Function 2. Present Value Function
; Given: pymt - regular payment
;        r - annual interest rate
;        c - cost of living
;        t - term (years)
; Result: Amount of money to be deposited to recieve pymt yearly for t years

(define (Payment1 pymt r c t)
  (display "Initial deposit is: ")
  (display (* pymt (/ (- 1 (expt (/ (+ 1 c) (+ 1 r)) t)) (- r c))))
)

(Payment1 10000 0.05 0.02 10)
(newline)


; Function 3. Monthly Payment Function
; Given: i - monthly interest rate
;        N - number of months
;        P - present value
; Result: The amount of Peter Parker's monthly loan payment

(define (MonthlyPayment i N P)
  (display "Monthly Payment is: ")
  (display (/ (* P i) (- 1 (expt (+ 1 i) (* -1 N)))))
)

(MonthlyPayment 0.01 36 12000)
(newline)


; Function 4. Future Account Value Function
; Given: m - monthly payment
;        i - monthly interest rate
;        N - number of months
; Result: Amount of money in account after N years

(define (Accrued m i N)
  (display "Accrued Amount is: ")
  (display (- (* (/ m i) (- (expt (+ 1 i) (+ N 1)) 1)) m))
)

(Accrued 200 0.005 120)
(newline)


; Function 5. Monthly Payment function
; Given: F - future value
;        i - periodic interest rate
;        n - number of periods
; Result: Amount to deposit at the end of the next n months to accumulate F in time for t.

(define (Savings F i n)
  (display "Monthly Deposit is: ")
  (display (/ (* F i) (- (expt (+ 1 i) n) 1)))
)
  
(Savings 1000 0.01 11)
(newline)


; Function 6. Present Value of an Ordinary Annuity
; Given: m - monthly payment
;        i - interest rate (monthly)
;        N - number of months
; Result: Present value of an ordianry annuity that requires m deposits for N months with i compounded monthly.

(define (PresentValue m i N)
  (display "Present Value is: ")
  (display (* (/ m i) (- 1 (expt (+ 1 i) (* -1 N)))))
)

(PresentValue 100 0.01 60)
(newline)     