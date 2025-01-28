#lang scheme

(require racket/math)

; gauss formula for summatory
(define (summatory n)
  (/ (* n (+ n 1)) 2))

(summatory 100)

; leibniz formula for pi/4

(define (sum-pi a b)
  (if (> a b)
      0
      (+ (/ (if (even? a) 1 -1)
            (+ (* 2 a) 1))
         (sum-pi (+ a 1) b))))

(* 4.0 (sum-pi 0.0 10000000.0))

; leibniz formula for pi/8

(define (summatory-pi a b)
  (if (> a b)
      0
      (+ (/ 1 (* a (+ a 2)))
         (summatory-pi (+ a 4) b))))

(* 8 (summatory-pi 1.0 1000000.0))
