#lang scheme

(require "fibonacci.scm")
(require racket/math)

(define phi (/ (+ 1 (sqrt 5)) 2))
(define psi (/ (- 1 (sqrt 5)) 2))

(define (fib-formula n)
  (/ (- (expt phi n) (expt psi n)) (sqrt 5)))

(define tolerance 0.0001)

(define (fib n)
  (if (< n 2)
      n
      (+ (fib (- n 1)) (fib (- n 2)))))

(define (good-enough? actual expected)
  (< (abs (- actual expected)) tolerance))

(define (verify-fib n)
  (let ((fib-value (fib n))
        (formula-value (fib-formula n)))
    (if (good-enough? fib-value formula-value)
        (display (string-append "Verified for n = " (number->string n) "\n"))
        (error "Mismatch for n = " n))))

(fib 6)
(fib-formula 6)

(expt 2 3)
