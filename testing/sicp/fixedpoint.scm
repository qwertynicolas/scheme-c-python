#lang scheme

(define (square x)
  (* x x))

(define tolerance 0.000000001)

(define (average x y)
  (/ (+ x y) 2))

(define (inc x)
  (+ x 1))

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

(define (average-damp f)
  (lambda (x) (average x (f x))))

;; (define (sqrt x)
;;   (fixed-point (average-damp (lambda (y) (/ x y)))
;;                1.0))

(define (cbrt x)
  (fixed-point (average-damp (lambda (y) (/ x (square y))))
               1.0))

(define dx 0.00001)

(define (cube x)
  (* x x x))

(define (deriv g)
  (lambda (x) (/ (- (g (+ x dx)) (g x))
                 dx)))

(define (newton-transform g)
  (lambda (x) (- x (/ (g x) ((deriv g) x)))))

(define (newton-method g guess)
  (fixed-point (newton-transform g)
               guess))

(define (sqrt x)
  (newton-method
   (lambda (y) (- (square y) x)) 1.0))

(define (fixed-point-of-transform g transform guess)
  (fixed-point (transform g) guess))

(define (sqrt-v2 x)
  (fixed-point-of-transform
   (lambda (y) (/ x y)) average-damp 1.0))

(define (sqrt-v3 x)
  (fixed-point-of-transform
   (lambda (y) (- (square y) x)) newton-transform 1.0))

(define (cubic a b c)
  (lambda (x) (+
               (cube x)
               (* a (square x))
               (* b x)
               c)))

; golden ratio = (1 + sqrt(5)) / 2
; it also satisfies the equation phi^2 = phi + 1

;; (fixed-point (lambda (x) (+ 1 (/ 1 x)))
;;              1.0)

;; (fixed-point (lambda (x) (/ (log 1000) (log x)))
;;              2.0)

;; (fixed-point (lambda (x) (average (/ (log 1000) (log x)) x))
;;              2.0)


; 51 steps without average damping
; 13 steps with average damping
