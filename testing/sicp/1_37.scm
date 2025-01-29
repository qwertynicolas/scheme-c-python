#lang scheme

; n d are procedures that accept one argument, the term index i
; k decides how long we keep going

; suppose we have k=1, then n and d only iterate one time
; therefore, they return:
; n1 / d1
; now suppose k = 2
; we'd have:
; n1 / (d1 + n2/d2)

; recursion
(define (cont-frac n d k)
  (define (iter i)
    (if (> i k)
        0
        (/ (n i) (+ (d i) (iter (+ i 1))))))
  (iter 1))

(cont-frac (lambda (i) 1.0)
           (lambda (i) 1.0)
           30)

; iteration
(define (cont-frac-iter n d k)
  (define (iter i secuence)
    (if (< i k)
        (iter (+ i 1)
              (/ (n i) (+ (d i) secuence)))
        secuence))
  (iter 1 0))

(cont-frac-iter (lambda (i) 1.0)
                (lambda (i) 1.0)
                30)
