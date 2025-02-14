#lang scheme

(define (make-interval a b)
  (cons a b))

(define (make-center-width c w)
  (cons (- c w) (+ c w)))

(define (lower-bound i)
  (car i))

(define (upper-bound i)
  (cdr i))

(define (center i)
  (/ (+ (lower-bound i) (upper-bound i)) 2))

(define (width i)
  (/ (- (upper-bound i) (lower-bound i)) 2))

(define (make-center-percent c p)
  (cons (- c (* c p))
        (+ c (* c p))))

(define (percent i)
  (let ((c (center i))
        (a (lower-bound i)))
    (abs (/ (- a c) c))))

(define interval-1
  (make-interval 6.12 7.48))

(define interval-2
  (make-interval 4.465 4.935))

(define (tolerance-product x y)
  (let ((p1 (percent x))
        (p2 (percent y)))
    (+ p1 p2)))

(define interval_1
  (make-center-percent 6.8 0.10))

(define (mul-interval x y)
  (let ((a (lower-bound x))
        (b (upper-bound x))
        (c (lower-bound y))
        (d (upper-bound y)))
    (cond ((and (>= a 0) (>= c 0)) ; case 1
           (make-interval (* a c) (* b d)))
          ((and (>= a 0) (< c 0) (> d 0)) ; case 2
           (make-interval (* b c) (* b d)))
          ((and (< a 0) (> b 0) (>= c 0)) ; case 3
           (make-interval (* a d) (* b d)))
          ((and (< a 0) (> b 0) (< c 0) (> d 0)) ; case 4
           (let ((p1 (* a c))
                 (p2 (* a d))
                 (p3 (* b c))
                 (p4 (* b d)))
             (make-interval
              (min p1 p2 p3 p4)
              (max p1 p2 p3 p4))))
          ((and (>= a 0) (<= d 0)) ; case 5
           (make-interval (* b c) (* a d)))
          ((and (<= b 0) (>= c 0)) ; case 6
           (make-interval (* a d) (* b c)))
          ((and (<= b 0) (<= d 0)) ; case 7
           (make-interval (* b d) (* a c)))
          ((and (<= b 0) (< c 0) (> d 0)) ; case 8
           (make-interval (* a d) (* a c)))
          ((and (< a 0) (> b 0) (<= d 0)) ; case 9
           (make-interval (* b c) (* a c))))))

(define (add-interval x y)
  (make-interval (+ (lower-bound x) (lower-bound y))
                 (+ (upper-bound x) (upper-bound y))))

(define (div-interval x y)
  (if (or (= (upper-bound y) 0) (= (lower-bound y) 0))
      (error "Division by zero" upper-bound lower-bound)
      (mul-interval
       x
       (make-interval (/ 1.0 (upper-bound y))
                      (/ 1.0 (lower-bound y))))))

(define (special-div-interval x y)
  (mul-interval
   x
   (make-interval (/ 1.0 (lower-bound y))
                  (/ 1.0 (upper-bound y)))))

; so, according to deepseek, it is possible to devise a new interval-arithmetic
; package in which these errors don't occur using affine arithmetic, but this escape my capabilities atm

(define (par1 r1 r2)
  (special-div-interval (mul-interval r1 r2)
                        (add-interval r1 r2)))

(define (par2 r1 r2)
  (let ((one (make-interval 1 1)))
    (div-interval
     one
     (add-interval (div-interval one r1)
                   (div-interval one r2)))))

(define interval-3
  (make-center-percent 25 0.10))

(define interval-4
  (make-center-percent 10 0.05))

(par1 interval-3 interval-4)
(par2 interval-3 interval-4)
