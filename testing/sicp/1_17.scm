#lang scheme

(define (mult n m)
  (cond ((= n 1) m)
        ((= m 1) n)
        ((or (= n 0) (= m 0)) 0)
        (else (+ n (mult n (- m 1))))))

(mult 3 2)

(define (halve n)
  (/ n 2))

(define (double n)
  (+ n n))

(define (mult-v2 n m)
  (define (fast-mult-iter a b accumulator)
    (cond ((= b 1) (+ accumulator a))
          ((even? b) (fast-mult-iter (double a) (halve b) accumulator))
          (else (fast-mult-iter a (- b 1) (+ accumulator n)))))
  (if (or (= n 0) (= m 0)) 0 (fast-mult-iter n m 0)))

(mult-v2 9 3)
