#lang scheme

(define (inc x)
  (+ x 1))

(define (square x)
  (* x x))

(define (double procedure)
  (lambda (x) (procedure (procedure x))))

(((double (double double)) inc) 5)

((double (double inc)) 5)

((double inc) 5)

