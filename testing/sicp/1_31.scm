#lang scheme

(define (identity x)
  x)

(define (square x)
  (* x x))

(define (cube x)
  (* x x x))

(define (inc x)
  (+ x 1))

(define (dec x)
  (- x 1))

(define (product f a b next)
  (define (iter a product)
    (if (> a b)
        product
        (iter (next a) (* (f a) product))))
  (iter a 1))

(product cube 2 3 inc)

(define (prod-recursion f a b next prod)
  (if (> a b)
      prod
      (prod-recursion f (next a) b next (* (f a) prod))))

(define (next-pi n)
  (+ n 2))

(define (pi-function n)
  (/ (square n) (- (square n) 1)))

(define (pi/4 n)
  (* 0.5 (product pi-function 2 n next-pi)))

(define (factorial n)
  (product identity 1 n (lambda (x) (+ x 1))))


; n! = (n-1) * (n-2) * ... * n

; n! = n * (n-1) * (n-2) * ... * 2 * 1

;; (define (factorial n)
;;   (define (fact-iter counter result)
;;     (if (= counter 1)
;;         result
;;         (fact-iter (- counter 1) (* result counter))))
;;   (fact-iter (- n 1) n))

; so, how do we rewrite this in terms of 'product'?

; what does it mean to write y in terms of x?
; lets suppose y = f(x), then y is a function that depends on x, that is, that is written in terms of x
; but how do apply this logic to 'product' and 'factorial'?
; well, let's suppose y = factorial and x = product
; then we'll to write y in terms of x, that is, a function
; but how do we achieve this?
; suppose we have:
; factorial = f(product)

; so, how do we make use of product in order to write a new 'factorial'?
; let's think about what 'product' does:
; 'product' receives four parameters, a function 'f', a starting point 'a', a finishing point 'b' and the change of 'a' in each iteration
; using 'next'
; a typical, and efficient, factorial function should only receive 1 parameter, that is the number that you want to get its factorial
; so we must make use of iteration in order to send more than 1 parameter to 'product'
; but what will those parameters be?
; first of all: the number 'n' that you send when you make the call to the function
; second: the ending point, this should always be 1, by definition of the factorial of a number
; third: the decreasing change, since you want to decrease the value of n in order to achieve n * (n-1)
; fourth: a multiplication function, which receives x and y (n and n-1) and computes its product

;
