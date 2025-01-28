#lang scheme

(define (square x)
  (* x x))

((lambda (x) (+ x 2)) 2)

(define (f x y)
  (let ((a (+ 1 (* x y)))
        (b (- 1 y)))
    (+ (* x (square a))
       (* y b)
       (* a b))))

(f 2 5)
