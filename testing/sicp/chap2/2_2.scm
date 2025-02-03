#lang scheme

(define (average x y)
  (/ (+ x y) 2))

(define (make-segment start end)
  (cons start end))

(define (start-point x)
  (car x))

(define (end-point x)
  (cdr x))

(define segment-1-3
  (make-segment 1 3))

(define (make-point x y)
  (cons x y))

(define (x-point p)
  (car p))

(define (y-point p)
  (cdr p))

(define random-point
  (make-point 3 4))

(define (print-point p)
  (newline)
  (display "(")
  (display (x-point p))
  (display ",")
  (display (y-point p))
  (display ")"))

(define (midpoint-segment segment)
  (average (start-point segment) (end-point segment)))

(midpoint-segment segment-1-3)
