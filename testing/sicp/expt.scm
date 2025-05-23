#lang scheme

(define (square x)
  (* x x))

(define (expt b n)
  (if (= n 0)
      1
      (* b (expt b (- n 1)))))

(define (expt-iter b counter product)
  (if (= counter 0)
      product
      (expt-iter b
                 (- counter 1)
                 (* product b))))

(define (expt-v2 b n)
  (expt-iter b n 1))

(expt-v2 3 2)

(define (expt-v3 b n)
  (cond ((= n 0) 1)
        ((even? n) (square (expt-v3 b (/ n 2))))
        (else (* b (expt-v3 b (- n 1))))))

(expt-v3 3 2)
