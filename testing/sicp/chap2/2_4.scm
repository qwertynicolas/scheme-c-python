#lang scheme

(define (cons x y)
  (lambda (m) (m x y)))

(define (car z)
  (z (lambda (p q) p)))

(define (cdr z)
  (z (lambda (p q) q)))

(define (sum x y)
  (+ x y))

(sum (car (cons 2 3)) (cdr (cons 2 3)))
