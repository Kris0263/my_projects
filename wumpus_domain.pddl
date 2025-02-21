(define (domain wumpus_domain_a)
  (:requirements :strips :typing)
  (:types agent location object wumpus) ;; Definnig  types used  in domain
  (:predicates
    (adjacent ?square-1 - location ?square-2 - location) ;; Defining Adjacent Locations
    (pit ?square - location) ;; Indicates that a pit is present at a given location
    (at ?who - (either agent object wumpus) ?square - location) ;;  Specifies location of  agent, object  ot wumpus
    (have ?who - agent ?what - object) ;;  Indicates that agent has an object
    (dead ?who - wumpus) ;; Indicates  dead wumpus
    (wumpus-in ?square - location)
    (is-agent ?who - agent)
    (is-wumpus ?who - wumpus)
    (is-gold ?what - object)
    (is-arrow ?what - object)
  )
  ;;  DEFINIG ACTIONS
  (:action move
    :parameters (?who - agent ?from - location ?to - location)
    :precondition (and 
                    (is-agent ?who)
                    (at ?who ?from) 
                    (adjacent ?from ?to) 
                    (not (pit ?to)) 
                    (not (wumpus-in ?to)))
    :effect (and 
             (at ?who ?to) 
             (not (at ?who ?from)))
  )

  (:action take
    :parameters (?who - agent ?what - object ?where - location)
    :precondition (and 
                    (is-agent ?who)
                    (at ?who ?where) 
                    (at ?what ?where))
    :effect (and 
             (have ?who ?what) 
             (not (at ?what ?where)))
  )
;; Updated shoot action -
  (:action shoot
    :parameters (?who - agent ?where - location ?with-what - object ?victim - wumpus ?where-victim - location)
    :precondition (and 
                    (is-agent ?who)
                    (have ?who ?with-what) 
                    (is-arrow ?with-what) 
                    (at ?who ?where) 
                    (is-wumpus ?victim) 
                    (at ?victim ?where-victim) 
                    (adjacent ?where ?where-victim))
    :effect (and 
             (dead ?victim) 
             (not (wumpus-in ?where-victim))  ;; This tells the wumpus is no longer in the 'where-victim' place 
             (not (have ?who ?with-what))) ;; The agent no longer has the arrow
  )
)
