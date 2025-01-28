#lang scheme
(define (average x y)
  (/ (+ x y) 2))

(define tolerance 0.0001)

(define (square x)
  (* x x))

(define (sqrt x)
  (define (improve guess)
    (average guess (/ x guess)))
  (define (good-enough? guess)
    (< (abs (- (square guess) x)) tolerance))
  (define (sqrt-root-iter guess)
    (if (good-enough? guess)
        guess
        (sqrt-root-iter (improve guess))))
  (sqrt-root-iter 1.0))

(sqrt 9)
