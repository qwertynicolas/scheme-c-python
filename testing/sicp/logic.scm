#lang scheme

(define (logAnd x y)
  (if (and (> x 0) (> y 0))
      "true"
      "false"))

(logAnd 2 3)

(define (logOr a b)
  (if (or (> a 0) (> b 0))
      "true"
      "false"))

(logOr -2 -3)

(define (xorGate q w)
  (if (or (and (> q 0) (< w 0))
          (and (< q 0) (> w 0)))
      #t
      #f))

(xorGate 1 -2)

(define (test x y) (- x y))

(test 4 6)
