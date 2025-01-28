#lang scheme

(require "1_16.scm")

(define (square x)
  (* x x))

; number of steps O(n) - my own algorithm (counter starts at n-1 and check with every c<n, so it's not very efficient)

(define (is-prime? n)
  (define (prime-iter counter)
    (cond ((and (> counter 1) (= (remainder n counter) 0)) "No")
          ((and (> counter 1) (not (= (remainder n counter) 0))) (prime-iter (- counter 1)))
          ((= counter 1) "Yes")))
  (prime-iter (- n 1)))

; number of steps O(sqrt(2)) - sicp algorithm

(define (smallest-divisor n)
  (find-divisor n 2))

(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
        ((divides? test-divisor n) test-divisor)
        (else (find-divisor n (next test-divisor)))))

(define (next input)
  (if (= input 2) 3 (+ input 2)))

(define (divides? a b)
  (= (remainder b a) 0))

(define (prime? n)
  (= n (smallest-divisor n)))

; number of steps O(log n) - fermat's little theorem algorithm

(define (expmod b exp m)
  (cond ((= exp 0) 1)
        ((even? exp) (begin
                       (miller-rabin-check b m)
                       (remainder (square (expmod b (/ exp 2) m)) m))) ; we can include a call to the miller rabin test here
        (else (begin
                (miller-rabin-check b m)
                (remainder (* b (expmod b (- exp 1) m)) m)))))

(define (expmod-v2 base exp mod)
  (remainder (fast-expt base exp) mod))

(define (fermat-test n)
  (define (try-at a)
    (= (expmod-v2 a n n) a))
  (try-at (+ 1 (random (- n 1)))))

; a non-trivial square root 1 (mod n) is when we perform
; (remainder x n) being x the number to evaluate primality and n the mod (which should be equal x + 1)
; and the results yields 1
; let's say: 1 is congruent to 9 modulo 8
; 9/8 gives a remainder of 1, therefore, 3 is a non-trivial square root of 1 mod 8, because 3^2 is equal to 9
; we could generalize this to (remainder x^2  n) = 1
; x could be any positive integer different than 1 and n-1
; we can just make one consequent that will be executed when the computation finds such a non-trivial square root
; which should return 0, making the program halt and return false, since the number being evaluated is not prime
; according to the miller rabin test

(define (miller-rabin-check base mod)
  (cond ((and (not (= base mod)) (not (= base (- mod 1))) (= 1 (remainder (square base) mod))) 0)))

(define (miller-rabin-test n)
  (define (try-at a)
    (= (expmod a n n) a))
  (try-at (+ 1 (random (- n 1)))))

(define (fast-prime n)
  (define (prime-iter times)
    (cond ((= times 0) true)
          ((miller-rabin-test n) (prime-iter (- times 1)))
          (else false)))
  (prime-iter 5))

(fast-prime 561)


; timed  test

(define (timed-prime-test n)
  (newline)
  (display n)
  (start-prime-test n (current-inexact-milliseconds)))

(define (start-prime-test n start-time)
  (if (fast-prime n)
      (report-prime (- (current-inexact-milliseconds) start-time)) (newline)))

(define (report-prime elapsed-time)
  (display " *** ")
  (display elapsed-time))


; another function that only receives arguments when we know for certain that the number is prime? or that
; the number is odd? and we also need to take in consideration that the counter needs to be < 3
; so, how do we pass this values to this function while we keep going on the iteration? that's it, how
; do we call 2 functions in one 'else' ?
; well, we have to introduce a new expression, 'begin', that allows us to call two functions at the same time

(define (search-for-primes lower upper)
  (define (search-iter n counter threshold)
    (cond ((or (>= n upper) (>= counter threshold)) (newline))
          ((even? n) (search-iter (+ n 1) counter threshold))
          ((fast-prime n) (begin ; this works so bad since i'm checking the primality of n two times in each iteration
                       (timed-prime-test n)
                       (search-iter (+ n 2) (+ counter 1) threshold)))
          (else (search-iter (+ n 2) counter threshold))))
  (search-iter lower 0 3))

