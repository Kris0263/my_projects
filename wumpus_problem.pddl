
(define (problem wumpus)
  (:domain wumpus_domain_a)
  (:objects
   john-wick - agent
   sq-1-1 sq-1-2 sq-1-3 sq-1-4
   sq-2-1 sq-2-2 sq-2-3 sq-2-4
   sq-3-1 sq-3-2 sq-3-3 sq-3-4
   sq-4-1 sq-4-2 sq-4-3 sq-4-4 - location
   the-gold - object
   the-arrow - object
   wumpus - wumpus)

  (:init
   ;; Vertical adjacencies notation: sq-{X-axis-coordinate}-{Y-axis-coordinate}
   (adjacent sq-1-1 sq-1-2) (adjacent sq-1-2 sq-1-1)
   (adjacent sq-1-2 sq-1-3) (adjacent sq-1-3 sq-1-2)
   (adjacent sq-1-3 sq-1-4) (adjacent sq-1-4 sq-1-3)
   (adjacent sq-2-1 sq-2-2) (adjacent sq-2-2 sq-2-1)
   (adjacent sq-2-2 sq-2-3) (adjacent sq-2-3 sq-2-2)
   (adjacent sq-2-3 sq-2-4) (adjacent sq-2-4 sq-2-3)
   (adjacent sq-3-1 sq-3-2) (adjacent sq-3-2 sq-3-1)
   (adjacent sq-3-2 sq-3-3) (adjacent sq-3-3 sq-3-2)
   (adjacent sq-3-3 sq-3-4) (adjacent sq-3-4 sq-3-3)
   (adjacent sq-4-1 sq-4-2) (adjacent sq-4-2 sq-4-1)
   (adjacent sq-4-2 sq-4-3) (adjacent sq-4-3 sq-4-2)
   (adjacent sq-4-3 sq-4-4) (adjacent sq-4-4 sq-4-3)
   
   ;; Horizontal adjacencies notation: sq-{X-axis-coordinate}-{Y-axis-coordinate}
   (adjacent sq-1-1 sq-2-1) (adjacent sq-2-1 sq-1-1)
   (adjacent sq-2-1 sq-3-1) (adjacent sq-3-1 sq-2-1)
   (adjacent sq-3-1 sq-4-1) (adjacent sq-4-1 sq-3-1)
   (adjacent sq-1-2 sq-2-2) (adjacent sq-2-2 sq-1-2)
   (adjacent sq-2-2 sq-3-2) (adjacent sq-3-2 sq-2-2)
   (adjacent sq-3-2 sq-4-2) (adjacent sq-4-2 sq-3-2)
   (adjacent sq-1-3 sq-2-3) (adjacent sq-2-3 sq-1-3)
   (adjacent sq-2-3 sq-3-3) (adjacent sq-3-3 sq-2-3)
   (adjacent sq-3-3 sq-4-3) (adjacent sq-4-3 sq-3-3)
   (adjacent sq-1-4 sq-2-4) (adjacent sq-2-4 sq-1-4)
   (adjacent sq-2-4 sq-3-4) (adjacent sq-3-4 sq-2-4)
   (adjacent sq-3-4 sq-4-4) (adjacent sq-4-4 sq-3-4)
   
   (at john-wick sq-1-1) ;; Agent starting position
   (at the-gold sq-3-3) ;; Gold's location
   (at wumpus sq-1-3)
   (have john-wick the-arrow) ;; Agent starts with the arrow
   (is-agent john-wick)
   (is-gold the-gold)
   (is-arrow the-arrow)
   (at the-arrow sq-1-1) ;; Arrow's initial location
  
   
   (pit sq-3-1) ;; Example of a pit
   (pit sq-4-4) ;; Example of a pit
   (pit sq-2-2) ;; Additional pit

   ;; Wumpus's location
   (is-wumpus wumpus)
   (wumpus-in sq-1-3))

  (:goal (and 
          (have john-wick the-gold) ;; Have the gold
          (at john-wick sq-1-1)     ;; At the starting square
          (dead wumpus)))            ;; Wumpus is dead
)