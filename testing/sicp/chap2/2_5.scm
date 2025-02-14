#lang scheme

(define (exp x n)
  (define (iter counter product)
    (if (= counter 1)
        product
        (iter (- counter 1) (* product x))))
  (iter n x))

(define (cons-v2 a b)
  (* (exp 2 a)
     (exp 3 b)))

(define (car-v2 pair)
  (define (iter a rem)
    (if (not (= (remainder rem 2) 0))
        a
        (iter (+ a 1) (/ rem 2))))
  (iter 0 pair))

(car-v2 (cons-v2 4 5))

(define (cdr-v2 pair)
  (define (iter b rem)
    (if (not (= (remainder rem 3) 0))
        b
        (iter (+ b 1) (/ rem 3))))
  (iter 0 pair))

(cdr-v2 (cons-v2 4 5))
