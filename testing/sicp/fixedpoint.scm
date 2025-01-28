#lang scheme

(define tolerance 0.00000001)

(define (average x y)
  (/ (+ x y) 2))

(define (fixed-point f guess)
  (define (good-enough? v1 v2)
    (< (abs (- v1 v2)) tolerance))
  (define (try guess)
    (let ((next (f guess)))
      (if (good-enough? guess next)
          (begin
            (newline)
            (display next))
          (begin
            (newline)
            (display next)
            (try next)))))
  (try guess))

(define (sqrt x)
  (fixed-point (lambda (y) (average y (/ x y)))
               1.0))

; golden ratio = (1 + sqrt(5)) / 2
; it also satisfies the equation phi^2 = phi + 1

;; (fixed-point (lambda (x) (+ 1 (/ 1 x)))
;;              1.0)

;; (fixed-point (lambda (x) (/ (log 1000) (log x)))
;;              2.0)

(fixed-point (lambda (x) (average (/ (log 1000) (log x)) x))
             2.0)
