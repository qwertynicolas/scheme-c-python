#lang scheme

(define (accumulate combiner null-value term a next b)
  (define (iter a accumulation)
    (if (> a b)
        accumulation
        (iter (next a) (combiner (term a) accumulation))))
 (iter a null-value))

(define (filtered-accumulate filter combiner null-value term a next b)
  (define (iter a accumulation)
    (cond ((> a b) accumulation)
          ((filter a) (iter (next a) (combiner (term a) accumulation)))
          (else (iter (next a) accumulation))))
  (iter a null-value))

(define (square x)
  (* x x))

(define (mult x y)
  (* x y))

(define (sum x y)
  (+ x y))

(define (product f a next b)
  (accumulate mult 1 f a next b))

(define (cube x)
  (* x x x))

(define (inc x)
  (+ x 1))

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

(define (sum-prime-squares a b)
  (filtered-accumulate fast-prime sum 0 square a inc b))

(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (remainder a b))))

(define (identity x)
  x)

(define (dec x)
  (- x 1))

(define (co-primes? i n)
  (= (gcd i n) 1))

(define (product-of-relatively-primes n)
  (filtered-accumulate (lambda (i) (co-primes? i n))
                       *
                       1
                       identity
                       1
                       inc
                       (- n 1)))

(product-of-relatively-primes 30)
