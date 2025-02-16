#lang scheme

(define (reverse list)
  (define (iter old-list new-list)
    (if (null? old-list)
        new-list
        (iter (cdr old-list) (cons (car old-list) new-list))))
  (iter list '()))

(define squares
  (list 1 4 9 16 25))

(define odds
  (list 1 3 5 7 9 11 13 15 17 19 21))

(reverse odds)
