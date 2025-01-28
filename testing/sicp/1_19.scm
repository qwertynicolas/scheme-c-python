#lang scheme

(define (square x)
  (* x x))

(define (fib n)
  (fib-iter 1 0 0 1 n))

(define (fib-iter a b p q counter)
  (cond ((= counter 0) b)
        ((even? counter)
         (fib-iter a
                   b
                   (+ (square p) (square q)) ; p'
                   (+ (* 2 p) (square q)) ; q'
                   (/ counter 2)))
        (else (fib-iter (+ (* b q) (* a q) (* a p))
                        (+ (* b p) (* a q))
                        p
                        q
                        (- counter 1)))))

(fib 7)
