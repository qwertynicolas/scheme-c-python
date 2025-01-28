#lang scheme

(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (remainder a b))))

(define (co-primality n i)
  (if (= (gcd n i) 1)
      #t
      #f))

(define (co-primes n)
  (cond ((= (- n 1) 1) false)
        ((= (gcd n (- n 1)) 1) true)
        (else (co-primes (- n 1)))))
