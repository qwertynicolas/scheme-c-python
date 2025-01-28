#lang scheme
(define (square-root S)
  (define tolerance 0.0001)

  (define (good-enough? guess)
  (< (abs (- (* guess guess) S)) tolerance))

  (define (improve guess)
    (/ (+ guess (/ S guess)) 2))

  (define (sqrt-iter guess)
    (if (good-enough? guess)
        guess
        (sqrt-iter (improve guess))))

  (sqrt-iter 1.0))

(define (prompt-for-numbers)
  (display "Enter a number (or a letter to quit): ")
  (flush-output)
  (let ((input (read)))
    (cond
     [(number? input)
      (display "The square root is: ")
      (displayln (square-root input))
      (prompt-for-numbers)]
     [else
      (displayln "Exiting. Goodbye!")])))

(prompt-for-numbers)
