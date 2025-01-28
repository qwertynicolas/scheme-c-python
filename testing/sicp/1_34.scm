#lang scheme

(define (f g) (g 2))

(define (square x)
  (* x x))

(f (lambda (z) (* z z)))

(f (lambda (z) (* z (+ z 1))))

(f f)
