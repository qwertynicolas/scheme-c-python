#lang scheme

(define a 9)
(define b 2)
(define c 7)

(define (first-largest a b c)
  (cond ((and (> a b) (> a c)) a)
        ((and (> b a) (> b c)) b)
        (else c)))

(define (second-largest largest a b c)
  (cond ((and (<= a largest) (or (>= a b) (>= a c))) a)
        ((and (<= b largest) (or (>= b a) (>= b c))) b)
        (else c)))

(define largest (first-largest a b c))
(define second (second-largest largest a b c))

(define (square x) (* x x))

(define square_first (square largest))
(define square_second (square second))

(define (sos x y) (+ x y))

(sos square_first square_second)
