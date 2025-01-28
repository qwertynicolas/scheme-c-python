#lang scheme

(define (square x)
  (* x x))

(define (fast-expt b n)
  (define (fast-expt-iter b n state)
    (cond ((= n 0) state)
          ((even? n) (fast-expt-iter (square b) (/ n 2) state))
          (else (fast-expt-iter b (- n 1) (* state b)))))
    (fast-expt-iter b n 1))

(provide fast-expt)
