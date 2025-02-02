#lang scheme

(define (square x)
  (* x x))

(define tolerance 0.00001)

(define (average x y)
  (/ (+ x y) 2))

(define (improve-sqrt guess x)
  (average guess (/ x guess)))

(define (good-enough-sqrt guess x)
  (< (abs (- (square guess) x)) tolerance))

(define (good-enough-fixed-point v1 f)
  (< (abs (- v1 (f v1))) tolerance))

(define (improve-fixed-point guess f)
  (f guess))

(define (iterative-improve good-enough? improve)
  (lambda (initial-guess)
    (lambda (x)
      (define (iter guess x)
        (if (good-enough? guess x)
            guess
            (iter (improve guess x) x)))
      (iter initial-guess x))))

(define (sqrt x)
  (((iterative-improve good-enough-sqrt improve-sqrt) 1.0) x))

; how should the sqrt procedure work?
; when we call sqrt we only pass one argument, that is, the value to get the square root
; but we also need a guess, since we are using iterative-improve
; but here comes the problem
; sqrt needs at least two values in order to compute the 'improve' and 'good-enough' parts
; therefore, we need to pass x and the initial guess to 'iterative-improve'
; but with this arises a new problem, iterative-improve should only take two arguments
; and return a procedure that ask for a guess
; so, when do we pass the x?

; and how should fixed-point work in terms of 'iterative-improve'?
; fixed-point requires an initial guess and a function
; for instance, cos and 1.0
; how does the improve function work in the original procedure?
; we make use of:
; the initial guess
; the function evaluated with the guess
; since iterative-improve is made so it needs at least two values outside the call to take in
; we need to pass, first, the initial guess, and second, the guess improved
; this is not true, we need to pass the guess and the function

(define (fixed-point f first-guess)
  (((iterative-improve good-enough-fixed-point improve-fixed-point) first-guess) f))

(fixed-point cos 1.0)
