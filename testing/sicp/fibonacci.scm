#lang scheme

(define (fib n)
  (cond ((= n 0) 0)
        ((= n 1) 1)
        ((+ (fib (- n 1)) (fib (- n 2))))))

(provide fib)

(define (fib n)
 (fib-iter 1 0 n))
(define (fib-iter a b count)
 (if (= count 0)
     b
     (fib-iter (+ a b) a (- count 1))))
