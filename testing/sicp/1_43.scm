#lang scheme

(define (square x)
 (* x x))

(define (repeater f n x)
  (define (iter accumulation end)
    (if (= end 0)
        accumulation
        (iter (f accumulation) (- end 1))))
  (iter x n))

(define (repeated f n)
  (lambda (x) (repeater f n x)))

((repeated square 2) 5)
