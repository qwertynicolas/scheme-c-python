#lang scheme

(define (no-more? list)
  (null? list))

(define (except-first-denomination list)
  (cdr list))

(define (first-denomination list)
  (car list))

(define (cc amount coin-values)
  (cond ((= amount 0) 1)
        ((or (< amount 0) (no-more? coin-values)) 0)
        (else
         (+ (cc amount
                (except-first-denomination
                 coin-values))
            (cc (- amount
                   (first-denomination
                    coin-values))
                coin-values)))))

(define us-coins (list 50 25 10 5 1))
(define uk-coins (list 100 50 20 10 5 2 1 0.5))
(define us-coins-reversed (list 1 5 10 25 50))

(define (length list)
  (define (iter counter items)
    (if (null? items)
        counter
        (iter (+ counter 1) (cdr items))))
  (iter 0 list))

(cc 100 us-coins-reversed)
