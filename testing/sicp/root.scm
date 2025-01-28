#lang scheme

(define (average x y)
  (/ (+ x y) 2))

(define (square x)
  (* x x))

(define (sqrt x)
  (define (improve guess)
    (average guess (/ x guess)))
  (define (good-enough? guess)
    (< (abs (- (square guess) x))
       .001))
  (define (try guess)
    (if (good-enough? guess)
        guess
        (try (improve guess))))
  (try 1))

(sqrt 4)

(define A (* 5 5))
(define (d) (* 5 5))

(* A A)
(+ A 0)
(+ (d) 0)
