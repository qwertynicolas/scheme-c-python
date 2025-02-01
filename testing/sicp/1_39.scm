#lang scheme

(define (square x)
  (* x x))

;; (define (tan-cf x k)
;;   (define (iter counter tangent)
;;     (cond ((= counter 1)
;;            (iter (+ counter 1) (/ x tangent))
;;           ((> counter 1)
;;            (iter (+ counter 1) (/ (square x) (- (+ tangent 2) (iter counter tangent)))))
;;           ((= counter k)
;;            tangent))))
;;     (iter 1 1))


(define (num i x)
  (if (= i 0)
      x
      (square x)))

(define (tan-cf x k)
  (define (iter i)
    (if (> i k)
        0
        (/
         (num i x)
         (- (+ (* 2 i) 1) (iter (+ i 1))))))
  (iter 0))

(tan-cf 2.0 15.0)
