#lang scheme

(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (remainder a b))))

(define x (cons 1 2))
(define y (cons 3 4))
(define z (cons x y))

(define (make-rat n d)
  (let ((g (gcd n d)))
    (cons (/ n g) (/ d g))))

;; (define (better-make-rat n d)
;;   (let ((g ((abs (gcd n d)))))
;;     (cons (if (or (< n 0) (< d 0))
;;               (- (/ n g))
;;               (/ n g))
;;           (/ (abs d) g))))

;; (define (better-make-rat n d)
;;   (let ((g (gcd n d)))
;;     (cons (if (or (< n 0) (< d 0))
;;               (- (abs (/ n g)))
;;               (/ n g))
;;           (abs (/ d g)))))

(define (make-rat-v2 n d)
  (let ((g (gcd n d)))
    (cons (cond ((and (< n 0) (< d 0)) (abs (/ n g)))
                ((or (< n 0) (< d 0)) (- (abs (/ n g))))
                (else (/ n g)))
          (abs (/ d g)))))

(make-rat-v2 -3 -5)

(define (numer x) (car x))
(define (denom x) (cdr x))

(define (print-rat x)
  (newline)
  (display (numer x))
  (display "/")
  (display (denom x)))

(define (add-rat x y)
  (print-rat
  (make-rat (+ (* (numer x) (denom y))
               (* (numer y) (denom x)))
            (* (denom x) (denom y)))))

(define (sub-rat x y)
  (make-rat (- (* (numer x) (denom y))
               (* (numer y) (denom x)))
            (* (denom x) (denom y))))

(define (mul-rat x y)
  (print-rat
   (make-rat (* (numer x) (numer y))
             (* (denom x) (denom y)))))

(define (div-rat x y)
  (print-rat
   (make-rat (* (numer x) (denom y))
             (* (denom x) (numer y)))))

(define one-half (make-rat 1 2))

(define one-third (make-rat 1 3))
