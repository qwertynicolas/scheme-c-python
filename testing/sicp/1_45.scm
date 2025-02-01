#lang scheme

(define tolerance 0.000000001)

(define (fixed-point f guess)
  (define (good-enough v1 v2)
    (< (abs (- v1 v2)) tolerance))
  (define (try guess counter)
    (let ((next (f guess)))
      (if (good-enough guess next)
          (begin
            (newline)
            (display next)
            (newline)
            (display counter)
            (display " steps"))
          (begin
            (newline)
            (display guess)
            (try next (+ counter 1))))))
  (try guess 1))

(define (average x y)
  (/ (+ x y) 2))

(define (average-damp f)
  (lambda (x) (average x (f x))))

(define (inc x)
  (+ x 1))

(define (cube x)
  (* x x x))

(define (square x)
  (* x x))

(define (fourth-exp x)
  (* x x x x))

(define (composed f g)
  (lambda (x) (f (g x))))

(define (repeated f n)
  (lambda (x)
    (define (iter accumulation end)
      (cond ((= end 1) (f accumulation))
            ((= end 0) accumulation)
            ((even? end) (iter ((composed f f) accumulation) (- end 2)))
            (else (iter (f accumulation) (- end 1)))))
    (iter x n)))

(define (sqrt x)
  (fixed-point (average-damp (lambda (y) (/ x y)))
               1.0))

(define (cbrt x)
  (fixed-point (average-damp (lambda (y) (/ x (square y))))
               1.0))

(define (fourth-root x)
  (fixed-point (average-damp (average-damp (lambda (y) (/ x (cube y)))))
               1.0))

(define (exp x n)
  (cond ((= n 0) 1)
        ((even? n) (square (exp x (/ n 2))))
        (else (* x (exp x (- n 1))))))

;; (define (nth-root x r)
;;   (let ((n (- r 2)))
;;     (if (or (= n 0) (= n 1))
;;      (fixed-point (average-damp (lambda (y) (/ x (exp y (- r 1))))) 1.0)
;;     (fixed-point ((repeated average-damp n) (lambda (y) (/ x (exp y (- r 1))))) 1.0))))

(define (nth-root x r)
  (let ((n (- r 2)))
    (if (or (= n 0) (= n 1))
       (fixed-point (average-damp (lambda (y) (/ x (exp y (- r 1))))) 1.0)
       (fixed-point ((repeated average-damp n) (lambda (y) (/ x (exp y (- r 1))))) 1.0))))

(nth-root 16384 7)

;; (define (fifth-root x)
;;   (fixed-point (average-damp (average-damp (lambda (y) (/ x (fourth-exp y)))))
;;                1.0))

(define (fifth-root x)
  (fixed-point (average-damp (average-damp (average-damp (lambda (y) (/ x (fourth-exp y))))))
               1.0))

(define (fifth-exp x)
  (* x x x x x))

(define (sixth-root x)
  (fixed-point (average-damp (average-damp (average-damp (average-damp (lambda (y) (/ x (fifth-exp y)))))))
               1.0))

;; (define (fourth-root x)
;;   (fixed-point (average-damp (lambda (y) (/ x (cube y))))
;;                1.0))

;; (define (nth-root x n))
