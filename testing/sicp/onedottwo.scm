#lang scheme
(define first-part (+
                    (+ 5 4)
                    (- 2 (- 3 (+ 6 4/5)))))

first-part

(define second-part (*
                     3
                     (- 6 2)
                     (- 2 7)))

second-part

(define operation (/ first-part second-part))

operation
