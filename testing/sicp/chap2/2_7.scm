#lang scheme

(define (make-interval a b)
  (cons a b))

;; (define (lower-bound r)
;;   (- (car r) (* (car r) (cdr r))))

;; (define (upper-bound r)
;;   (+ (car r) (* (car r) (cdr r))))

(define (lower-bound i)
  (car i))

(define (upper-bound i)
  (cdr i))

(define interval-1
  (make-interval 6.12 7.48))

(define interval-2
  (make-interval 4.465 4.935))

(define (add-interval x y)
  (make-interval (+ (lower-bound x) (lower-bound y))
                 (+ (upper-bound x) (upper-bound y))))

(define (eq-parallel x y)
  (make-interval (/ 1 (+
                        (/ 1 (lower-bound x))
                        (/ 1 (lower-bound y))))
                 (/ 1 (+
                       (/ 1 (upper-bound x))
                       (/ 1 (upper-bound y))))))

;; (define (mul-interval x y)
;;   (let ((p1 (* (lower-bound x) (lower-bound y)))
;;         (p2 (* (lower-bound x) (upper-bound y)))
;;         (p3 (* (upper-bound x) (lower-bound y)))
;;         (p4 (* (upper-bound x) (upper-bound y))))
;;     (make-interval (min p1 p2 p3 p4)
;;                    (max p1 p2 p3 p4))))

;; (define (div-interval-v2 x y)
;;   (mul-interval
;;    x
;;    (make-interval (/ 1.0 (upper-bound y))
;;                   (/ 1.0 (lower-bound y)))))

(define (div-interval x y)
  (if (or (= (upper-bound y) 0) (= (lower-bound y) 0))
      (error "Division by zero" upper-bound lower-bound)
      (mul-interval
       x
       (make-interval (/ 1.0 (upper-bound y))
                      (/ 1.0 (lower-bound y))))))

(define (sub-interval x y)
  (make-interval (- (lower-bound x) (lower-bound y))
                 (- (upper-bound x) (upper-bound y))))

(define (width-interval x)
  (/ (- (cdr x)
        (car x))
     2))

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

