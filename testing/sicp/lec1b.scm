#lang scheme

(define (decrement x)
  (- x 1))

(define (increment y)
  (+ y 1))

(define (sum x y)
  (if (= x 0)
      y
      (+ (decrement x) (increment y))))

(sum 302095445645645 24645634567545)

(define (fib n)
  (if (< n 2)
      n
      (+ (fib(- n 1))
         (fib(- n 2)))))

(fib 9)
