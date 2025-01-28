#lang scheme

(define (cube x)
  (* x x x))

(define (simpsons-rule f a b n)
  (define h (/ (- b a) n))
  (define (iter counter summatory)
    (define yk (f (+ a (* counter h))))
    (if (not (> counter n))
         (begin
          (iter (+ counter 1) (cond
                               ((or (= counter 0) (= counter n))
                                (+ summatory yk))
                               ((even? counter)
                                (+ summatory (* 2 yk)))
                               (else
                                (+ summatory (* 4 yk))))))
        (* (/ h 3) summatory)))
  (if (> a b)
      0
      (iter 0 0)))

(simpsons-rule cube 2 3 100)
;; (define (<name> a b)
;;  (if (> a b)
;;      0
;;      (+ (<term> a)
;;         (<name> (<next> a) b))))
