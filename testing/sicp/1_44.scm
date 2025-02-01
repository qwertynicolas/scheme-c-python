#lang scheme

(define dx 0.0001)

(define (average x y z)
  (/ (+ x y z) 3))

(define (repeater f n x)
  (define (iter accumulation end)
    (if (= end 0)
        accumulation
        (iter (f accumulation) (- end 1))))
  (iter x n))

(define (repeated f n)
  (lambda (x) (repeater f n x)))

(define (square x)
  (* x x))

(define (smooth f)
  (lambda (x) (average
               (f (- x dx))
               (f x)
               (f (+ x dx)))))

(define (repeated-smoothing f n x)
  (((repeated smooth n) f) x))

(repeated-smoothing square 3 4)

(((repeated smooth 3) square) 4)

;; (define (smooth f x)
;;   (average
;;    (f (- x dx))
;;    (f x)
;;    (f (+ x dx))))

;; ((repeated (smooth square) 5) 4) ; what happens with this call is n² 5 times starting with n=4
