#lang scheme

(define (lenght items)
  (define (iter n list)
    (if (not (null? list))
        (iter (+ n 1) (cdr list))
        n))
  (iter 0 items))

(define (list-ref list n)
  (if (= n 0)
      (car list)
      (list-ref (cdr list) (- n 1))))

; lenght - 1 provides the last item using list-ref

(define squares
  (list 1 4 9 16 25))

;; (lenght squares)

;; (list-ref squares 4)

(define (last-pair list)
  (let ((long (lenght list)))
    (cons (list-ref list (- long 1)) '())))

(last-pair squares)
(last-pair (list 23 72 149 34))
