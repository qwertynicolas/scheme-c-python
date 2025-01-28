#lang scheme

(define (increment x)
  (+ x 1))

(define counter 1)
(define product 1)

(define (factorial n)
  (if (= n 1)
      1
      (* n (factorial (- n 1)))))

(define (fact-iter count prod n)
  (if (> count n)
      prod
      (fact-iter (increment count) (* count prod) n)))

(define (fact n)
  (fact-iter 1 1 n))

(fact 6)
