#lang scheme

(define (square x)
  (* x x))

(define (expmod base exp mod)
  (cond ((= exp 0) 1)
        ((even? exp)
         (define x (expmod base (/ exp 2) mod))
         (define x-squared (remainder (square x) mod)) ; x² mod n
         (if
          (and
           (not (or
                 (= x 1) (= x (- mod 1)))) ; check for a non-trivial square root of 1 mod n for a<n
           (= x-squared 1))
          0
          x-squared))
        (else
         (remainder (* base (expmod base (- exp 1) mod)) mod))))

(define (miller-rabin-test n)
  (define a (+ 1 (random (- n 1))))
  (define result (expmod a (- n 1) n))
  (= result 1))

(define (fast-prime n)
  (define (prime-iter times)
    (cond ((= times 0) true)
          ((miller-rabin-test n) (prime-iter (- times 1)))
          (else false)))
  (prime-iter 5))

(provide fast-prime) ; the main difference between fermat's algorithm and this one is that this test can't be fooled by carmichael numbers
