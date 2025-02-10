#lang scheme

(define (make-point x y)
  (cons x y))

(define (x-point a)
  (car a))

(define (y-point b)
  (cdr b))

; we need at least 3 points to make a rectangle

(define point1
  (make-point 3 4))

(define point2
  (make-point 3 6))

(define point3
  (make-point 4 4))

(define (make-rectangle p1 p2 p3)
  (cons p1 (cons p2 (cons p3 '()))))

(define first-rectangle
  (make-rectangle point1 point2 point3))

(define (access-rectangle rectangle point coord)
  (cond ((= point 1)
         (if (equal? coord 'x)
             (car (car rectangle))
             (cdr (car rectangle))))
        ((= point 2)
         (if (equal? coord 'x)
             (car (car (cdr rectangle)))
             (cdr (car (cdr rectangle)))))
        ((= point 3)
         (if (equal? coord 'x)
             (car (car (cdr (cdr rectangle))))
             (cdr (car (cdr (cdr rectangle))))))))

;; (define (rectangle-base rectangle)
;;   (let ((x_a (access-rectangle rectangle 1 'x))
;;         (x_b (access-rectangle rectangle 2 'x))
;;         (y_a (access-rectangle rectangle 1 'y))
;;         (y_b (access-rectangle rectangle 2 'y))
;;         (x_c (access-rectangle rectangle 3 'x))
;;         (y_c (access-rectangle rectangle 3 'y)))
;;     (cond
;;      ((and (= y_a y_b) (not (= x_a x_b)))
;;       (abs (- x_a x_b)))
;;      ((and (= y_a y_c) (not (= x_a x_c)))
;;       (abs (- x_a x_c)))
;;      ((and (= y_b y_c) (not (= x_b x_c)))
;;       (abs (- x_b x_c))))))

(define (base-height rectangle)
  (let ((x_a (access-rectangle rectangle 1 'x))
        (x_b (access-rectangle rectangle 2 'x))
        (y_a (access-rectangle rectangle 1 'y))
        (y_b (access-rectangle rectangle 2 'y))
        (x_c (access-rectangle rectangle 3 'x))
        (y_c (access-rectangle rectangle 3 'y)))
    (cons
     (cond
      ((and (= y_a y_b) (not (= x_a x_b)))
      (abs (- x_a x_b)))
     ((and (= y_a y_c) (not (= x_a x_c)))
      (abs (- x_a x_c)))
     ((and (= y_b y_c) (not (= x_b x_c)))
      (abs (- x_b x_c))))
     (cond
      ((and (= x_a x_c) (not (= y_a y_c)))
       (abs (- y_a y_c)))
      ((and (= x_a x_b) (not (= y_a y_b)))
       (abs (- y_a y_b)))
      ((and (= x_b x_c) (not (= y_b y_c)))
       (abs (- y_b y_c)))))))

(define (area-rectangle rectangle)
  (* (car (base-height rectangle))
     (cdr (base-height rectangle))))

(define (perimeter-rectangle rectangle)
  (* (+ (car (base-height rectangle))
        (cdr (base-height rectangle)))
     2))

(define random-rectangle
  (cons point1 (cons point2 (cons point3 '()))))

(define c_1
  (make-point 3 7))

(define a_1
  (make-point 3 4))

(define b_1
  (make-point 6 4))

(define rectangle_1
  (make-rectangle c_1 a_1 b_1))

(area-rectangle rectangle_1)

(perimeter-rectangle rectangle_1)
