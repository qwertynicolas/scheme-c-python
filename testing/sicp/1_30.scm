#lang scheme

(define (cube x)
  (* x x x))

(define (next x)
  (+ x 1))

; recursion
(define (sum term a next b)
  (if (> a b)
      0
      (+ (term a)
         (sum term (next a) next b))))

(sum cube 1 next 5)

; next and term needs to be defined previously, before calling them
; next decides the change in variables, for example, by increasing the term by 1
; term is the mathematical function to be perfomed, for instance, it can be a cube function

; iteration
(define (sum-v2 term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a) (+ (term a)
                          result))))
  (iter a 0))

(sum-v2 cube 1 next 5)
