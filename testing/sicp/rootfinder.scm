#lang scheme

(define (average x y)
  (/ (+ x y) 2))

(define tolerance 0.001)

(define (close-enough? x y)
  (< (abs (- x y)) tolerance))

(define (root-finder f neg-point pos-point)
  (let ((midpoint (average neg-point pos-point)))
    (if (close-enough? neg-point pos-point)
        midpoint
        (let ((test-value (f midpoint)))
          (cond ((positive? test-value)
                 (root-finder f neg-point midpoint))
                ((negative? test-value)
                 (root-finder f midpoint pos-point))
                (else midpoint)))))) ; if it's not positive or negative, then it's a root, that is, 0

(define (mid-interval f a b)
  (let ((a-value (f a))
        (b-value (f b)))
    (cond ((and (negative? a-value) (positive? b-value))
           (root-finder f a b))
          ((and (negative? b-value) (positive? a-value))
           (root-finder f b a))
          (else
           (error "The values have the same sign" a b)))))

(mid-interval sin 2.0 4.0)

(mid-interval (lambda (x) (- (* x x x) (* 2 x) 3))
              1.0
              2.0)
