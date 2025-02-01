#lang scheme

(define (cont-frac n d k)
  (define (iter i)
    (if (> i k)
        0
        (/ (n i) (+ (d i) (iter (+ i 1))))))
  (iter 1))

(define (denominator i)
  (cond ((= i 1) 1.0)
        ((= i 2) 2.0)
        ((= (modulo (- i 2) 3) 0) (* 2.0 (/ (+ i 1) 3))) ; whenever i is of the form 3k + 2, being k a positive integer starting at zero
        (else 1.0)))                                     ; such as i = 5, i = 8, i = 11, etc

(+ 2 (cont-frac (lambda (i) 1.0)
           denominator
           30))
