#lang scheme
(define tolerance 0.00001)

(define (new-if predicate then-clause else-clause)
  (cond (predicate then-clause)
        (else else-clause)))

(define (average x y)
  (/ (+ x y) 2))

(define (improve guess x)
  (average guess (/ x guess)))

(define (improve-cube guess-cube x-cube)
  (/ (+ (/ x-cube (square guess-cube)) (* 2 guess-cube)) 3))

(define (good-enough? guess-cube x-cube)
  (< (abs (- (square guess-cube) x-cube)) tolerance))

(define (good-enough-v2 guess prev-guess)
  (< (abs (- guess prev-guess)) (* tolerance guess)))

(define (square x) (* x x))

(define (sqrt-iter guess x)
  (if (good-enough? guess x)
      guess
      (sqrt-iter (improve guess x) x)))

(define (sqrt x)
  (sqrt-iter 1.0 x))

(define (new-sqrt-iter guess prev-guess x)
  (if (good-enough-v2 guess prev-guess)
      guess
      (new-sqrt-iter (improve guess x) guess x)))

(define (sqrt-v2 x)
  (new-sqrt-iter 1.0 0.0 x))

(define (cube-root-iter guess-cube prev-guess-cube x-cube)
  (if (good-enough-v2 guess-cube prev-guess-cube)
      guess-cube
      (cube-root-iter (improve-cube guess-cube x-cube) guess-cube x-cube)))

(define (cube-root x)
  (cube-root-iter 1.0 0.0 x))

(cube-root 8)
